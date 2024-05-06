/*
 * FreeRTOS Kernel V10.4.2
 * Copyright (C) 2020 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * https://www.FreeRTOS.org
 * https://github.com/FreeRTOS
 *
 * 1 tab == 4 spaces!
 */

/*-----------------------------------------------------------
 * Implementation of functions defined in portable.h for the RISC-V RV32 port.
 *----------------------------------------------------------*/

/* Scheduler includes. */
#include "3rd-party/freertos-V5/include/FreeRTOS.h"
#include "3rd-party/freertos-V5/include/task.h"
#include "3rd-party/freertos-V5/portable/GCC/RISC-V/portmacro.h"

/* Standard includes. */
#include "string.h"
#include "compiler.h"

#if( FREERTOS_ENABLE )

extern bool blt_ota_isOtaBusy(void);
extern bool blc_ll_isBrxWindowBusy(void);

#if configCLINT_BASE_ADDRESS
	#warning The configCLINT_BASE_ADDRESS constant has been deprecated.  configMTIME_BASE_ADDRESS and configMTIMECMP_BASE_ADDRESS are currently being derived from the (possibly 0) configCLINT_BASE_ADDRESS setting.  Please update to define configMTIME_BASE_ADDRESS and configMTIMECMP_BASE_ADDRESS dirctly in place of configCLINT_BASE_ADDRESS.  See https://www.FreeRTOS.org/Using-FreeRTOS-on-RISC-V.html
#endif

#ifndef configMTIME_BASE_ADDRESS
	#warning configMTIME_BASE_ADDRESS must be defined in FreeRTOSConfig.h.  If the target chip includes a memory-mapped mtime register then set configMTIME_BASE_ADDRESS to the mapped address.  Otherwise set configMTIME_BASE_ADDRESS to 0.  See https://www.FreeRTOS.org/Using-FreeRTOS-on-RISC-V.html
#endif

#ifndef configMTIMECMP_BASE_ADDRESS
	#warning configMTIMECMP_BASE_ADDRESS must be defined in FreeRTOSConfig.h.  If the target chip includes a memory-mapped mtimecmp register then set configMTIMECMP_BASE_ADDRESS to the mapped address.  Otherwise set configMTIMECMP_BASE_ADDRESS to 0.  See https://www.FreeRTOS.org/Using-FreeRTOS-on-RISC-V.html
#endif

/* Let the user override the pre-loading of the initial LR with the address of
prvTaskExitError() in case it messes up unwinding of the stack in the
debugger. */
#ifdef configTASK_RETURN_ADDRESS
	#define portTASK_RETURN_ADDRESS	configTASK_RETURN_ADDRESS
#else
	#define portTASK_RETURN_ADDRESS	prvTaskExitError
#endif

/* The stack used by interrupt service routines.  Set configISR_STACK_SIZE_WORDS
to use a statically allocated array as the interrupt stack.  Alternative leave
configISR_STACK_SIZE_WORDS undefined and update the linker script so that a
linker variable names __freertos_irq_stack_top has the same value as the top
of the stack used by main.  Using the linker script method will repurpose the
stack that was used by main before the scheduler was started for use as the
interrupt stack after the scheduler has started. */
#ifdef configISR_STACK_SIZE_WORDS
	PRIVILEGED_DATA static __attribute__ ((aligned(8))) StackType_t xISRStack[ configISR_STACK_SIZE_WORDS ] = { 0 };
	PRIVILEGED_DATA StackType_t xISRStackTop = ( StackType_t ) &( xISRStack[ configISR_STACK_SIZE_WORDS & ~portBYTE_ALIGNMENT_MASK ] );

	/* Don't use 0xa5 as the stack fill bytes as that is used by the kernerl for
	the task stacks, and so will legitimately appear in many positions within
	the ISR stack. */
	#define portISR_STACK_FILL_BYTE	0xee
#else
	extern const uint32_t __freertos_irq_stack_top[];
	PRIVILEGED_DATA StackType_t xISRStackTop = ( StackType_t ) __freertos_irq_stack_top;
