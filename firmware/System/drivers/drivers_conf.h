//*** <<< Use Configuration Wizard in Context Menu >>> ***

/**
 * \file
 * \brief Fichier de configuration des pilote STM32
 * \author Pascal ACCO (INSA - Toulouse,France)
 * \author Sébastien DI MERCURIO (INSA - Toulouse,France)
 * \version 1.0
 * \date 17/02/2012
 *
 * Ce fichier fait partie des pilotes pour STM32 de l'INSA de Toulouse, France.
 * Merci de consulter le fichier LICENCE.txt au sujet des conditions de redistribution,
 * modification et copyright concernant ce pilote. Le fichier LICENCE.txt doit faire partie
 * des fichiers fournis avec ce pilote.
 *
 * Copyright (c) 2012, INSA-GEI Toulouse, France.
 * Tout droits réservés.
 */

#ifndef __DRIVERS_CONF_H__
#define __DRIVERS_CONF_H__

/**
 * \page drivers_conf Configuration des pilotes
 * \section drivers_conf_intro Présentation
 *
 * Le fichier de configuration des pilotes sert configurer, à la compilation, les pilotes de la bibliothèque STM32. Cette
 * configuration concerne essentiellement des points tels:
 *  - Le matériel sur lequel vont s'excuter les pilotes (le modèle de MCU)
 *  - Le choix entre fonctionnement par interruption ou DMA
 *  - La taille éventuelle de buffer
 *  - Les fréquences d'horloge
 *  .
 *
 * \section drivers_conf_compinfo Clefs de compilation
 * Les clefs de compilation suivantes peuvent être utilisées:
 *  - STM32F10X_MD : Compile les pilotes de la bibliothèque en ciblant les micros de la famille medium density (de 64 K à 256 K de flash, comme le STM32F103)
 *  - STM32F10X_CL : Compile les pilotes de la bibliothèque en ciblant les micros de la famille Connectivity Line (STM32F107 notamment)
 *  .
 * Par défaut, si aucune de ces clefs n'est défini, une erreur est générée
 *
 * \section drivers_conf_reference Liste des options de configuration
 *  - \ref drivers_conf
 */

/**
 * @addtogroup drivers_conf Configuration des pilotes
 * @{
 */

/* 
 * Définition de la cible
 *
 * Activez l'une des clefs de compilation suivantes ou passez la sur la ligne de
 * commande du compilateur (par exemple -DSTM32F10X_MD)
 */
//#define STM32F10X_MD
//#define STM32F10X_CL


#if !defined(STM32F30X)
	#error "Aucune cible definie, selectionne soit STM32F10X_CL, soit STM32F10X_MD, soit STM32F10X_LD "
#endif

#include "stm32f30x.h"


// <h> Peripheriques du STM32

/* Configuration for USART -----------------------------------------------------*/

	/** @addtogroup conf_USART Configuration du pilote USART
	 * @{
	 */

// <e.0>   USART 
/**
 * \def _USE_USART_
 * \brief Inclu le driver d'USART
 *
 * _USE_USART=0: Le driver n'est pas compilé
 * _USE_USART=1: Le driver est compilé et inclu dans le build final
 */
#define _USE_USART_ 1

/**
 * \def _USART_BUFFER_LENGTH_
 * \brief Defini la taille des buffers pour la reception et la transmission
 */
//     <o.0..9>   Taille des buffers (_USART_BUFFER_LENGTH_)  <1-512>
#define _USART_BUFFER_LENGTH_ 80

/**
 * \def USART1_IRQ_LEVEL
 * Configure les niveaux de priorité des IT de l'UART 1 (de 0 à 15)
 */
//     <o.0..4>   Niveau d'IT USART1 (USART1_IRQ_LEVEL) <0-15>
#define USART1_IRQ_LEVEL	4

/**
 * \def USART2_IRQ_LEVEL
 * Configure les niveaux de priorité des IT de l'UART 2 (de 0 à 15)
 */
//     <o.0..4>   Niveau d'IT USART2 (USART2_IRQ_LEVEL) <0-15>
#define USART2_IRQ_LEVEL	2

/**
 * \def USART3_IRQ_LEVEL
 * Configure les niveaux de priorité des IT de l'UART 3 (de 0 à 15)
 */
//     <o.0..4>   Niveau d'IT USART3 (USART3_IRQ_LEVEL) <0-15>
#define USART3_IRQ_LEVEL	12
// </e>

	/**
	 * @}
	 */

/* Configuration for I2C -----------------------------------------------------*/

	/** @addtogroup conf_I2C Configuration du pilote I2C
	 * @{
	 */
	 
//  <e.0> I2C 
/**
 * \def _USE_I2C_
 * \brief Inclu le driver I2C
 *
 * _USE_I2C_=0: Le driver n'est pas compilé
 * _USE_I2C_=1: Le driver est compilé et inclu dans le build final
 */
