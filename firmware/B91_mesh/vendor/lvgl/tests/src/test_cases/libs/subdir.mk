################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../vendor/lvgl/tests/src/test_cases/libs/test_barcode.c \
../vendor/lvgl/tests/src/test_cases/libs/test_bin_decoder.c \
../vendor/lvgl/tests/src/test_cases/libs/test_bmp.c \
../vendor/lvgl/tests/src/test_cases/libs/test_font_stress.c \
../vendor/lvgl/tests/src/test_cases/libs/test_freetype.c \
../vendor/lvgl/tests/src/test_cases/libs/test_libjpeg_turbo.c \
../vendor/lvgl/tests/src/test_cases/libs/test_libpng.c \
../vendor/lvgl/tests/src/test_cases/libs/test_lodepng.c \
../vendor/lvgl/tests/src/test_cases/libs/test_memmove.c \
../vendor/lvgl/tests/src/test_cases/libs/test_qrcode.c \
../vendor/lvgl/tests/src/test_cases/libs/test_tiny_ttf.c \
../vendor/lvgl/tests/src/test_cases/libs/test_tjpgd.c 

OBJS += \
./vendor/lvgl/tests/src/test_cases/libs/test_barcode.o \
./vendor/lvgl/tests/src/test_cases/libs/test_bin_decoder.o \
./vendor/lvgl/tests/src/test_cases/libs/test_bmp.o \
./vendor/lvgl/tests/src/test_cases/libs/test_font_stress.o \
./vendor/lvgl/tests/src/test_cases/libs/test_freetype.o \
./vendor/lvgl/tests/src/test_cases/libs/test_libjpeg_turbo.o \
./vendor/lvgl/tests/src/test_cases/libs/test_libpng.o \
./vendor/lvgl/tests/src/test_cases/libs/test_lodepng.o \
./vendor/lvgl/tests/src/test_cases/libs/test_memmove.o \
./vendor/lvgl/tests/src/test_cases/libs/test_qrcode.o \
./vendor/lvgl/tests/src/test_cases/libs/test_tiny_ttf.o \
./vendor/lvgl/tests/src/test_cases/libs/test_tjpgd.o 

C_DEPS += \
./vendor/lvgl/tests/src/test_cases/libs/test_barcode.d \
./vendor/lvgl/tests/src/test_cases/libs/test_bin_decoder.d \
./vendor/lvgl/tests/src/test_cases/libs/test_bmp.d \
./vendor/lvgl/tests/src/test_cases/libs/test_font_stress.d \
./vendor/lvgl/tests/src/test_cases/libs/test_freetype.d \
./vendor/lvgl/tests/src/test_cases/libs/test_libjpeg_turbo.d \
./vendor/lvgl/tests/src/test_cases/libs/test_libpng.d \
./vendor/lvgl/tests/src/test_cases/libs/test_lodepng.d \
./vendor/lvgl/tests/src/test_cases/libs/test_memmove.d \
./vendor/lvgl/tests/src/test_cases/libs/test_qrcode.d \
./vendor/lvgl/tests/src/test_cases/libs/test_tiny_ttf.d \
./vendor/lvgl/tests/src/test_cases/libs/test_tjpgd.d 


# Each subdirectory must supply rules for building sources it contributes
vendor/lvgl/tests/src/test_cases/libs/%.o: ../vendor/lvgl/tests/src/test_cases/libs/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Andes C Compiler'
	$(CROSS_COMPILE)gcc -D__TLSR_RISCV_EN__=1 -DCHIP_TYPE=CHIP_TYPE_9518 -D__PROJECT_MESH__=1 -I"/cygdrive/C/TelinkV323/B91_GC9A01/GC9A01-master/firmware" -I../drivers/B91 -I../vendor/Common -I../common -I"/cygdrive/C/TelinkV323/B91_GC9A01/GC9A01-master/firmware/vendor/common/mi_api/libs" -I"/cygdrive/C/TelinkV323/B91_GC9A01/GC9A01-master/firmware/vendor/common/mi_api/mijia_ble_api" -O2 -flto -g3 -Wall -mcpu=d25f -ffunction-sections -fdata-sections -c -fmessage-length=0 -fno-builtin -fomit-frame-pointer -fno-strict-aliasing -fshort-wchar -fuse-ld=bfd -fpack-struct -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d) $(@:%.o=%.o)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


