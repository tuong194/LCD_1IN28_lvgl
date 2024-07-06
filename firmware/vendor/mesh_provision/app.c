/********************************************************************************************************
 * @file	app.c
 *
 * @brief	for TLSR chips
 *
 * @author	telink
 * @date	Sep. 30, 2010
 *
 * @par     Copyright (c) 2017, Telink Semiconductor (Shanghai) Co., Ltd. ("TELINK")
 *          All rights reserved.
 *
 *          Licensed under the Apache License, Version 2.0 (the "License");
 *          you may not use this file except in compliance with the License.
 *          You may obtain a copy of the License at
 *
 *              http://www.apache.org/licenses/LICENSE-2.0
 *
 *          Unless required by applicable law or agreed to in writing, software
 *          distributed under the License is distributed on an "AS IS" BASIS,
 *          WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *          See the License for the specific language governing permissions and
 *          limitations under the License.
 *
 *******************************************************************************************************/
#include "tl_common.h"
#include "drivers.h"
#include "proj_lib/mesh_crypto/mesh_crypto.h"
#include "proj_lib/mesh_crypto/mesh_md5.h"
#include "proj_lib/sig_mesh/app_mesh.h"
#include "../common/app_provison.h"
#include "../common/app_beacon.h"
#include "../common/app_proxy.h"
#include "../common/app_health.h"
#include "../common/mesh_ota.h"
#include "application/keyboard/keyboard.h"
#include "app.h"
#include "app_ui.h"
#if __TLSR_RISCV_EN__
#include "stack/ble//controller/ble_controller.h" // include gap.h
#include "stack/ble/host/gap/gap.h"
#include "stack/ble/service/ota/ota_server.h"
#include "stack/ble/ble.h"
#else
#include "stack/ble/gap/gap.h"
#endif
#include "vendor/common/blt_soft_timer.h"
//#include "proj/drivers/rf_pa.h"
#include "../common/remote_prov.h"
#include "../common/security_network_beacon.h"
#include "../common/mesh_access_layer.h"
#if SMART_PROVISION_ENABLE
#include "vendor/common/smart_provision.h"
#endif
#if (MESH_CDTP_ENABLE)
#include "mesh_cdtp.h"
#endif

#if (HCI_ACCESS==HCI_USE_UART)
#include "drivers.h"
#endif

#if 1
// refert to "app_buffer.c/app_buffer.h"
#else
#if(MCU_CORE_TYPE == MCU_CORE_8269) // 8269 ram limited
MYFIFO_INIT(blt_rxfifo, 64, 8);
MYFIFO_INIT(blt_txfifo, 40, 4);
#else
#define BLT_RX_FIFO_SIZE        (MESH_DLE_MODE ? DLE_RX_FIFO_SIZE : 64)
#define BLT_TX_FIFO_SIZE        (MESH_DLE_MODE ? DLE_TX_FIFO_SIZE : 40)

MYFIFO_INIT(blt_rxfifo, BLT_RX_FIFO_SIZE, 16);
MYFIFO_INIT(blt_txfifo, BLT_TX_FIFO_SIZE, 16); // 16 is enough for gateway. no need too much, especially when extend adv is enable.
#endif
#endif


// u8		peer_type;
// u8		peer_mac[12];

#if MD_SENSOR_EN
STATIC_ASSERT(FLASH_ADR_MD_SENSOR != FLASH_ADR_VC_NODE_INFO);   // address conflict
#endif
//////////////////////////////////////////////////////////////////////////////
//	Initialization: MAC address, Adv Packet, Response Packet
//////////////////////////////////////////////////////////////////////////////

//----------------------- UI ---------------------------------------------
#if (BLT_SOFTWARE_TIMER_ENABLE)
/**
 * @brief   This function is soft timer callback function.
 * @return  <0:delete the timer; ==0:timer use the same interval as prior; >0:timer use the return value as new interval. 
 */