#define _USE_I2C_ 0

/**
 * \def _I2C_USE_DMA_
 * \brief Utilise la DMA lors des transferts
 *
 * _I2C_USE_DMA_ =1: Le driver I2C utilise la DMA lors des transferts
 * _I2C_USE_DMA_ =0: Le driver I2C utilise fonctionne en IRQ
 */
//     <o.0..1>   DMA ou IRQ   <0=> IRQ    <1=> DMA
#define _I2C_USE_DMA_ 0

/**
 * \def I2C1_IRQ_LEVEL
 * Configure les niveaux de priorité des IT de l'I2C1
 */
//     <o.0..4>   Niveau d'IT I2C1  <0-15>
#define I2C1_IRQ_LEVEL	10

/**
 * \def I2C2_IRQ_LEVEL
 * Configure les niveaux de priorité des IT de l'I2C2
 */
//     <o.0..4>   Niveau d'IT I2C2  <0-15>
#define I2C2_IRQ_LEVEL	11

// </e>
	/**
	 * @}
	 */

/* Configuration for SPI -----------------------------------------------------*/

	/** @addtogroup conf_SPI Configuration du pilote SPI
	 * @{
	 */

//  <e.0> SPI
/**
 * \def _USE_SPI_
 * \brief Inclu le driver SPI
 *
 * _USE_SPI_=0: Le driver n'est pas compilé
 * _USE_SPI_=1: Le driver est compilé et inclu dans le build final
 */
#define _USE_SPI_ 0

/**
 * \def _SPI_USE_DMA_
 * \brief Utilise la DMA lors des transferts
 *
 * _SPI_USE_DMA_ =1: Le driver SPI utilise la DMA lors des transferts
 * _SPI_USE_DMA_ =0: Le driver SPI utilise fonctionne en IRQ
 */
//     <o.0..1>   DMA ou IRQ   <0=> IRQ    <1=> DMA
#define _SPI_USE_DMA_ 0

/**
 * \def SPI1_IRQ_LEVEL
 * Configure les niveaux de priorité des IT du SPI 1
 */
//     <o.0..4>   Niveau d'IT SPI1  <0-15>
#define SPI1_IRQ_LEVEL	10

/**
 * \def SPI2_IRQ_LEVEL
 * Configure les niveaux de priorité des IT du SPI 2
 */
//     <o.0..4>   Niveau d'IT SPI2  <0-15>
#define SPI2_IRQ_LEVEL	11

/**
 * \def SPI3_IRQ_LEVEL
 * Configure les niveaux de priorité des IT du SPI 3
 */
//     <o.0..4>   Niveau d'IT SPI3  <0-15>
#define SPI3_IRQ_LEVEL	12

// </e>
	/**
	 * @}
	 */

/* Configuration for TIMER -----------------------------------------------------*/

	/** @addtogroup conf_TIM Configuration des timers
	 * @{
	 */

//  <e.0> TIMERS
/**
 * \def _USE_TIMERS_
 * \brief Inclu le driver de Timer 
 *
 * _USE_TIMERS_=0: Le driver n'est pas compilé
 * _USE_TIMERS_=1: Le driver est compilé et inclu dans le build final
 */
#define _USE_TIMERS_ 0

//  <q.0> Inclus le SYSTICK
/**
 * \def _USE_SYSTICK_
 * \brief Inclu la gestion du systick par le driver de Timer 
 *
 * _USE_SYSTICK_=0: La gestion du Systick n'est pas incluse dans le driver
 * _USE_SYSTICK_=1: La gestion du Systick est incluse dans le driver
 */
#define _USE_SYSTICK_ 1

// </e>
	/**
	 * @}
	 */

/* Configuration for ADC -----------------------------------------------------*/

	/** @addtogroup conf_ADC Configuration des ADC
	 * @{
	 */

//  <e.0> ADC
/**
 * \def _USE_ADC_
 * \brief Inclu le driver des ADC
 *
 * _USE_ADC_=0: Le driver n'est pas compilé
 * _USE_ADC_=1: Le driver est compilé et inclu dans le build final
 */
#define _USE_ADC_ 0

// </e>
	/**
	 * @}
	 */

/* Configuration for DAC -----------------------------------------------------*/

	/** @addtogroup conf_DAC Configuration des DAC
	 * @{
	 */

//  <e.0> DAC
/**
 * \def _USE_DAC_
 * \brief Inclu le driver des DAC
 *
 * _USE_DAC_=0: Le driver n'est pas compilé
 * _USE_DAC_=1: Le driver est compilé et inclu dans le build final
 */
#define _USE_DAC_ 0

// </e>
	/**
	 * @}
	 */
	 
