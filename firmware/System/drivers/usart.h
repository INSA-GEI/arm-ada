/**
 * \file
 * \brief Pilote de liaison serie USART pour STM32
 * \author Sébastien DI MERCURIO (INSA - Toulouse,France)
 * \version 1.0
 * \date 02/05/2012
 *
 * Ce pilote fait partie des pilotes pour STM32 de l'INSA de Toulouse, France.
 * Merci de consulter le fichier LICENCE.txt au sujet des conditions de redistribution,
 * modification et copyright concernant ce pilote. Le fichier LICENCE.txt doit faire partie
 * des fichiers fournis avec ce pilote.
 *
 * Copyright (c) 2012, INSA-GEI Toulouse, France.
 * Tout droits réservés.
 */

#ifndef __USART_H__
#define __USART_H__

#include "stm32f30x.h"

/**
 * \page usart USART
 * \section USART_intro Présentation
 *
 * Le pilote USART fournit le support des liaisons serie pour l'envoi et la reception de données
 *
 * \section USART_dep Dépendances
 *  Le driver USART utilise les services des drivers suivants:
 *  - \ref clock
 *  
 *  De plus, il utilise les services de la Peripherals Library de ST, notamment ceux des modules:
 *  - stm32f10x_usart
 *  - stm32f10x_gpio
 *  - misc
 *
 * \section USART_compinfo Clefs de compilation
 * Les clefs de compilation suivantes peuvent être utilisées:
 *  - STM32F10X_MD : Configure les horloges pour un micro STM32F103
 *  - STM32F10X_CL : Configure les horloges pour un micro STM32F107
 *
 * \section USART_reference Liste des API relatif à ce pilote
 *  - \ref USART_driver
 *
 * \section USART_exemples Exemples d'utilisation
 *  Exemple: Envoi et reception de donnée sur l'UART 1
 *
 *  \code
 *  #include <stm32f10x.h>
 *  
 *  #include "clock.h"
 *  #include "usart.h"
 *  
 *  volatile int i;
 *  
 *  int main (void)
 *  {
 *  char buffer[16];
 *  	
 *  	// Configure l'UART 1 à 9600 bauds (sans parité, 1 bit de stop, pas de controle de flux), 
 *  	// et sans remap des lignes TX et RX
 *  	USART_Configure(USART1, 9600, USART_NO_REMAP);
 *  	
 *  	// Envoi 20 octets de données
 *  	USART_Send(USART1, "Envoi de qq donnees!", 20);
 *  	
 *  	// Recoit 10 octets de données
 *  	USART_Receive(USART1, buffer, 10);
 *  	
 *  	while (1)
 *  	{	
 *  		i = i+1;
 *  	}
 *  	
 *  	return 0;
 *  
 *  \endcode
 */

/**
 * @addtogroup USART_driver USART
 * @{
 */

/**
 * Definition des types de reconfiguration (remap) des entrées
 */
enum USART_REMAP_EN
{
	USART_NO_REMAP =0,    /*!< Pas de "remap" des lignes TX et RX                         */
	USART_PARTIAL_REMAP,	/*!< "Remap" partiel des lignes TX et RX (USART 3)                         */
	USART_FULL_REMAP			/*!< "Remap" complet des lignes TX et RX                         */
};

typedef enum USART_REMAP_EN USART_Remap;

/**
 * \brief Configure une liaison serie en mode bi-directionnel
 *
 * \note Tests réalisés:
 *  - Simulation: OK
 *  - Reel: A faire
 *
 * \param[in] usart Identifiant de l'uart configuré (UART1, UART2, ...)
 * \param[in] baudrate Vitesse (baudrate) desiré. 
 * \param[in] remap Indique si un remapping des lignes d'E/S est necessaire. Vaut une valeur de \ref USART_Remap
 *
 * \attention La vitesse programmé peut ne pas etre exactement celle indiquée, du aux
 * limitations des differentes horloges et prescaler
 */
void USART_Configure(USART_TypeDef* usart, u32 baudrate, USART_Remap remap);

#if (_USART_USE_DMA_ == 0)
/**
 * \brief Active les interruptions sur l'UART indiquée
 *
 * \param[in] usart Identifiant de l'uart (UART1, UART2, ...)
 */
#define USART_EnableInterrupts(usart) usart->CR1 |= USART_CR1_RXNEIE

/**
 * \brief Interdit les interruptions sur l'UART indiquée
 *
 * \param[in] usart Identifiant de l'uart (UART1, UART2, ...)
 */
#define USART_DisableInterrupts(usart) usart->CR1 &= ~(USART_CR1_RXNEIE)
#endif /* #if _USART_USE_DMA_ == 0 */

/**
 * \brief Envoi un caractere sur la liaison serie indiquée. 
 *
 * \note Tests réalisés:
 *  - Simulation: OK
 *  - Reel: A faire
 *
 * \param[in] usart Identifiant de l'uart (UART1, UART2, ...)
 * \param[in] data Caractere à envoyer
 * \return Le nombre d'octet effectivement transferé dans le buffer de transmission
 *
 * \attention La fonction n'est pas bloquante, sauf si le buffer interne de transmission est plein
 */
int USART_Send(USART_TypeDef* usart, char data);

/**
 * \brief Recoit un caractere sur la liaison serie indiquée. 
 *
 * \note Tests réalisés:
 *  - Simulation: OK
 *  - Reel: A faire
 *
 * \param[in] usart Identifiant de l'uart (UART1, UART2, ...)
 * \param[in] data Pointeur sur le caractere à recevoir
 * \return Le nombre d'octet effectivement lu à partir du buffer de reception
 *
 * \attention La fonction est bloquante tant que suffisament de donnée n'ont pas été recue.
 */
int USART_Receive(USART_TypeDef* usart, char *data);

/**
 * \brief Retourne le nombre d'octet dans le buffer de reception et pas encore recuperé grace à la fonction \ref USART_Receive
 *
 * \note Tests réalisés:
 *  - Simulation: OK
 *  - Reel: A faire
 *
 * \param[in] usart Identifiant de l'uart (UART1, UART2, ...)
 * \return Nombre d'octet present dans le buffer de reception
 */
int USART_GetRXBufferLength(USART_TypeDef* usart);

/**
 * \brief Retourne le nombre d'octet dans le buffer de transmission et en attente d'envoi sur la liaison serie
 *
 * \note Tests réalisés:
 *  - Simulation: OK
 *  - Reel: A faire
 *
 * \param[in] usart Identifiant de l'uart (UART1, UART2, ...)
 * \return Nombre d'octet present dans le buffer de transmission
 */
int USART_GetTXBufferLength(USART_TypeDef* usart);

/**
 * @}
 */

#endif /* __USART_H__ */
