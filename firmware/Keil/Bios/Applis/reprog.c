/******************************************************************************/
/* Reprog.c: Reprogramming functionalities                                    */
/*                                                                            */
/******************************************************************************/
/* This program is free software: you can redistribute it and/or modify       */
/*    it under the terms of the GNU General Public License as published by    */
/*    the Free Software Foundation, either version 3 of the License, or       */
/*    (at your option) any later version.                                     */
/*                                                                            */
/*    This program is distributed in the hope that it will be useful,         */
/*    but WITHOUT ANY WARRANTY; without even the implied warranty of          */
/*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the           */
/*    GNU General Public License for more details.                            */
/*                                                                            */
/*    You should have received a copy of the GNU General Public License       */
/*    along with this program.  If not, see <http://www.gnu.org/licenses/>.   */
/******************************************************************************/

#include "stm32f30x.h"
#include "stdio.h"
#include "stdlib.h"

#include "glcd.h"
#include "gui.h"
#include "usart.h"

#include "reprog.h"
#include "version.h"

#include <ctype.h>

typedef enum {FAILED = 0, PASSED = !FAILED} TestStatus;

#define FLASH_PAGE_SIZE         ((uint32_t)0x00000800)   /* FLASH Page Size */
#define FLASH_USER_START_ADDR   ((uint32_t)0x08003000)   /* Start @ of user Flash area */
#define FLASH_USER_END_ADDR     ((uint32_t)0x08040000)   /* End @ of user Flash area */
#define DATA_32                 ((uint32_t)0x12345678)

#define FLASH_VERIFY_START			(0x08003000)

#define PROGRAM_PACKET_SIZE			32

#define PRG_REPROG_PATTERN 0xADDAADDA
#define PRG_SOFTRESET_PATTERN 0xDEADBEEF

uint32_t NbrOfPage = 0x00;
uint32_t EraseCounter = 0x00;
uint32_t Address = 0x00;
uint32_t Base_Address = 0x00;
uint32_t Data = 0x3210ABCD;
__IO FLASH_Status FLASHStatus = FLASH_COMPLETE;
__IO TestStatus MemoryProgramStatus = PASSED;
char Filename[50];
uint32_t NbrBlocks=0x00;
uint32_t CurrentBlock=0x00;

extern volatile uint32_t Image$$SHARED_DATA$$Base;
//static volatile uint32_t *PRG_ReprogAddrPattern; // fin de la zone memoire de 8 Ko située en 0x10001FFC
#define PRG_ReprogAddrPattern Image$$SHARED_DATA$$Base

/* Variables et fonctions pour tester et entrer en mode reprog */
static const char PRG_ReprogEscapeChar = '`';
volatile char PRG_ReprogEscapeCharCounter=0;
static uint8_t FromHextoU8(char* str);
static uint16_t FromHextoU16(char* str);
static uint32_t FromHextoU32(char* str);
static int DoCommand (char* command, int length);
static int DoErase (uint32_t start, uint32_t end);
static int DoSetAddress (uint32_t address);
//static int DoProgram (uint32_t addr, uint8_t *data, uint16_t length);
static int DoVerify (uint32_t start, uint32_t end, uint16_t checksum);
static int DoReset (void);
static int DoOpenFlash (void);
static int DoCloseFlash (void);
static void PRG_Panic(int i);
static void *PRG_CopyToRAM(void);

#define CMD_BUFFER_LENGTH 1024*2+20

uint32_t baseAddress=0;
char commandString[CMD_BUFFER_LENGTH];
int commandStringLength=0;
uint8_t bufferData[CMD_BUFFER_LENGTH];
	
// Constantes pour les types de commande et le protocol
#define CMD_ACQ 'A'
#define CMD_NACQ 'N'
#define CMD_INVALIDCHECKSUM 'I'
#define CMD_ERASE 'E'
#define CMD_SETADRESSE '@'
#define CMD_PROGRAM 'P'
#define CMD_VERIFY 'V'
#define CMD_RESET 'R'
#define CMD_SETFILENAME 'F'

// Constante pour les code retour de DoCommand
#define DOCMD_SUCCESS	0
#define DOCMD_DO_NOTHING	2
#define DOCMD_UNKNOWN_CMD	-1
#define DOCMD_INVALID_ADDRESS	-2
#define DOCMD_INVALID_CHECKSUM -3
#define DOCMD_ERASE_FAIL -4
#define DOCMD_PROGRAM_FAIL -5
#define DOCMD_RESET	1