/* Configuration for CAN -----------------------------------------------------*/

	/** @addtogroup conf_CAN Configuration du bus CAN
	 * @{
	 */

//  <e.0> CAN bus
/**
 * \def _USE_CAN_
 * \brief Inclu le driver de bus CAN
 *
 * _USE_CAN_=0: Le driver n'est pas compilé
 * _USE_CAN_=1: Le driver est compilé et inclu dans le build final
 */
#define _USE_CAN_ 0

// </e>
	/**
	 * @}
	 */

//</h>

/* Configuration des peripheriques externes au MCU */

	/** @addtogroup conf_external_devices Configuration des peripheriques externes au MCU
	 * @{
	 */

// <h> Peripheriques externes au MCU

/* Configuration de l'ecran LCD */
	/** @addtogroup conf_LCD Configuration du pilote LCD
	 * @{
	 */

// <h> Ecran LCD
/**
 * \def _LCD_USE_BUSY_STATUS_
 * \brief L'ecran LCD utilise la ligne "busy".
 *
 * La définition de cette macro permet de faire utiliser par le pilote LCD l'etat de la ligne
 * "busy" dans la boucle d'attente.
 * Les valeurs possibles sont 0 = désactivé ou 1 = activé
 */
// <o.0> Utilise l'etat du flag BUSY [_LCD_USE_BUSY_STATUS_] <0=> Attente sur tempo    <1=> Attente sur flag BUSY
// <i> Tempo base sur le flag BUSY ou sur une tempo logicielle
#define _LCD_USE_BUSY_STATUS_ 1

/**
 * \def _LCD_SIMU_
 * \brief L'ecran LCD est preparé pour la simu.
 *
 * La mise a 1 de cette macro permet de ne pas faire de boucle d'attente, idéal pour la simu.
 * Les valeurs possibles sont 0 = désactivé (Mode réél) ou 1 = activé (mode simu)
 */
// <o.0> Compile pour le simulateur [_LCD_SIMU_] <0=> Reel (tempo)    <1=> Simu (sans tempo)
// <i> Permet de ne pas faire de boucle d'attente (idéal pour la simu).
#define _LCD_SIMU_ 0

/*
 * Configuration des lignes d'E/S liées à l'ecran
 *
 * Attention: toutes les lignes doivent etre sur le meme port
 */

/* PINS:
   - DB4 = PC3
   - DB5 = PC2
   - DB6 = PC1
   - DB7 = PC0
   - E   = PC10
   - RW  = PC11
   - RS  = PC12
 */
#define LCD_PORT						GPIOC
#define LCD_PIN_E       		GPIO_Pin_10
#define LCD_PIN_RW      		GPIO_Pin_11
#define LCD_PIN_RS      		GPIO_Pin_12
#define LCD_PINS_D0					GPIO_Pin_0
#define LCD_PINS_D1					GPIO_Pin_1
#define LCD_PINS_D2					GPIO_Pin_2
#define LCD_PINS_D3					GPIO_Pin_3
#define LCD_PINS_DATA_BASE  0

/**
 * \def LCD_DELAY_2N
 * \brief Constante d'attente
 *
 * Cette constante sert dans la boucle d'attente "delay". Plus le processeur va vite, plus la valeur doit être grande.
 * Cette constante n'est pas utilisé si l'ecran LCD est configuré pour utiliser l'etat du flag BUSY (_LCD_USE_BUSY_STATUS_=1) ou 
 * compilé pour etre utilisé en simu (_LCD_SIMU_=1)
 */
// <o.0..3> Valeur de tempo [LCD_DELAY_2N] <0-7>
// <i> Valeur de 0 (processeur lent) a 7 (processeur rapide). 
#define LCD_DELAY_2N	0

/**
 * \def LCD_WIDTH
 * \brief Largeur d'écran
 *
 * Cette constante indique la longueur d'une ligne en caractères affichables.
 */
// <o.0..6> Largueur d'ecran (en caractere) [LCD_WIDTH] <8-64>
// <i> Largueur de l'ecran, exprime en caractere. 
#define LCD_WIDTH		16               /* Width (in characters)              */

/**
 * \def LCD_HEIGHT
 * \brief Hauteur d'écran
 *
 * Cette constante indique le nombre de lignes affichables.
 */
// <o.0..4> Hauteur d'ecran (en ligne) [LCD_HEIGHT] <1-8>
// <i> Hauteur de l'ecran, exprime en ligne. 
#define LCD_HEIGHT     	2                /* Height (in lines)                  */

// </h>
	/**
	 * @}
	 */

// </h>

	/**
	 * @}
	 */
	 
/**
 * @}
 */
 
// <<< Use Configuration Wizard in Context Menu >>>

#endif /* __DRIVERS_CONF_H__ */
