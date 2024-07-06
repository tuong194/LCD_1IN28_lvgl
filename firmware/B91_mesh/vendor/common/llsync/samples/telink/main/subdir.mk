################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../vendor/common/llsync/samples/telink/main/ble_qiot_template_vendor.c \
../vendor/common/llsync/samples/telink/main/ll_app_mesh.c 

OBJS += \
./vendor/common/llsync/samples/telink/main/ble_qiot_template_vendor.o \
./vendor/common/llsync/samples/telink/main/ll_app_mesh.o 

C_DEPS += \
./vendor/common/llsync/samples/telink/main/ble_qiot_template_vendor.d \
./vendor/common/llsync/samples/telink/main/ll_app_mesh.d 


# Each subdirectory must supply rules for building sources it contributes
vendor/common/llsync/samples/telink/main/%.o: ../vendor/common/llsync/samples/telink/main/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Andes C Compiler'
	$(CROSS_COMPILE)gcc -D__TLSR_RISCV_EN__=1 -DCHIP_TYPE=CHIP_TYPE_9518 -D__PROJECT_MESH__=1 -I../ -I../drivers/B91 -I../vendor/common -I../common -I../vendor/common/mi_api/libs -I../vendor/common/mi_api/mijia_ble_api -I../vendor/common/llsync/sdk_src/include -I../vendor/common/llsync/include -I../vendor/common/llsync/cfg -I../vendor/common/llsync/data_template -O2 -flto -g3 -Wall -mcpu=d25f -ffunction-sections -fdata-sections -mext-dsp -c -fmessage-length=0 -fno-builtin -fomit-frame-pointer -fno-strict-aliasing -fshort-wchar -fuse-ld=bfd -fpack-struct -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d) $(@:%.o=%.o)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