// Constante pour les panic
#define PANIC_MALLOC_FAILED 	1

/* Definition des routine de programmation en RAM */
extern char DoProgram_RAM;
extern char DoProgram_RAM_End;
int (*DoProgram_Ptr)(uint32_t addr, uint8_t *data, uint16_t length);
volatile int length;

/*void PRG_Init(void)
{
	int toto = (int)&Image$$SHARED_DATA$$Base;
	PRG_ReprogAddrPattern = (uint32_t*)&Image$$SHARED_DATA$$Base;
}*/

/* Fonction pour gerer le depart en reprog */
void PRG_CheckDownloadPattern(char c)
{
	if (c == PRG_ReprogEscapeChar) PRG_ReprogEscapeCharCounter++;
	else PRG_ReprogEscapeCharCounter =0;
	
	if (PRG_ReprogEscapeCharCounter>=5) 
	{
		/* Depart en mode download */
		PRG_ReprogEscapeCharCounter=0;
		
		/* Ecriture d'un pattern en memoire */
		PRG_ReprogAddrPattern = PRG_REPROG_PATTERN;
		
		/* Disable all interrupts */
		NVIC->ICER[0]=0xFFFFFFFF;
		NVIC->ICER[1]=0xFFFFFFFF;
		NVIC->ICER[1]=0xFFFFFFFF;
		SysTick->CTRL=0;
		
		/* et reboot */
		NVIC_SystemReset();
	}
}

/* Fonction pour tester si une reprog est necessaire */
int PRG_CheckReprogRequest(void)
{
	if (PRG_ReprogAddrPattern == PRG_REPROG_PATTERN) return PRG_RESET_REPROG;
	else if (PRG_ReprogAddrPattern == PRG_SOFTRESET_PATTERN) return PRG_RESET_SOFTRESET;
	else return PRG_RESET_HARDRESET;
}

/* Fonction pour nettoyer la condition de reprog */
void PRG_ResetReprogRequest(void)
{
	PRG_ReprogAddrPattern = PRG_SOFTRESET_PATTERN;
}

/* Fonction qui affiche une condition de panique */
void PRG_Panic(int i)
{
	GLCD_Clear(Red);
	GLCD_SetTextColor(White);
	
	if (i==PANIC_MALLOC_FAILED)
	{
		GLCD_DrawString(5,4, "Memory allocation failed");
		GLCD_DrawString(5,5, "Unable to copie code to RAM");		
	}
	else GLCD_DrawString(5,4, "Unknown failure");

	GLCD_DrawString(3,14, "System halted");
	
	while (1);
}

void *PRG_CopyToRAM(void)
{
	char *ptr, *ptr2;
	int i;
	
	/* Copie des routines de programmation en RAM */
	length = (int)&DoProgram_RAM_End;
	length = length - (int)&DoProgram_RAM;
	DoProgram_Ptr = (int(*)(uint32_t, uint8_t *, uint16_t))malloc(length+2);
	if (DoProgram_Ptr == 0) PRG_Panic(PANIC_MALLOC_FAILED);
	
	ptr= (char*)DoProgram_Ptr;
	ptr2 = (char*)&DoProgram_RAM;
	ptr2 = ptr2-1; // Les adresses des fonctions sont toujours impaires (thumb), d'ou le -1 pour retrouver la vraie adresse
	
	for (i=0; i<length; i++)
	{
		*(ptr+i) = *(ptr2+i);
	}
	
	ptr = (char*)DoProgram_Ptr;
	ptr++;	// pour pouvoir sauter à la fonction, l'adresse doit etre impaire (+1) -> Thumb, sinon UsageFault (invalidstate)
	
	return (void *)ptr;
}