#endif

/*
 * Setup the timer to generate the tick interrupts.  The implementation in this
 * file is weak to allow application writers to change the timer used to
 * generate the tick interrupt.
 */
void vPortSetupTimerInterrupt( void ) __attribute__(( weak ));

/*-----------------------------------------------------------*/

/* Used to program the machine timer compare register. */
PRIVILEGED_DATA uint64_t ullNextTime = 0ULL;
PRIVILEGED_DATA uint64_t *pullNextTime = &ullNextTime;
PRIVILEGED_DATA size_t uxTimerIncrementsForOneTick = ( size_t ) ( ( configCPU_CLOCK_HZ ) / ( configTICK_RATE_HZ ) ); /* Assumes increment won't go over 32-bits. */
PRIVILEGED_DATA uint32_t ullMachineTimerCompareRegisterBase = configMTIMECMP_BASE_ADDRESS;
PRIVILEGED_DATA volatile uint64_t * pullMachineTimerCompareRegister = NULL;

/* Set configCHECK_FOR_STACK_OVERFLOW to 3 to add ISR stack checking to task
stack checking.  A problem in the ISR stack will trigger an assert, not call the
stack overflow hook function (because the stack overflow hook is specific to a
task stack, not the ISR stack). */
#if defined( configISR_STACK_SIZE_WORDS ) && ( configCHECK_FOR_STACK_OVERFLOW > 2 )
	#warning This path not tested, or even compiled yet.

	static const uint8_t ucExpectedStackBytes[] = {
									portISR_STACK_FILL_BYTE, portISR_STACK_FILL_BYTE, portISR_STACK_FILL_BYTE, portISR_STACK_FILL_BYTE,		\
									portISR_STACK_FILL_BYTE, portISR_STACK_FILL_BYTE, portISR_STACK_FILL_BYTE, portISR_STACK_FILL_BYTE,		\
									portISR_STACK_FILL_BYTE, portISR_STACK_FILL_BYTE, portISR_STACK_FILL_BYTE, portISR_STACK_FILL_BYTE,		\
									portISR_STACK_FILL_BYTE, portISR_STACK_FILL_BYTE, portISR_STACK_FILL_BYTE, portISR_STACK_FILL_BYTE,		\
									portISR_STACK_FILL_BYTE, portISR_STACK_FILL_BYTE, portISR_STACK_FILL_BYTE, portISR_STACK_FILL_BYTE };	\

	#define portCHECK_ISR_STACK() configASSERT( ( memcmp( ( void * ) xISRStack, ( void * ) ucExpectedStackBytes, sizeof( ucExpectedStackBytes ) ) == 0 ) )
#else
	/* Define the function away. */
	#define portCHECK_ISR_STACK()
#endif /* configCHECK_FOR_STACK_OVERFLOW > 2 */

/*-----------------------------------------------------------*/

#if( configMTIME_BASE_ADDRESS != 0 ) && ( configMTIMECMP_BASE_ADDRESS != 0 )

	void vPortSetupTimerInterrupt( void )
	{
	uint32_t ulCurrentTimeHigh, ulCurrentTimeLow;
	volatile uint32_t * const pulTimeHigh = ( volatile uint32_t * const ) ( ( configMTIME_BASE_ADDRESS ) + 4UL ); /* 8-byte typer so high 32-bit word is 4 bytes up. */
	volatile uint32_t * const pulTimeLow = ( volatile uint32_t * const ) ( configMTIME_BASE_ADDRESS );
	volatile uint32_t ulHartId;

		__asm volatile( "csrr %0, mhartid" : "=r"( ulHartId ) );
		pullMachineTimerCompareRegister  = ( volatile uint64_t * ) ( ullMachineTimerCompareRegisterBase + ( ulHartId * sizeof( uint64_t ) ) );

		do
		{
			ulCurrentTimeHigh = *pulTimeHigh;
			ulCurrentTimeLow = *pulTimeLow;
		} while( ulCurrentTimeHigh != *pulTimeHigh );

		ullNextTime = ( uint64_t ) ulCurrentTimeHigh;
		ullNextTime <<= 32ULL; /* High 4-byte word is 32-bits up. */
		ullNextTime |= ( uint64_t ) ulCurrentTimeLow;
		ullNextTime += ( uint64_t ) uxTimerIncrementsForOneTick;
		*pullMachineTimerCompareRegister = ullNextTime;

		/* Prepare the time to use after the next tick interrupt. */
		ullNextTime += ( uint64_t ) uxTimerIncrementsForOneTick;
	}

