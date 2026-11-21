/**
 * @file usart1_init.h
 * @brief STM32 USART1 register-level initialization driver (compile-time, bare-metal, no HAL/LL)
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
 *  If you are using a different STM32 family (e.g. F0 / F4 / L4)
 *  or a different development board, you MUST review and update the
 *  "USER SETTINGS" section accordingly.
 *
 *  STM32F1 is NOT supported: its GPIO uses CRL/CRH instead of MODER/AFR
 *  (a compile-time #error stops the build on F1).
 *
 *  ⚠️ Even after required modifications, 
 *  this driver may not work on all STM32 devices due to differences in 
 *  hardware architecture, clock tree configuration, and peripheral register 
 *  implementation across STM32 families.
 */

#ifndef USART1_INIT_H_
#define USART1_INIT_H_

#define USART1_ID    		2
#define SELECTED_USART1_ID  USART1_ID

/*--- PORT SELECTION IDs START ---*/
#define USART1_PORT_A_ID    1			//A PINS
#define USART1_PORT_B_ID    2			//B PINS
#define USART1_PORT_C_ID   	3			//C PINS
#define USART1_PORT_D_ID    4			//D PINS
#define USART1_PORT_E_ID    5			//E PINS
#define USART1_PORT_F_ID    6			//F PINS
#define USART1_PORT_G_ID    7			//G PINS
#define USART1_PORT_H_ID   	8			//H PINS
#define USART1_PORT_I_ID    9			//I PINS
#define USART1_PORT_J_ID    10			//J PINS
#define USART1_PORT_K_ID    11			//K PINS
/*--- PORT SELECTION IDs END ---*/



/*--- ------------------- ------------------------------------------------------------*///
/*--- USER SETTINGS START ------------------------------------------------------------*///
/*--- ------------------- ------------------------------------------------------------*///
//library:																				//
#include "stm32f3xx.h"			//Change this header with your specific...				//
								//...STM32 series CMSIS header (e.g., f0xx, f4xx)		//
																						//
//pin settings:																			//
#define USART1_TX_SELECTED_PORT_ID		USART1_PORT_B_ID //exp: if PA2, USART1_PORT_A_ID//
#define USART1_RX_SELECTED_PORT_ID		USART1_PORT_B_ID //exp: if PA2, USART1_PORT_A_ID//
#define USART1_TX_PIN 					6				 //exp: if PA2, 2				//
#define USART1_RX_PIN 					7				 //exp: if PA3,	3	 			//
																						//
// IMPORTANT: Alternate Function (AF) number varies by MCU model.                       //
// For STM32F302R8: USART1 is AF7. Check your MCU's Datasheet (Table: Alternate Funct.) //
#define USART1_AF_VALUE					7				//AF NUMBER						//
																						//
//usart settings:																		//
// USART1_BUS_CLOCK_HZ = clock of the APB2 bus. 8 MHz is the reset default (HSI, no prescaler).
// Update it if you change the system clock (PLL) or the APB2 prescaler.
#define USART1_BUS_CLOCK_HZ    			8000000U		//BUS CLOCK SPEED (HZ)			//
#define USART1_TARGET_BAUDRATE  		9600U			//TARGET BAUDRATE (HZ)			//
																						//
/*--- ----------------- --------------------------------------------------------------*///
/*--- USER SETTINGS END --------------------------------------------------------------*///
/*--- ----------------- --------------------------------------------------------------*///



/* --- USART_TX_PORT SELECTION --- */
#if (USART1_TX_SELECTED_PORT_ID 	== USART1_PORT_A_ID)	&& defined(GPIOA)
	#define USART1_TX_PORT    GPIOA
#elif (USART1_TX_SELECTED_PORT_ID == USART1_PORT_B_ID)	&& defined(GPIOB)
	#define USART1_TX_PORT    GPIOB
#elif (USART1_TX_SELECTED_PORT_ID == USART1_PORT_C_ID)	&& defined(GPIOC)
	#define USART1_TX_PORT    GPIOC
#elif (USART1_TX_SELECTED_PORT_ID == USART1_PORT_D_ID)	&& defined(GPIOD)
	#define USART1_TX_PORT    GPIOD
#elif (USART1_TX_SELECTED_PORT_ID == USART1_PORT_E_ID)	&& defined(GPIOE)
	#define USART1_TX_PORT    GPIOE