void PRG_Run(void)
{
	int i;
	int isDownloading =1;
	uint8_t checksum;
	int status;
	
	/* Avant toutes chose, envoi de l'acquitement */
	printf("%c",CMD_ACQ);
	
	/* Ouverture de la flash */
	DoOpenFlash();
	
	/* Recopie les routines d'ecriture en ram */
	DoProgram_Ptr = (int(*)(uint32_t, uint8_t*, uint16_t))PRG_CopyToRAM();
	
	while (isDownloading)
	{				
		/* Etape 1, recuperation d'une chaine de commande complete */
		do
		{
			commandString[commandStringLength]=getchar();
			
			commandStringLength++;
			
			if (commandStringLength >=CMD_BUFFER_LENGTH) 
			{
				commandStringLength=CMD_BUFFER_LENGTH;
				commandString[commandStringLength-1]='\n';
			}
		} while (commandString[commandStringLength-1]!='\n');
		
		checksum =0;
		
		/* Etape 2: verification de la validité de la chaine recue */
		for (i=0; i<(commandStringLength-3); i++)
		{
			checksum = checksum ^ (uint8_t)commandString[i];
		}
				
		if (checksum != FromHextoU8(commandString+commandStringLength-3))
		{
			printf("%c",CMD_NACQ);
			commandStringLength=0;
		}
		else
		{
			/* tout bon, on peut analyser la commande */
			status = DoCommand(commandString, commandStringLength);

			switch (status)
			{
				case DOCMD_SUCCESS:
					printf("%c",CMD_ACQ);
					break;
				case DOCMD_UNKNOWN_CMD:
					printf("%c",CMD_NACQ);
					break;
				case DOCMD_INVALID_ADDRESS:
					printf("%c",CMD_NACQ);
					break;
				case DOCMD_INVALID_CHECKSUM:
					printf("%c",CMD_INVALIDCHECKSUM);
					isDownloading=0;
					break;
				case DOCMD_DO_NOTHING:
					break;
				case DOCMD_RESET:
					//printf("%c",CMD_ACQ);
					isDownloading=0;
					break;
				default:
					printf("%c",CMD_NACQ);
			}

			commandStringLength=0;
		}
	}
	
	/* Fermeture de la flash et lancement du reset */
	DoCloseFlash();
	DoReset();
}

static int DoCommand (char* command, int length)
{
	char commandType;
	int status = DOCMD_SUCCESS;
	
	uint32_t startAddress;
	uint32_t endAddress;
	uint16_t addressOffset;
	uint16_t checksum;
  char bufferPrintf[64];
	
	uint16_t blockSize;
	uint32_t i;
	uint16_t dataLength;
	uint32_t fileSize;
	
	commandType = command[0];

	switch (commandType)
	{
		case CMD_ERASE:
			
			/* Recuperation des adresses de debut et de fin */
		  startAddress = FromHextoU32(command+1);
		  endAddress = FromHextoU32(command+8+1);
			
			// Verification des adresses
			if ((startAddress >= FLASH_USER_START_ADDR) && 
				  (endAddress < FLASH_USER_END_ADDR) &&
			    (startAddress<=endAddress))
			{
				/* Les parametres sont bon */
				status = DoErase(startAddress, endAddress);
			}
			else status = DOCMD_INVALID_ADDRESS;
			break;
		case CMD_SETFILENAME:
			GLCD_Clear(White);
		  
			dataLength = FromHextoU8(command+1);
		  blockSize = FromHextoU16(command+3);
			fileSize = FromHextoU32(command+7);
			NbrBlocks = fileSize/blockSize;
		  dataLength = dataLength - 6;
		  
		  for (i = 0; i< dataLength; i++)
			{
				Filename[i] = command[15+i];
			}
			
			Filename[dataLength+1]=0x0;
			
			sprintf(bufferPrintf, "File: %s", Filename);
			GLCD_DrawString(5,4, bufferPrintf);
			sprintf(bufferPrintf, "Size: %d", fileSize);
			GLCD_DrawString(5,5, bufferPrintf);
			sprintf(bufferPrintf, "BIOS ver. %s, CC BY-NC-SA GEI-2017", BL_VERSION);
			GLCD_DrawString(3,14, bufferPrintf);
			
			GUI_CreateProgressBar(50, 140, 220, 20, NbrBlocks);
			
			break;
		case CMD_SETADRESSE:
			startAddress = FromHextoU32(command+1);
		
			if ((startAddress>=FLASH_USER_START_ADDR) &&
				  (startAddress<FLASH_USER_END_ADDR))
			{
				/* Les parametres sont bons */
				status = DoSetAddress(startAddress);
			}
			else status = DOCMD_INVALID_ADDRESS;
			break;
		case CMD_PROGRAM:
			addressOffset = FromHextoU16(command+1);
			
		  printf("%c",CMD_ACQ);
		
			if ((Base_Address + addressOffset) >= FLASH_USER_END_ADDR) status= DOCMD_INVALID_ADDRESS; // Adresse invalide -> fin du traitement
			else
			{
				/* recuperer les data */
				dataLength = (length-(1+4+2))/2;
				
				if ((Base_Address + addressOffset) + dataLength >= FLASH_USER_END_ADDR) // Si le buffer depasse la memoire, on le tronque
					dataLength = FLASH_USER_END_ADDR - (Base_Address + addressOffset);
				
				for (i=0; i<dataLength; i++)
				{
					bufferData[i]=FromHextoU8(command+5+(2*i));
				}
						
				GUI_UpdateProgressBar(CurrentBlock);
				CurrentBlock++;
				
				DoProgram_Ptr ((Base_Address + addressOffset), bufferData, dataLength);
				
				status = DOCMD_DO_NOTHING;
		  }
			break;
		case CMD_VERIFY:
			startAddress = FromHextoU32(command+1);
			endAddress = FromHextoU32(command+8+1);
			checksum = FromHextoU16(command+16+1);
			status = DoVerify(startAddress, endAddress, checksum);
			break;
		case CMD_RESET:
			status = DOCMD_RESET;
			break;
		default:
			status = DOCMD_UNKNOWN_CMD;
	}
	
	return status;
}

