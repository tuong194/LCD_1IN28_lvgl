/********************************************************************************************************
 * @file	main.c
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
#include "vendor/common/user_config.h"
#include "proj_lib/ble/blt_config.h"
#include "proj_lib/sig_mesh/app_mesh.h"

// user define

// -- user define end

unsigned int g_addr_load = FW_START_BY_BOOTLOADER_ADDR;

#define LOG_BOOTLOADER_DEBUG(pbuf, len, format, ...)    //LOG_MSG_LIB(TL_LOG_NODE_BASIC, pbuf, len, format, ##__VA_ARGS__)

#if 0
static volatile u8 AAA_pause = 1;
#define DEBUG_PAUSE(s_cnt)    \
    do{\
        while (AAA_pause) {\
            reg_tmr_sta = FLD_TMR_STA_WD;/* wd_clear();*/ \
            static volatile u32 s_cnt;s_cnt++;\
        }\
        AAA_pause = 1;\
    }while(0)
#else
#define DEBUG_PAUSE(s_cnt)    
#endif

_attribute_ram_code_ void irq_handler(void)
{
}

/**
 * @brief		BLE SDK RF interrupt handler.
 * @param[in]	none
 * @return      none
 */
_attribute_ram_code_
void rf_irq_handler(void)
{

	DBG_CHN10_HIGH;

	irq_handler();
	DBG_CHN10_LOW;

}

_attribute_ram_code_
void stimer_irq_handler(void)
{
	DBG_CHN9_HIGH;

	irq_handler();

	DBG_CHN9_LOW;
}

static const unsigned long crc32_half_tbl[16] = {
	0x00000000, 0x1db71064, 0x3b6e20c8, 0x26d930ac,
	0x76dc4190, 0x6b6b51f4, 0x4db26158, 0x5005713c,
	0xedb88320, 0xf00f9344, 0xd6d6a3e8, 0xcb61b38c,
	0x9b64c2b0, 0x86d3d2d4, 0xa00ae278, 0xbdbdf21c
};

#define OTA_FW_CRC_CHUNK_LEN	(256)
#define OTA_CRC_VAL_SIZE		(4)

u32 get_fw_crc_agthm2(u32 fw_addr, u32 fw_len)
{
	u32 crc_init = 0xFFFFFFFF;  	// crc init
	if(fw_len <= OTA_CRC_VAL_SIZE){
		return 0xFFFFFFFF;
	}

	fw_len -= OTA_CRC_VAL_SIZE;		// crc size

	u32 addr_read = fw_addr;
	while(fw_len > 0){
		u8 crc_buff[OTA_FW_CRC_CHUNK_LEN*2];
		u8 *pFwDat = crc_buff + OTA_FW_CRC_CHUNK_LEN;
		
		u32 crc_len = fw_len > OTA_FW_CRC_CHUNK_LEN ? OTA_FW_CRC_CHUNK_LEN : fw_len;
		flash_read_page(addr_read, crc_len, pFwDat);
		fw_len -= crc_len;
		addr_read += crc_len;
		
		for(int i=0; i<crc_len; i++){
			crc_buff[i*2]   = pFwDat[i] & 0x0f;
			crc_buff[i*2+1] = pFwDat[i]>>4;
		}
		
		//my_dump_str_data(DBG_OTA_FLOW, "FW CRC", &blotaSvr.fw_crc_init, 4);
		/* 16M clock, OTA PDU maximum length 240 Byte, 390 uS*/
		crc_init = crc32_half_cal(crc_init, crc_buff, (unsigned long* )crc32_half_tbl, crc_len*2);
	}

	return crc_init;
}

int is_fw_crc_valid(u32 fw_addr)
{
	u8 *pFwDat = (u8 *)(fw_addr + FLASH_R_BASE_ADDR);
	//u32 fw_crc_init = 0;
	u8 need_check_type = 0;
	u32 fw_len = *(u32 *)(pFwDat + FW_SIZE_ADDR);
	if(pFwDat[6] == 0x5D){
		need_check_type = pFwDat[7];
	}
	
	if(need_check_type == FW_CHECK_AGTHM1){
		//fw_crc_init = 0;	// init
	}else if(need_check_type == FW_CHECK_AGTHM2){
		#if 1
		u32 crc_cal = get_fw_crc_agthm2(fw_addr, fw_len);
		u32 crc_fw;
		flash_read_page(fw_addr + fw_len - 4, sizeof(crc_fw), (u8 *)&crc_fw);
		LOG_BOOTLOADER_DEBUG(0,0,"crc crc_cal: 0x%x, crc_fw: 0x%x", crc_cal, crc_fw);
		return (crc_cal == crc_fw);
		#else
		ota_program_offset = 0; 		// parameter for flash_fw_check_
		ota_program_bootAddr = fw_addr; // parameter for flash_fw_check_
		if(0 != flash_fw_check(0xFFFFFFFF)){
			LOG_BOOTLOADER_DEBUG(0,0,"fw crc failed");
		}else{
			LOG_BOOTLOADER_DEBUG(0,0,"fw crc ok");
			return 1;
		}
		#endif
	}

	return 0; // force check crc
}

