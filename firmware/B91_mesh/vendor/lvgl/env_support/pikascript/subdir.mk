################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../vendor/lvgl/env_support/pikascript/pika_lv_point_t.c \
../vendor/lvgl/env_support/pikascript/pika_lv_timer_t.c \
../vendor/lvgl/env_support/pikascript/pika_lv_wegit.c \
../vendor/lvgl/env_support/pikascript/pika_lvgl.c \
../vendor/lvgl/env_support/pikascript/pika_lvgl_indev_t.c \
../vendor/lvgl/env_support/pikascript/pika_lvgl_lv_event.c \
../vendor/lvgl/env_support/pikascript/pika_lvgl_lv_obj.c \
../vendor/lvgl/env_support/pikascript/pika_lvgl_lv_style_t.c 

OBJS += \
./vendor/lvgl/env_support/pikascript/pika_lv_point_t.o \
./vendor/lvgl/env_support/pikascript/pika_lv_timer_t.o \
./vendor/lvgl/env_support/pikascript/pika_lv_wegit.o \
./vendor/lvgl/env_support/pikascript/pika_lvgl.o \
./vendor/lvgl/env_support/pikascript/pika_lvgl_indev_t.o \
./vendor/lvgl/env_support/pikascript/pika_lvgl_lv_event.o \
./vendor/lvgl/env_support/pikascript/pika_lvgl_lv_obj.o \
./vendor/lvgl/env_support/pikascript/pika_lvgl_lv_style_t.o 

C_DEPS += \
./vendor/lvgl/env_support/pikascript/pika_lv_point_t.d \
./vendor/lvgl/env_support/pikascript/pika_lv_timer_t.d \
./vendor/lvgl/env_support/pikascript/pika_lv_wegit.d \
./vendor/lvgl/env_support/pikascript/pika_lvgl.d \
./vendor/lvgl/env_support/pikascript/pika_lvgl_indev_t.d \
./vendor/lvgl/env_support/pikascript/pika_lvgl_lv_event.d \
./vendor/lvgl/env_support/pikascript/pika_lvgl_lv_obj.d \
./vendor/lvgl/env_support/pikascript/pika_lvgl_lv_style_t.d 


# Each subdirectory must supply rules for building sources it contributes
vendor/lvgl/env_support/pikascript/%.o: ../vendor/lvgl/env_support/pikascript/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Andes C Compiler'
	$(CROSS_COMPILE)gcc -D__TLSR_RISCV_EN__=1 -DCHIP_TYPE=CHIP_TYPE_9518 -D__PROJECT_MESH__=1 -I"/cygdrive/C/TelinkV323/B91_GC9A01/GC9A01-master/firmware" -I../drivers/B91 -I../vendor/Common -I../common -I"/cygdrive/C/TelinkV323/B91_GC9A01/GC9A01-master/firmware/vendor/common/mi_api/libs" -I"/cygdrive/C/TelinkV323/B91_GC9A01/GC9A01-master/firmware/vendor/common/mi_api/mijia_ble_api" -O2 -flto -g3 -Wall -mcpu=d25f -ffunction-sections -fdata-sections -c -fmessage-length=0 -fno-builtin -fomit-frame-pointer -fno-strict-aliasing -fshort-wchar -fuse-ld=bfd -fpack-struct -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d) $(@:%.o=%.o)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


