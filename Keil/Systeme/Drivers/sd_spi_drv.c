/*-----------------------------------------------------------------------*/
/* Low level disk I/O module skeleton for FatFs     (C)ChaN, 2012        */
/*-----------------------------------------------------------------------*/
/* If a working storage control module is available, it should be        */
/* attached to the FatFs via a glue function rather than modifying it.   */
/* This is an example of glue functions to attach various exsisting      */
/* storage control module to the FatFs module with a defined API.        */
/*-----------------------------------------------------------------------*/

#include <stm32f30x.h>
#include "sd_spi_drv.h"		

/*--------------------------------------------------------------------------

   Module Private Functions and Variables

---------------------------------------------------------------------------*/

const DWORD socket_state_mask_cp = (1 << 0);
const DWORD socket_state_mask_wp = (1 << 1);

volatile DSTATUS Stat = STA_NOINIT;	/* Disk status */

volatile DWORD Timer1, Timer2;	/* 100Hz decrement timers */

BYTE CardType;			/* Card type flags */

void interface_speed( speed_setting speed )
{
	DWORD tmp;

	tmp = SPI_SD->CR1;
	if ( speed == INTERFACE_SLOW ) {
		/* Set slow clock (100k-400k) */
		tmp = ( tmp | SPI_BaudRatePrescaler_256 );
	} else {
		/* Set fast clock (depends on the CSD) */
		tmp = ( tmp & ~SPI_BaudRatePrescaler_256 ) | SPI_BaudRatePrescaler_SPI_SD;
	}
	SPI_SD->CR1 = tmp;
}

#if SOCKET_WP_CONNECTED
/* Socket's Write-Protection Pin: high = write-protected, low = writable */

void socket_wp_init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

	/* Configure I/O for write-protect */
	RCC_APB2PeriphClockCmd(RCC_APBxPeriph_GPIO_WP, ENABLE);
	GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_WP;
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_WP;
	GPIO_Init(GPIO_WP, &GPIO_InitStructure);
}

DWORD socket_is_write_protected(void)
{
	return ( GPIO_ReadInputData(GPIO_WP) & GPIO_Pin_WP ) ? socket_state_mask_wp : 0;
}

#else

void socket_wp_init(void)
{
	return;
}

DWORD socket_is_write_protected(void)
{
	return 0; /* fake not protected */
}

#endif /* SOCKET_WP_CONNECTED */


#if SOCKET_CP_CONNECTED
/* Socket's Card-Present Pin: high = socket empty, low = card inserted */

void socket_cp_init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

	/* Configure I/O for card-present */
	RCC_APB2PeriphClockCmd(RCC_AHBPeriph_GPIO_CP, ENABLE);
	GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_CP;
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_CP;
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;
	GPIO_Init(GPIO_CP, &GPIO_InitStructure);
}

DWORD socket_is_empty(void)
{
	return ( GPIO_ReadInputData(GPIO_CP) & GPIO_Pin_CP ) ?  socket_state_mask_cp: FALSE;
}

#else

void socket_cp_init(void)
{
	return;
}

DWORD socket_is_empty(void)
{
	return 0; /* fake inserted */
}

#endif /* SOCKET_CP_CONNECTED */


#if CARD_SUPPLY_SWITCHABLE

void card_power(BOOL on)		/* switch FET for card-socket VCC */
{
	GPIO_InitTypeDef GPIO_InitStructure;

	/* Turn on GPIO for power-control pin connected to FET's gate */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIO_PWR, ENABLE);
	/* Configure I/O for Power FET */
	GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_PWR;
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_PWR;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIO_PWR, &GPIO_InitStructure);
	if (on) {
		GPIO_ResetBits(GPIO_PWR, GPIO_Pin_PWR);
	} else {
		/* Chip select internal pull-down (to avoid parasite powering) */
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_CS;
		GPIO_Init(GPIO_CS, &GPIO_InitStructure);

		GPIO_SetBits(GPIO_PWR, GPIO_Pin_PWR);
	}
}

