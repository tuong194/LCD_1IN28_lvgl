################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../vendor/lvgl/src/libs/fsdrv/lv_fs_cbfs.c \
../vendor/lvgl/src/libs/fsdrv/lv_fs_fatfs.c \
../vendor/lvgl/src/libs/fsdrv/lv_fs_littlefs.c \
../vendor/lvgl/src/libs/fsdrv/lv_fs_memfs.c \
../vendor/lvgl/src/libs/fsdrv/lv_fs_posix.c \
../vendor/lvgl/src/libs/fsdrv/lv_fs_stdio.c \
../vendor/lvgl/src/libs/fsdrv/lv_fs_win32.c 

OBJS += \
./vendor/lvgl/src/libs/fsdrv/lv_fs_cbfs.o \
./vendor/lvgl/src/libs/fsdrv/lv_fs_fatfs.o \
./vendor/lvgl/src/libs/fsdrv/lv_fs_littlefs.o \
./vendor/lvgl/src/libs/fsdrv/lv_fs_memfs.o \
./vendor/lvgl/src/libs/fsdrv/lv_fs_posix.o \
./vendor/lvgl/src/libs/fsdrv/lv_fs_stdio.o \
./vendor/lvgl/src/libs/fsdrv/lv_fs_win32.o 

C_DEPS += \
./vendor/lvgl/src/libs/fsdrv/lv_fs_cbfs.d \
./vendor/lvgl/src/libs/fsdrv/lv_fs_fatfs.d \
./vendor/lvgl/src/libs/fsdrv/lv_fs_littlefs.d \
./vendor/lvgl/src/libs/fsdrv/lv_fs_memfs.d \
./vendor/lvgl/src/libs/fsdrv/lv_fs_posix.d \
./vendor/lvgl/src/libs/fsdrv/lv_fs_stdio.d \
./vendor/lvgl/src/libs/fsdrv/lv_fs_win32.d 


# Each subdirectory must supply rules for building sources it contributes
vendor/lvgl/src/libs/fsdrv/%.o: ../vendor/lvgl/src/libs/fsdrv/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Andes C Compiler'
	$(CROSS_COMPILE)gcc -D__TLSR_RISCV_EN__=1 -DCHIP_TYPE=CHIP_TYPE_9518 -D__PROJECT_MESH__=1 -I"/cygdrive/C/TelinkV323/B91_GC9A01/GC9A01-master/firmware" -I../drivers/B91 -I../vendor/Common -I../common -I"/cygdrive/C/TelinkV323/B91_GC9A01/GC9A01-master/firmware/vendor/common/mi_api/libs" -I"/cygdrive/C/TelinkV323/B91_GC9A01/GC9A01-master/firmware/vendor/common/mi_api/mijia_ble_api" -O2 -flto -g3 -Wall -mcpu=d25f -ffunction-sections -fdata-sections -c -fmessage-length=0 -fno-builtin -fomit-frame-pointer -fno-strict-aliasing -fshort-wchar -fuse-ld=bfd -fpack-struct -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d) $(@:%.o=%.o)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


