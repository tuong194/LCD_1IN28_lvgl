################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../3rd-party/freertos-V5/croutine.c \
../3rd-party/freertos-V5/event_groups.c \
../3rd-party/freertos-V5/list.c \
../3rd-party/freertos-V5/queue.c \
../3rd-party/freertos-V5/stream_buffer.c \
../3rd-party/freertos-V5/tasks.c \
../3rd-party/freertos-V5/timers.c 

OBJS += \
./3rd-party/freertos-V5/croutine.o \
./3rd-party/freertos-V5/event_groups.o \
./3rd-party/freertos-V5/list.o \
./3rd-party/freertos-V5/queue.o \
./3rd-party/freertos-V5/stream_buffer.o \
./3rd-party/freertos-V5/tasks.o \
./3rd-party/freertos-V5/timers.o 

C_DEPS += \
./3rd-party/freertos-V5/croutine.d \
./3rd-party/freertos-V5/event_groups.d \
./3rd-party/freertos-V5/list.d \
./3rd-party/freertos-V5/queue.d \
./3rd-party/freertos-V5/stream_buffer.d \
./3rd-party/freertos-V5/tasks.d \
./3rd-party/freertos-V5/timers.d 


# Each subdirectory must supply rules for building sources it contributes
3rd-party/freertos-V5/%.o: ../3rd-party/freertos-V5/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Andes C Compiler'
	$(CROSS_COMPILE)gcc -D__TLSR_RISCV_EN__=1 -DCHIP_TYPE=CHIP_TYPE_9518 -D__PROJECT_MESH__=1 -I"/cygdrive/C/TelinkV323/9218/B91_SIG_Mesh_SDK/firmware" -I../drivers/B91 -I../vendor/Common -I../common -I"/cygdrive/C/TelinkV323/9218/B91_SIG_Mesh_SDK/firmware/vendor/common/mi_api/libs" -I"/cygdrive/C/TelinkV323/9218/B91_SIG_Mesh_SDK/firmware/vendor/common/mi_api/mijia_ble_api" -O2 -flto -g3 -Wall -mcpu=d25f -ffunction-sections -fdata-sections -c -fmessage-length=0 -fno-builtin -fomit-frame-pointer -fno-strict-aliasing -fshort-wchar -fuse-ld=bfd -fpack-struct -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d) $(@:%.o=%.o)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


