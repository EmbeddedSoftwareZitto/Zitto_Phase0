################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Source/Core_Layer/main.c \
../Core/Source/Core_Layer/stm32f3xx_hal_msp.c \
../Core/Source/Core_Layer/stm32f3xx_it.c \
../Core/Source/Core_Layer/syscalls.c \
../Core/Source/Core_Layer/sysmem.c \
../Core/Source/Core_Layer/system_stm32f3xx.c 

OBJS += \
./Core/Source/Core_Layer/main.o \
./Core/Source/Core_Layer/stm32f3xx_hal_msp.o \
./Core/Source/Core_Layer/stm32f3xx_it.o \
./Core/Source/Core_Layer/syscalls.o \
./Core/Source/Core_Layer/sysmem.o \
./Core/Source/Core_Layer/system_stm32f3xx.o 

C_DEPS += \
./Core/Source/Core_Layer/main.d \
./Core/Source/Core_Layer/stm32f3xx_hal_msp.d \
./Core/Source/Core_Layer/stm32f3xx_it.d \
./Core/Source/Core_Layer/syscalls.d \
./Core/Source/Core_Layer/sysmem.d \
./Core/Source/Core_Layer/system_stm32f3xx.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Source/Core_Layer/%.o Core/Source/Core_Layer/%.su: ../Core/Source/Core_Layer/%.c Core/Source/Core_Layer/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F303xC -c -I../Core/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Source-2f-Core_Layer

clean-Core-2f-Source-2f-Core_Layer:
	-$(RM) ./Core/Source/Core_Layer/main.d ./Core/Source/Core_Layer/main.o ./Core/Source/Core_Layer/main.su ./Core/Source/Core_Layer/stm32f3xx_hal_msp.d ./Core/Source/Core_Layer/stm32f3xx_hal_msp.o ./Core/Source/Core_Layer/stm32f3xx_hal_msp.su ./Core/Source/Core_Layer/stm32f3xx_it.d ./Core/Source/Core_Layer/stm32f3xx_it.o ./Core/Source/Core_Layer/stm32f3xx_it.su ./Core/Source/Core_Layer/syscalls.d ./Core/Source/Core_Layer/syscalls.o ./Core/Source/Core_Layer/syscalls.su ./Core/Source/Core_Layer/sysmem.d ./Core/Source/Core_Layer/sysmem.o ./Core/Source/Core_Layer/sysmem.su ./Core/Source/Core_Layer/system_stm32f3xx.d ./Core/Source/Core_Layer/system_stm32f3xx.o ./Core/Source/Core_Layer/system_stm32f3xx.su

.PHONY: clean-Core-2f-Source-2f-Core_Layer

