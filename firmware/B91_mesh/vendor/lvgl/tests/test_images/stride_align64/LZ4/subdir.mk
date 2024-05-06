################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../vendor/lvgl/tests/test_images/stride_align64/LZ4/test_A1_LZ4_align64.c \
../vendor/lvgl/tests/test_images/stride_align64/LZ4/test_A2_LZ4_align64.c \
../vendor/lvgl/tests/test_images/stride_align64/LZ4/test_A4_LZ4_align64.c \
../vendor/lvgl/tests/test_images/stride_align64/LZ4/test_A8_LZ4_align64.c \
../vendor/lvgl/tests/test_images/stride_align64/LZ4/test_ARGB8888_LZ4_align64.c \
../vendor/lvgl/tests/test_images/stride_align64/LZ4/test_I1_LZ4_align64.c \
../vendor/lvgl/tests/test_images/stride_align64/LZ4/test_I2_LZ4_align64.c \
../vendor/lvgl/tests/test_images/stride_align64/LZ4/test_I4_LZ4_align64.c \
../vendor/lvgl/tests/test_images/stride_align64/LZ4/test_I8_LZ4_align64.c \
../vendor/lvgl/tests/test_images/stride_align64/LZ4/test_L8_LZ4_align64.c \
../vendor/lvgl/tests/test_images/stride_align64/LZ4/test_RGB565A8_LZ4_align64.c \
../vendor/lvgl/tests/test_images/stride_align64/LZ4/test_RGB565_LZ4_align64.c \
../vendor/lvgl/tests/test_images/stride_align64/LZ4/test_RGB888_LZ4_align64.c \
../vendor/lvgl/tests/test_images/stride_align64/LZ4/test_XRGB8888_LZ4_align64.c 

OBJS += \
./vendor/lvgl/tests/test_images/stride_align64/LZ4/test_A1_LZ4_align64.o \
./vendor/lvgl/tests/test_images/stride_align64/LZ4/test_A2_LZ4_align64.o \
./vendor/lvgl/tests/test_images/stride_align64/LZ4/test_A4_LZ4_align64.o \
./vendor/lvgl/tests/test_images/stride_align64/LZ4/test_A8_LZ4_align64.o \
./vendor/lvgl/tests/test_images/stride_align64/LZ4/test_ARGB8888_LZ4_align64.o \
./vendor/lvgl/tests/test_images/stride_align64/LZ4/test_I1_LZ4_align64.o \
./vendor/lvgl/tests/test_images/stride_align64/LZ4/test_I2_LZ4_align64.o \
./vendor/lvgl/tests/test_images/stride_align64/LZ4/test_I4_LZ4_align64.o \
./vendor/lvgl/tests/test_images/stride_align64/LZ4/test_I8_LZ4_align64.o \
./vendor/lvgl/tests/test_images/stride_align64/LZ4/test_L8_LZ4_align64.o \
./vendor/lvgl/tests/test_images/stride_align64/LZ4/test_RGB565A8_LZ4_align64.o \
./vendor/lvgl/tests/test_images/stride_align64/LZ4/test_RGB565_LZ4_align64.o \
./vendor/lvgl/tests/test_images/stride_align64/LZ4/test_RGB888_LZ4_align64.o \
./vendor/lvgl/tests/test_images/stride_align64/LZ4/test_XRGB8888_LZ4_align64.o 

C_DEPS += \
./vendor/lvgl/tests/test_images/stride_align64/LZ4/test_A1_LZ4_align64.d \
./vendor/lvgl/tests/test_images/stride_align64/LZ4/test_A2_LZ4_align64.d \
./vendor/lvgl/tests/test_images/stride_align64/LZ4/test_A4_LZ4_align64.d \
./vendor/lvgl/tests/test_images/stride_align64/LZ4/test_A8_LZ4_align64.d \
./vendor/lvgl/tests/test_images/stride_align64/LZ4/test_ARGB8888_LZ4_align64.d \
./vendor/lvgl/tests/test_images/stride_align64/LZ4/test_I1_LZ4_align64.d \
./vendor/lvgl/tests/test_images/stride_align64/LZ4/test_I2_LZ4_align64.d \
./vendor/lvgl/tests/test_images/stride_align64/LZ4/test_I4_LZ4_align64.d \
./vendor/lvgl/tests/test_images/stride_align64/LZ4/test_I8_LZ4_align64.d \
./vendor/lvgl/tests/test_images/stride_align64/LZ4/test_L8_LZ4_align64.d \
./vendor/lvgl/tests/test_images/stride_align64/LZ4/test_RGB565A8_LZ4_align64.d \
./vendor/lvgl/tests/test_images/stride_align64/LZ4/test_RGB565_LZ4_align64.d \
./vendor/lvgl/tests/test_images/stride_align64/LZ4/test_RGB888_LZ4_align64.d \
./vendor/lvgl/tests/test_images/stride_align64/LZ4/test_XRGB8888_LZ4_align64.d 


# Each subdirectory must supply rules for building sources it contributes
vendor/lvgl/tests/test_images/stride_align64/LZ4/%.o: ../vendor/lvgl/tests/test_images/stride_align64/LZ4/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Andes C Compiler'
	$(CROSS_COMPILE)gcc -D__TLSR_RISCV_EN__=1 -DCHIP_TYPE=CHIP_TYPE_9518 -D__PROJECT_MESH__=1 -I"/cygdrive/C/TelinkV323/B91_SIG_Mesh_SDK/firmware" -I../drivers/B91 -I../vendor/Common -I../common -I"/cygdrive/C/TelinkV323/B91_SIG_Mesh_SDK/firmware/vendor/common/mi_api/libs" -I"/cygdrive/C/TelinkV323/B91_SIG_Mesh_SDK/firmware/vendor/common/mi_api/mijia_ble_api" -O2 -flto -g3 -Wall -mcpu=d25f -ffunction-sections -fdata-sections -c -fmessage-length=0 -fno-builtin -fomit-frame-pointer -fno-strict-aliasing -fshort-wchar -fuse-ld=bfd -fpack-struct -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d) $(@:%.o=%.o)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


