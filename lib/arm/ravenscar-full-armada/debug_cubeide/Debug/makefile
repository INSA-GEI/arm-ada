################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include startup/subdir.mk
-include src/subdir.mk
-include bsp/wrapper/GUI/subdir.mk
-include bsp/wrapper/subdir.mk
-include bsp/res/subdir.mk
-include bsp/lvgl/tests/lv_test_widgets/subdir.mk
-include bsp/lvgl/tests/lv_test_fonts/subdir.mk
-include bsp/lvgl/tests/lv_test_core/subdir.mk
-include bsp/lvgl/tests/subdir.mk
-include bsp/lvgl/src/lv_widgets/subdir.mk
-include bsp/lvgl/src/lv_themes/subdir.mk
-include bsp/lvgl/src/lv_misc/subdir.mk
-include bsp/lvgl/src/lv_hal/subdir.mk
-include bsp/lvgl/src/lv_gpu/subdir.mk
-include bsp/lvgl/src/lv_font/subdir.mk
-include bsp/lvgl/src/lv_draw/subdir.mk
-include bsp/lvgl/src/lv_core/subdir.mk
-include bsp/lvgl/examples/porting/subdir.mk
-include bsp/hal_stm_lvgl/touchpad/subdir.mk
-include bsp/hal_stm_lvgl/tft/subdir.mk
-include bsp/Utilities/Fonts/subdir.mk
-include bsp/STM32F7xx_HAL_Driver/Src/Legacy/subdir.mk
-include bsp/STM32F7xx_HAL_Driver/Src/subdir.mk
-include bsp/BSP/STM32746G-Discovery/subdir.mk
-include bsp/BSP/Components/wm8994/subdir.mk
-include bsp/BSP/Components/lsm6ds3/subdir.mk
-include bsp/BSP/Components/lis2mdl/subdir.mk
-include bsp/BSP/Components/ft5336/subdir.mk
-include bsp/BSP/Components/bmp280/subdir.mk
-include bsp/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
BSP\ Ravenscar-full-armada.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
BSP\ Ravenscar-full-armada.list \

OBJCOPY_BIN += \
BSP\ Ravenscar-full-armada.bin \


# All Target
all: BSP\ Ravenscar-full-armada.elf secondary-outputs

# Tool invocations
BSP\ Ravenscar-full-armada.elf: $(OBJS) $(USER_OBJS) /home/dimercur/Travail/git/arm-ada/lib/arm/ravenscar-full-armada/debug_cubeide/LinkerScript.ld
	arm-none-eabi-gcc -o "BSP Ravenscar-full-armada.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m7 -T"/home/dimercur/Travail/git/arm-ada/lib/arm/ravenscar-full-armada/debug_cubeide/LinkerScript.ld" --specs=nosys.specs -Wl,-Map="BSP Ravenscar-full-armada.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

BSP\ Ravenscar-full-armada.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "BSP Ravenscar-full-armada.list"
	@echo 'Finished building: $@'
	@echo ' '

BSP\ Ravenscar-full-armada.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "BSP Ravenscar-full-armada.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