#endif /* ( configMTIME_BASE_ADDRESS != 0 ) && ( configMTIME_BASE_ADDRESS != 0 ) */
/*-----------------------------------------------------------*/

BaseType_t xPortStartScheduler( void )
{
extern void xPortStartFirstTask( void );

	#if( configASSERT_DEFINED == 1 )
	{
		volatile uint32_t mtvec = 0;

		/* Check the least significant two bits of mtvec are 00 - indicating
		single vector mode. */
		__asm volatile( "csrr %0, mtvec" : "=r"( mtvec ) );
//		configASSERT( ( mtvec & 0x03UL ) == 0 );

		/* Check alignment of the interrupt stack - which is the same as the
		stack that was being used by main() prior to the scheduler being
		started. */
		configASSERT( ( xISRStackTop & portBYTE_ALIGNMENT_MASK ) == 0 );

		#ifdef configISR_STACK_SIZE_WORDS
		{
			memset( ( void * ) xISRStack, portISR_STACK_FILL_BYTE, sizeof( xISRStack ) );
		}
		#endif	 /* configISR_STACK_SIZE_WORDS */
	}
	#endif /* configASSERT_DEFINED */

	/* If there is a CLINT then it is ok to use the default implementation
	in this file, otherwise vPortSetupTimerInterrupt() must be implemented to
	configure whichever clock is to be used to generate the tick interrupt. */
	vPortSetupTimerInterrupt();

	#if( ( configMTIME_BASE_ADDRESS != 0 ) && ( configMTIMECMP_BASE_ADDRESS != 0 ) )
	{
		/* Enable mtime and external interrupts.  1<<7 for timer interrupt, 1<<11
		for external interrupt.  _RB_ What happens here when mtime is not present as
		with pulpino? */
		__asm volatile( "csrs mie, %0" :: "r"(0x880) );
	}
	#else
	{
		/* Enable external interrupts. */
		__asm volatile( "csrs mie, %0" :: "r"(0x800) );
	}
	#endif /* ( configMTIME_BASE_ADDRESS != 0 ) && ( configMTIMECMP_BASE_ADDRESS != 0 ) */

	xPortStartFirstTask();

	/* Should not get here as after calling xPortStartFirstTask() only tasks
	should be executing. */
	return pdFAIL;
}
/*-----------------------------------------------------------*/

void vPortEndScheduler( void )
{
	/* Not implemented. */
	for( ;; );
}

void vAssertCalled( const char * pcFile, unsigned long ulLine ){
	( void ) pcFile; ( void ) ulLine; 
//	printf("assert fail: %s, %d\r\n", pcFile, ulLine);
}




////  Telink Specific //////////////////////////////////////////////////////////////////////////////
#include "user_config.h"
#include "core.h"
#include "stimer.h"
#include "stack/ble/controller/ll/ll.h"

void vPortSetupTimerInterrupt( void );
void vPortRestoreActiveTask();
unsigned char bls_pm_getSuspendMask (void);
void bls_pm_setAppWakeupLowPower(u32 wakeup_tick, u8 enable);
void blt_brx_sleep();

