################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Generated_Code/Cpu.c \
../Generated_Code/MainTask.c \
../Generated_Code/TX.c \
../Generated_Code/clockMan1.c \
../Generated_Code/dd_monitor.c \
../Generated_Code/dd_scheduler.c \
../Generated_Code/dd_user_task.c \
../Generated_Code/fsl_hwtimer1.c \
../Generated_Code/fsl_mpu1.c \
../Generated_Code/hardware_init.c \
../Generated_Code/mqx_ksdk.c \
../Generated_Code/myUART.c \
../Generated_Code/osa1.c \
../Generated_Code/pin_init.c \
../Generated_Code/uart1.c 

OBJS += \
./Generated_Code/Cpu.o \
./Generated_Code/MainTask.o \
./Generated_Code/TX.o \
./Generated_Code/clockMan1.o \
./Generated_Code/dd_monitor.o \
./Generated_Code/dd_scheduler.o \
./Generated_Code/dd_user_task.o \
./Generated_Code/fsl_hwtimer1.o \
./Generated_Code/fsl_mpu1.o \
./Generated_Code/hardware_init.o \
./Generated_Code/mqx_ksdk.o \
./Generated_Code/myUART.o \
./Generated_Code/osa1.o \
./Generated_Code/pin_init.o \
./Generated_Code/uart1.o 

C_DEPS += \
./Generated_Code/Cpu.d \
./Generated_Code/MainTask.d \
./Generated_Code/TX.d \
./Generated_Code/clockMan1.d \
./Generated_Code/dd_monitor.d \
./Generated_Code/dd_scheduler.d \
./Generated_Code/dd_user_task.d \
./Generated_Code/fsl_hwtimer1.d \
./Generated_Code/fsl_mpu1.d \
./Generated_Code/hardware_init.d \
./Generated_Code/mqx_ksdk.d \
./Generated_Code/myUART.d \
./Generated_Code/osa1.d \
./Generated_Code/pin_init.d \
./Generated_Code/uart1.d 


# Each subdirectory must supply rules for building sources it contributes
Generated_Code/%.o: ../Generated_Code/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -D"CPU_MK64FN1M0VLL12" -D"FSL_RTOS_MQX" -D"PEX_MQX_KSDK" -I"C:/Users/afbcom/workspace.kds/project3/SDK/platform/hal/inc" -I"C:/Users/afbcom/workspace.kds/project3/SDK/platform/hal/src/sim/MK64F12" -I"C:/Users/afbcom/workspace.kds/project3/SDK/platform/system/src/clock/MK64F12" -I"C:/Users/afbcom/workspace.kds/project3/SDK/platform/system/inc" -I"C:/Users/afbcom/workspace.kds/project3/SDK/platform/osa/inc" -I"C:/Users/afbcom/workspace.kds/project3/SDK/platform/CMSIS/Include" -I"C:/Users/afbcom/workspace.kds/project3/SDK/platform/devices" -I"C:/Users/afbcom/workspace.kds/project3/SDK/platform/devices/MK64F12/include" -I"C:/Users/afbcom/workspace.kds/project3/SDK/platform/utilities/src" -I"C:/Users/afbcom/workspace.kds/project3/SDK/platform/utilities/inc" -I"C:/Users/afbcom/workspace.kds/project3/SDK/platform/devices/MK64F12/startup" -I"C:/Users/afbcom/workspace.kds/project3/Generated_Code/SDK/platform/devices/MK64F12/startup" -I"C:/Users/afbcom/workspace.kds/project3/Sources" -I"C:/Users/afbcom/workspace.kds/project3/Generated_Code" -I"C:/Users/afbcom/workspace.kds/project3/SDK/platform/drivers/inc" -I"C:/Users/afbcom/workspace.kds/project3/SDK/rtos/mqx/mqx/source/psp/cortex_m" -I"C:/Users/afbcom/workspace.kds/project3/SDK/rtos/mqx/mqx/source/psp/cortex_m/cpu" -I"C:/Users/afbcom/workspace.kds/project3/SDK/rtos/mqx/config/common" -I"C:/Users/afbcom/workspace.kds/project3/SDK/rtos/mqx/mqx/source/include" -I"C:/Users/afbcom/workspace.kds/project3/SDK/rtos/mqx/mqx/source/bsp" -I"C:/Users/afbcom/workspace.kds/project3/SDK/rtos/mqx/mqx/source/psp/cortex_m/compiler/gcc_arm" -I"C:/Users/afbcom/workspace.kds/project3/SDK/rtos/mqx/mqx/source/nio" -I"C:/Users/afbcom/workspace.kds/project3/SDK/rtos/mqx/mqx/source/nio/src" -I"C:/Users/afbcom/workspace.kds/project3/SDK/rtos/mqx/mqx/source/nio/fs" -I"C:/Users/afbcom/workspace.kds/project3/SDK/rtos/mqx/mqx/source/nio/drivers/nio_dummy" -I"C:/Users/afbcom/workspace.kds/project3/SDK/rtos/mqx/mqx/source/nio/drivers/nio_serial" -I"C:/Users/afbcom/workspace.kds/project3/SDK/rtos/mqx/mqx/source/nio/drivers/nio_tty" -I"C:/Users/afbcom/workspace.kds/project3/SDK/rtos/mqx/mqx_stdlib/source/include" -I"C:/Users/afbcom/workspace.kds/project3/SDK/rtos/mqx/mqx_stdlib/source/stdio" -I"C:/Users/afbcom/workspace.kds/project3/SDK/platform/hal/src/uart" -I"C:/Users/afbcom/workspace.kds/project3/SDK/platform/drivers/src/uart" -I"C:/Users/afbcom/workspace.kds/project3/Generated_Code/SDK/rtos/mqx/config/board" -I"C:/Users/afbcom/workspace.kds/project3/Generated_Code/SDK/rtos/mqx/config/mcu" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