int soft_timer_test0(void)
{
	//gpio 0 toggle to see the effect
	DBG_CHN4_TOGGLE;
	static u32 soft_timer_cnt0 = 0;
	soft_timer_cnt0++;
	return 0;
}
#endif


//----------------------- handle BLE event ---------------------------------------------
int app_event_handler (u32 h, u8 *p, int n)
{
	static u32 event_cb_num;
	event_cb_num++;
	int send_to_hci = 1;

	if (h == (HCI_FLAG_EVENT_BT_STD | HCI_EVT_LE_META))		//LE event
	{
		u8 subcode = p[0];

	//------------ ADV packet --------------------------------------------
		if (subcode == HCI_SUB_EVT_LE_ADVERTISING_REPORT)	// ADV packet
		{
			event_adv_report_t *pa = (event_adv_report_t *)p;
			if(LL_TYPE_ADV_NONCONN_IND != (pa->event_type & 0x0F)){
				return 0;
			}

			#if 0 // TESTCASE_FLAG_ENABLE
			u8 mac_pts[] = {0xDA,0xE2,0x08,0xDC,0x1B,0x00};	// 0x001BDC08E2DA
			if(memcmp(pa->mac, mac_pts,6)){
				return 0;
			}
			#endif
			
			#if DEBUG_MESH_DONGLE_IN_VC_EN
			send_to_hci = (0 == mesh_dongle_adv_report2vc(pa->data, MESH_ADV_PAYLOAD));
			#else
			send_to_hci = (0 == app_event_handler_adv(pa->data, MESH_BEAR_ADV, 1));
			#endif
		}

	//------------ connection complete -------------------------------------
		else if (subcode == HCI_SUB_EVT_LE_CONNECTION_COMPLETE)	// connection complete
		{
			event_connection_complete_t *pc = (event_connection_complete_t *)p;
			if (!pc->status)							// status OK
			{
				//app_led_en (pc->handle, 1);

				//peer_type = pc->peer_adr_type;
				//memcpy (peer_mac, pc->mac, 6);
			}
			#if DEBUG_BLE_EVENT_ENABLE
			rf_link_light_event_callback(LGT_CMD_BLE_CONN);
			#endif

			#if DEBUG_MESH_DONGLE_IN_VC_EN
			debug_mesh_report_BLE_st2usb(1);
			#endif
			
			#if (MESH_CDTP_ENABLE)
			app_coc_ble_connect_cb(p);
			#endif
			
			proxy_cfg_list_init_upon_connection(BLS_CONN_HANDLE);
			mesh_service_change_report(BLS_CONN_HANDLE);
		}

	//------------ connection update complete -------------------------------
		else if (subcode == HCI_SUB_EVT_LE_CONNECTION_UPDATE_COMPLETE)	// connection update
		{
		}
	}

	//------------ disconnect -------------------------------------
	else if (h == (HCI_FLAG_EVENT_BT_STD | HCI_EVT_DISCONNECTION_COMPLETE))		//disconnect
	{

		event_disconnection_t	*pd = (event_disconnection_t *)p;
		//app_led_en (pd->handle, 0);
		//terminate reason
		if(pd->reason == HCI_ERR_CONN_TIMEOUT){

		}
		else if(pd->reason == HCI_ERR_REMOTE_USER_TERM_CONN){  //0x13

		}
		#if 0 // TODO
		else if(pd->reason == SLAVE_TERMINATE_CONN_ACKED || pd->reason == SLAVE_TERMINATE_CONN_TIMEOUT){

		}
		#endif
		#if DEBUG_BLE_EVENT_ENABLE
		rf_link_light_event_callback(LGT_CMD_BLE_ADV);
		#endif 

		#if DEBUG_MESH_DONGLE_IN_VC_EN
		debug_mesh_report_BLE_st2usb(0);
		#endif
		
		#if (MESH_CDTP_ENABLE)
		app_coc_ble_disconnect_cb(p);
		#endif

		mesh_ble_disconnect_cb(p);
	}

	if (send_to_hci)
	{
		//blc_hci_send_data (h, p, n);
	}

	return 0;
}

