################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../vendor/lvgl/examples/libs/rlottie/lv_example_rlottie_1.c \
../vendor/lvgl/examples/libs/rlottie/lv_example_rlottie_2.c \
../vendor/lvgl/examples/libs/rlottie/lv_example_rlottie_approve.c 

OBJS += \
./vendor/lvgl/examples/libs/rlottie/lv_example_rlottie_1.o \
./vendor/lvgl/examples/libs/rlottie/lv_example_rlottie_2.o \
./vendor/lvgl/examples/libs/rlottie/lv_example_rlottie_approve.o 

C_DEPS += \
./vendor/lvgl/examples/libs/rlottie/lv_example_rlottie_1.d \
./vendor/lvgl/examples/libs/rlottie/lv_example_rlottie_2.d \
./vendor/lvgl/examples/libs/rlottie/lv_example_rlottie_approve.d 


# Each subdirectory must supply rules for building sources it contributes
vendor/lvgl/examples/libs/rlottie/%.o: ../vendor/lvgl/examples/libs/rlottie/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Andes C Compiler'
	$(CROSS_COMPILE)gcc -D__TLSR_RISCV_EN__=1 -DCHIP_TYPE=CHIP_TYPE_9518 -D__PROJECT_MESH__=1 -I"/cygdrive/C/TelinkV323/9218/B91_SIG_Mesh_SDK/firmware" -I../drivers/B91 -I../vendor/Common -I../common -I"/cygdrive/C/TelinkV323/9218/B91_SIG_Mesh_SDK/firmware/vendor/common/mi_api/libs" -I"/cygdrive/C/TelinkV323/9218/B91_SIG_Mesh_SDK/firmware/vendor/common/mi_api/mijia_ble_api" -O2 -flto -g3 -Wall -mcpu=d25f -ffunction-sections -fdata-sections -c -fmessage-length=0 -fno-builtin -fomit-frame-pointer -fno-strict-aliasing -fshort-wchar -fuse-ld=bfd -fpack-struct -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d) $(@:%.o=%.o)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


