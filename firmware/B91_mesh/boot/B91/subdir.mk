################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_UPPER_SRCS += \
../boot/B91/cstartup_B91.S \
../boot/B91/cstartup_B91_DLM.S \
../boot/B91/cstartup_B91_Data_Bss_Retention.S 

OBJS += \
./boot/B91/cstartup_B91.o \
./boot/B91/cstartup_B91_DLM.o \
./boot/B91/cstartup_B91_Data_Bss_Retention.o 

S_UPPER_DEPS += \
./boot/B91/cstartup_B91.d \
./boot/B91/cstartup_B91_DLM.d \
./boot/B91/cstartup_B91_Data_Bss_Retention.d 


# Each subdirectory must supply rules for building sources it contributes
boot/B91/%.o: ../boot/B91/%.S
	@echo 'Building file: $<'
	@echo 'Invoking: Andes C Compiler'
	$(CROSS_COMPILE)gcc -D__TLSR_RISCV_EN__=1 -DCHIP_TYPE=CHIP_TYPE_9518 -D__PROJECT_MESH__=1 -I"/cygdrive/C/TelinkV323/LCD_1IN28_lvgl/firmware" -I../drivers/B91 -I../vendor/Common -I../common -I"/cygdrive/C/TelinkV323/LCD_1IN28_lvgl/firmware/vendor/common/mi_api/libs" -I"/cygdrive/C/TelinkV323/LCD_1IN28_lvgl/firmware/vendor/common/mi_api/mijia_ble_api" -O2 -flto -g3 -Wall -mcpu=d25f -ffunction-sections -fdata-sections -c -fmessage-length=0 -fno-builtin -fomit-frame-pointer -fno-strict-aliasing -fshort-wchar -fuse-ld=bfd -fpack-struct -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d) $(@:%.o=%.o)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


