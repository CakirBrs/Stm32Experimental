################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/coreM4.c \
../Src/gpio.c \
../Src/lcd.c \
../Src/main.c \
../Src/rng.c \
../Src/syscalls.c \
../Src/sysmem.c \
../Src/timer.c \
../Src/utility.c 

OBJS += \
./Src/coreM4.o \
./Src/gpio.o \
./Src/lcd.o \
./Src/main.o \
./Src/rng.o \
./Src/syscalls.o \
./Src/sysmem.o \
./Src/timer.o \
./Src/utility.o 

C_DEPS += \
./Src/coreM4.d \
./Src/gpio.d \
./Src/lcd.d \
./Src/main.d \
./Src/rng.d \
./Src/syscalls.d \
./Src/sysmem.d \
./Src/timer.d \
./Src/utility.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F407VGTx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/coreM4.d ./Src/coreM4.o ./Src/coreM4.su ./Src/gpio.d ./Src/gpio.o ./Src/gpio.su ./Src/lcd.d ./Src/lcd.o ./Src/lcd.su ./Src/main.d ./Src/main.o ./Src/main.su ./Src/rng.d ./Src/rng.o ./Src/rng.su ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su ./Src/timer.d ./Src/timer.o ./Src/timer.su ./Src/utility.d ./Src/utility.o ./Src/utility.su

.PHONY: clean-Src

