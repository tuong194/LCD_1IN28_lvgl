################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../vendor/lvgl/src/draw/nxp/vglite/lv_draw_vglite.c \
../vendor/lvgl/src/draw/nxp/vglite/lv_draw_vglite_arc.c \
../vendor/lvgl/src/draw/nxp/vglite/lv_draw_vglite_blend.c \
../vendor/lvgl/src/draw/nxp/vglite/lv_draw_vglite_line.c \
../vendor/lvgl/src/draw/nxp/vglite/lv_draw_vglite_rect.c \
../vendor/lvgl/src/draw/nxp/vglite/lv_vglite_buf.c \
../vendor/lvgl/src/draw/nxp/vglite/lv_vglite_utils.c 

OBJS += \
./vendor/lvgl/src/draw/nxp/vglite/lv_draw_vglite.o \
./vendor/lvgl/src/draw/nxp/vglite/lv_draw_vglite_arc.o \
./vendor/lvgl/src/draw/nxp/vglite/lv_draw_vglite_blend.o \
./vendor/lvgl/src/draw/nxp/vglite/lv_draw_vglite_line.o \
./vendor/lvgl/src/draw/nxp/vglite/lv_draw_vglite_rect.o \
./vendor/lvgl/src/draw/nxp/vglite/lv_vglite_buf.o \
./vendor/lvgl/src/draw/nxp/vglite/lv_vglite_utils.o 

C_DEPS += \
./vendor/lvgl/src/draw/nxp/vglite/lv_draw_vglite.d \
./vendor/lvgl/src/draw/nxp/vglite/lv_draw_vglite_arc.d \
./vendor/lvgl/src/draw/nxp/vglite/lv_draw_vglite_blend.d \
./vendor/lvgl/src/draw/nxp/vglite/lv_draw_vglite_line.d \
./vendor/lvgl/src/draw/nxp/vglite/lv_draw_vglite_rect.d \
./vendor/lvgl/src/draw/nxp/vglite/lv_vglite_buf.d \
./vendor/lvgl/src/draw/nxp/vglite/lv_vglite_utils.d 


# Each subdirectory must supply rules for building sources it contributes
vendor/lvgl/src/draw/nxp/vglite/%.o: ../vendor/lvgl/src/draw/nxp/vglite/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Andes C Compiler'
	$(CROSS_COMPILE)gcc -D__TLSR_RISCV_EN__=1 -DCHIP_TYPE=CHIP_TYPE_9518 -D__PROJECT_MESH__=1 -I"/cygdrive/C/TelinkV323/9518/LCD_1IN28/LCD_1IN28_lvgl-tuong194/firmware" -I../drivers/B91 -I../vendor/Common -I../common -I"/cygdrive/C/TelinkV323/9518/LCD_1IN28/LCD_1IN28_lvgl-tuong194/firmware/vendor/common/mi_api/libs" -I"/cygdrive/C/TelinkV323/9518/LCD_1IN28/LCD_1IN28_lvgl-tuong194/firmware/vendor/common/mi_api/mijia_ble_api" -O2 -flto -g3 -Wall -mcpu=d25f -ffunction-sections -fdata-sections -c -fmessage-length=0 -fno-builtin -fomit-frame-pointer -fno-strict-aliasing -fshort-wchar -fuse-ld=bfd -fpack-struct -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d) $(@:%.o=%.o)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


