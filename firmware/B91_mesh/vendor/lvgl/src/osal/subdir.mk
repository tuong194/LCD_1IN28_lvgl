################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../vendor/lvgl/src/osal/lv_cmsis_rtos2.c \
../vendor/lvgl/src/osal/lv_freertos.c \
../vendor/lvgl/src/osal/lv_os_none.c \
../vendor/lvgl/src/osal/lv_pthread.c \
../vendor/lvgl/src/osal/lv_rtthread.c \
../vendor/lvgl/src/osal/lv_windows.c 

OBJS += \
./vendor/lvgl/src/osal/lv_cmsis_rtos2.o \
./vendor/lvgl/src/osal/lv_freertos.o \
./vendor/lvgl/src/osal/lv_os_none.o \
./vendor/lvgl/src/osal/lv_pthread.o \
./vendor/lvgl/src/osal/lv_rtthread.o \
./vendor/lvgl/src/osal/lv_windows.o 

C_DEPS += \
./vendor/lvgl/src/osal/lv_cmsis_rtos2.d \
./vendor/lvgl/src/osal/lv_freertos.d \
./vendor/lvgl/src/osal/lv_os_none.d \
./vendor/lvgl/src/osal/lv_pthread.d \
./vendor/lvgl/src/osal/lv_rtthread.d \
./vendor/lvgl/src/osal/lv_windows.d 


# Each subdirectory must supply rules for building sources it contributes
vendor/lvgl/src/osal/%.o: ../vendor/lvgl/src/osal/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Andes C Compiler'
	$(CROSS_COMPILE)gcc -D__TLSR_RISCV_EN__=1 -DCHIP_TYPE=CHIP_TYPE_9518 -D__PROJECT_MESH__=1 -I"/cygdrive/C/TelinkV323/B91_GC9A01/GC9A01-master/firmware" -I../drivers/B91 -I../vendor/Common -I../common -I"/cygdrive/C/TelinkV323/B91_GC9A01/GC9A01-master/firmware/vendor/common/mi_api/libs" -I"/cygdrive/C/TelinkV323/B91_GC9A01/GC9A01-master/firmware/vendor/common/mi_api/mijia_ble_api" -O2 -flto -g3 -Wall -mcpu=d25f -ffunction-sections -fdata-sections -c -fmessage-length=0 -fno-builtin -fomit-frame-pointer -fno-strict-aliasing -fshort-wchar -fuse-ld=bfd -fpack-struct -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d) $(@:%.o=%.o)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


