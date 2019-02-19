/*-----------------------------------------------------------------------
/  Low level disk interface modlue include file   (C)ChaN, 2012
/-----------------------------------------------------------------------*/

#ifndef _SD_SPI_DRV
#define _SD_SPI_DRV

#include "diskio.h"

extern const DWORD socket_state_mask_cp ;
extern const DWORD socket_state_mask_wp;

extern volatile DSTATUS Stat;	/* Disk status */

extern volatile DWORD Timer1, Timer2;	/* 100Hz decrement timers */

extern BYTE CardType;			/* Card type flags */

// demo uses a command line option to define this (see Makefile):
// #define STM32_SD_USE_DMA


#ifdef STM32_SD_USE_DMA
// #warning "Information only: using DMA"
#pragma message "*** Using DMA ***"
#endif

/* set to 1 to provide a disk_ioctrl function even if not needed by the FatFs */
#define STM32_SD_DISK_IOCTRL_FORCE      0

#if (_MAX_SS != 512) || (_FS_READONLY == 0) || (STM32_SD_DISK_IOCTRL_FORCE == 1)
#define STM32_SD_DISK_IOCTRL   1
#else
#define STM32_SD_DISK_IOCTRL   0
#endif

// demo uses a command line option to define this (see Makefile):
//#define USE_EK_STM32F
//#define USE_STM32_P103
//#define USE_MINI_STM32

#if defined(USE_EK_STM32F)
#define CARD_SUPPLY_SWITCHABLE   1
#define GPIO_PWR                 GPIOD
#define RCC_APB2Periph_GPIO_PWR  RCC_APB2Periph_GPIOD
#define GPIO_Pin_PWR             GPIO_Pin_10
#define GPIO_Mode_PWR            GPIO_Mode_Out_OD /* pull-up resistor at power FET */
#define SOCKET_WP_CONNECTED      0
#define SOCKET_CP_CONNECTED      0
#define SPI_SD                   SPI1
#define GPIO_CS                  GPIOD
#define RCC_APB2Periph_GPIO_CS   RCC_APB2Periph_GPIOD
#define GPIO_Pin_CS              GPIO_Pin_9
#define DMA_Channel_SPI_SD_RX    DMA1_Channel2
#define DMA_Channel_SPI_SD_TX    DMA1_Channel3
#define DMA_FLAG_SPI_SD_TC_RX    DMA1_FLAG_TC2
#define DMA_FLAG_SPI_SD_TC_TX    DMA1_FLAG_TC3
#define GPIO_SPI_SD              GPIOA
#define GPIO_Pin_SPI_SD_SCK      GPIO_Pin_5
#define GPIO_Pin_SPI_SD_MISO     GPIO_Pin_6
#define GPIO_Pin_SPI_SD_MOSI     GPIO_Pin_7
#define RCC_APBPeriphClockCmd_SPI_SD  RCC_APB2PeriphClockCmd
#define RCC_APBPeriph_SPI_SD     RCC_APB2Periph_SPI1
/* - for SPI1 and full-speed APB2: 72MHz/4 */
#define SPI_BaudRatePrescaler_SPI_SD  SPI_BaudRatePrescaler_4

#elif defined(USE_STM32_P103)
// Olimex STM32-P103 not tested!
#define CARD_SUPPLY_SWITCHABLE   0
#define SOCKET_WP_CONNECTED      1 /* write-protect socket-switch */
#define SOCKET_CP_CONNECTED      1 /* card-present socket-switch */
#define GPIO_WP                  GPIOC
#define GPIO_CP                  GPIOC
#define RCC_APBxPeriph_GPIO_WP   RCC_APB2Periph_GPIOC
#define RCC_APBxPeriph_GPIO_CP   RCC_APB2Periph_GPIOC
#define GPIO_Pin_WP              GPIO_Pin_6
#define GPIO_Pin_CP              GPIO_Pin_7
#define GPIO_Mode_WP             GPIO_Mode_IN_FLOATING /* external resistor */
#define GPIO_Mode_CP             GPIO_Mode_IN_FLOATING /* external resistor */
#define SPI_SD                   SPI2
#define GPIO_CS                  GPIOB
#define RCC_APB2Periph_GPIO_CS   RCC_APB2Periph_GPIOB
#define GPIO_Pin_CS              GPIO_Pin_12
#define DMA_Channel_SPI_SD_RX    DMA1_Channel4
#define DMA_Channel_SPI_SD_TX    DMA1_Channel5
#define DMA_FLAG_SPI_SD_TC_RX    DMA1_FLAG_TC4
#define DMA_FLAG_SPI_SD_TC_TX    DMA1_FLAG_TC5
#define GPIO_SPI_SD              GPIOB
#define GPIO_Pin_SPI_SD_SCK      GPIO_Pin_13
#define GPIO_Pin_SPI_SD_MISO     GPIO_Pin_14
#define GPIO_Pin_SPI_SD_MOSI     GPIO_Pin_15
#define RCC_APBPeriphClockCmd_SPI_SD  RCC_APB1PeriphClockCmd
#define RCC_APBPeriph_SPI_SD     RCC_APB1Periph_SPI2
/* for SPI2 and full-speed APB1: 36MHz/2 */
/* !! PRESCALE 4 used here - 2 does not work, maybe because
       of the poor wiring on the HELI_V1 prototype hardware */
