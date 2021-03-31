PROJECT_NAME = missionmagneto
PROJECT_NAME_NEW = application
PROJECT_NAME_SIM = magneto.gpr

TARGET = $(PROJECT_NAME).elf
TARGET_NEW = $(PROJECT_NAME_NEW).elf
TARGET_SIM = $(PROJECT_NAME).adx

DEP_ADA = obj/$(PROJECT_NAME).o obj/magneto.o
DEP_ALI = 
DEP_ASM = 
DEP_C =

RESSOURCES_NAME = 

#############################################################################################################################
## Ne rien modifier sous cette ligne
##
## Do not modify anything under this line
#############################################################################################################################

ARM_ADA_COMPILER_PATH = /usr/local/insa/arm-ada
STLINK_PROGRAMMER_PATH = /usr/local/insa/STM32Cube/STM32CubeProgrammer/bin
ARM_ADA_PATH = $(HOME)/arm-ada
SIMULATOR_PATH = $(ARM_ADA_PATH)/simulator

LIBGNAT_PATH = $(ARM_ADA_COMPILER_PATH)/compilateur/gcc-arm-none-eabi/lib/gcc/arm-none-eabi/6.3.1/thumb/v7e-m/fpv4-sp/hard/adalib
LIBWRAPPER_PATH = $(ARM_ADA_PATH)/lib/native/wrapper/lib
LIBINSA_PATH =  $(ARM_ADA_PATH)/lib/native/lib-ada

OPTIONS = -gdwarf-2 -O0 --function-sections -march=armv7e-m -mthumb -mthumb-interwork -mfloat-abi=hard -mfpu=fpv4-sp-d16

SRCDIR   = src
OBJDIR   = obj
BINDIR   = obj
SOLDIR   = solutions
DOCDIR   = docs