static int DoErase (uint32_t start, uint32_t end)
{
uint32_t first_addr, last_addr;
int status = DOCMD_SUCCESS;
	
	// Erase the selected flash area
	// (area defined by start and end) ***********/

  /* Clear pending flags (if any) */  
  FLASH_ClearFlag(FLASH_FLAG_EOP | FLASH_FLAG_PGERR | FLASH_FLAG_WRPERR); 

  /* Define the number of page to be erased */
	first_addr=start;
	last_addr=end;
	first_addr = (first_addr/FLASH_PAGE_SIZE)*FLASH_PAGE_SIZE;
	last_addr = (last_addr/FLASH_PAGE_SIZE)*FLASH_PAGE_SIZE;
	
	if (last_addr<end) last_addr = last_addr+ FLASH_PAGE_SIZE;
	
  NbrOfPage = (last_addr - first_addr) / FLASH_PAGE_SIZE;
	
	/* Erase the FLASH pages */
  for(EraseCounter = 0; (EraseCounter < NbrOfPage) && (FLASHStatus == FLASH_COMPLETE); EraseCounter++)
  {
		FLASHStatus = FLASH_ErasePage(first_addr + (FLASH_PAGE_SIZE * EraseCounter));
		
    if (FLASHStatus!= FLASH_COMPLETE)
    {
     /* Error occurred while sector erase. 
         User can add here some code to deal with this error  */
      status= DOCMD_ERASE_FAIL;
    }
  }
	
	return status;
}

static int DoSetAddress (uint32_t address)
{
	Base_Address = address;
	
	return 0;
}

static int DoVerify (uint32_t start, uint32_t end, uint16_t checksum)
{
uint16_t local_checksum=0;
uint8_t* ptr=(uint8_t*)start;

	while (ptr<=(uint8_t*)end)
	{
		local_checksum=local_checksum + *ptr;
	
		ptr++;
	}
	
	if (checksum != local_checksum) return DOCMD_INVALID_CHECKSUM;
	return DOCMD_SUCCESS;
}

static int DoReset (void)
{
	NVIC_SystemReset();
	
	return 0;
}

static int DoOpenFlash (void)
{
	// Unlock flash to enable flash control register access
	FLASH_Unlock();
	
	return 0;
}

static int DoCloseFlash (void)
{
	// Lock flash to disable flash control access
	FLASH_Lock();
	
	return 0;
}

static uint8_t FromHextoU8(char* str)
{
	char str_local[3];
	uint8_t val=0;
	
	str_local[0] = str[0];
	str_local[1] = str[1];
	str_local[2]=0;
	
	val=(uint8_t)strtol(str_local, NULL, 16);
	return val;
}

static uint16_t FromHextoU16(char* str)
{
	char str_local[5];
	uint16_t val=0;
	
	str_local[0] = str[0];
	str_local[1] = str[1];
	str_local[2] = str[2];
	str_local[3] = str[3];
	str_local[4]=0;
	
	val=(uint16_t)strtol(str_local, NULL, 16);
	return val;
}

static uint32_t FromHextoU32(char* str)
{
	char str_local[9];
	uint32_t val=0;
	
	str_local[0] = str[0];
	str_local[1] = str[1];
	str_local[2] = str[2];
	str_local[3] = str[3];
	str_local[4] = str[4];
	str_local[5] = str[5];
	str_local[6] = str[6];
	str_local[7] = str[7];
	str_local[8]=0;
	
	val=(uint32_t)strtol(str_local, NULL, 16);
	return val;
}