_attribute_ram_code_ int is_valid_fw_bootloader(u32 addr_fw)
{
    u32 startup_flag;
    flash_read_page(addr_fw + BOOT_MARK_ADDR, sizeof(startup_flag), (u8 *)&startup_flag);
    return (START_UP_FLAG == startup_flag);
}

_attribute_ram_code_ void boot_load_with_ota_check(u32 addr_load)
{
#if 1   // ota
    if(is_valid_fw_bootloader(FLASH_ADR_UPDATE_NEW_FW)){
    	// crc has been check in application firmware
		LOG_BOOTLOADER_DEBUG(0,0,"new firmware found, addr: 0x%x", FLASH_ADR_UPDATE_NEW_FW);
        u32 fw_size_max = FW_SIZE_MAX_USER_K *1024;
        u8 buff[256];
        flash_read_page (FLASH_ADR_UPDATE_NEW_FW, 256, buff);
        u32 fw_size = *(u32 *)(buff + FW_SIZE_ADDR);
        if(fw_size <= fw_size_max)
        {
			// flash OTA area was unprotected and only protect 64k before OTA reboot, so no need to unprotect here again.
        	// copy from receive area to run area
            for (int i=0; i<fw_size; i+=256)
            {
                #if (BATT_CHECK_ENABLE)
                app_battery_power_check_and_sleep_handle(1);
                #endif
                if ((i & 0xfff) == 0)
                {
                    flash_erase_sector (addr_load + i);
                }
        
                flash_read_page (FLASH_ADR_UPDATE_NEW_FW + i, 256, buff);
                flash_write_page (addr_load + i, 256, buff);
            }

    		// need to check CRC again ?
    		int crc_valid_flag = is_fw_crc_valid(FLASH_ADR_UPDATE_NEW_FW);
			LOG_BOOTLOADER_DEBUG(0,0,"crc valid = %d", crc_valid_flag);
    		if(0 == crc_valid_flag){
				while(1){
					// if auto reboot, it may cause too much erase action when flash write error.
					// manual reboot should be better.
					static volatile u32 ota_copy_err;ota_copy_err++;
					wd_clear();
				};
			}else{
		        //erase receive area
		        for (int i = 0; i < ((fw_size + 4095)/4096); i++) {
		            #if (BATT_CHECK_ENABLE)
		            app_battery_power_check_and_sleep_handle(1);
		            #endif
		            flash_erase_sector(FLASH_ADR_UPDATE_NEW_FW + i*4096);
		        }
				LOG_USER_MSG_INFO(0,0,"new firmware copy ok and OTA receive area clear complete");
			}
        }
    }
#endif

    if(is_valid_fw_bootloader(addr_load)){
        //u32 fw_size = 0;
        //flash_read_page(addr_load + FW_SIZE_ADDR, sizeof(fw_size), (unsigned char *)&fw_size);
        if (1){//(is_valid_signature(addr_load, fw_size, 0)) {
            irq_disable();  // must, can't enter irq, because cstartup will be changed.
			// jump to next image
			((void(*)(void))(FLASH_R_BASE_ADDR + addr_load))();
			
			while(1){// have been reboot before, just make sure not go ahead.
				static volatile u32 boot_load_err;boot_load_err++;
			};
        } else {
            LOG_BOOTLOADER_DEBUG(0,0,"Application Signature Invalid, addr: 0x%x", addr_load);
        }
    }else{
        LOG_BOOTLOADER_DEBUG(0,0,"Firmware start up flag Invalid, addr: 0x%x", addr_load);
    }
}

_attribute_ram_code_ int main(void)
{
	blc_pm_select_internal_32k_crystal();
	sys_init(DCDC_1P4_LDO_1P8,VBAT_MAX_VALUE_GREATER_THAN_3V6); // need to confirm if want to use DCDC.
	clock_init_B91();
#if (MODULE_WATCHDOG_ENABLE)
	wd_set_interval_ms(WATCHDOG_INIT_TIMEOUT);
	wd_start();
#endif
	//gpio_init(!deepRetWakeUp);

	blc_app_loadCustomizedParameters();		// call to handle zbit flash

#if (BATT_CHECK_ENABLE)
    app_battery_power_check_and_sleep_handle(0); //battery check must do before OTA relative operation
#endif

#if 1 //jump to selected firmware
    irq_disable();  // must, can't enter irq, because cstartup have been changed.
	LOG_USER_MSG_INFO(0, 0,"[boot] Start from Bootloader");
	
	// flash is protected in application firmware, so no need to protect here again
    boot_load_with_ota_check(g_addr_load);  // should reboot inside.
#endif

    // should not run here for ever.
    while (1) {
    	static volatile u32 boot_loader_loop_cnt;
    	boot_loader_loop_cnt++;
    }
}