#elif (USART1_TX_SELECTED_PORT_ID == USART1_PORT_F_ID)	&& defined(GPIOF)
	#define USART1_TX_PORT    GPIOF
#elif (USART1_TX_SELECTED_PORT_ID == USART1_PORT_G_ID)	&& defined(GPIOG)
	#define USART1_TX_PORT    GPIOG
#elif (USART1_TX_SELECTED_PORT_ID == USART1_PORT_H_ID)	&& defined(GPIOH)
	#define USART1_TX_PORT    GPIOH
#elif (USART1_TX_SELECTED_PORT_ID == USART1_PORT_I_ID)	&& defined(GPIOI)
	#define USART1_TX_PORT    GPIOI
#elif (USART1_TX_SELECTED_PORT_ID == USART1_PORT_J_ID)	&& defined(GPIOJ)
	#define USART1_TX_PORT    GPIOJ
#elif (USART1_TX_SELECTED_PORT_ID == USART1_PORT_K_ID)	&& defined(GPIOK)
	#define USART1_TX_PORT    GPIOK
#endif

/* --- USART_RX_PORT SELECTION --- */
#if (USART1_RX_SELECTED_PORT_ID 	== USART1_PORT_A_ID)	&& defined(GPIOA)
	#define USART1_RX_PORT    GPIOA
#elif (USART1_RX_SELECTED_PORT_ID == USART1_PORT_B_ID)	&& defined(GPIOB)
	#define USART1_RX_PORT    GPIOB
#elif (USART1_RX_SELECTED_PORT_ID == USART1_PORT_C_ID)	&& defined(GPIOC)
	#define USART1_RX_PORT    GPIOC
#elif (USART1_RX_SELECTED_PORT_ID == USART1_PORT_D_ID)	&& defined(GPIOD)
	#define USART1_RX_PORT    GPIOD
#elif (USART1_RX_SELECTED_PORT_ID == USART1_PORT_E_ID)	&& defined(GPIOE)
	#define USART1_RX_PORT    GPIOE
#elif (USART1_RX_SELECTED_PORT_ID == USART1_PORT_F_ID)	&& defined(GPIOF)
	#define USART1_RX_PORT    GPIOF
#elif (USART1_RX_SELECTED_PORT_ID == USART1_PORT_G_ID)	&& defined(GPIOG)
	#define USART1_RX_PORT    GPIOG
#elif (USART1_RX_SELECTED_PORT_ID == USART1_PORT_H_ID)	&& defined(GPIOH)
	#define USART1_RX_PORT    GPIOH
#elif (USART1_RX_SELECTED_PORT_ID == USART1_PORT_I_ID)	&& defined(GPIOI)
	#define USART1_RX_PORT    GPIOI
#elif (USART1_RX_SELECTED_PORT_ID == USART1_PORT_J_ID)	&& defined(GPIOJ)
	#define USART1_RX_PORT    GPIOJ
#elif (USART1_RX_SELECTED_PORT_ID == USART1_PORT_K_ID)	&& defined(GPIOK)
	#define USART1_RX_PORT    GPIOK
#endif


/* --- COMPILE-TIME CHECKS --- */
#if defined(RCC_APB2ENR_IOPAEN)
	#error "STM32F1 is not supported: its GPIO uses CRL/CRH instead of MODER/AFR."
#endif
#if !defined(USART1_TX_PORT)
	#error "USART1_TX_SELECTED_PORT_ID is invalid or that GPIO port does not exist on this MCU."
#endif
#if !defined(USART1_RX_PORT)
	#error "USART1_RX_SELECTED_PORT_ID is invalid or that GPIO port does not exist on this MCU."
#endif
#if (USART1_TX_PIN > 15) || (USART1_RX_PIN > 15)
	#error "USART1 pin numbers must be 0..15."
#endif
#if (USART1_AF_VALUE > 15)
	#error "USART1_AF_VALUE must be 0..15."
#endif
#if ((USART1_BUS_CLOCK_HZ / USART1_TARGET_BAUDRATE) < 16)
	#error "USART1_TARGET_BAUDRATE is too high for this bus clock (BRR must be >= 16 with OVER8 = 0)."
#endif

/* --- FUNCTIONS --- */
void USART1_Init(void);

#endif /* USART1_INIT_H_ */
