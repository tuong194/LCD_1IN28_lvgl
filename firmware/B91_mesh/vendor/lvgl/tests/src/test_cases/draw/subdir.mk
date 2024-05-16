################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../vendor/lvgl/tests/src/test_cases/draw/test_clip_corner.c \
../vendor/lvgl/tests/src/test_cases/draw/test_draw_blend.c \
../vendor/lvgl/tests/src/test_cases/draw/test_draw_label.c \
../vendor/lvgl/tests/src/test_cases/draw/test_draw_layer.c \
../vendor/lvgl/tests/src/test_cases/draw/test_draw_sw_rotate.c \
../vendor/lvgl/tests/src/test_cases/draw/test_draw_vector.c \
../vendor/lvgl/tests/src/test_cases/draw/test_image_formats.c \
../vendor/lvgl/tests/src/test_cases/draw/test_layer_transform.c \
../vendor/lvgl/tests/src/test_cases/draw/test_render_to_al88.c \
../vendor/lvgl/tests/src/test_cases/draw/test_render_to_argb8888.c \
../vendor/lvgl/tests/src/test_cases/draw/test_render_to_l8.c \
../vendor/lvgl/tests/src/test_cases/draw/test_render_to_rgb565.c \
../vendor/lvgl/tests/src/test_cases/draw/test_render_to_rgb888.c \
../vendor/lvgl/tests/src/test_cases/draw/test_render_to_xrgb8888.c 

OBJS += \
./vendor/lvgl/tests/src/test_cases/draw/test_clip_corner.o \
./vendor/lvgl/tests/src/test_cases/draw/test_draw_blend.o \
./vendor/lvgl/tests/src/test_cases/draw/test_draw_label.o \
./vendor/lvgl/tests/src/test_cases/draw/test_draw_layer.o \
./vendor/lvgl/tests/src/test_cases/draw/test_draw_sw_rotate.o \
./vendor/lvgl/tests/src/test_cases/draw/test_draw_vector.o \
./vendor/lvgl/tests/src/test_cases/draw/test_image_formats.o \
./vendor/lvgl/tests/src/test_cases/draw/test_layer_transform.o \
./vendor/lvgl/tests/src/test_cases/draw/test_render_to_al88.o \
./vendor/lvgl/tests/src/test_cases/draw/test_render_to_argb8888.o \
./vendor/lvgl/tests/src/test_cases/draw/test_render_to_l8.o \
./vendor/lvgl/tests/src/test_cases/draw/test_render_to_rgb565.o \
./vendor/lvgl/tests/src/test_cases/draw/test_render_to_rgb888.o \
./vendor/lvgl/tests/src/test_cases/draw/test_render_to_xrgb8888.o 

C_DEPS += \
./vendor/lvgl/tests/src/test_cases/draw/test_clip_corner.d \
./vendor/lvgl/tests/src/test_cases/draw/test_draw_blend.d \
./vendor/lvgl/tests/src/test_cases/draw/test_draw_label.d \
./vendor/lvgl/tests/src/test_cases/draw/test_draw_layer.d \
./vendor/lvgl/tests/src/test_cases/draw/test_draw_sw_rotate.d \
./vendor/lvgl/tests/src/test_cases/draw/test_draw_vector.d \
./vendor/lvgl/tests/src/test_cases/draw/test_image_formats.d \
./vendor/lvgl/tests/src/test_cases/draw/test_layer_transform.d \
./vendor/lvgl/tests/src/test_cases/draw/test_render_to_al88.d \
./vendor/lvgl/tests/src/test_cases/draw/test_render_to_argb8888.d \
./vendor/lvgl/tests/src/test_cases/draw/test_render_to_l8.d \
./vendor/lvgl/tests/src/test_cases/draw/test_render_to_rgb565.d \
./vendor/lvgl/tests/src/test_cases/draw/test_render_to_rgb888.d \
./vendor/lvgl/tests/src/test_cases/draw/test_render_to_xrgb8888.d 


# Each subdirectory must supply rules for building sources it contributes
vendor/lvgl/tests/src/test_cases/draw/%.o: ../vendor/lvgl/tests/src/test_cases/draw/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Andes C Compiler'
	$(CROSS_COMPILE)gcc -D__TLSR_RISCV_EN__=1 -DCHIP_TYPE=CHIP_TYPE_9518 -D__PROJECT_MESH__=1 -I"/cygdrive/C/TelinkV323/B91_GC9A01/GC9A01-master/firmware" -I../drivers/B91 -I../vendor/Common -I../common -I"/cygdrive/C/TelinkV323/B91_GC9A01/GC9A01-master/firmware/vendor/common/mi_api/libs" -I"/cygdrive/C/TelinkV323/B91_GC9A01/GC9A01-master/firmware/vendor/common/mi_api/mijia_ble_api" -O2 -flto -g3 -Wall -mcpu=d25f -ffunction-sections -fdata-sections -c -fmessage-length=0 -fno-builtin -fomit-frame-pointer -fno-strict-aliasing -fshort-wchar -fuse-ld=bfd -fpack-struct -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d) $(@:%.o=%.o)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


