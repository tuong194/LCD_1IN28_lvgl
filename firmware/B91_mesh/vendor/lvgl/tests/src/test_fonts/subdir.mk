################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../vendor/lvgl/tests/src/test_fonts/font_1.c \
../vendor/lvgl/tests/src/test_fonts/font_2.c \
../vendor/lvgl/tests/src/test_fonts/font_3.c \
../vendor/lvgl/tests/src/test_fonts/ubuntu_font.c 

OBJS += \
./vendor/lvgl/tests/src/test_fonts/font_1.o \
./vendor/lvgl/tests/src/test_fonts/font_2.o \
./vendor/lvgl/tests/src/test_fonts/font_3.o \
./vendor/lvgl/tests/src/test_fonts/ubuntu_font.o 

C_DEPS += \
./vendor/lvgl/tests/src/test_fonts/font_1.d \
./vendor/lvgl/tests/src/test_fonts/font_2.d \
./vendor/lvgl/tests/src/test_fonts/font_3.d \
./vendor/lvgl/tests/src/test_fonts/ubuntu_font.d 


# Each subdirectory must supply rules for building sources it contributes
vendor/lvgl/tests/src/test_fonts/%.o: ../vendor/lvgl/tests/src/test_fonts/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Andes C Compiler'
	$(CROSS_COMPILE)gcc -D__TLSR_RISCV_EN__=1 -DCHIP_TYPE=CHIP_TYPE_9518 -D__PROJECT_MESH__=1 -I"/cygdrive/C/TelinkV323/LCD_1IN28_lvgl/firmware" -I../drivers/B91 -I../vendor/Common -I../common -I"/cygdrive/C/TelinkV323/LCD_1IN28_lvgl/firmware/vendor/common/mi_api/libs" -I"/cygdrive/C/TelinkV323/LCD_1IN28_lvgl/firmware/vendor/common/mi_api/mijia_ble_api" -O2 -flto -g3 -Wall -mcpu=d25f -ffunction-sections -fdata-sections -mext-dsp -c -fmessage-length=0 -fno-builtin -fomit-frame-pointer -fno-strict-aliasing -fshort-wchar -fuse-ld=bfd -fpack-struct -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d) $(@:%.o=%.o)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


