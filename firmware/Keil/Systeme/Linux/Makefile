PROJECT_NAME = arm-ada-system

INCLUDE_PATH = -I../Applis -I../Boot -I../Drivers -I../FatFS -I../GUI -I../Libraries -I../Libraries/CMSIS -I../Ressources -I../FatFS/src

APPLIS = ../Applis
BOOT = ../Boot
DRIVERS = ../Drivers
FATFS = ../FatFS
GUI = ../GUI
LIBRARIES = ../Libraries
RESSOURCES = ../Ressources
LINUX = .

TARGET = $(PROJECT_NAME).elf
DEP_APPLIS = panic.o reprog.o ABI_Table.o system.o tests.o unpackbmp.o
DEP_BOOT = system_stm32f30x.o
DEP_DRIVERS = audio.o console.o GLCD_8Bits_STM32.o keys.o l3gd20.o led.o lsm303dlhc.o m_alloc.o potentiometers.o rng.o sd_spi_drv.o sram.o stm32303c_eval_spi_sd.o timer.o usart.o
DEP_GUI = ProgressBar.o Window.o
DEP_LIBRARIES = stm32f30x_adc.o stm32f30x_can.o stm32f30x_comp.o stm32f30x_crc.o stm32f30x_dac.o stm32f30x_dbgmcu.o stm32f30x_dma.o stm32f30x_exti.o stm32f30x_flash.o stm32f30x_gpio.o stm32f30x_i2c.o stm32f30x_iwdg.o stm32f30x_misc.o stm32f30x_opamp.o stm32f30x_pwr.o stm32f30x_rcc.o stm32f30x_rtc.o stm32f30x_spi.o stm32f30x_syscfg.o stm32f30x_tim.o stm32f30x_usart.o stm32f30x_wwdg.o
DEP_RESSOURCES = ressources.o
DEP_FATFS =
DEP_GCC = retarget_gcc.o startup_gcc.o ABI_Table_Ptr_gcc.o

OPTIONS = -gdwarf-2 -O3 --function-sections -march=armv7e-m -mthumb -mthumb-interwork -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DUSE_STDPERIPH_DRIVER -DSTM32F30X -DUSE_MCBSTM32F300

.PHONY: all clean pre_build

all: $(TARGET)
	arm-none-eabi-objcopy -O ihex $(TARGET) $(PROJECT_NAME).hex
	arm-none-eabi-size $(TARGET)

pre_build:
	cp -v $(APPLIS)/*.c $(BOOT)/*.c $(DRIVERS)/*.c $(GUI)/*.c $(LIBRARIES)/*.c $(RESSOURCES)/*.c .

# Say how to compile C programs.
.SUFFIXES: .asm .S .s .c

.S.o:
	arm-none-eabi-gcc $(OPTIONS) -c $<

.c.o:
	arm-none-eabi-gcc $(OPTIONS) -I. $(INCLUDE_PATH) -c $<

$(TARGET): $(DEP_APPLIS) $(DEP_BOOT) $(DEP_DRIVERS) $(DEP_LIBRARIES) $(DEP_GUI) $(DEP_RESSOURCES) $(DEP_GCC) $(LINUX)/linker-script-system.ld 
	arm-none-eabi-gcc -gdwarf-2 -march=armv7e-m -mthumb -mthumb-interwork -mfloat-abi=hard -mfpu=fpv4-sp-d16 -Wl,-Map="arm-ada-system.map" -Wl,--gc-section -T $(LINUX)/linker-script-system.ld -o $(TARGET) *.o -nostartfiles

clean:
	rm -f  *.o $(TARGET) $(PROJECT_NAME).hex arm-ada-system.map