/////////////////////////////////////////////////////////////////////
// main loop flow
/////////////////////////////////////////////////////////////////////
_attribute_no_inline_ void main_loop ()
{
	static u32 tick_loop;

	tick_loop ++;
#if (BLT_SOFTWARE_TIMER_ENABLE)
	blt_soft_timer_process(MAINLOOP_ENTRY);
#endif
	mesh_loop_proc_prior();
	////////////////////////////////////// BLE entry /////////////////////////////////
	blt_sdk_main_loop ();
#if MODULE_USB_ENABLE
	usb_handle_irq();
#endif


	////////////////////////////////////// UI entry /////////////////////////////////
	//  add spp UI task:
#if (BATT_CHECK_ENABLE)
    app_battery_power_check_and_sleep_handle(1);
#endif
	proc_ui();
	proc_led();
	factory_reset_cnt_check();
	
	mesh_loop_process();
#if ADC_ENABLE
	static u32 adc_check_time;
	if(clock_time_exceed(adc_check_time, 1000*1000)){
		adc_check_time = clock_time();
		volatile static u16 T_adc_val;
		
		#if (BATT_CHECK_ENABLE)
		app_battery_check_and_re_init_user_adc();
		#endif
	#if(MCU_CORE_TYPE == MCU_CORE_8269)     
		T_adc_val = adc_BatteryValueGet();
	#else
		T_adc_val = adc_sample_and_get_result();
	#endif
	}  
#endif

	#if (TESTCASE_FLAG_ENABLE && (!__PROJECT_MESH_PRO__))
	test_case_key_refresh_patch();
	#endif
	
#if MESH_CDTP_ENABLE
	mesh_cdtp_loop();
#endif

#if __TLSR_RISCV_EN__
	main_loop_risv_sdk();	// at last should be better.
#endif
}

