/**
 * @file usart2_init.h
 * @brief STM32 USART2 register-level initialization driver (compile-time, bare-metal, no HAL/LL)
 * @author Abdusselam
 * @license MIT
 */

#ifndef USART2_INIT_H_
#define USART2_INIT_H_

#define USART2_ID    			2
#define SELECTED_USART2_ID   	USART2_ID
/*--- PORT SELECTION IDs START ---*/
#define USART2_PORT_A_ID    1			//A PINS
#define USART2_PORT_B_ID    2			//B PINS
#define USART2_PORT_C_ID   	3			//C PINS
#define USART2_PORT_D_ID    4			//D PINS
#define USART2_PORT_E_ID    5			//E PINS
#define USART2_PORT_F_ID    6			//F PINS
#define USART2_PORT_G_ID    7			//G PINS
#define USART2_PORT_H_ID   	8			//H PINS
#define USART2_PORT_I_ID    9			//I PINS
#define USART2_PORT_J_ID    10			//J PINS
#define USART2_PORT_K_ID    11			//K PINS
/*--- PORT SELECTION IDs END ---*/



/*--- ------------------- ------------------------------------------------------------*///
/*--- USER SETTINGS START ------------------------------------------------------------*///
/*--- ------------------- ------------------------------------------------------------*///
//library:																				//
#include "stm32f3xx.h"			//Change this header with your specific...				//
								//...STM32 series CMSIS header (e.g., f1xx, f4xx)		//
																						//
//pin settings:																			//
#define USART2_TX_SELECTED_PORT_ID		USART2_PORT_B_ID //exp: if PA2, USART2_PORT_A_ID//
#define USART2_RX_SELECTED_PORT_ID		USART2_PORT_B_ID //exp: if PA2, USART2_PORT_A_ID//
#define USART2_TX_PIN 					3				 //exp: if PA2, 2				//
#define USART2_RX_PIN 					4				 //exp: if PA3,	3	 			//
																						//
// IMPORTANT: Alternate Function (AF) number varies by MCU model.                       //
// For STM32F302R8: USART2 is AF7. Check your MCU's Datasheet (Table: Alternate Funct.) //
#define USART2_AF_VALUE					7				//AF NUMBER						//
																						//
//usart settings:																		//
#define USART2_BUS_CLOCK_HZ    			8000000U			//BUS CLOCK SPEED (HZ)		//
#define USART2_TARGET_BAUDRATE  		9600U				//TARGET BAUDRATE (HZ)		//
																						//
/*--- ----------------- --------------------------------------------------------------*///
/*--- USER SETTINGS END --------------------------------------------------------------*///
/*--- ----------------- --------------------------------------------------------------*///



/* --- USART_TX_PORT SELECTION --- */
#if (USART2_TX_SELECTED_PORT_ID 	== USART2_PORT_A_ID)	&& defined(GPIOA)
	#define USART2_TX_PORT    GPIOA
#elif (USART2_TX_SELECTED_PORT_ID == USART2_PORT_B_ID)	&& defined(GPIOB)
	#define USART2_TX_PORT    GPIOB
#elif (USART2_TX_SELECTED_PORT_ID == USART2_PORT_C_ID)	&& defined(GPIOC)
	#define USART2_TX_PORT    GPIOC
#elif (USART2_TX_SELECTED_PORT_ID == USART2_PORT_D_ID)	&& defined(GPIOD)
	#define USART2_TX_PORT    GPIOD
#elif (USART2_TX_SELECTED_PORT_ID == USART2_PORT_E_ID)	&& defined(GPIOE)
	#define USART2_TX_PORT    GPIOE
#elif (USART2_TX_SELECTED_PORT_ID == USART2_PORT_F_ID)	&& defined(GPIOF)
	#define USART2_TX_PORT    GPIOF
#elif (USART2_TX_SELECTED_PORT_ID == USART2_PORT_G_ID)	&& defined(GPIOG)
	#define USART2_TX_PORT    GPIOG
#elif (USART2_TX_SELECTED_PORT_ID == USART2_PORT_H_ID)	&& defined(GPIOH)
	#define USART2_TX_PORT    GPIOH
#elif (USART2_TX_SELECTED_PORT_ID == USART2_PORT_I_ID)	&& defined(GPIOI)
	#define USART2_TX_PORT    GPIOI
#elif (USART2_TX_SELECTED_PORT_ID == USART2_PORT_J_ID)	&& defined(GPIOJ)
	#define USART2_TX_PORT    GPIOJ
#elif (USART2_TX_SELECTED_PORT_ID == USART2_PORT_K_ID)	&& defined(GPIOK)
	#define USART2_TX_PORT    GPIOK
#endif

/* --- USART_RX_PORT SELECTION --- */
#if (USART2_RX_SELECTED_PORT_ID 	== USART2_PORT_A_ID)	&& defined(GPIOA)
	#define USART2_RX_PORT    GPIOA
#elif (USART2_RX_SELECTED_PORT_ID == USART2_PORT_B_ID)	&& defined(GPIOB)
	#define USART2_RX_PORT    GPIOB
#elif (USART2_RX_SELECTED_PORT_ID == USART2_PORT_C_ID)	&& defined(GPIOC)
	#define USART2_RX_PORT    GPIOC
#elif (USART2_RX_SELECTED_PORT_ID == USART2_PORT_D_ID)	&& defined(GPIOD)
	#define USART2_RX_PORT    GPIOD
#elif (USART2_RX_SELECTED_PORT_ID == USART2_PORT_E_ID)	&& defined(GPIOE)
	#define USART2_RX_PORT    GPIOE
#elif (USART2_RX_SELECTED_PORT_ID == USART2_PORT_F_ID)	&& defined(GPIOF)
	#define USART2_RX_PORT    GPIOF
#elif (USART2_RX_SELECTED_PORT_ID == USART2_PORT_G_ID)	&& defined(GPIOG)
	#define USART2_RX_PORT    GPIOG
#elif (USART2_RX_SELECTED_PORT_ID == USART2_PORT_H_ID)	&& defined(GPIOH)
	#define USART2_RX_PORT    GPIOH
#elif (USART2_RX_SELECTED_PORT_ID == USART2_PORT_I_ID)	&& defined(GPIOI)
	#define USART2_RX_PORT    GPIOI
#elif (USART2_RX_SELECTED_PORT_ID == USART2_PORT_J_ID)	&& defined(GPIOJ)
	#define USART2_RX_PORT    GPIOJ
#elif (USART2_RX_SELECTED_PORT_ID == USART2_PORT_K_ID)	&& defined(GPIOK)
	#define USART2_RX_PORT    GPIOK
#endif

#endif /* USART2_INIT_H_ */
