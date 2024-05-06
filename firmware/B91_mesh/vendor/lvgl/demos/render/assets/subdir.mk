################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../vendor/lvgl/demos/render/assets/img_render_arc_bg.c \
../vendor/lvgl/demos/render/assets/img_render_lvgl_logo_argb8888.c \
../vendor/lvgl/demos/render/assets/img_render_lvgl_logo_l8.c \
../vendor/lvgl/demos/render/assets/img_render_lvgl_logo_rgb565.c \
../vendor/lvgl/demos/render/assets/img_render_lvgl_logo_rgb888.c \
../vendor/lvgl/demos/render/assets/img_render_lvgl_logo_xrgb8888.c 

OBJS += \
./vendor/lvgl/demos/render/assets/img_render_arc_bg.o \
./vendor/lvgl/demos/render/assets/img_render_lvgl_logo_argb8888.o \
./vendor/lvgl/demos/render/assets/img_render_lvgl_logo_l8.o \
./vendor/lvgl/demos/render/assets/img_render_lvgl_logo_rgb565.o \
./vendor/lvgl/demos/render/assets/img_render_lvgl_logo_rgb888.o \
./vendor/lvgl/demos/render/assets/img_render_lvgl_logo_xrgb8888.o 

C_DEPS += \
./vendor/lvgl/demos/render/assets/img_render_arc_bg.d \
./vendor/lvgl/demos/render/assets/img_render_lvgl_logo_argb8888.d \
./vendor/lvgl/demos/render/assets/img_render_lvgl_logo_l8.d \
./vendor/lvgl/demos/render/assets/img_render_lvgl_logo_rgb565.d \
./vendor/lvgl/demos/render/assets/img_render_lvgl_logo_rgb888.d \
./vendor/lvgl/demos/render/assets/img_render_lvgl_logo_xrgb8888.d 


# Each subdirectory must supply rules for building sources it contributes
vendor/lvgl/demos/render/assets/%.o: ../vendor/lvgl/demos/render/assets/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Andes C Compiler'
	$(CROSS_COMPILE)gcc -D__TLSR_RISCV_EN__=1 -DCHIP_TYPE=CHIP_TYPE_9518 -D__PROJECT_MESH__=1 -I"/cygdrive/C/TelinkV323/B91_GC9A01/GC9A01-master/firmware" -I../drivers/B91 -I../vendor/Common -I../common -I"/cygdrive/C/TelinkV323/B91_GC9A01/GC9A01-master/firmware/vendor/common/mi_api/libs" -I"/cygdrive/C/TelinkV323/B91_GC9A01/GC9A01-master/firmware/vendor/common/mi_api/mijia_ble_api" -O2 -flto -g3 -Wall -mcpu=d25f -ffunction-sections -fdata-sections -c -fmessage-length=0 -fno-builtin -fomit-frame-pointer -fno-strict-aliasing -fshort-wchar -fuse-ld=bfd -fpack-struct -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d) $(@:%.o=%.o)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


