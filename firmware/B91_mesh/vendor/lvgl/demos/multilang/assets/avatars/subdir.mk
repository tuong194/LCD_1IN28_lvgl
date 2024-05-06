################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../vendor/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_1.c \
../vendor/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_10.c \
../vendor/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_11.c \
../vendor/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_12.c \
../vendor/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_13.c \
../vendor/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_14.c \
../vendor/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_15.c \
../vendor/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_16.c \
../vendor/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_17.c \
../vendor/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_18.c \
../vendor/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_19.c \
../vendor/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_2.c \
../vendor/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_22.c \
../vendor/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_25.c \
../vendor/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_3.c \
../vendor/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_4.c \
../vendor/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_5.c \
../vendor/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_6.c \
../vendor/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_7.c \
../vendor/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_8.c \
../vendor/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_9.c 

OBJS += \
./vendor/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_1.o \
./vendor/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_10.o \
./vendor/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_11.o \
./vendor/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_12.o \
./vendor/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_13.o \
./vendor/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_14.o \
./vendor/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_15.o \
./vendor/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_16.o \
./vendor/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_17.o \
./vendor/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_18.o \
./vendor/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_19.o \
./vendor/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_2.o \
./vendor/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_22.o \
./vendor/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_25.o \
./vendor/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_3.o \
./vendor/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_4.o \
./vendor/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_5.o \
./vendor/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_6.o \
./vendor/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_7.o \
./vendor/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_8.o \
./vendor/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_9.o 

C_DEPS += \
./vendor/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_1.d \
./vendor/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_10.d \
./vendor/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_11.d \
./vendor/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_12.d \
./vendor/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_13.d \
./vendor/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_14.d \
./vendor/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_15.d \
./vendor/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_16.d \
./vendor/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_17.d \
./vendor/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_18.d \
./vendor/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_19.d \
./vendor/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_2.d \
./vendor/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_22.d \
./vendor/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_25.d \
./vendor/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_3.d \
./vendor/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_4.d \
./vendor/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_5.d \
./vendor/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_6.d \
./vendor/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_7.d \
./vendor/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_8.d \
./vendor/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_9.d 


# Each subdirectory must supply rules for building sources it contributes
vendor/lvgl/demos/multilang/assets/avatars/%.o: ../vendor/lvgl/demos/multilang/assets/avatars/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Andes C Compiler'
	$(CROSS_COMPILE)gcc -D__TLSR_RISCV_EN__=1 -DCHIP_TYPE=CHIP_TYPE_9518 -D__PROJECT_MESH__=1 -I"/cygdrive/C/TelinkV323/B91_GC9A01/GC9A01-master/firmware" -I../drivers/B91 -I../vendor/Common -I../common -I"/cygdrive/C/TelinkV323/B91_GC9A01/GC9A01-master/firmware/vendor/common/mi_api/libs" -I"/cygdrive/C/TelinkV323/B91_GC9A01/GC9A01-master/firmware/vendor/common/mi_api/mijia_ble_api" -O2 -flto -g3 -Wall -mcpu=d25f -ffunction-sections -fdata-sections -c -fmessage-length=0 -fno-builtin -fomit-frame-pointer -fno-strict-aliasing -fshort-wchar -fuse-ld=bfd -fpack-struct -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d) $(@:%.o=%.o)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