#if (STM32_SD_DISK_IOCTRL == 1)
int chk_power(void)		/* Socket power state: 0=off, 1=on */
{
	if ( GPIO_ReadOutputDataBit(GPIO_PWR, GPIO_Pin_PWR) == Bit_SET ) {
		return 0;
	} else {
		return 1;
	}
}
#endif

#else

void card_power(BYTE on)
{
	on=on;
}

#if (STM32_SD_DISK_IOCTRL == 1)
int chk_power(void)
{
	return 1; /* fake powered */
}
#endif

#endif /* CARD_SUPPLY_SWITCHABLE */


/*-----------------------------------------------------------------------*/
/* Transmit/Receive a byte to MMC via SPI  (Platform dependent)          */
/*-----------------------------------------------------------------------*/
BYTE stm32_spi_rw( BYTE out )
{
	/* Loop while DR register in not empty */
	while (SPI_I2S_GetFlagStatus(SPI_SD, SPI_I2S_FLAG_TXE) == RESET) { ; }

	/* Send byte through the SPI peripheral */
	SPI_SendData8(SPI_SD, out);

	/* Wait to receive a byte */
	while (SPI_I2S_GetFlagStatus(SPI_SD, /*SPI_I2S_FLAG_RXNE*/SPI_I2S_FLAG_TXE) == RESET) { ; }

	/* Return the byte read from the SPI bus */
	return SPI_ReceiveData8(SPI_SD);
}

/*-----------------------------------------------------------------------*/
/* Receive a byte from MMC via SPI  (Platform dependent)                 */
/*-----------------------------------------------------------------------*/

BYTE rcvr_spi (void)
{
	//return stm32_spi_rw(0xff);
	return stm32_spi_rw(0xFF);
}

/*-----------------------------------------------------------------------*/
/* Wait for card ready                                                   */
/*-----------------------------------------------------------------------*/

BYTE wait_ready (void)
{
	BYTE res;


	Timer2 = 50;	/* Wait for ready in timeout of 500ms */
	rcvr_spi();
	do
		res = rcvr_spi();
	while ((res != 0xFF) && Timer2);

	return res;
}

/*-----------------------------------------------------------------------*/
/* Deselect the card and release SPI bus                                 */
/*-----------------------------------------------------------------------*/

void release_spi (void)
{
	DESELECT();
	rcvr_spi();
}

