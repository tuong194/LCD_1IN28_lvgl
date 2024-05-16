################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../vendor/lvgl/demos/multilang/assets/emojis/img_emoji_artist_palette.c \
../vendor/lvgl/demos/multilang/assets/emojis/img_emoji_books.c \
../vendor/lvgl/demos/multilang/assets/emojis/img_emoji_camera_with_flash.c \
../vendor/lvgl/demos/multilang/assets/emojis/img_emoji_cat_face.c \
../vendor/lvgl/demos/multilang/assets/emojis/img_emoji_deciduous_tree.c \
../vendor/lvgl/demos/multilang/assets/emojis/img_emoji_dog_face.c \
../vendor/lvgl/demos/multilang/assets/emojis/img_emoji_earth_globe_europe_africa.c \
../vendor/lvgl/demos/multilang/assets/emojis/img_emoji_flexed_biceps.c \
../vendor/lvgl/demos/multilang/assets/emojis/img_emoji_movie_camera.c \
../vendor/lvgl/demos/multilang/assets/emojis/img_emoji_red_heart.c \
../vendor/lvgl/demos/multilang/assets/emojis/img_emoji_rocket.c \
../vendor/lvgl/demos/multilang/assets/emojis/img_emoji_soccer_ball.c 

OBJS += \
./vendor/lvgl/demos/multilang/assets/emojis/img_emoji_artist_palette.o \
./vendor/lvgl/demos/multilang/assets/emojis/img_emoji_books.o \
./vendor/lvgl/demos/multilang/assets/emojis/img_emoji_camera_with_flash.o \
./vendor/lvgl/demos/multilang/assets/emojis/img_emoji_cat_face.o \
./vendor/lvgl/demos/multilang/assets/emojis/img_emoji_deciduous_tree.o \
./vendor/lvgl/demos/multilang/assets/emojis/img_emoji_dog_face.o \
./vendor/lvgl/demos/multilang/assets/emojis/img_emoji_earth_globe_europe_africa.o \
./vendor/lvgl/demos/multilang/assets/emojis/img_emoji_flexed_biceps.o \
./vendor/lvgl/demos/multilang/assets/emojis/img_emoji_movie_camera.o \
./vendor/lvgl/demos/multilang/assets/emojis/img_emoji_red_heart.o \
./vendor/lvgl/demos/multilang/assets/emojis/img_emoji_rocket.o \
./vendor/lvgl/demos/multilang/assets/emojis/img_emoji_soccer_ball.o 

C_DEPS += \
./vendor/lvgl/demos/multilang/assets/emojis/img_emoji_artist_palette.d \
./vendor/lvgl/demos/multilang/assets/emojis/img_emoji_books.d \
./vendor/lvgl/demos/multilang/assets/emojis/img_emoji_camera_with_flash.d \
./vendor/lvgl/demos/multilang/assets/emojis/img_emoji_cat_face.d \
./vendor/lvgl/demos/multilang/assets/emojis/img_emoji_deciduous_tree.d \
./vendor/lvgl/demos/multilang/assets/emojis/img_emoji_dog_face.d \
./vendor/lvgl/demos/multilang/assets/emojis/img_emoji_earth_globe_europe_africa.d \
./vendor/lvgl/demos/multilang/assets/emojis/img_emoji_flexed_biceps.d \
./vendor/lvgl/demos/multilang/assets/emojis/img_emoji_movie_camera.d \
./vendor/lvgl/demos/multilang/assets/emojis/img_emoji_red_heart.d \
./vendor/lvgl/demos/multilang/assets/emojis/img_emoji_rocket.d \
./vendor/lvgl/demos/multilang/assets/emojis/img_emoji_soccer_ball.d 


# Each subdirectory must supply rules for building sources it contributes
vendor/lvgl/demos/multilang/assets/emojis/%.o: ../vendor/lvgl/demos/multilang/assets/emojis/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Andes C Compiler'
	$(CROSS_COMPILE)gcc -D__TLSR_RISCV_EN__=1 -DCHIP_TYPE=CHIP_TYPE_9518 -D__PROJECT_MESH__=1 -I"/cygdrive/C/TelinkV323/B91_GC9A01/GC9A01-master/firmware" -I../drivers/B91 -I../vendor/Common -I../common -I"/cygdrive/C/TelinkV323/B91_GC9A01/GC9A01-master/firmware/vendor/common/mi_api/libs" -I"/cygdrive/C/TelinkV323/B91_GC9A01/GC9A01-master/firmware/vendor/common/mi_api/mijia_ble_api" -O2 -flto -g3 -Wall -mcpu=d25f -ffunction-sections -fdata-sections -c -fmessage-length=0 -fno-builtin -fomit-frame-pointer -fno-strict-aliasing -fshort-wchar -fuse-ld=bfd -fpack-struct -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d) $(@:%.o=%.o)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


