################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../vendor/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d.c \
../vendor/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_arc.c \
../vendor/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_border.c \
../vendor/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_fill.c \
../vendor/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_image.c \
../vendor/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_label.c \
../vendor/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_line.c \
../vendor/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_mask_rectangle.c \
../vendor/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_triangle.c \
../vendor/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_utils.c 

OBJS += \
./vendor/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d.o \
./vendor/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_arc.o \
./vendor/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_border.o \
./vendor/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_fill.o \
./vendor/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_image.o \
./vendor/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_label.o \
./vendor/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_line.o \
./vendor/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_mask_rectangle.o \
./vendor/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_triangle.o \
./vendor/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_utils.o 

C_DEPS += \
./vendor/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d.d \
./vendor/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_arc.d \
./vendor/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_border.d \
./vendor/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_fill.d \
./vendor/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_image.d \
./vendor/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_label.d \
./vendor/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_line.d \
./vendor/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_mask_rectangle.d \
./vendor/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_triangle.d \
./vendor/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_utils.d 


# Each subdirectory must supply rules for building sources it contributes
vendor/lvgl/src/draw/renesas/dave2d/%.o: ../vendor/lvgl/src/draw/renesas/dave2d/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Andes C Compiler'
	$(CROSS_COMPILE)gcc -D__TLSR_RISCV_EN__=1 -DCHIP_TYPE=CHIP_TYPE_9518 -D__PROJECT_MESH__=1 -I"/cygdrive/C/TelinkV323/B91_GC9A01/GC9A01-master/firmware" -I../drivers/B91 -I../vendor/Common -I../common -I"/cygdrive/C/TelinkV323/B91_GC9A01/GC9A01-master/firmware/vendor/common/mi_api/libs" -I"/cygdrive/C/TelinkV323/B91_GC9A01/GC9A01-master/firmware/vendor/common/mi_api/mijia_ble_api" -O2 -flto -g3 -Wall -mcpu=d25f -ffunction-sections -fdata-sections -c -fmessage-length=0 -fno-builtin -fomit-frame-pointer -fno-strict-aliasing -fshort-wchar -fuse-ld=bfd -fpack-struct -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d) $(@:%.o=%.o)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