#ifdef STM32_SD_USE_DMA
/*-----------------------------------------------------------------------*/
/* Transmit/Receive Block using DMA (Platform dependent. STM32 here)     */
/*-----------------------------------------------------------------------*/
void stm32_dma_transfer(
	BOOL receive,		/* FALSE for buff->SPI, TRUE for SPI->buff               */
	const BYTE *buff,	/* receive TRUE  : 512 byte data block to be transmitted
						   receive FALSE : Data buffer to store received data    */
	UINT btr 			/* receive TRUE  : Byte count (must be multiple of 2)
						   receive FALSE : Byte count (must be 512)              */
)
{
	DMA_InitTypeDef DMA_InitStructure;
	WORD rw_workbyte[] = { 0xffff };

	/* shared DMA configuration values */
	DMA_InitStructure.DMA_PeripheralBaseAddr = (DWORD)(&(SPI_SD->DR));
	DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
	DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
	DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
	DMA_InitStructure.DMA_BufferSize = btr;
	DMA_InitStructure.DMA_Mode = DMA_Mode_Normal;
	DMA_InitStructure.DMA_Priority = DMA_Priority_VeryHigh;
	DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;

	DMA_DeInit(DMA_Channel_SPI_SD_RX);
	DMA_DeInit(DMA_Channel_SPI_SD_TX);

	if ( receive ) {

		/* DMA1 channel2 configuration SPI1 RX ---------------------------------------------*/
		/* DMA1 channel4 configuration SPI2 RX ---------------------------------------------*/
		DMA_InitStructure.DMA_MemoryBaseAddr = (DWORD)buff;
		DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;
		DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
		DMA_Init(DMA_Channel_SPI_SD_RX, &DMA_InitStructure);

		/* DMA1 channel3 configuration SPI1 TX ---------------------------------------------*/
		/* DMA1 channel5 configuration SPI2 TX ---------------------------------------------*/
		DMA_InitStructure.DMA_MemoryBaseAddr = (DWORD)rw_workbyte;
		DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralDST;
		DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Disable;
		DMA_Init(DMA_Channel_SPI_SD_TX, &DMA_InitStructure);

	} else {

#if _FS_READONLY == 0
		/* DMA1 channel2 configuration SPI1 RX ---------------------------------------------*/
		/* DMA1 channel4 configuration SPI2 RX ---------------------------------------------*/
		DMA_InitStructure.DMA_MemoryBaseAddr = (DWORD)rw_workbyte;
		DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;
		DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Disable;
		DMA_Init(DMA_Channel_SPI_SD_RX, &DMA_InitStructure);

		/* DMA1 channel3 configuration SPI1 TX ---------------------------------------------*/
		/* DMA1 channel5 configuration SPI2 TX ---------------------------------------------*/
		DMA_InitStructure.DMA_MemoryBaseAddr = (DWORD)buff;
		DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralDST;
		DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
		DMA_Init(DMA_Channel_SPI_SD_TX, &DMA_InitStructure);
#endif

	}

	/* Enable DMA RX Channel */
	DMA_Cmd(DMA_Channel_SPI_SD_RX, ENABLE);
	/* Enable DMA TX Channel */
	DMA_Cmd(DMA_Channel_SPI_SD_TX, ENABLE);

	/* Enable SPI TX/RX request */
	SPI_I2S_DMACmd(SPI_SD, SPI_I2S_DMAReq_Rx | SPI_I2S_DMAReq_Tx, ENABLE);

	/* Wait until DMA1_Channel 3 Transfer Complete */
	/// not needed: while (DMA_GetFlagStatus(DMA_FLAG_SPI_SD_TC_TX) == RESET) { ; }
	/* Wait until DMA1_Channel 2 Receive Complete */
	while (DMA_GetFlagStatus(DMA_FLAG_SPI_SD_TC_RX) == RESET) { ; }
	// same w/o function-call:
	// while ( ( ( DMA1->ISR ) & DMA_FLAG_SPI_SD_TC_RX ) == RESET ) { ; }

	/* Disable DMA RX Channel */
	DMA_Cmd(DMA_Channel_SPI_SD_RX, DISABLE);
	/* Disable DMA TX Channel */
	DMA_Cmd(DMA_Channel_SPI_SD_TX, DISABLE);

	/* Disable SPI RX/TX request */
	SPI_I2S_DMACmd(SPI_SD, SPI_I2S_DMAReq_Rx | SPI_I2S_DMAReq_Tx, DISABLE);
}
#endif /* STM32_SD_USE_DMA */


/*-----------------------------------------------------------------------*/
/* Power Control and interface-initialization (Platform dependent)       */
/*-----------------------------------------------------------------------*/