#define SPI_BaudRatePrescaler_SPI_SD  SPI_BaudRatePrescaler_4

#elif defined(USE_MINI_STM32)
#define CARD_SUPPLY_SWITCHABLE   0
#define SOCKET_WP_CONNECTED      0
#define SOCKET_CP_CONNECTED      0
#define SPI_SD                   SPI1
#define GPIO_CS                  GPIOB
#define RCC_APB2Periph_GPIO_CS   RCC_APB2Periph_GPIOB
#define GPIO_Pin_CS              GPIO_Pin_6
#define DMA_Channel_SPI_SD_RX    DMA1_Channel2
#define DMA_Channel_SPI_SD_TX    DMA1_Channel3
#define DMA_FLAG_SPI_SD_TC_RX    DMA1_FLAG_TC2
#define DMA_FLAG_SPI_SD_TC_TX    DMA1_FLAG_TC3
#define GPIO_SPI_SD              GPIOA
#define GPIO_Pin_SPI_SD_SCK      GPIO_Pin_5
#define GPIO_Pin_SPI_SD_MISO     GPIO_Pin_6
#define GPIO_Pin_SPI_SD_MOSI     GPIO_Pin_7
#define RCC_APBPeriphClockCmd_SPI_SD  RCC_APB2PeriphClockCmd
#define RCC_APBPeriph_SPI_SD     RCC_APB2Periph_SPI1
/* - for SPI1 and full-speed APB2: 72MHz/4 */
#define SPI_BaudRatePrescaler_SPI_SD  SPI_BaudRatePrescaler_4

#elif defined(USE_MCBSTM32F400)
#define CARD_SUPPLY_SWITCHABLE   0
#define SOCKET_WP_CONNECTED      0
#define SOCKET_CP_CONNECTED      1
#define SPI_SD                   SPI1
#define GPIO_CS                  GPIOB
#define RCC_APB2Periph_GPIO_CS   RCC_APB2Periph_GPIOB
#define GPIO_Pin_CS              GPIO_Pin_6
#define DMA_Channel_SPI_SD_RX    DMA1_Channel2
#define DMA_Channel_SPI_SD_TX    DMA1_Channel3
#define DMA_FLAG_SPI_SD_TC_RX    DMA1_FLAG_TC2
#define DMA_FLAG_SPI_SD_TC_TX    DMA1_FLAG_TC3
#define GPIO_SPI_SD              GPIOA
#define GPIO_Pin_SPI_SD_SCK      GPIO_Pin_5
#define GPIO_Pin_SPI_SD_MISO     GPIO_Pin_6
#define GPIO_Pin_SPI_SD_MOSI     GPIO_Pin_7
#define RCC_APBPeriphClockCmd_SPI_SD  RCC_APB2PeriphClockCmd
#define RCC_APBPeriph_SPI_SD     RCC_APB2Periph_SPI1
/* - for SPI1 and full-speed APB2: 72MHz/4 */
#define SPI_BaudRatePrescaler_SPI_SD  SPI_BaudRatePrescaler_4

#elif defined(USE_MCBSTM32F300)
#define CARD_SUPPLY_SWITCHABLE   0
#define SOCKET_WP_CONNECTED      0 /* write-protect socket-switch */
#define SOCKET_CP_CONNECTED      1 /* card-present socket-switch */
#define GPIO_WP                  GPIOA
#define GPIO_CP                  GPIOB
#define RCC_AHBPeriph_GPIO_WP    RCC_AHBPeriph_GPIOA
#define RCC_AHBPeriph_GPIO_CP    RCC_AHBPeriph_GPIOB
#define GPIO_Pin_WP              GPIO_Pin_6
#define GPIO_Pin_CP              GPIO_Pin_11
#define GPIO_Mode_WP             GPIO_Mode_IN /* external resistor */
#define GPIO_Mode_CP             GPIO_Mode_IN /* external resistor */
#define SPI_SD                   SPI2
#define GPIO_CS                  GPIOB
#define RCC_AHBPeriph_GPIO_CS    RCC_AHBPeriph_GPIOB
#define GPIO_Pin_CS              GPIO_Pin_12
#define DMA_Channel_SPI_SD_RX    DMA1_Channel4
#define DMA_Channel_SPI_SD_TX    DMA1_Channel5
#define DMA_FLAG_SPI_SD_TC_RX    DMA1_FLAG_TC4
#define DMA_FLAG_SPI_SD_TC_TX    DMA1_FLAG_TC5
#define GPIO_SPI_SD              GPIOB
#define GPIO_Pin_SPI_SD_SCK      GPIO_Pin_13
#define GPIO_Pin_SPI_SD_MISO     GPIO_Pin_14
#define GPIO_Pin_SPI_SD_MOSI     GPIO_Pin_15
#define RCC_APBPeriphClockCmd_SPI_SD  RCC_APB1PeriphClockCmd
#define RCC_APBPeriph_SPI_SD     RCC_APB1Periph_SPI2
/* for SPI2 and full-speed APB1: 36MHz/2 */
/* !! PRESCALE 4 used here - 2 does not work, maybe because
       of the poor wiring on the HELI_V1 prototype hardware */
