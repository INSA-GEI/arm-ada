####################################################################### 
# Configuration de l'environnement arm-ada 2025 (installation locale) #
#######################################################################

BASE_ARMADA=/mnt/commetud/2emeAnneeIMACS
ARMADA_TOOLS_PATH=/mnt/commetud/2emeAnneeIMACS/ADA/tools/bin

GNAT_COMPILER_PATH=$BASE_ARMADA/arm-ada-tools-2025/bin
GNATSTUDIO_PATH=
STM32_PRG_PATH=$BASE_ARMADA/arm-ada-tools-2025/STM32CubeProgrammer/bin

var1=$(echo $PATH | grep "arm-ada-tools")

if [ -d $GNAT_COMPILER_PATH ]; then
	if [ "$var1" = "" ]; then
   		PATH=$GNAT_COMPILER_PATH:$GNATSTUDIO_PATH:$ARMADA_TOOLS_PATH:$STM32_PRG_PATH:$PATH
	fi
fi

