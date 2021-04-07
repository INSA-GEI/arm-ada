################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/BSP/Components/lis2mdl/lis2mdl_reg.c 

OBJS += \
./Drivers/BSP/Components/lis2mdl/lis2mdl_reg.o 

C_DEPS += \
./Drivers/BSP/Components/lis2mdl/lis2mdl_reg.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/Components/lis2mdl/lis2mdl_reg.o: ../Drivers/BSP/Components/lis2mdl/lis2mdl_reg.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F746xx -UADA_TEST_SYSTEM -c -I../Drivers/CMSIS/Include -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../configuration -I../Drivers/BSP/STM32746G-Discovery/conf -I../Drivers/BSP/STM32746G-Discovery -I../Drivers/BSP/Components/es_wifi -I../Utilities/Fonts -I../Utilities/Log -I../Middlewares/Third_Party/fatfs -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7_MPU/r0p1 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/Common -I../src -I../Legacy -I../Tests -I../Ressources -O2 -ffunction-sections -fdata-sections -mslow-flash-data -Wall -fstack-usage -MMD -MP -MF"Drivers/BSP/Components/lis2mdl/lis2mdl_reg.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