SOURCES  := $(wildcard $(SRCDIR)/*.adb)
INCLUDES := $(wildcard $(SRCDIR)/*.ads)
OBJECTS_ADB  := $(SOURCES:$(SRCDIR)/%.adb=$(OBJDIR)/%.o)
OBJECTS_ADS  := $(INCLUDES:$(SRCDIR)/%.ads=$(OBJDIR)/%.ali)
rm       = rm -f

.PHONY: all new clean clean-sim install install-sim install-new ressources doc export solution solution-new solution-sim

all: $(BINDIR)/$(TARGET)
	arm-none-eabi-objcopy -O ihex $(OBJDIR)/$(TARGET) $(OBJDIR)/$(PROJECT_NAME).hex
	arm-none-eabi-size $(OBJDIR)/$(TARGET)

new: $(BINDIR)/$(TARGET_NEW)
	arm-none-eabi-objcopy -O ihex $(OBJDIR)/$(TARGET_NEW) $(OBJDIR)/$(PROJECT_NAME_NEW).hex
	arm-none-eabi-size $(OBJDIR)/$(TARGET_NEW)

sim: $(BINDIR)/$(TARGET_SIM)

# Say how to compile Ada programs.
.SUFFIXES: .ada .adb .ads .asm .S .ali

$(OBJECTS_ADB): $(OBJDIR)/%.o : $(SRCDIR)/%.adb
	arm-none-eabi-gcc $(OPTIONS) -I$(LIBINSA_PATH) -I$(LIBWRAPPER_PATH) -c $< -o $@

$(OBJECTS_ADS): $(OBJDIR)/%.ali : $(SRCDIR)/%.ads
	arm-none-eabi-gcc $(OPTIONS) -I$(LIBINSA_PATH) -I$(LIBWRAPPER_PATH) -c $< -o $@

$(BINDIR)/$(TARGET): $(OBJDIR)/$(RESSOURCES_NAME).o $(DEP_ADA) $(DEP_ALI) $(DEP_ASM) $(DEP_C) 
	arm-none-eabi-gnatbind -I$(LIBINSA_PATH) -x $(OBJDIR)/$(PROJECT_NAME).ali
	mv b~* $(OBJDIR)
	arm-none-eabi-gcc -gdwarf-2 $(OPTIONS) -I$(LIBINSA_PATH) -I$(LIBWRAPPER_PATH) -o $(OBJDIR)/b~$(PROJECT_NAME).o -c $(OBJDIR)/b~$(PROJECT_NAME).adb
	arm-none-eabi-gcc -gdwarf-2 -march=armv7e-m -mthumb -mthumb-interwork -mfloat-abi=hard -mfpu=fpv4-sp-d16 -Wl,-Map="ada-program.map" -Wl,--gc-section -T $(ARM_ADA_PATH)/lib/native/linker-script-insa.ld -o $(OBJDIR)/$(TARGET) $(OBJDIR)/*.o $(LIBWRAPPER_PATH)/retarget.o -nostartfiles -nodefaultlibs -L $(LIBWRAPPER_PATH) -L $(LIBINSA_PATH) -L $(LIBGNAT_PATH) -lgnat -lc -ladainsa -lwrapper

$(BINDIR)/$(TARGET_NEW): $(OBJDIR)/$(RESSOURCES_NAME).o $(DEP_ADA) $(DEP_ALI) $(DEP_ASM) $(DEP_C)
	arm-none-eabi-gnatbind -I$(LIBINSA_PATH) -x $(OBJDIR)/$(PROJECT_NAME).ali
	mv b~* $(OBJDIR)
	arm-none-eabi-gcc -gdwarf-2 $(OPTIONS) -I$(LIBINSA_PATH) -I$(LIBWRAPPER_PATH) -o $(OBJDIR)/b~$(PROJECT_NAME).o -c $(OBJDIR)/b~$(PROJECT_NAME).adb
	arm-none-eabi-gcc -gdwarf-2 -march=armv7e-m -mthumb -mthumb-interwork -mfloat-abi=hard -mfpu=fpv4-sp-d16 -Wl,-Map="ada-program.map" -Wl,--gc-section -T $(ARM_ADA_PATH)/lib/native/linker-script-arm-ada-new.ld -o $(OBJDIR)/$(TARGET_NEW) $(OBJDIR)/*.o $(LIBWRAPPER_PATH)/retarget.o -nostartfiles -nodefaultlibs -L $(LIBWRAPPER_PATH) -L $(LIBINSA_PATH) -L $(LIBGNAT_PATH) -lgnat -lc -ladainsa -lwrapper

$(BINDIR)/$(TARGET_SIM): $(OBJDIR)/$(RESSOURCES_NAME).o $(DEP_ADA) $(DEP_ALI) $(DEP_ASM) $(DEP_C)
	gprbuild -r $(PROJECT_NAME_SIM)

clean:
	rm -f  $(OBJDIR)/* ada-program.map *.log

install:
	flashprog $(OBJDIR)/$(PROJECT_NAME).hex

solution:
	flashprog $(SOLDIR)/solution-v1.hex

install-new:
	$(STLINK_PROGRAMMER_PATH)/STM32_Programmer_CLI -c port=SWD -d $(OBJDIR)/$(PROJECT_NAME_NEW).hex -rst

solution-new:
	$(STLINK_PROGRAMMER_PATH)/STM32_Programmer_CLI -c port=SWD -d $(SOLDIR)/solution-v2.hex -rst

install-sim:
	$(SIMULATOR_PATH)/simulator obj/$(TARGET_SIM)

solution-sim:
	$(SIMULATOR_PATH)/simulator $(SOLDIR)/solution-sim.adx
doc:
	a2ps -R -o $(DOCDIR)/doc.ps $(SRCDIR)/simon.ads
	ps2pdf $(DOCDIR)/doc.ps
	mv *.pdf $(DOCDIR)
 
$(OBJDIR)/$(RESSOURCES_NAME).o:
ifdef RESSOURCES_NAME
	rca $(RESSOURCES_NAME).job
	mv $(RESSOURCES_NAME).ads $(SRCDIR)/$(RESSOURCES_NAME).ads
	arm-none-eabi-gcc $(OPTIONS) -I$(LIBINSA_PATH) -I$(LIBWRAPPER_PATH) -c $(SRCDIR)/$(RESSOURCES_NAME).ads -o $(OBJDIR)/$(RESSOURCES_NAME).o
endif

export:
	mv $(BINDIR)/$(PROJECT_NAME).hex $(SOLDIR)/solution-v1.hex
	mv $(BINDIR)/$(PROJECT_NAME_NEW).hex $(SOLDIR)/solution-v2.hex
	mv $(BINDIR)/$(PROJECT_NAME).adx $(SOLDIR)/solution-sim.adx
	rm -f  $(OBJDIR)/$(PROJECT_NAME).o $(OBJDIR)/$(PROJECT_NAME).ali $(OBJDIR)/b~* $(OBJDIR)/$(TARGET) $(OBJDIR)/$(TARGET_NEW) $(OBJDIR)/$(PROJECT_NAME).hex $(OBJDIR)/$(PROJECT_NAME_NEW).hex ada-program.map *.log $(OBJDIR)/*.o
	mv $(PROJECT_NAME).adb.tp $(PROJECT_NAME).adb
