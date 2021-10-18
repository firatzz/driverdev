################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../myDriver/Src/EXTI.c \
../myDriver/Src/GPIO.c \
../myDriver/Src/RCC.c 

OBJS += \
./myDriver/Src/EXTI.o \
./myDriver/Src/GPIO.o \
./myDriver/Src/RCC.o 

C_DEPS += \
./myDriver/Src/EXTI.d \
./myDriver/Src/GPIO.d \
./myDriver/Src/RCC.d 


# Each subdirectory must supply rules for building sources it contributes
myDriver/Src/%.o: ../myDriver/Src/%.c myDriver/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F407G_DISC1 -DSTM32F4 -DSTM32F407VGTx -c -I../Inc -I"C:/Users/Firat/STM32CubeIDE/workspace_1.7.0/driverdev/myDriver/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

