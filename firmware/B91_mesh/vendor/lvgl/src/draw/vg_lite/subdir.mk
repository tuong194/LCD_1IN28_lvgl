################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../vendor/lvgl/src/draw/vg_lite/lv_draw_buf_vg_lite.c \
../vendor/lvgl/src/draw/vg_lite/lv_draw_vg_lite.c \
../vendor/lvgl/src/draw/vg_lite/lv_draw_vg_lite_arc.c \
../vendor/lvgl/src/draw/vg_lite/lv_draw_vg_lite_border.c \
../vendor/lvgl/src/draw/vg_lite/lv_draw_vg_lite_box_shadow.c \
../vendor/lvgl/src/draw/vg_lite/lv_draw_vg_lite_fill.c \
../vendor/lvgl/src/draw/vg_lite/lv_draw_vg_lite_img.c \
../vendor/lvgl/src/draw/vg_lite/lv_draw_vg_lite_label.c \
../vendor/lvgl/src/draw/vg_lite/lv_draw_vg_lite_layer.c \
../vendor/lvgl/src/draw/vg_lite/lv_draw_vg_lite_line.c \
../vendor/lvgl/src/draw/vg_lite/lv_draw_vg_lite_mask_rect.c \
../vendor/lvgl/src/draw/vg_lite/lv_draw_vg_lite_triangle.c \
../vendor/lvgl/src/draw/vg_lite/lv_draw_vg_lite_vector.c \
../vendor/lvgl/src/draw/vg_lite/lv_vg_lite_decoder.c \
../vendor/lvgl/src/draw/vg_lite/lv_vg_lite_grad.c \
../vendor/lvgl/src/draw/vg_lite/lv_vg_lite_math.c \
../vendor/lvgl/src/draw/vg_lite/lv_vg_lite_path.c \
../vendor/lvgl/src/draw/vg_lite/lv_vg_lite_pending.c \
../vendor/lvgl/src/draw/vg_lite/lv_vg_lite_utils.c 

OBJS += \
./vendor/lvgl/src/draw/vg_lite/lv_draw_buf_vg_lite.o \
./vendor/lvgl/src/draw/vg_lite/lv_draw_vg_lite.o \
./vendor/lvgl/src/draw/vg_lite/lv_draw_vg_lite_arc.o \
./vendor/lvgl/src/draw/vg_lite/lv_draw_vg_lite_border.o \
./vendor/lvgl/src/draw/vg_lite/lv_draw_vg_lite_box_shadow.o \
./vendor/lvgl/src/draw/vg_lite/lv_draw_vg_lite_fill.o \
./vendor/lvgl/src/draw/vg_lite/lv_draw_vg_lite_img.o \
./vendor/lvgl/src/draw/vg_lite/lv_draw_vg_lite_label.o \
./vendor/lvgl/src/draw/vg_lite/lv_draw_vg_lite_layer.o \
./vendor/lvgl/src/draw/vg_lite/lv_draw_vg_lite_line.o \
./vendor/lvgl/src/draw/vg_lite/lv_draw_vg_lite_mask_rect.o \
./vendor/lvgl/src/draw/vg_lite/lv_draw_vg_lite_triangle.o \
./vendor/lvgl/src/draw/vg_lite/lv_draw_vg_lite_vector.o \
./vendor/lvgl/src/draw/vg_lite/lv_vg_lite_decoder.o \
./vendor/lvgl/src/draw/vg_lite/lv_vg_lite_grad.o \
./vendor/lvgl/src/draw/vg_lite/lv_vg_lite_math.o \
./vendor/lvgl/src/draw/vg_lite/lv_vg_lite_path.o \
./vendor/lvgl/src/draw/vg_lite/lv_vg_lite_pending.o \
./vendor/lvgl/src/draw/vg_lite/lv_vg_lite_utils.o 

C_DEPS += \
./vendor/lvgl/src/draw/vg_lite/lv_draw_buf_vg_lite.d \
./vendor/lvgl/src/draw/vg_lite/lv_draw_vg_lite.d \
./vendor/lvgl/src/draw/vg_lite/lv_draw_vg_lite_arc.d \
./vendor/lvgl/src/draw/vg_lite/lv_draw_vg_lite_border.d \
./vendor/lvgl/src/draw/vg_lite/lv_draw_vg_lite_box_shadow.d \
./vendor/lvgl/src/draw/vg_lite/lv_draw_vg_lite_fill.d \
./vendor/lvgl/src/draw/vg_lite/lv_draw_vg_lite_img.d \
./vendor/lvgl/src/draw/vg_lite/lv_draw_vg_lite_label.d \
./vendor/lvgl/src/draw/vg_lite/lv_draw_vg_lite_layer.d \
./vendor/lvgl/src/draw/vg_lite/lv_draw_vg_lite_line.d \
./vendor/lvgl/src/draw/vg_lite/lv_draw_vg_lite_mask_rect.d \
./vendor/lvgl/src/draw/vg_lite/lv_draw_vg_lite_triangle.d \
./vendor/lvgl/src/draw/vg_lite/lv_draw_vg_lite_vector.d \
./vendor/lvgl/src/draw/vg_lite/lv_vg_lite_decoder.d \
./vendor/lvgl/src/draw/vg_lite/lv_vg_lite_grad.d \
./vendor/lvgl/src/draw/vg_lite/lv_vg_lite_math.d \
./vendor/lvgl/src/draw/vg_lite/lv_vg_lite_path.d \
./vendor/lvgl/src/draw/vg_lite/lv_vg_lite_pending.d \
./vendor/lvgl/src/draw/vg_lite/lv_vg_lite_utils.d 


# Each subdirectory must supply rules for building sources it contributes
vendor/lvgl/src/draw/vg_lite/%.o: ../vendor/lvgl/src/draw/vg_lite/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Andes C Compiler'
	$(CROSS_COMPILE)gcc -D__TLSR_RISCV_EN__=1 -DCHIP_TYPE=CHIP_TYPE_9518 -D__PROJECT_MESH__=1 -I"/cygdrive/C/TelinkV323/B91_GC9A01/GC9A01-master/firmware" -I../drivers/B91 -I../vendor/Common -I../common -I"/cygdrive/C/TelinkV323/B91_GC9A01/GC9A01-master/firmware/vendor/common/mi_api/libs" -I"/cygdrive/C/TelinkV323/B91_GC9A01/GC9A01-master/firmware/vendor/common/mi_api/mijia_ble_api" -O2 -flto -g3 -Wall -mcpu=d25f -ffunction-sections -fdata-sections -c -fmessage-length=0 -fno-builtin -fomit-frame-pointer -fno-strict-aliasing -fshort-wchar -fuse-ld=bfd -fpack-struct -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d) $(@:%.o=%.o)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


