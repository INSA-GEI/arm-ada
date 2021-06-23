################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/BSP/STM32746G-Discovery/stm32746g_discovery.c \
/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/BSP/STM32746G-Discovery/stm32746g_discovery_acc_gyro.c \
/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/BSP/STM32746G-Discovery/stm32746g_discovery_audio.c \
/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/BSP/STM32746G-Discovery/stm32746g_discovery_eeprom.c \
/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/BSP/STM32746G-Discovery/stm32746g_discovery_keys.c \
/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/BSP/STM32746G-Discovery/stm32746g_discovery_mag.c \
/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/BSP/STM32746G-Discovery/stm32746g_discovery_pressure.c \
/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/BSP/STM32746G-Discovery/stm32746g_discovery_qspi.c \
/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/BSP/STM32746G-Discovery/stm32746g_discovery_rng.c \
/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/BSP/STM32746G-Discovery/stm32746g_discovery_sd.c \
/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/BSP/STM32746G-Discovery/stm32746g_discovery_sdram.c \
/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/BSP/STM32746G-Discovery/stm32746g_discovery_stdio.c \
/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/BSP/STM32746G-Discovery/stm32746g_discovery_ts.c 

OBJS += \
./bsp/BSP/STM32746G-Discovery/stm32746g_discovery.o \
./bsp/BSP/STM32746G-Discovery/stm32746g_discovery_acc_gyro.o \
./bsp/BSP/STM32746G-Discovery/stm32746g_discovery_audio.o \
./bsp/BSP/STM32746G-Discovery/stm32746g_discovery_eeprom.o \
./bsp/BSP/STM32746G-Discovery/stm32746g_discovery_keys.o \
./bsp/BSP/STM32746G-Discovery/stm32746g_discovery_mag.o \
./bsp/BSP/STM32746G-Discovery/stm32746g_discovery_pressure.o \
./bsp/BSP/STM32746G-Discovery/stm32746g_discovery_qspi.o \
./bsp/BSP/STM32746G-Discovery/stm32746g_discovery_rng.o \
./bsp/BSP/STM32746G-Discovery/stm32746g_discovery_sd.o \
./bsp/BSP/STM32746G-Discovery/stm32746g_discovery_sdram.o \
./bsp/BSP/STM32746G-Discovery/stm32746g_discovery_stdio.o \
./bsp/BSP/STM32746G-Discovery/stm32746g_discovery_ts.o 

C_DEPS += \
./bsp/BSP/STM32746G-Discovery/stm32746g_discovery.d \
./bsp/BSP/STM32746G-Discovery/stm32746g_discovery_acc_gyro.d \
./bsp/BSP/STM32746G-Discovery/stm32746g_discovery_audio.d \
./bsp/BSP/STM32746G-Discovery/stm32746g_discovery_eeprom.d \
./bsp/BSP/STM32746G-Discovery/stm32746g_discovery_keys.d \
./bsp/BSP/STM32746G-Discovery/stm32746g_discovery_mag.d \
./bsp/BSP/STM32746G-Discovery/stm32746g_discovery_pressure.d \
./bsp/BSP/STM32746G-Discovery/stm32746g_discovery_qspi.d \
./bsp/BSP/STM32746G-Discovery/stm32746g_discovery_rng.d \
./bsp/BSP/STM32746G-Discovery/stm32746g_discovery_sd.d \
./bsp/BSP/STM32746G-Discovery/stm32746g_discovery_sdram.d \
./bsp/BSP/STM32746G-Discovery/stm32746g_discovery_stdio.d \
./bsp/BSP/STM32746G-Discovery/stm32746g_discovery_ts.d 


