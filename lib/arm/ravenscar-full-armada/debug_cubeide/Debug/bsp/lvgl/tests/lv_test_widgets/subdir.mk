################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/lvgl/tests/lv_test_widgets/lv_test_label.c 

OBJS += \
./bsp/lvgl/tests/lv_test_widgets/lv_test_label.o 

C_DEPS += \
./bsp/lvgl/tests/lv_test_widgets/lv_test_label.d 


# Each subdirectory must supply rules for building sources it contributes
bsp/lvgl/tests/lv_test_widgets/lv_test_label.o: /home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/lvgl/tests/lv_test_widgets/lv_test_label.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DSTM32 -DSTM32F7 -DSTM32F746NGHx -DSTM32F746G_DISCO -DDEBUG -DSTM32F746xx -DUSE_HAL_DRIVER -DLV_EX_CONF_INCLUDE_SIMPLE -c -I"/home/dimercur/Travail/git/arm-ada/lib/arm/ravenscar-full-armada/debug_cubeide" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/CMSIS/Include" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/CMSIS/Device/ST/STM32F7xx/Include" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/conf" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/STM32F7xx_HAL_Driver/Inc" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/hal_stm_lvgl/tft" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/hal_stm_lvgl/touchpad" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/BSP/STM32746G-Discovery" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/BSP/Components/bmp280" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/BSP/Components/lis2mdl" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/BSP/Components/lsm6ds3" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/BSP/Components/rk043fn48h" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/BSP/Components/ft5336" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/wrapper" -Os -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"bsp/lvgl/tests/lv_test_widgets/lv_test_label.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

