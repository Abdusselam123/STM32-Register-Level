/**
 * @file usart3_init.h
 * @brief STM32 USART3 register-level initialization driver (compile-time, bare-metal, no HAL/LL)
 * @author Abdusselam
 * @license MIT
 */
/*
 * ======================================================================
 *  !!! CRITICAL HARDWARE NOTICE !!!
 * ======================================================================
 *  TARGET BOARD: NUCLEO-F302R8 (STM32F302R8)
 * ----------------------------------------------------------------------
 *  This driver is pre-configured for the target board above.
 *
 *  If you are using a different STM32 family (F1 / F3 / F4 / L4, etc.)
 *  or a different development board, you MUST review and update the
 *  "USER SETTINGS" section accordingly.
 *
 *  ⚠️ Even after required modifications, 
 *  this driver may not work on all STM32 devices due to differences in 
 *  hardware architecture, clock tree configuration, and peripheral register 
 *  implementation across STM32 families.
 */

#ifndef USART3_INIT_H_
#define USART3_INIT_H_

#define USART3_ID    			2
#define SELECTED_USART3_ID   	USART3_ID
/*--- PORT SELECTION IDs START ---*/
#define USART3_PORT_A_ID    1			//A PINS
#define USART3_PORT_B_ID    2			//B PINS
#define USART3_PORT_C_ID   	3			//C PINS
#define USART3_PORT_D_ID    4			//D PINS
#define USART3_PORT_E_ID    5			//E PINS
#define USART3_PORT_F_ID    6			//F PINS
#define USART3_PORT_G_ID    7			//G PINS
#define USART3_PORT_H_ID   	8			//H PINS
#define USART3_PORT_I_ID    9			//I PINS
#define USART3_PORT_J_ID    10			//J PINS
#define USART3_PORT_K_ID    11			//K PINS
/*--- PORT SELECTION IDs END ---*/



/*--- ------------------- ------------------------------------------------------------*///
/*--- USER SETTINGS START ------------------------------------------------------------*///
/*--- ------------------- ------------------------------------------------------------*///
//library:																				//
#include "stm32f3xx.h"			//Change this header with your specific...				//
								//...STM32 series CMSIS header (e.g., f1xx, f4xx)		//
																						//
//pin settings:																			//
#define USART3_TX_SELECTED_PORT_ID		USART3_PORT_B_ID //exp: if PA2, USART3_PORT_A_ID//
#define USART3_RX_SELECTED_PORT_ID		USART3_PORT_B_ID //exp: if PA2, USART3_PORT_A_ID//
#define USART3_TX_PIN 					10				 //exp: if PA2, 2				//
#define USART3_RX_PIN 					11				 //exp: if PA3,	3	 			//
																						//
// IMPORTANT: Alternate Function (AF) number varies by MCU model.                       //
// For STM32F302R8: USART3 is AF7. Check your MCU's Datasheet (Table: Alternate Funct.) //
#define USART3_AF_VALUE					7				//AF NUMBER						//
																						//
//usart settings:																		//
#define USART3_BUS_CLOCK_HZ    			8000000U			//BUS CLOCK SPEED (HZ)		//
#define USART3_TARGET_BAUDRATE  		9600U				//TARGET BAUDRATE (HZ)		//
																						//
/*--- ----------------- --------------------------------------------------------------*///
/*--- USER SETTINGS END --------------------------------------------------------------*///
/*--- ----------------- --------------------------------------------------------------*///



/* --- USART_TX_PORT SELECTION --- */
#if (USART3_TX_SELECTED_PORT_ID 	== USART3_PORT_A_ID)	&& defined(GPIOA)
	#define USART3_TX_PORT    GPIOA
#elif (USART3_TX_SELECTED_PORT_ID == USART3_PORT_B_ID)	&& defined(GPIOB)
	#define USART3_TX_PORT    GPIOB
#elif (USART3_TX_SELECTED_PORT_ID == USART3_PORT_C_ID)	&& defined(GPIOC)
	#define USART3_TX_PORT    GPIOC
#elif (USART3_TX_SELECTED_PORT_ID == USART3_PORT_D_ID)	&& defined(GPIOD)
	#define USART3_TX_PORT    GPIOD
#elif (USART3_TX_SELECTED_PORT_ID == USART3_PORT_E_ID)	&& defined(GPIOE)
	#define USART3_TX_PORT    GPIOE
#elif (USART3_TX_SELECTED_PORT_ID == USART3_PORT_F_ID)	&& defined(GPIOF)
	#define USART3_TX_PORT    GPIOF
#elif (USART3_TX_SELECTED_PORT_ID == USART3_PORT_G_ID)	&& defined(GPIOG)
	#define USART3_TX_PORT    GPIOG
#elif (USART3_TX_SELECTED_PORT_ID == USART3_PORT_H_ID)	&& defined(GPIOH)
	#define USART3_TX_PORT    GPIOH
#elif (USART3_TX_SELECTED_PORT_ID == USART3_PORT_I_ID)	&& defined(GPIOI)
	#define USART3_TX_PORT    GPIOI
#elif (USART3_TX_SELECTED_PORT_ID == USART3_PORT_J_ID)	&& defined(GPIOJ)
	#define USART3_TX_PORT    GPIOJ
#elif (USART3_TX_SELECTED_PORT_ID == USART3_PORT_K_ID)	&& defined(GPIOK)
	#define USART3_TX_PORT    GPIOK
#endif

/* --- USART_RX_PORT SELECTION --- */
#if (USART3_RX_SELECTED_PORT_ID 	== USART3_PORT_A_ID)	&& defined(GPIOA)
	#define USART3_RX_PORT    GPIOA
#elif (USART3_RX_SELECTED_PORT_ID == USART3_PORT_B_ID)	&& defined(GPIOB)
	#define USART3_RX_PORT    GPIOB
#elif (USART3_RX_SELECTED_PORT_ID == USART3_PORT_C_ID)	&& defined(GPIOC)
	#define USART3_RX_PORT    GPIOC
#elif (USART3_RX_SELECTED_PORT_ID == USART3_PORT_D_ID)	&& defined(GPIOD)
	#define USART3_RX_PORT    GPIOD
#elif (USART3_RX_SELECTED_PORT_ID == USART3_PORT_E_ID)	&& defined(GPIOE)
	#define USART3_RX_PORT    GPIOE
#elif (USART3_RX_SELECTED_PORT_ID == USART3_PORT_F_ID)	&& defined(GPIOF)
	#define USART3_RX_PORT    GPIOF
#elif (USART3_RX_SELECTED_PORT_ID == USART3_PORT_G_ID)	&& defined(GPIOG)
	#define USART3_RX_PORT    GPIOG
#elif (USART3_RX_SELECTED_PORT_ID == USART3_PORT_H_ID)	&& defined(GPIOH)
	#define USART3_RX_PORT    GPIOH
#elif (USART3_RX_SELECTED_PORT_ID == USART3_PORT_I_ID)	&& defined(GPIOI)
	#define USART3_RX_PORT    GPIOI
#elif (USART3_RX_SELECTED_PORT_ID == USART3_PORT_J_ID)	&& defined(GPIOJ)
	#define USART3_RX_PORT    GPIOJ
#elif (USART3_RX_SELECTED_PORT_ID == USART3_PORT_K_ID)	&& defined(GPIOK)
	#define USART3_RX_PORT    GPIOK
#endif

#endif /* USART3_INIT_H_ */
