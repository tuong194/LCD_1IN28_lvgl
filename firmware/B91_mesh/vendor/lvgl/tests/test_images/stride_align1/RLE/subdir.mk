################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../vendor/lvgl/tests/test_images/stride_align1/RLE/test_A1_RLE_align1.c \
../vendor/lvgl/tests/test_images/stride_align1/RLE/test_A2_RLE_align1.c \
../vendor/lvgl/tests/test_images/stride_align1/RLE/test_A4_RLE_align1.c \
../vendor/lvgl/tests/test_images/stride_align1/RLE/test_A8_RLE_align1.c \
../vendor/lvgl/tests/test_images/stride_align1/RLE/test_ARGB8888_RLE_align1.c \
../vendor/lvgl/tests/test_images/stride_align1/RLE/test_I1_RLE_align1.c \
../vendor/lvgl/tests/test_images/stride_align1/RLE/test_I2_RLE_align1.c \
../vendor/lvgl/tests/test_images/stride_align1/RLE/test_I4_RLE_align1.c \
../vendor/lvgl/tests/test_images/stride_align1/RLE/test_I8_RLE_align1.c \
../vendor/lvgl/tests/test_images/stride_align1/RLE/test_L8_RLE_align1.c \
../vendor/lvgl/tests/test_images/stride_align1/RLE/test_RGB565A8_RLE_align1.c \
../vendor/lvgl/tests/test_images/stride_align1/RLE/test_RGB565_RLE_align1.c \
../vendor/lvgl/tests/test_images/stride_align1/RLE/test_RGB888_RLE_align1.c \
../vendor/lvgl/tests/test_images/stride_align1/RLE/test_XRGB8888_RLE_align1.c 

OBJS += \
./vendor/lvgl/tests/test_images/stride_align1/RLE/test_A1_RLE_align1.o \
./vendor/lvgl/tests/test_images/stride_align1/RLE/test_A2_RLE_align1.o \
./vendor/lvgl/tests/test_images/stride_align1/RLE/test_A4_RLE_align1.o \
./vendor/lvgl/tests/test_images/stride_align1/RLE/test_A8_RLE_align1.o \
./vendor/lvgl/tests/test_images/stride_align1/RLE/test_ARGB8888_RLE_align1.o \
./vendor/lvgl/tests/test_images/stride_align1/RLE/test_I1_RLE_align1.o \
./vendor/lvgl/tests/test_images/stride_align1/RLE/test_I2_RLE_align1.o \
./vendor/lvgl/tests/test_images/stride_align1/RLE/test_I4_RLE_align1.o \
./vendor/lvgl/tests/test_images/stride_align1/RLE/test_I8_RLE_align1.o \
./vendor/lvgl/tests/test_images/stride_align1/RLE/test_L8_RLE_align1.o \
./vendor/lvgl/tests/test_images/stride_align1/RLE/test_RGB565A8_RLE_align1.o \
./vendor/lvgl/tests/test_images/stride_align1/RLE/test_RGB565_RLE_align1.o \
./vendor/lvgl/tests/test_images/stride_align1/RLE/test_RGB888_RLE_align1.o \
./vendor/lvgl/tests/test_images/stride_align1/RLE/test_XRGB8888_RLE_align1.o 

C_DEPS += \
./vendor/lvgl/tests/test_images/stride_align1/RLE/test_A1_RLE_align1.d \
./vendor/lvgl/tests/test_images/stride_align1/RLE/test_A2_RLE_align1.d \
./vendor/lvgl/tests/test_images/stride_align1/RLE/test_A4_RLE_align1.d \
./vendor/lvgl/tests/test_images/stride_align1/RLE/test_A8_RLE_align1.d \
./vendor/lvgl/tests/test_images/stride_align1/RLE/test_ARGB8888_RLE_align1.d \
./vendor/lvgl/tests/test_images/stride_align1/RLE/test_I1_RLE_align1.d \
./vendor/lvgl/tests/test_images/stride_align1/RLE/test_I2_RLE_align1.d \
./vendor/lvgl/tests/test_images/stride_align1/RLE/test_I4_RLE_align1.d \
./vendor/lvgl/tests/test_images/stride_align1/RLE/test_I8_RLE_align1.d \
./vendor/lvgl/tests/test_images/stride_align1/RLE/test_L8_RLE_align1.d \
./vendor/lvgl/tests/test_images/stride_align1/RLE/test_RGB565A8_RLE_align1.d \
./vendor/lvgl/tests/test_images/stride_align1/RLE/test_RGB565_RLE_align1.d \
./vendor/lvgl/tests/test_images/stride_align1/RLE/test_RGB888_RLE_align1.d \
./vendor/lvgl/tests/test_images/stride_align1/RLE/test_XRGB8888_RLE_align1.d 


# Each subdirectory must supply rules for building sources it contributes
vendor/lvgl/tests/test_images/stride_align1/RLE/%.o: ../vendor/lvgl/tests/test_images/stride_align1/RLE/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Andes C Compiler'
	$(CROSS_COMPILE)gcc -D__TLSR_RISCV_EN__=1 -DCHIP_TYPE=CHIP_TYPE_9518 -D__PROJECT_MESH__=1 -I"/cygdrive/C/TelinkV323/B91_SIG_Mesh_SDK/firmware" -I../drivers/B91 -I../vendor/Common -I../common -I"/cygdrive/C/TelinkV323/B91_SIG_Mesh_SDK/firmware/vendor/common/mi_api/libs" -I"/cygdrive/C/TelinkV323/B91_SIG_Mesh_SDK/firmware/vendor/common/mi_api/mijia_ble_api" -O2 -flto -g3 -Wall -mcpu=d25f -ffunction-sections -fdata-sections -c -fmessage-length=0 -fno-builtin -fomit-frame-pointer -fno-strict-aliasing -fshort-wchar -fuse-ld=bfd -fpack-struct -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d) $(@:%.o=%.o)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

