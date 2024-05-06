################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../vendor/lvgl/src/drivers/nuttx/lv_nuttx_cache.c \
../vendor/lvgl/src/drivers/nuttx/lv_nuttx_entry.c \
../vendor/lvgl/src/drivers/nuttx/lv_nuttx_fbdev.c \
../vendor/lvgl/src/drivers/nuttx/lv_nuttx_image_cache.c \
../vendor/lvgl/src/drivers/nuttx/lv_nuttx_lcd.c \
../vendor/lvgl/src/drivers/nuttx/lv_nuttx_libuv.c \
../vendor/lvgl/src/drivers/nuttx/lv_nuttx_profiler.c \
../vendor/lvgl/src/drivers/nuttx/lv_nuttx_touchscreen.c 

OBJS += \
./vendor/lvgl/src/drivers/nuttx/lv_nuttx_cache.o \
./vendor/lvgl/src/drivers/nuttx/lv_nuttx_entry.o \
./vendor/lvgl/src/drivers/nuttx/lv_nuttx_fbdev.o \
./vendor/lvgl/src/drivers/nuttx/lv_nuttx_image_cache.o \
./vendor/lvgl/src/drivers/nuttx/lv_nuttx_lcd.o \
./vendor/lvgl/src/drivers/nuttx/lv_nuttx_libuv.o \
./vendor/lvgl/src/drivers/nuttx/lv_nuttx_profiler.o \
./vendor/lvgl/src/drivers/nuttx/lv_nuttx_touchscreen.o 

C_DEPS += \
./vendor/lvgl/src/drivers/nuttx/lv_nuttx_cache.d \
./vendor/lvgl/src/drivers/nuttx/lv_nuttx_entry.d \
./vendor/lvgl/src/drivers/nuttx/lv_nuttx_fbdev.d \
./vendor/lvgl/src/drivers/nuttx/lv_nuttx_image_cache.d \
./vendor/lvgl/src/drivers/nuttx/lv_nuttx_lcd.d \
./vendor/lvgl/src/drivers/nuttx/lv_nuttx_libuv.d \
./vendor/lvgl/src/drivers/nuttx/lv_nuttx_profiler.d \
./vendor/lvgl/src/drivers/nuttx/lv_nuttx_touchscreen.d 


# Each subdirectory must supply rules for building sources it contributes
vendor/lvgl/src/drivers/nuttx/%.o: ../vendor/lvgl/src/drivers/nuttx/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Andes C Compiler'
	$(CROSS_COMPILE)gcc -D__TLSR_RISCV_EN__=1 -DCHIP_TYPE=CHIP_TYPE_9518 -D__PROJECT_MESH__=1 -I"/cygdrive/C/TelinkV323/B91_GC9A01/GC9A01-master/firmware" -I../drivers/B91 -I../vendor/Common -I../common -I"/cygdrive/C/TelinkV323/B91_GC9A01/GC9A01-master/firmware/vendor/common/mi_api/libs" -I"/cygdrive/C/TelinkV323/B91_GC9A01/GC9A01-master/firmware/vendor/common/mi_api/mijia_ble_api" -O2 -flto -g3 -Wall -mcpu=d25f -ffunction-sections -fdata-sections -c -fmessage-length=0 -fno-builtin -fomit-frame-pointer -fno-strict-aliasing -fshort-wchar -fuse-ld=bfd -fpack-struct -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d) $(@:%.o=%.o)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


