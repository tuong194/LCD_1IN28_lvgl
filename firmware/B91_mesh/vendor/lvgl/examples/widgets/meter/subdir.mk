################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../vendor/lvgl/examples/widgets/meter/lv_example_meter_1.c \
../vendor/lvgl/examples/widgets/meter/lv_example_meter_2.c \
../vendor/lvgl/examples/widgets/meter/lv_example_meter_3.c \
../vendor/lvgl/examples/widgets/meter/lv_example_meter_4.c 

OBJS += \
./vendor/lvgl/examples/widgets/meter/lv_example_meter_1.o \
./vendor/lvgl/examples/widgets/meter/lv_example_meter_2.o \
./vendor/lvgl/examples/widgets/meter/lv_example_meter_3.o \
./vendor/lvgl/examples/widgets/meter/lv_example_meter_4.o 

C_DEPS += \
./vendor/lvgl/examples/widgets/meter/lv_example_meter_1.d \
./vendor/lvgl/examples/widgets/meter/lv_example_meter_2.d \
./vendor/lvgl/examples/widgets/meter/lv_example_meter_3.d \
./vendor/lvgl/examples/widgets/meter/lv_example_meter_4.d 


# Each subdirectory must supply rules for building sources it contributes
vendor/lvgl/examples/widgets/meter/%.o: ../vendor/lvgl/examples/widgets/meter/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Andes C Compiler'
	$(CROSS_COMPILE)gcc -D__TLSR_RISCV_EN__=1 -DCHIP_TYPE=CHIP_TYPE_9518 -D__PROJECT_MESH__=1 -I"/cygdrive/C/TelinkV323/B91_GC9A01/GC9A01-master/firmware" -I../drivers/B91 -I../vendor/Common -I../common -I"/cygdrive/C/TelinkV323/B91_GC9A01/GC9A01-master/firmware/vendor/common/mi_api/libs" -I"/cygdrive/C/TelinkV323/B91_GC9A01/GC9A01-master/firmware/vendor/common/mi_api/mijia_ble_api" -O2 -flto -g3 -Wall -mcpu=d25f -ffunction-sections -fdata-sections -c -fmessage-length=0 -fno-builtin -fomit-frame-pointer -fno-strict-aliasing -fshort-wchar -fuse-ld=bfd -fpack-struct -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d) $(@:%.o=%.o)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