#define SYSTICK_TO_OSTICK		(SYSTEM_TIMER_TICK_1S / configTICK_RATE_HZ)
PRIVILEGED_DATA static unsigned int timeBeforeSleep;
static void vPortRestoreTick(){
#if ( configUSE_TICKLESS_IDLE != 0 )
	unsigned int t = (unsigned int)(stimer_get_tick() - timeBeforeSleep);
	if(t < ((unsigned int)0xffffffff) / 2){
		vTaskStepTick((t + SYSTICK_TO_OSTICK/2) / SYSTICK_TO_OSTICK);
	}
#endif	
	vPortSetupTimerInterrupt(); 	//	reset the timer compare register to prevent irq triggered immediately
}

__attribute__(( weak )) void vPortWakeupNotify(){}

PRIVILEGED_DATA volatile int pm_enable = 1;
void vPortSuppressTicksAndSleep_i(uint32_t xExpectedIdleTime){
	if(pm_enable && bls_pm_getSuspendMask() && blt_miscParam.pm_enter_en){
		timeBeforeSleep = stimer_get_tick();

		if(xExpectedIdleTime > ((unsigned int)0xffffffff) / 2 / SYSTICK_TO_OSTICK){
			bls_pm_setAppWakeupLowPower(0, 0);
		}else{
			bls_pm_setAppWakeupLowPower(timeBeforeSleep + xExpectedIdleTime * SYSTICK_TO_OSTICK, 1);
		}
		blt_brx_sleep();
		vPortRestoreTick();
	}
	vPortWakeupNotify();
}

void vPortRestoreTask(){
	__asm volatile( "csrci	 mstatus,8");
	vPortRestoreTick();
	// to reset IDLE task stack
	vPortRestoreActiveTask();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
extern u32 blt_advExpectTime;
extern u32 blc_ll_cal_connwakeuptick();
extern int blc_ll_allow_block();
#define BLE_STATE_BRX_E_			7		//  that is the BLE_STATE_BRX_E in src

static u32 blc_ll_next_wakeup_duration(){
#if 0
	u32 nexttime = ((u32)(reg_system_tick_irq - clock_time()));
	return nexttime < (((unsigned int)0xffffffff) / 2) ? nexttime : 0;
#else
	u32 nexttime = ((u32)(blc_ll_cal_connwakeuptick() - clock_time()));
	return nexttime < ((unsigned int)0xE0000000) ? nexttime : 0;
#endif
}
void proto_task( void *pvParameters ){
	while (1){
		if(!((blc_ll_getCurrentState() == BLS_LINK_STATE_CONN) && blc_ll_isBrxBusy() )){
			//printf("enter blt_sdk_main_loop.\r\n");
			blt_sdk_main_loop();
			//printf("EXIT blt_sdk_main_loop.\r\n");
		}
		//printf("enter if.\r\n");
		if( blt_ota_isOtaBusy() )		{continue;}

		if(blc_ll_allow_block()){
			if(blc_ll_getCurrentState() == BLS_LINK_STATE_ADV){
				u32 dur = blt_advExpectTime - clock_time();
				dur = dur < (((unsigned int)0xffffffff) / 2) ? dur : 0;
				if(dur > 2 * SYSTEM_TIMER_TICK_1MS){
					//printf("5A. %d",dur/SYSTICK_TO_OSTICK);
					ulTaskNotifyTake( pdTRUE, dur / SYSTICK_TO_OSTICK);
				}
			}else if((blc_ll_getCurrentState() == BLS_LINK_STATE_CONN) && !blc_ll_isBrxBusy()){
				u32 dur = blc_ll_next_wakeup_duration();//blc_ll_cal_connwakeuptick() - clock_time();//blc_ll_next_wakeup_duration();
				if(dur > 3 * SYSTEM_TIMER_TICK_1MS){
					//printf("A %d",dur/SYSTICK_TO_OSTICK);
					ulTaskNotifyTake( pdTRUE, dur / SYSTICK_TO_OSTICK);
				}
			}else{
				//printf("EA.");
				ulTaskNotifyTake( pdTRUE, 50 / portTICK_PERIOD_MS);
			}
		}
		//printf("EXIT if.\r\n");
	}
}
#endif