# Each subdirectory must supply rules for building sources it contributes
bsp/BSP/STM32746G-Discovery/stm32746g_discovery.o: /home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/BSP/STM32746G-Discovery/stm32746g_discovery.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DSTM32 -DSTM32F7 -DSTM32F746NGHx -DSTM32F746G_DISCO -DDEBUG -DSTM32F746xx -DUSE_HAL_DRIVER -DLV_EX_CONF_INCLUDE_SIMPLE -c -I"/home/dimercur/Travail/git/arm-ada/lib/arm/ravenscar-full-armada/debug_cubeide" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/CMSIS/Include" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/CMSIS/Device/ST/STM32F7xx/Include" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/conf" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/STM32F7xx_HAL_Driver/Inc" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/hal_stm_lvgl/tft" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/hal_stm_lvgl/touchpad" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/BSP/STM32746G-Discovery" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/BSP/Components/bmp280" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/BSP/Components/lis2mdl" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/BSP/Components/lsm6ds3" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/BSP/Components/rk043fn48h" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/BSP/Components/ft5336" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/wrapper" -Os -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"bsp/BSP/STM32746G-Discovery/stm32746g_discovery.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
bsp/BSP/STM32746G-Discovery/stm32746g_discovery_acc_gyro.o: /home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/BSP/STM32746G-Discovery/stm32746g_discovery_acc_gyro.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DSTM32 -DSTM32F7 -DSTM32F746NGHx -DSTM32F746G_DISCO -DDEBUG -DSTM32F746xx -DUSE_HAL_DRIVER -DLV_EX_CONF_INCLUDE_SIMPLE -c -I"/home/dimercur/Travail/git/arm-ada/lib/arm/ravenscar-full-armada/debug_cubeide" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/CMSIS/Include" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/CMSIS/Device/ST/STM32F7xx/Include" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/conf" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/STM32F7xx_HAL_Driver/Inc" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/hal_stm_lvgl/tft" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/hal_stm_lvgl/touchpad" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/BSP/STM32746G-Discovery" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/BSP/Components/bmp280" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/BSP/Components/lis2mdl" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/BSP/Components/lsm6ds3" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/BSP/Components/rk043fn48h" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/BSP/Components/ft5336" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/wrapper" -Os -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"bsp/BSP/STM32746G-Discovery/stm32746g_discovery_acc_gyro.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
bsp/BSP/STM32746G-Discovery/stm32746g_discovery_audio.o: /home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/BSP/STM32746G-Discovery/stm32746g_discovery_audio.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DSTM32 -DSTM32F7 -DSTM32F746NGHx -DSTM32F746G_DISCO -DDEBUG -DSTM32F746xx -DUSE_HAL_DRIVER -DLV_EX_CONF_INCLUDE_SIMPLE -c -I"/home/dimercur/Travail/git/arm-ada/lib/arm/ravenscar-full-armada/debug_cubeide" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/CMSIS/Include" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/CMSIS/Device/ST/STM32F7xx/Include" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/conf" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/STM32F7xx_HAL_Driver/Inc" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/hal_stm_lvgl/tft" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/hal_stm_lvgl/touchpad" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/BSP/STM32746G-Discovery" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/BSP/Components/bmp280" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/BSP/Components/lis2mdl" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/BSP/Components/lsm6ds3" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/BSP/Components/rk043fn48h" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/BSP/Components/ft5336" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/wrapper" -Os -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"bsp/BSP/STM32746G-Discovery/stm32746g_discovery_audio.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
bsp/BSP/STM32746G-Discovery/stm32746g_discovery_eeprom.o: /home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/BSP/STM32746G-Discovery/stm32746g_discovery_eeprom.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DSTM32 -DSTM32F7 -DSTM32F746NGHx -DSTM32F746G_DISCO -DDEBUG -DSTM32F746xx -DUSE_HAL_DRIVER -DLV_EX_CONF_INCLUDE_SIMPLE -c -I"/home/dimercur/Travail/git/arm-ada/lib/arm/ravenscar-full-armada/debug_cubeide" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/CMSIS/Include" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/CMSIS/Device/ST/STM32F7xx/Include" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/conf" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/STM32F7xx_HAL_Driver/Inc" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/hal_stm_lvgl/tft" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/hal_stm_lvgl/touchpad" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/BSP/STM32746G-Discovery" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/BSP/Components/bmp280" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/BSP/Components/lis2mdl" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/BSP/Components/lsm6ds3" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/BSP/Components/rk043fn48h" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/BSP/Components/ft5336" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/wrapper" -Os -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"bsp/BSP/STM32746G-Discovery/stm32746g_discovery_eeprom.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
bsp/BSP/STM32746G-Discovery/stm32746g_discovery_keys.o: /home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/BSP/STM32746G-Discovery/stm32746g_discovery_keys.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DSTM32 -DSTM32F7 -DSTM32F746NGHx -DSTM32F746G_DISCO -DDEBUG -DSTM32F746xx -DUSE_HAL_DRIVER -DLV_EX_CONF_INCLUDE_SIMPLE -c -I"/home/dimercur/Travail/git/arm-ada/lib/arm/ravenscar-full-armada/debug_cubeide" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/CMSIS/Include" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/CMSIS/Device/ST/STM32F7xx/Include" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/conf" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/STM32F7xx_HAL_Driver/Inc" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/hal_stm_lvgl/tft" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/hal_stm_lvgl/touchpad" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/BSP/STM32746G-Discovery" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/BSP/Components/bmp280" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/BSP/Components/lis2mdl" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/BSP/Components/lsm6ds3" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/BSP/Components/rk043fn48h" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/BSP/Components/ft5336" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/wrapper" -Os -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"bsp/BSP/STM32746G-Discovery/stm32746g_discovery_keys.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
bsp/BSP/STM32746G-Discovery/stm32746g_discovery_mag.o: /home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/BSP/STM32746G-Discovery/stm32746g_discovery_mag.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DSTM32 -DSTM32F7 -DSTM32F746NGHx -DSTM32F746G_DISCO -DDEBUG -DSTM32F746xx -DUSE_HAL_DRIVER -DLV_EX_CONF_INCLUDE_SIMPLE -c -I"/home/dimercur/Travail/git/arm-ada/lib/arm/ravenscar-full-armada/debug_cubeide" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/CMSIS/Include" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/CMSIS/Device/ST/STM32F7xx/Include" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/conf" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/STM32F7xx_HAL_Driver/Inc" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/hal_stm_lvgl/tft" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/hal_stm_lvgl/touchpad" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/BSP/STM32746G-Discovery" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/BSP/Components/bmp280" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/BSP/Components/lis2mdl" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/BSP/Components/lsm6ds3" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/BSP/Components/rk043fn48h" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/BSP/Components/ft5336" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/wrapper" -Os -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"bsp/BSP/STM32746G-Discovery/stm32746g_discovery_mag.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
bsp/BSP/STM32746G-Discovery/stm32746g_discovery_pressure.o: /home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/BSP/STM32746G-Discovery/stm32746g_discovery_pressure.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DSTM32 -DSTM32F7 -DSTM32F746NGHx -DSTM32F746G_DISCO -DDEBUG -DSTM32F746xx -DUSE_HAL_DRIVER -DLV_EX_CONF_INCLUDE_SIMPLE -c -I"/home/dimercur/Travail/git/arm-ada/lib/arm/ravenscar-full-armada/debug_cubeide" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/CMSIS/Include" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/CMSIS/Device/ST/STM32F7xx/Include" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/conf" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/STM32F7xx_HAL_Driver/Inc" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/hal_stm_lvgl/tft" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/hal_stm_lvgl/touchpad" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/BSP/STM32746G-Discovery" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/BSP/Components/bmp280" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/BSP/Components/lis2mdl" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/BSP/Components/lsm6ds3" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/BSP/Components/rk043fn48h" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/BSP/Components/ft5336" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/wrapper" -Os -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"bsp/BSP/STM32746G-Discovery/stm32746g_discovery_pressure.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
bsp/BSP/STM32746G-Discovery/stm32746g_discovery_qspi.o: /home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/BSP/STM32746G-Discovery/stm32746g_discovery_qspi.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DSTM32 -DSTM32F7 -DSTM32F746NGHx -DSTM32F746G_DISCO -DDEBUG -DSTM32F746xx -DUSE_HAL_DRIVER -DLV_EX_CONF_INCLUDE_SIMPLE -c -I"/home/dimercur/Travail/git/arm-ada/lib/arm/ravenscar-full-armada/debug_cubeide" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/CMSIS/Include" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/CMSIS/Device/ST/STM32F7xx/Include" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/conf" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/STM32F7xx_HAL_Driver/Inc" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/hal_stm_lvgl/tft" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/hal_stm_lvgl/touchpad" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/BSP/STM32746G-Discovery" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/BSP/Components/bmp280" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/BSP/Components/lis2mdl" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/BSP/Components/lsm6ds3" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/BSP/Components/rk043fn48h" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/BSP/Components/ft5336" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/wrapper" -Os -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"bsp/BSP/STM32746G-Discovery/stm32746g_discovery_qspi.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
bsp/BSP/STM32746G-Discovery/stm32746g_discovery_rng.o: /home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/BSP/STM32746G-Discovery/stm32746g_discovery_rng.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DSTM32 -DSTM32F7 -DSTM32F746NGHx -DSTM32F746G_DISCO -DDEBUG -DSTM32F746xx -DUSE_HAL_DRIVER -DLV_EX_CONF_INCLUDE_SIMPLE -c -I"/home/dimercur/Travail/git/arm-ada/lib/arm/ravenscar-full-armada/debug_cubeide" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/CMSIS/Include" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/CMSIS/Device/ST/STM32F7xx/Include" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/conf" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/STM32F7xx_HAL_Driver/Inc" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/hal_stm_lvgl/tft" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/hal_stm_lvgl/touchpad" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/BSP/STM32746G-Discovery" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/BSP/Components/bmp280" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/BSP/Components/lis2mdl" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/BSP/Components/lsm6ds3" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/BSP/Components/rk043fn48h" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/BSP/Components/ft5336" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/wrapper" -Os -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"bsp/BSP/STM32746G-Discovery/stm32746g_discovery_rng.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
bsp/BSP/STM32746G-Discovery/stm32746g_discovery_sd.o: /home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/BSP/STM32746G-Discovery/stm32746g_discovery_sd.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DSTM32 -DSTM32F7 -DSTM32F746NGHx -DSTM32F746G_DISCO -DDEBUG -DSTM32F746xx -DUSE_HAL_DRIVER -DLV_EX_CONF_INCLUDE_SIMPLE -c -I"/home/dimercur/Travail/git/arm-ada/lib/arm/ravenscar-full-armada/debug_cubeide" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/CMSIS/Include" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/CMSIS/Device/ST/STM32F7xx/Include" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/conf" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/STM32F7xx_HAL_Driver/Inc" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/hal_stm_lvgl/tft" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/hal_stm_lvgl/touchpad" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/BSP/STM32746G-Discovery" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/BSP/Components/bmp280" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/BSP/Components/lis2mdl" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/BSP/Components/lsm6ds3" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/BSP/Components/rk043fn48h" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/BSP/Components/ft5336" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/wrapper" -Os -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"bsp/BSP/STM32746G-Discovery/stm32746g_discovery_sd.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
bsp/BSP/STM32746G-Discovery/stm32746g_discovery_sdram.o: /home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/BSP/STM32746G-Discovery/stm32746g_discovery_sdram.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DSTM32 -DSTM32F7 -DSTM32F746NGHx -DSTM32F746G_DISCO -DDEBUG -DSTM32F746xx -DUSE_HAL_DRIVER -DLV_EX_CONF_INCLUDE_SIMPLE -c -I"/home/dimercur/Travail/git/arm-ada/lib/arm/ravenscar-full-armada/debug_cubeide" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/CMSIS/Include" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/CMSIS/Device/ST/STM32F7xx/Include" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/conf" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/STM32F7xx_HAL_Driver/Inc" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/hal_stm_lvgl/tft" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/hal_stm_lvgl/touchpad" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/BSP/STM32746G-Discovery" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/BSP/Components/bmp280" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/BSP/Components/lis2mdl" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/BSP/Components/lsm6ds3" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/BSP/Components/rk043fn48h" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/BSP/Components/ft5336" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/wrapper" -Os -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"bsp/BSP/STM32746G-Discovery/stm32746g_discovery_sdram.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
bsp/BSP/STM32746G-Discovery/stm32746g_discovery_stdio.o: /home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/BSP/STM32746G-Discovery/stm32746g_discovery_stdio.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DSTM32 -DSTM32F7 -DSTM32F746NGHx -DSTM32F746G_DISCO -DDEBUG -DSTM32F746xx -DUSE_HAL_DRIVER -DLV_EX_CONF_INCLUDE_SIMPLE -c -I"/home/dimercur/Travail/git/arm-ada/lib/arm/ravenscar-full-armada/debug_cubeide" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/CMSIS/Include" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/CMSIS/Device/ST/STM32F7xx/Include" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/conf" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/STM32F7xx_HAL_Driver/Inc" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/hal_stm_lvgl/tft" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/hal_stm_lvgl/touchpad" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/BSP/STM32746G-Discovery" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/BSP/Components/bmp280" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/BSP/Components/lis2mdl" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/BSP/Components/lsm6ds3" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/BSP/Components/rk043fn48h" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/BSP/Components/ft5336" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/wrapper" -Os -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"bsp/BSP/STM32746G-Discovery/stm32746g_discovery_stdio.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
bsp/BSP/STM32746G-Discovery/stm32746g_discovery_ts.o: /home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/BSP/STM32746G-Discovery/stm32746g_discovery_ts.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DSTM32 -DSTM32F7 -DSTM32F746NGHx -DSTM32F746G_DISCO -DDEBUG -DSTM32F746xx -DUSE_HAL_DRIVER -DLV_EX_CONF_INCLUDE_SIMPLE -c -I"/home/dimercur/Travail/git/arm-ada/lib/arm/ravenscar-full-armada/debug_cubeide" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/CMSIS/Include" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/CMSIS/Device/ST/STM32F7xx/Include" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/conf" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/STM32F7xx_HAL_Driver/Inc" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/hal_stm_lvgl/tft" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/hal_stm_lvgl/touchpad" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/BSP/STM32746G-Discovery" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/BSP/Components/bmp280" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/BSP/Components/lis2mdl" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/BSP/Components/lsm6ds3" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/BSP/Components/rk043fn48h" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/BSP/Components/ft5336" -I"/home/dimercur/Travail/ada/ravenscar-port-armada/ravenscar-full-armada/bsp/wrapper" -Os -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"bsp/BSP/STM32746G-Discovery/stm32746g_discovery_ts.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