_attribute_no_inline_ void user_init()
{
    #if (BATT_CHECK_ENABLE)
    app_battery_power_check_and_sleep_handle(0); //battery check must do before OTA relative operation
    #endif
	enable_mesh_provision_buf();
	mesh_global_var_init();
	#if (0 == __TLSR_RISCV_EN__) // TODO
	set_blc_hci_flag_fun(0);// disable the hci part of for the lib .
	proc_telink_mesh_to_sig_mesh();		// must at first
	#endif
	#if (0 == __TLSR_RISCV_EN__) // B91 called in main_()
	blc_app_loadCustomizedParameters();  //load customized freq_offset cap value and tp value
	#endif

	#if (APP_FLASH_PROTECTION_ENABLE)
	app_flash_protection_operation(FLASH_OP_EVT_APP_INITIALIZATION, 0, 0);
	blc_appRegisterStackFlashOperationCallback(app_flash_protection_operation); //register flash operation callback for stack
	#endif

#if (HCI_ACCESS == HCI_USE_USB)
	#if (0 == __TLSR_RISCV_EN__)
	usb_id_init();
	usb_log_init ();
	#else
	//set USB ID
	REG_ADDR8(0x1401f4) = 0x65;
	REG_ADDR16(0x1401fe) = 0x08d4;
	REG_ADDR8(0x1401f4) = 0x00;
	
	//////////////// config USB ISO IN/OUT interrupt /////////////////
		#if 0 // no need irq
	reg_usb_ep_irq_mask = BIT(7);			//audio in interrupt enable
	plic_interrupt_enable(IRQ11_USB_ENDPOINT);
	plic_set_priority(IRQ11_USB_ENDPOINT, 1);
	reg_usb_ep6_buf_addr = 0x80;
	reg_usb_ep7_buf_addr = 0x60;
	reg_usb_ep_max_size = (256 >> 3);
		#endif
	
		#if MODULE_USB_ENABLE // use manual USB descriptor
	usb_init();
	usb_set_pin_en();
		#else
		#endif
	#endif
	
	// need to have a simulate insert
	usb_dp_pullup_en (0);  //open USB enum
	gpio_set_func(GPIO_DP,AS_GPIO);
	gpio_set_output_en(GPIO_DP,1);
	gpio_write(GPIO_DP,0);
	sleep_us(20000);
	#if (0 == __TLSR_RISCV_EN__)
	gpio_set_func(GPIO_DP,AS_USB);
	#else
	gpio_set_func(GPIO_DP,AS_USB_DP);
	#endif
	usb_dp_pullup_en (1);  //open USB enum
#endif

	////////////////// BLE stack initialization ////////////////////////////////////
	ble_mac_init();    

	//link layer initialization
	//bls_ll_init (tbl_mac);
#if(MCU_CORE_TYPE == MCU_CORE_8269)
	blc_ll_initBasicMCU(tbl_mac);   //mandatory
#elif((MCU_CORE_TYPE == MCU_CORE_8258) || (MCU_CORE_TYPE == MCU_CORE_8278) || (MCU_CORE_TYPE == MCU_CORE_9518))
	blc_ll_initBasicMCU();                      //mandatory
	blc_ll_initStandby_module(tbl_mac);				//mandatory
#endif

#if (EXTENDED_ADV_ENABLE)
	mesh_blc_ll_initExtendedAdv();
#endif
#if __TLSR_RISCV_EN__
	blc_ll_initAdvertising_module(); 	//adv module: 		 mandatory for BLE slave,
#else
	blc_ll_initAdvertising_module(tbl_mac); 	//adv module: 		 mandatory for BLE slave,
#endif
	blc_ll_initSlaveRole_module();				//slave module: 	 mandatory for BLE slave,


#if (__TLSR_RISCV_EN__) 
	blc_ll_setAclConnMaxOctetsNumber(ACL_CONN_MAX_RX_OCTETS, ACL_CONN_MAX_TX_OCTETS);

	blc_ll_initAclConnTxFifo(app_acl_txfifo, ACL_TX_FIFO_SIZE, ACL_TX_FIFO_NUM);
	blc_ll_initAclConnRxFifo(app_acl_rxfifo, ACL_RX_FIFO_SIZE, ACL_RX_FIFO_NUM);

	u8 check_status = blc_controller_check_appBufferInitialization();
	if(check_status != BLE_SUCCESS){
		/* here user should set some log to know which application buffer incorrect */
		write_log32(0x88880000 | check_status);
		while(1);
	}
#endif
	//////////// Controller Initialization  End /////////////////////////

#if BLE_REMOTE_PM_ENABLE
	blc_ll_initPowerManagement_module();        //pm module:      	 optional
#endif

	//l2cap initialization
	//blc_l2cap_register_handler (blc_l2cap_packet_receive);
	blc_l2cap_register_handler (app_l2cap_packet_receive);
	blc_smp_setSecurityLevel(No_Security);
	///////////////////// USER application initialization ///////////////////

#if EXTENDED_ADV_ENABLE
	/*u8 status = */mesh_blc_ll_setExtAdvParamAndEnable();
#endif
	u8 status = bls_ll_setAdvParam( ADV_INTERVAL_MIN, ADV_INTERVAL_MAX, \
			 	 	 	 	 	     ADV_TYPE_CONNECTABLE_UNDIRECTED, OWN_ADDRESS_PUBLIC, \
			 	 	 	 	 	     0,  NULL,  BLT_ENABLE_ADV_ALL, ADV_FP_NONE);

	if(status != BLE_SUCCESS){  //adv setting err
		#if (0 == __TLSR_RISCV_EN__)
		write_reg8(0x8000, 0x11);  //debug
		#endif
		while(1);
	}
	
	// normally use this settings 
	blc_ll_setAdvCustomedChannel (37, 38, 39);

	bls_ll_setAdvEnable(1);  //adv enable

	rf_set_power_level_index (MY_RF_POWER_INDEX);
	bls_pm_setSuspendMask (SUSPEND_DISABLE);//(SUSPEND_ADV | SUSPEND_CONN)
    blc_hci_le_setEventMask_cmd(HCI_LE_EVT_MASK_ADVERTISING_REPORT|HCI_LE_EVT_MASK_CONNECTION_COMPLETE);

	////////////////// SPP initialization ///////////////////////////////////
#if (HCI_ACCESS != HCI_USE_NONE)
	#if (HCI_ACCESS==HCI_USE_USB)
	//blt_set_bluetooth_version (BLUETOOTH_VER_4_2);
	//bls_ll_setAdvChannelMap (BLT_ENABLE_ADV_ALL);
	usb_bulk_drv_init (0);
	blc_register_hci_handler (app_hci_cmd_from_usb, blc_hci_tx_to_usb);
	#elif (HCI_ACCESS == HCI_USE_UART)	//uart
	uart_drv_init();
	blc_register_hci_handler (blc_rx_from_uart, blc_hci_tx_to_uart);		//default handler
	//blc_register_hci_handler(rx_from_uart_cb,tx_to_uart_cb);				//customized uart handler
	#endif
#endif
#if ADC_ENABLE
	adc_drv_init();	// still init even though BATT_CHECK_ENABLE is enable, beause battery check may not be called in user init.
#endif
	rf_pa_init();
	bls_app_registerEventCallback (BLT_EV_FLAG_CONNECT, (blt_event_callback_t)&mesh_ble_connect_cb);
	blc_hci_registerControllerEventHandler(app_event_handler);		//register event callback
	//bls_hci_mod_setEventMask_cmd(0xffff);			//enable all 15 events,event list see ble_ll.h
	bls_set_advertise_prepare (app_advertise_prepare_handler);
	//bls_set_update_chn_cb(chn_conn_update_dispatch);
	

#if __TLSR_RISCV_EN__
	#if (BLE_OTA_ENABLE)
	////////////////// OTA relative ////////////////////////
	/* OTA module initialization must be called after "blc_ota_setNewFirmwwareStorageAddress"(if used), and before any other OTA API.*/
	blc_ota_initOtaServer_module();

	blc_ota_setOtaProcessTimeout(OTA_CMD_INTER_TIMEOUT_S);	//OTA process timeout:	30 seconds
	blc_ota_setOtaDataPacketTimeout(4); //OTA data packet timeout:	4 seconds
	blc_ota_registerOtaStartCmdCb(entry_ota_mode);
	blc_ota_registerOtaResultIndicationCb(show_ota_result);
	#endif
#else
	bls_ota_registerStartCmdCb(entry_ota_mode);
	bls_ota_registerResultIndicateCb(show_ota_result);
#endif
	app_enable_scan_all_device ();	// enable scan adv packet 

	// mesh_mode and layer init
	mesh_init_all();
	// OTA init
	bls_ota_clearNewFwDataArea(0); //must

	#if (MCU_CORE_TYPE == MCU_CORE_9518)
	// use original scan flow.
	blc_ll_initScanning_module_mesh();//blc_ll_initScanning_module(tbl_mac);
	#endif
	//gatt initialization
	#if((MCU_CORE_TYPE == MCU_CORE_8258) || (MCU_CORE_TYPE == MCU_CORE_8278) || (MCU_CORE_TYPE == MCU_CORE_9518))
	blc_gap_peripheral_init();    //gap initialization
	#endif	
	
	mesh_scan_rsp_init();
	my_att_init (provision_mag.gatt_mode);
	blc_att_setServerDataPendingTime_upon_ClientCmd(10);
	system_time_init();
#if (BLT_SOFTWARE_TIMER_ENABLE)
	blt_soft_timer_init();
	//blt_soft_timer_add(&soft_timer_test0, 1*1000*1000);
#endif

#if MESH_CDTP_ENABLE
	mesh_cdtp_init();
	// blc_att_enableWriteReqReject(1); // TODO: response error code for OTS
#endif

#if MESH_RX_TEST	
	mesh_register_upper_transport_layer_callback(mesh_upper_transport_layer_cb);
#endif

#if __TLSR_RISCV_EN__
	user_init_risv_sdk();	// at last should be better.
#endif
}

