################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/MyLibraries/GPIO.c \
../Core/MyLibraries/SPI.c \
../Core/MyLibraries/USART.c 

OBJS += \
./Core/MyLibraries/GPIO.o \
./Core/MyLibraries/SPI.o \
./Core/MyLibraries/USART.o 

C_DEPS += \
./Core/MyLibraries/GPIO.d \
./Core/MyLibraries/SPI.d \
./Core/MyLibraries/USART.d 


# Each subdirectory must supply rules for building sources it contributes
Core/MyLibraries/%.o Core/MyLibraries/%.su Core/MyLibraries/%.cyclo: ../Core/MyLibraries/%.c Core/MyLibraries/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32L476xx -DUSE_FULL_LL_DRIVER -DHSE_VALUE=8000000 -DHSE_STARTUP_TIMEOUT=100 -DLSE_STARTUP_TIMEOUT=5000 -DLSE_VALUE=32768 -DMSI_VALUE=4000000 -DEXTERNALSAI1_CLOCK_VALUE=2097000 -DEXTERNALSAI2_CLOCK_VALUE=2097000 -DHSI_VALUE=16000000 -DLSI_VALUE=32000 -DVDD_VALUE=3300 -DPREFETCH_ENABLE=0 -DINSTRUCTION_CACHE_ENABLE=1 -DDATA_CACHE_ENABLE=1 -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-MyLibraries

clean-Core-2f-MyLibraries:
	-$(RM) ./Core/MyLibraries/GPIO.cyclo ./Core/MyLibraries/GPIO.d ./Core/MyLibraries/GPIO.o ./Core/MyLibraries/GPIO.su ./Core/MyLibraries/SPI.cyclo ./Core/MyLibraries/SPI.d ./Core/MyLibraries/SPI.o ./Core/MyLibraries/SPI.su ./Core/MyLibraries/USART.cyclo ./Core/MyLibraries/USART.d ./Core/MyLibraries/USART.o ./Core/MyLibraries/USART.su

.PHONY: clean-Core-2f-MyLibraries