void power_on (void)
{
	SPI_InitTypeDef  SPI_InitStructure;
	GPIO_InitTypeDef GPIO_InitStructure;
	volatile BYTE dummyread;

	/* Enable GPIO clock for CS */
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIO_CS, ENABLE);
	/* Enable SPI clock, SPI1: APB2, SPI2: APB1 */
	RCC_APBPeriphClockCmd_SPI_SD(RCC_APBPeriph_SPI_SD, ENABLE);

	card_power(1);
	socket_cp_init();
	socket_wp_init();

	for (Timer1 = 25; Timer1; );	/* Wait for 250ms */

	/* Configure I/O for Flash Chip select */
	GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_CS;
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(GPIO_CS, &GPIO_InitStructure);

	/* De-select the Card: Chip Select high */
	DESELECT();

	/* Configure SPI pins: SCK and MOSI with default alternate function (not re-mapped) push-pull */
	GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_SPI_SD_SCK ;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(GPIO_SPI_SD, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_SPI_SD_MOSI ;
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIO_SPI_SD, &GPIO_InitStructure);	
	
	/* Configure MISO as Input with internal pull-up */
	GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_SPI_SD_MISO;
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_IN;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIO_SPI_SD, &GPIO_InitStructure);

  /* Connect PXx to SD_SPI_SCK */
  GPIO_PinAFConfig(GPIO_SPI_SD, GPIO_PinSource13, GPIO_AF_5);

  /* Connect PXx to SD_SPI_MISO */
  GPIO_PinAFConfig(GPIO_SPI_SD, GPIO_PinSource14, GPIO_AF_5); 

  /* Connect PXx to SD_SPI_MOSI */
  GPIO_PinAFConfig(GPIO_SPI_SD, GPIO_PinSource15, GPIO_AF_5);  

	/* SPI configuration */
	SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;
	SPI_InitStructure.SPI_Mode = SPI_Mode_Master;
	SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;
	SPI_InitStructure.SPI_CPOL = SPI_CPOL_High;
	SPI_InitStructure.SPI_CPHA = SPI_CPHA_2Edge;
	SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;
	SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_256; // 72000kHz/256=281kHz < 400kHz
	SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;
	SPI_InitStructure.SPI_CRCPolynomial = 7;

	SPI_Init(SPI_SD, &SPI_InitStructure);
	SPI_RxFIFOThresholdConfig(SPI_SD, SPI_RxFIFOThreshold_QF);
	SPI_CalculateCRC(SPI_SD, DISABLE);
	SPI_Cmd(SPI_SD, ENABLE);

	/* drain SPI */
	while (SPI_I2S_GetFlagStatus(SPI_SD, SPI_I2S_FLAG_TXE) == RESET) { ; }
	dummyread = SPI_ReceiveData8(SPI_SD);

#ifdef STM32_SD_USE_DMA
	/* enable DMA clock */
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);
#endif
}

void power_off (void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

	if (!(Stat & STA_NOINIT)) {
		SELECT();
		wait_ready();
		release_spi();
	}

	SPI_I2S_DeInit(SPI_SD);
	SPI_Cmd(SPI_SD, DISABLE);
	RCC_APBPeriphClockCmd_SPI_SD(RCC_APBPeriph_SPI_SD, DISABLE);

	/* All SPI-Pins to input with weak internal pull-downs */
	GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_SPI_SD_SCK | GPIO_Pin_SPI_SD_MISO | GPIO_Pin_SPI_SD_MOSI;
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_IN;
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;
	GPIO_Init(GPIO_SPI_SD, &GPIO_InitStructure);

	card_power(0);

	Stat |= STA_NOINIT;		/* Set STA_NOINIT */
}


/*-----------------------------------------------------------------------*/
/* Receive a data packet from MMC                                        */
/*-----------------------------------------------------------------------*/

BOOL rcvr_datablock (
	BYTE *buff,			/* Data buffer to store received data */
	UINT btr			/* Byte count (must be multiple of 4) */
)
{
	BYTE token;


	Timer1 = 10;
	do {							/* Wait for data packet in timeout of 100ms */
		token = rcvr_spi();
	} while ((token == 0xFF) && Timer1);
	if(token != 0xFE) return FALSE;	/* If not valid data token, return with error */

#ifdef STM32_SD_USE_DMA
	stm32_dma_transfer( TRUE, buff, btr );
#else
	do {							/* Receive the data block into buffer */
		rcvr_spi_m(buff++);
		rcvr_spi_m(buff++);
		rcvr_spi_m(buff++);
		rcvr_spi_m(buff++);
	} while (btr -= 4);
#endif /* STM32_SD_USE_DMA */

	rcvr_spi();						/* Discard CRC */
	rcvr_spi();

	return TRUE;					/* Return with success */
}



/*-----------------------------------------------------------------------*/
/* Send a data packet to MMC                                             */
/*-----------------------------------------------------------------------*/

