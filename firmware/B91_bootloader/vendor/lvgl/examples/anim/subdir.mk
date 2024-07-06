################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../vendor/lvgl/examples/anim/lv_example_anim_1.c \
../vendor/lvgl/examples/anim/lv_example_anim_2.c \
../vendor/lvgl/examples/anim/lv_example_anim_3.c \
../vendor/lvgl/examples/anim/lv_example_anim_timeline_1.c 

OBJS += \
./vendor/lvgl/examples/anim/lv_example_anim_1.o \
./vendor/lvgl/examples/anim/lv_example_anim_2.o \
./vendor/lvgl/examples/anim/lv_example_anim_3.o \
./vendor/lvgl/examples/anim/lv_example_anim_timeline_1.o 

C_DEPS += \
./vendor/lvgl/examples/anim/lv_example_anim_1.d \
./vendor/lvgl/examples/anim/lv_example_anim_2.d \
./vendor/lvgl/examples/anim/lv_example_anim_3.d \
./vendor/lvgl/examples/anim/lv_example_anim_timeline_1.d 


# Each subdirectory must supply rules for building sources it contributes
vendor/lvgl/examples/anim/%.o: ../vendor/lvgl/examples/anim/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Andes C Compiler'
	$(CROSS_COMPILE)gcc -D__TLSR_RISCV_EN__=1 -DCHIP_TYPE=CHIP_TYPE_9518 -D__PROJECT_BOOTLOADER__=1 -I../ -I../drivers/B91 -I../vendor/common -I../common -I../vendor/common/mi_api/libs -I../vendor/common/mi_api/mijia_ble_api -I../vendor/common/llsync/sdk_src/include -I../vendor/common/llsync/include -I../vendor/common/llsync/cfg -I../vendor/common/llsync/data_template -O2 -mcmodel=medium -flto -g3 -Wall -mcpu=d25f -ffunction-sections -fdata-sections -mext-dsp -c -fmessage-length=0 -fno-builtin -fomit-frame-pointer -fno-strict-aliasing -fshort-wchar -fuse-ld=bfd -fpack-struct -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d) $(@:%.o=%.o)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


