################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../vendor/UI/images/ui_img_31572172.c \
../vendor/UI/images/ui_img_h_png.c \
../vendor/UI/images/ui_img_m_png.c \
../vendor/UI/images/ui_img_rect7541_png.c \
../vendor/UI/images/ui_img_s_png.c 

OBJS += \
./vendor/UI/images/ui_img_31572172.o \
./vendor/UI/images/ui_img_h_png.o \
./vendor/UI/images/ui_img_m_png.o \
./vendor/UI/images/ui_img_rect7541_png.o \
./vendor/UI/images/ui_img_s_png.o 

C_DEPS += \
./vendor/UI/images/ui_img_31572172.d \
./vendor/UI/images/ui_img_h_png.d \
./vendor/UI/images/ui_img_m_png.d \
./vendor/UI/images/ui_img_rect7541_png.d \
./vendor/UI/images/ui_img_s_png.d 


# Each subdirectory must supply rules for building sources it contributes
vendor/UI/images/%.o: ../vendor/UI/images/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Andes C Compiler'
	$(CROSS_COMPILE)gcc -D__TLSR_RISCV_EN__=1 -DCHIP_TYPE=CHIP_TYPE_9518 -D__PROJECT_MESH__=1 -I"/cygdrive/C/TelinkV323/LCD_1IN28_lvgl/firmware" -I../drivers/B91 -I../vendor/Common -I../common -I"/cygdrive/C/TelinkV323/LCD_1IN28_lvgl/firmware/vendor/common/mi_api/libs" -I"/cygdrive/C/TelinkV323/LCD_1IN28_lvgl/firmware/vendor/common/mi_api/mijia_ble_api" -O2 -flto -g3 -Wall -mcpu=d25f -ffunction-sections -fdata-sections -mext-dsp -c -fmessage-length=0 -fno-builtin -fomit-frame-pointer -fno-strict-aliasing -fshort-wchar -fuse-ld=bfd -fpack-struct -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d) $(@:%.o=%.o)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