#if _FS_READONLY == 0
BOOL xmit_datablock (
	const BYTE *buff,	/* 512 byte data block to be transmitted */
	BYTE token			/* Data/Stop token */
)
{
	BYTE resp;
#ifndef STM32_SD_USE_DMA
	BYTE wc;
#endif

	if (wait_ready() != 0xFF) return FALSE;

	xmit_spi(token);					/* transmit data token */
	if (token != 0xFD) {	/* Is data token */

#ifdef STM32_SD_USE_DMA
		stm32_dma_transfer( FALSE, buff, 512 );
#else
		wc = 0;
		do {							/* transmit the 512 byte data block to MMC */
			xmit_spi(*buff++);
			xmit_spi(*buff++);
		} while (--wc);
#endif /* STM32_SD_USE_DMA */

		xmit_spi(0xFF);					/* CRC (Dummy) */
		xmit_spi(0xFF);
		resp = rcvr_spi();				/* Receive data response */
		if ((resp & 0x1F) != 0x05)		/* If not accepted, return with error */
			return FALSE;
	}

	return TRUE;
}
#endif /* _READONLY */

/*-----------------------------------------------------------------------*/
/* Send a command packet to MMC                                          */
/*-----------------------------------------------------------------------*/

BYTE send_cmd (
	BYTE cmd,		/* Command byte */
	DWORD arg		/* Argument */
)
{
	BYTE n, res;


	if (cmd & 0x80) {	/* ACMD<n> is the command sequence of CMD55-CMD<n> */
		cmd &= 0x7F;
		res = send_cmd(CMD55, 0);
		if (res > 1) return res;
	}

	/* Select the card and wait for ready */
	DESELECT();
	SELECT();
	if (wait_ready() != 0xFF) {
		return 0xFF;
	}

	/* Send command packet */
	xmit_spi(cmd);						/* Start + Command index */
	xmit_spi((BYTE)(arg >> 24));		/* Argument[31..24] */
	xmit_spi((BYTE)(arg >> 16));		/* Argument[23..16] */
	xmit_spi((BYTE)(arg >> 8));			/* Argument[15..8] */
	xmit_spi((BYTE)arg);				/* Argument[7..0] */
	n = 0x01;							/* Dummy CRC + Stop */
	if (cmd == CMD0) n = 0x95;			/* Valid CRC for CMD0(0) */
	if (cmd == CMD8) n = 0x87;			/* Valid CRC for CMD8(0x1AA) */
	xmit_spi(n);

	/* Receive command response */
	if (cmd == CMD12) rcvr_spi();		/* Skip a stuff byte when stop reading */

	n = 10;								/* Wait for a valid response in timeout of 10 attempts */
	do
		res = rcvr_spi();
	while ((res & 0x80) && --n);

	return res;			/* Return with the response value */
}

/*-----------------------------------------------------------------------*/
/* Device Timer Interrupt Procedure  (Platform dependent)                */
/*-----------------------------------------------------------------------*/
/* This function must be called in period of 10ms                        */

void disk_timerproc (void)
{
	static DWORD pv;
	DWORD ns;
	BYTE n, s;


	n = Timer1;                /* 100Hz decrement timers */
	if (n) Timer1 = --n;
	n = Timer2;
	if (n) Timer2 = --n;

	ns = pv;
	pv = socket_is_empty() | socket_is_write_protected();	/* Sample socket switch */

	if (ns == pv) {                         /* Have contacts stabled? */
		s = Stat;

		if (pv & socket_state_mask_wp)      /* WP is H (write protected) */
			s |= STA_PROTECT;
		else                                /* WP is L (write enabled) */
			s &= ~STA_PROTECT;

		if (pv & socket_state_mask_cp)      /* INS = H (Socket empty) */
			s |= (STA_NODISK | STA_NOINIT);
		else                                /* INS = L (Card inserted) */
			s &= ~STA_NODISK;

		Stat = s;
	}
}

