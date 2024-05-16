################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../vendor/lvgl/src/misc/cache/_lv_cache_lru_rb.c \
../vendor/lvgl/src/misc/cache/lv_cache.c \
../vendor/lvgl/src/misc/cache/lv_cache_entry.c \
../vendor/lvgl/src/misc/cache/lv_image_cache.c \
../vendor/lvgl/src/misc/cache/lv_image_header_cache.c 

OBJS += \
./vendor/lvgl/src/misc/cache/_lv_cache_lru_rb.o \
./vendor/lvgl/src/misc/cache/lv_cache.o \
./vendor/lvgl/src/misc/cache/lv_cache_entry.o \
./vendor/lvgl/src/misc/cache/lv_image_cache.o \
./vendor/lvgl/src/misc/cache/lv_image_header_cache.o 

C_DEPS += \
./vendor/lvgl/src/misc/cache/_lv_cache_lru_rb.d \
./vendor/lvgl/src/misc/cache/lv_cache.d \
./vendor/lvgl/src/misc/cache/lv_cache_entry.d \
./vendor/lvgl/src/misc/cache/lv_image_cache.d \
./vendor/lvgl/src/misc/cache/lv_image_header_cache.d 


# Each subdirectory must supply rules for building sources it contributes
vendor/lvgl/src/misc/cache/%.o: ../vendor/lvgl/src/misc/cache/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Andes C Compiler'
	$(CROSS_COMPILE)gcc -D__TLSR_RISCV_EN__=1 -DCHIP_TYPE=CHIP_TYPE_9518 -D__PROJECT_MESH__=1 -I"/cygdrive/C/TelinkV323/B91_GC9A01/GC9A01-master/firmware" -I../drivers/B91 -I../vendor/Common -I../common -I"/cygdrive/C/TelinkV323/B91_GC9A01/GC9A01-master/firmware/vendor/common/mi_api/libs" -I"/cygdrive/C/TelinkV323/B91_GC9A01/GC9A01-master/firmware/vendor/common/mi_api/mijia_ble_api" -O2 -flto -g3 -Wall -mcpu=d25f -ffunction-sections -fdata-sections -c -fmessage-length=0 -fno-builtin -fomit-frame-pointer -fno-strict-aliasing -fshort-wchar -fuse-ld=bfd -fpack-struct -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d) $(@:%.o=%.o)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


