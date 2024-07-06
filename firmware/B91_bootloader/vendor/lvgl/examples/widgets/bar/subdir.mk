################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../vendor/lvgl/examples/widgets/bar/lv_example_bar_1.c \
../vendor/lvgl/examples/widgets/bar/lv_example_bar_2.c \
../vendor/lvgl/examples/widgets/bar/lv_example_bar_3.c \
../vendor/lvgl/examples/widgets/bar/lv_example_bar_4.c \
../vendor/lvgl/examples/widgets/bar/lv_example_bar_5.c \
../vendor/lvgl/examples/widgets/bar/lv_example_bar_6.c 

OBJS += \
./vendor/lvgl/examples/widgets/bar/lv_example_bar_1.o \
./vendor/lvgl/examples/widgets/bar/lv_example_bar_2.o \
./vendor/lvgl/examples/widgets/bar/lv_example_bar_3.o \
./vendor/lvgl/examples/widgets/bar/lv_example_bar_4.o \
./vendor/lvgl/examples/widgets/bar/lv_example_bar_5.o \
./vendor/lvgl/examples/widgets/bar/lv_example_bar_6.o 

C_DEPS += \
./vendor/lvgl/examples/widgets/bar/lv_example_bar_1.d \
./vendor/lvgl/examples/widgets/bar/lv_example_bar_2.d \
./vendor/lvgl/examples/widgets/bar/lv_example_bar_3.d \
./vendor/lvgl/examples/widgets/bar/lv_example_bar_4.d \
./vendor/lvgl/examples/widgets/bar/lv_example_bar_5.d \
./vendor/lvgl/examples/widgets/bar/lv_example_bar_6.d 


# Each subdirectory must supply rules for building sources it contributes
vendor/lvgl/examples/widgets/bar/%.o: ../vendor/lvgl/examples/widgets/bar/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Andes C Compiler'
	$(CROSS_COMPILE)gcc -D__TLSR_RISCV_EN__=1 -DCHIP_TYPE=CHIP_TYPE_9518 -D__PROJECT_BOOTLOADER__=1 -I../ -I../drivers/B91 -I../vendor/common -I../common -I../vendor/common/mi_api/libs -I../vendor/common/mi_api/mijia_ble_api -I../vendor/common/llsync/sdk_src/include -I../vendor/common/llsync/include -I../vendor/common/llsync/cfg -I../vendor/common/llsync/data_template -O2 -mcmodel=medium -flto -g3 -Wall -mcpu=d25f -ffunction-sections -fdata-sections -mext-dsp -c -fmessage-length=0 -fno-builtin -fomit-frame-pointer -fno-strict-aliasing -fshort-wchar -fuse-ld=bfd -fpack-struct -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d) $(@:%.o=%.o)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