#define SPI_BaudRatePrescaler_SPI_SD  SPI_BaudRatePrescaler_4


#else
#error "unsupported board"
#endif

/* Manley EK-STM32F board does not offer socket contacts -> dummy values: */
#define SOCKPORT	1			/* Socket contact port */
#define SOCKWP		0			/* Write protect switch (PB5) */
#define SOCKINS		0			/* Card detect switch (PB4) */

enum speed_setting_en { INTERFACE_SLOW, INTERFACE_FAST };
typedef enum speed_setting_en speed_setting;

/* Definitions for MMC/SDC command */
#define CMD0	(0x40+0)	/* GO_IDLE_STATE */
#define CMD1	(0x40+1)	/* SEND_OP_COND (MMC) */
#define ACMD41	(0xC0+41)	/* SEND_OP_COND (SDC) */
#define CMD8	(0x40+8)	/* SEND_IF_COND */
#define CMD9	(0x40+9)	/* SEND_CSD */
#define CMD10	(0x40+10)	/* SEND_CID */
#define CMD12	(0x40+12)	/* STOP_TRANSMISSION */
#define ACMD13	(0xC0+13)	/* SD_STATUS (SDC) */
#define CMD16	(0x40+16)	/* SET_BLOCKLEN */
#define CMD17	(0x40+17)	/* READ_SINGLE_BLOCK */
#define CMD18	(0x40+18)	/* READ_MULTIPLE_BLOCK */
#define CMD23	(0x40+23)	/* SET_BLOCK_COUNT (MMC) */
#define ACMD23	(0xC0+23)	/* SET_WR_BLK_ERASE_COUNT (SDC) */
#define CMD24	(0x40+24)	/* WRITE_BLOCK */
#define CMD25	(0x40+25)	/* WRITE_MULTIPLE_BLOCK */
#define CMD55	(0x40+55)	/* APP_CMD */
#define CMD58	(0x40+58)	/* READ_OCR */

/* Card-Select Controls  (Platform dependent) */
#define SELECT()        GPIO_ResetBits(GPIO_CS, GPIO_Pin_CS)    /* MMC CS = L */
#define DESELECT()      GPIO_SetBits(GPIO_CS, GPIO_Pin_CS)      /* MMC CS = H */

/*-----------------------------------------------------------------------*/
/* Transmit a byte to MMC via SPI  (Platform dependent)                  */
/*-----------------------------------------------------------------------*/
#define xmit_spi(dat)  stm32_spi_rw(dat)

/* Alternative macro to receive data fast */
#define rcvr_spi_m(dst)  *(dst)=stm32_spi_rw(0xff)

void interface_speed(speed_setting speed );
void socket_wp_init(void);
DWORD socket_is_write_protected(void);
void socket_cp_init(void);
DWORD socket_is_empty(void);
void card_power(BYTE on);
int chk_power(void);
BYTE stm32_spi_rw( BYTE out );
BYTE rcvr_spi (void);
BYTE wait_ready (void);
void release_spi (void);
void stm32_dma_transfer( 	BOOL receive,		/* FALSE for buff->SPI, TRUE for SPI->buff               */
		const BYTE *buff,	/* receive TRUE  : 512 byte data block to be transmitted
																						receive FALSE : Data buffer to store received data    */
		UINT btr 			/* receive TRUE  : Byte count (must be multiple of 2)
																					receive FALSE : Byte count (must be 512)              */);

void power_on (void);
void power_off (void);
BOOL rcvr_datablock (	BYTE *buff,			/* Data buffer to store received data */
		UINT btr			/* Byte count (must be multiple of 4) */);


BYTE send_cmd (	BYTE cmd,		/* Command byte */
		DWORD arg		/* Argument */);
BOOL xmit_datablock (	const BYTE *buff,	/* 512 byte data block to be transmitted */
		BYTE token			/* Data/Stop token */);

void disk_timerproc (void);

#endif /* _SD_SPI_DRV */
