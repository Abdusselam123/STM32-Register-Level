/*
 * @file usart2_init.c
 * @brief STM32 USART2 register-level initialization implementation (compile-time, bare-metal, no HAL/LL)
 */

#include "usart2_init.h"

#define ENABLE_GPIO_CLOCK(CLOCK_BUS, CLOCK_PORT) 			RCC->CLOCK_BUS |= RCC_##CLOCK_BUS##_##CLOCK_PORT##EN
#define ENABLE_USART_CLOCK(CLOCK_USART_BUS, CLOCK_USART) 	RCC->CLOCK_USART_BUS |= RCC_##CLOCK_USART_BUS##_##CLOCK_USART##EN
static inline void Enable_Usart_GPIO_Clock(void);
static inline void Enable_Usart_Clock(void);

void USART2_Init(){

	//CLOCK SETTINGS
	Enable_Usart_GPIO_Clock();
	Enable_Usart_Clock();

	//USART2_TX_PIN RESET & AF
	USART2_TX_PORT->MODER &= ~(3<<(USART2_TX_PIN*2));
	USART2_TX_PORT->MODER |= (2<<(USART2_TX_PIN*2));
	//USART2_RX_PIN RESET & AF
	USART2_RX_PORT->MODER &= ~(3<<(USART2_RX_PIN*2));
	USART2_RX_PORT->MODER |= (2<<(USART2_RX_PIN*2));

	if(USART2_TX_PIN<8){
		//TX_PIN RESET
		USART2_TX_PORT->AFR[0] &= ~(0xF<<(USART2_TX_PIN*4));
		//TX_PIN SET
		USART2_TX_PORT->AFR[0] |= (USART2_AF_VALUE<<(USART2_TX_PIN*4));
	}
		else{
			uint8_t shift_amount_1 = (uint8_t)((USART2_TX_PIN - 8) * 4);
			//TX_PIN RESET
			USART2_TX_PORT->AFR[1] &= ~(0xF<<shift_amount_1);
			//TX_PIN SET
			USART2_TX_PORT->AFR[1] |= (USART2_AF_VALUE<<shift_amount_1);
		}

	if(USART2_RX_PIN<8){
			//TX_PIN RESET
			USART2_RX_PORT->AFR[0] &= ~(0xF<<(USART2_RX_PIN*4));
			//TX_PIN SET
			USART2_RX_PORT->AFR[0] |= (USART2_AF_VALUE<<(USART2_RX_PIN*4));
		}
			else{
				uint8_t shift_amount_2 = (uint8_t)((USART2_RX_PIN - 8) * 4);
				//TX_PIN RESET
				USART2_RX_PORT->AFR[1] &= ~(0xF<<shift_amount_2);
				//TX_PIN SET
				USART2_RX_PORT->AFR[1] |= (USART2_AF_VALUE<<shift_amount_2);
			}


	//USART SETTINGS
	USART2->BRR  = (USART2_BUS_CLOCK_HZ + (USART2_TARGET_BAUDRATE/2))/USART2_TARGET_BAUDRATE; //8MHZ/BAUDRATE
	USART2->CR1 |= USART_CR1_TE | USART_CR1_RE;
	USART2->CR1 |= USART_CR1_UE;
	}

static inline void Enable_Usart_GPIO_Clock(void){

	/* --- TX CLOCK CONFIGURATION START --- */

	// Enable Clock for Port A
	#if (USART2_TX_SELECTED_PORT_ID == USART2_PORT_A_ID)
		//for f3 series
	    #if defined(RCC_AHBENR_GPIOAEN)
	        ENABLE_GPIO_CLOCK(AHBENR, GPIOA);
	    #elif defined(RCC_AHB1ENR_GPIOAEN)
	        ENABLE_GPIO_CLOCK(AHB1ENR, GPIOA);
		#elif defined(RCC_AHB2ENR_GPIOAEN)
	        ENABLE_GPIO_CLOCK(AHB2ENR, GPIOA);
		#elif defined(RCC_APBENR_GPIOAEN)
	        ENABLE_GPIO_CLOCK(APBENR, GPIOA);
		#elif defined(RCC_APB1ENR_GPIOAEN)
	        ENABLE_GPIO_CLOCK(APB1ENR, GPIOA);
		#elif defined(RCC_APB2ENR_GPIOAEN)
	        ENABLE_GPIO_CLOCK(APB2ENR, GPIOA);
		#endif
	#endif


	// Enable Clock for Port B
	#if (USART2_TX_SELECTED_PORT_ID == USART2_PORT_B_ID)
		//for f3 series
	    #if defined(RCC_AHBENR_GPIOBEN)
	        ENABLE_GPIO_CLOCK(AHBENR, GPIOB);
	    #elif defined(RCC_AHB1ENR_GPIOBEN)
	        ENABLE_GPIO_CLOCK(AHB1ENR, GPIOB);
		#elif defined(RCC_AHB2ENR_GPIOBEN)
	        ENABLE_GPIO_CLOCK(AHB2ENR, GPIOB);
		#elif defined(RCC_APBENR_GPIOBEN)
	        ENABLE_GPIO_CLOCK(APBENR, GPIOB);
		#elif defined(RCC_APB1ENR_GPIOBEN)
	        ENABLE_GPIO_CLOCK(APB1ENR, GPIOB);
		#elif defined(RCC_APB2ENR_GPIOBEN)
	        ENABLE_GPIO_CLOCK(APB2ENR, GPIOB);
		#endif
	#endif


	// Enable Clock for Port C
	#if (USART2_TX_SELECTED_PORT_ID == USART2_PORT_C_ID)
	    //for f3 series
	    #if defined(RCC_AHBENR_GPIOCEN)
	        ENABLE_GPIO_CLOCK(AHBENR, GPIOC);
	    #elif defined(RCC_AHB1ENR_GPIOCEN)
	        ENABLE_GPIO_CLOCK(AHB1ENR, GPIOC);
		#elif defined(RCC_AHB2ENR_GPIOCEN)
	        ENABLE_GPIO_CLOCK(AHB2ENR, GPIOC);
		#elif defined(RCC_APBENR_GPIOCEN)
	        ENABLE_GPIO_CLOCK(APBENR, GPIOC);
		#elif defined(RCC_APB1ENR_GPIOCEN)
	        ENABLE_GPIO_CLOCK(APB1ENR, GPIOC);
		#elif defined(RCC_APB2ENR_GPIOCEN)
	        ENABLE_GPIO_CLOCK(APB2ENR, GPIOC);
		#endif
	#endif


	// Enable Clock for Port D
	#if (USART2_TX_SELECTED_PORT_ID == USART2_PORT_D_ID)
	    //for f3 series
	    #if defined(RCC_AHBENR_GPIODEN)
	        ENABLE_GPIO_CLOCK(AHBENR, GPIOD);
	    #elif defined(RCC_AHB1ENR_GPIODEN)
	        ENABLE_GPIO_CLOCK(AHB1ENR, GPIOD);
		#elif defined(RCC_AHB2ENR_GPIODEN)
	        ENABLE_GPIO_CLOCK(AHB2ENR, GPIOD);
		#elif defined(RCC_APBENR_GPIODEN)
	        ENABLE_GPIO_CLOCK(APBENR, GPIOD);
		#elif defined(RCC_APB1ENR_GPIODEN)
	        ENABLE_GPIO_CLOCK(APB1ENR, GPIOD);
		#elif defined(RCC_APB2ENR_GPIODEN)
	        ENABLE_GPIO_CLOCK(APB2ENR, GPIOD);
		#endif
	#endif


	// Enable Clock for Port E
	#if (USART2_TX_SELECTED_PORT_ID == USART2_PORT_E_ID)
	    //for f3 series
	    #if defined(RCC_AHBENR_GPIOEEN)
	        ENABLE_GPIO_CLOCK(AHBENR, GPIOE);
	    #elif defined(RCC_AHB1ENR_GPIOEEN)
	        ENABLE_GPIO_CLOCK(AHB1ENR, GPIOE);
		#elif defined(RCC_AHB2ENR_GPIOEEN)
	        ENABLE_GPIO_CLOCK(AHB2ENR, GPIOE);
		#elif defined(RCC_APBENR_GPIOEEN)
	        ENABLE_GPIO_CLOCK(APBENR, GPIOE);
		#elif defined(RCC_APB1ENR_GPIOEEN)
	        ENABLE_GPIO_CLOCK(APB1ENR, GPIOE);
		#elif defined(RCC_APB2ENR_GPIOEEN)
	        ENABLE_GPIO_CLOCK(APB2ENR, GPIOE);
		#endif
	#endif


	// Enable Clock for Port F
	#if (USART2_TX_SELECTED_PORT_ID == USART2_PORT_F_ID)
	    //for f3 series
	    #if defined(RCC_AHBENR_GPIOFEN)
	        ENABLE_GPIO_CLOCK(AHBENR, GPIOF);
	    #elif defined(RCC_AHB1ENR_GPIOFEN)
	        ENABLE_GPIO_CLOCK(AHB1ENR, GPIOF);
		#elif defined(RCC_AHB2ENR_GPIOFEN)
	        ENABLE_GPIO_CLOCK(AHB2ENR, GPIOF);
		#elif defined(RCC_APBENR_GPIOFEN)
	        ENABLE_GPIO_CLOCK(APBENR, GPIOF);
		#elif defined(RCC_APB1ENR_GPIOFEN)
	        ENABLE_GPIO_CLOCK(APB1ENR, GPIOF);
		#elif defined(RCC_APB2ENR_GPIOFEN)
	        ENABLE_GPIO_CLOCK(APB2ENR, GPIOF);
		#endif
	#endif


	// Enable Clock for Port G
	#if (USART2_TX_SELECTED_PORT_ID == USART2_PORT_G_ID)
	    //for f3 series
	    #if defined(RCC_AHBENR_GPIOGEN)
	        ENABLE_GPIO_CLOCK(AHBENR, GPIOG);
	    #elif defined(RCC_AHB1ENR_GPIOGEN)
	        ENABLE_GPIO_CLOCK(AHB1ENR, GPIOG);
		#elif defined(RCC_AHB2ENR_GPIOGEN)
	        ENABLE_GPIO_CLOCK(AHB2ENR, GPIOG);
		#elif defined(RCC_APBENR_GPIOGEN)
	        ENABLE_GPIO_CLOCK(APBENR, GPIOG);
		#elif defined(RCC_APB1ENR_GPIOGEN)
	        ENABLE_GPIO_CLOCK(APB1ENR, GPIOG);
		#elif defined(RCC_APB2ENR_GPIOGEN)
	        ENABLE_GPIO_CLOCK(APB2ENR, GPIOG);
		#endif
	#endif


	// Enable Clock for Port H
	#if (USART2_TX_SELECTED_PORT_ID == USART2_PORT_H_ID)
	    //for f3 series
	    #if defined(RCC_AHBENR_GPIOHEN)
	        ENABLE_GPIO_CLOCK(AHBENR, GPIOH);
	    #elif defined(RCC_AHB1ENR_GPIOHEN)
	        ENABLE_GPIO_CLOCK(AHB1ENR, GPIOH);
		#elif defined(RCC_AHB2ENR_GPIOHEN)
	        ENABLE_GPIO_CLOCK(AHB2ENR, GPIOH);
		#elif defined(RCC_APBENR_GPIOHEN)
	        ENABLE_GPIO_CLOCK(APBENR, GPIOH);
		#elif defined(RCC_APB1ENR_GPIOHEN)
	        ENABLE_GPIO_CLOCK(APB1ENR, GPIOH);
		#elif defined(RCC_APB2ENR_GPIOHEN)
	        ENABLE_GPIO_CLOCK(APB2ENR, GPIOH);
		#endif
	#endif


	// Enable Clock for Port I
	#if (USART2_TX_SELECTED_PORT_ID == USART2_PORT_I_ID)
	    //for f3 series
	    #if defined(RCC_AHBENR_GPIOIEN)
	        ENABLE_GPIO_CLOCK(AHBENR, GPIOI);
	    #elif defined(RCC_AHB1ENR_GPIOIEN)
	        ENABLE_GPIO_CLOCK(AHB1ENR, GPIOI);
		#elif defined(RCC_AHB2ENR_GPIOIEN)
	        ENABLE_GPIO_CLOCK(AHB2ENR, GPIOI);
		#elif defined(RCC_APBENR_GPIOIEN)
	        ENABLE_GPIO_CLOCK(APBENR, GPIOI);
		#elif defined(RCC_APB1ENR_GPIOIEN)
	        ENABLE_GPIO_CLOCK(APB1ENR, GPIOI);
		#elif defined(RCC_APB2ENR_GPIOIEN)
	        ENABLE_GPIO_CLOCK(APB2ENR, GPIOI);
		#endif
	#endif


	// Enable Clock for Port J
	#if (USART2_TX_SELECTED_PORT_ID == USART2_PORT_J_ID)
	    //for f3 series
	    #if defined(RCC_AHBENR_GPIOJEN)
	        ENABLE_GPIO_CLOCK(AHBENR, GPIOJ);
	    #elif defined(RCC_AHB1ENR_GPIOJEN)
	        ENABLE_GPIO_CLOCK(AHB1ENR, GPIOJ);
		#elif defined(RCC_AHB2ENR_GPIOJEN)
	        ENABLE_GPIO_CLOCK(AHB2ENR, GPIOJ);
		#elif defined(RCC_APBENR_GPIOJEN)
	        ENABLE_GPIO_CLOCK(APBENR, GPIOJ);
		#elif defined(RCC_APB1ENR_GPIOJEN)
	        ENABLE_GPIO_CLOCK(APB1ENR, GPIOJ);
		#elif defined(RCC_APB2ENR_GPIOJEN)
	        ENABLE_GPIO_CLOCK(APB2ENR, GPIOJ);
		#endif
	#endif


	// Enable Clock for Port K
	#if (USART2_TX_SELECTED_PORT_ID == USART2_PORT_K_ID)
	    //for f3 series
	    #if defined(RCC_AHBENR_GPIOKEN)
	        ENABLE_GPIO_CLOCK(AHBENR, GPIOK);
	    #elif defined(RCC_AHB1ENR_GPIOKEN)
	        ENABLE_GPIO_CLOCK(AHB1ENR, GPIOK);
		#elif defined(RCC_AHB2ENR_GPIOKEN)
	        ENABLE_GPIO_CLOCK(AHB2ENR, GPIOK);
		#elif defined(RCC_APBENR_GPIOKEN)
	        ENABLE_GPIO_CLOCK(APBENR, GPIOK);
		#elif defined(RCC_APB1ENR_GPIOKEN)
	        ENABLE_GPIO_CLOCK(APB1ENR, GPIOK);
		#elif defined(RCC_APB2ENR_GPIOKEN)
	        ENABLE_GPIO_CLOCK(APB2ENR, GPIOK);
		#endif
	#endif

	/* --- TX CLOCK CONFIGURATION END --- */





	/* --- RX CLOCK CONFIGURATION START --- */

	// Enable Clock for Port A
	#if (USART2_RX_SELECTED_PORT_ID == USART2_PORT_A_ID)
		//for f3 series
	    #if defined(RCC_AHBENR_GPIOAEN)
	        ENABLE_GPIO_CLOCK(AHBENR, GPIOA);
	    #elif defined(RCC_AHB1ENR_GPIOAEN)
	        ENABLE_GPIO_CLOCK(AHB1ENR, GPIOA);
		#elif defined(RCC_AHB2ENR_GPIOAEN)
	        ENABLE_GPIO_CLOCK(AHB2ENR, GPIOA);
		#elif defined(RCC_APBENR_GPIOAEN)
	        ENABLE_GPIO_CLOCK(APBENR, GPIOA);
		#elif defined(RCC_APB1ENR_GPIOAEN)
	        ENABLE_GPIO_CLOCK(APB1ENR, GPIOA);
		#elif defined(RCC_APB2ENR_GPIOAEN)
	        ENABLE_GPIO_CLOCK(APB2ENR, GPIOA);
		#endif
	#endif


	// Enable Clock for Port B
	#if (USART2_RX_SELECTED_PORT_ID == USART2_PORT_B_ID)
		//for f3 series
	    #if defined(RCC_AHBENR_GPIOBEN)
	        ENABLE_GPIO_CLOCK(AHBENR, GPIOB);
	    #elif defined(RCC_AHB1ENR_GPIOBEN)
	        ENABLE_GPIO_CLOCK(AHB1ENR, GPIOB);
		#elif defined(RCC_AHB2ENR_GPIOBEN)
	        ENABLE_GPIO_CLOCK(AHB2ENR, GPIOB);
		#elif defined(RCC_APBENR_GPIOBEN)
	        ENABLE_GPIO_CLOCK(APBENR, GPIOB);
		#elif defined(RCC_APB1ENR_GPIOBEN)
	        ENABLE_GPIO_CLOCK(APB1ENR, GPIOB);
		#elif defined(RCC_APB2ENR_GPIOBEN)
	        ENABLE_GPIO_CLOCK(APB2ENR, GPIOB);
		#endif
	#endif


	// Enable Clock for Port C
	#if (USART2_RX_SELECTED_PORT_ID == USART2_PORT_C_ID)
	    //for f3 series
	    #if defined(RCC_AHBENR_GPIOCEN)
	        ENABLE_GPIO_CLOCK(AHBENR, GPIOC);
	    #elif defined(RCC_AHB1ENR_GPIOCEN)
	        ENABLE_GPIO_CLOCK(AHB1ENR, GPIOC);
		#elif defined(RCC_AHB2ENR_GPIOCEN)
	        ENABLE_GPIO_CLOCK(AHB2ENR, GPIOC);
		#elif defined(RCC_APBENR_GPIOCEN)
	        ENABLE_GPIO_CLOCK(APBENR, GPIOC);
		#elif defined(RCC_APB1ENR_GPIOCEN)
	        ENABLE_GPIO_CLOCK(APB1ENR, GPIOC);
		#elif defined(RCC_APB2ENR_GPIOCEN)
	        ENABLE_GPIO_CLOCK(APB2ENR, GPIOC);
		#endif
	#endif


	// Enable Clock for Port D
	#if (USART2_RX_SELECTED_PORT_ID == USART2_PORT_D_ID)
	    //for f3 series
	    #if defined(RCC_AHBENR_GPIODEN)
	        ENABLE_GPIO_CLOCK(AHBENR, GPIOD);
	    #elif defined(RCC_AHB1ENR_GPIODEN)
	        ENABLE_GPIO_CLOCK(AHB1ENR, GPIOD);
		#elif defined(RCC_AHB2ENR_GPIODEN)
	        ENABLE_GPIO_CLOCK(AHB2ENR, GPIOD);
		#elif defined(RCC_APBENR_GPIODEN)
	        ENABLE_GPIO_CLOCK(APBENR, GPIOD);
		#elif defined(RCC_APB1ENR_GPIODEN)
	        ENABLE_GPIO_CLOCK(APB1ENR, GPIOD);
		#elif defined(RCC_APB2ENR_GPIODEN)
	        ENABLE_GPIO_CLOCK(APB2ENR, GPIOD);
		#endif
	#endif


	// Enable Clock for Port E
	#if (USART2_RX_SELECTED_PORT_ID == USART2_PORT_E_ID)
	    //for f3 series
	    #if defined(RCC_AHBENR_GPIOEEN)
	        ENABLE_GPIO_CLOCK(AHBENR, GPIOE);
	    #elif defined(RCC_AHB1ENR_GPIOEEN)
	        ENABLE_GPIO_CLOCK(AHB1ENR, GPIOE);
		#elif defined(RCC_AHB2ENR_GPIOEEN)
	        ENABLE_GPIO_CLOCK(AHB2ENR, GPIOE);
		#elif defined(RCC_APBENR_GPIOEEN)
	        ENABLE_GPIO_CLOCK(APBENR, GPIOE);
		#elif defined(RCC_APB1ENR_GPIOEEN)
	        ENABLE_GPIO_CLOCK(APB1ENR, GPIOE);
		#elif defined(RCC_APB2ENR_GPIOEEN)
	        ENABLE_GPIO_CLOCK(APB2ENR, GPIOE);
		#endif
	#endif


	// Enable Clock for Port F
	#if (USART2_RX_SELECTED_PORT_ID == USART2_PORT_F_ID)
	    //for f3 series
	    #if defined(RCC_AHBENR_GPIOFEN)
	        ENABLE_GPIO_CLOCK(AHBENR, GPIOF);
	    #elif defined(RCC_AHB1ENR_GPIOFEN)
	        ENABLE_GPIO_CLOCK(AHB1ENR, GPIOF);
		#elif defined(RCC_AHB2ENR_GPIOFEN)
	        ENABLE_GPIO_CLOCK(AHB2ENR, GPIOF);
		#elif defined(RCC_APBENR_GPIOFEN)
	        ENABLE_GPIO_CLOCK(APBENR, GPIOF);
		#elif defined(RCC_APB1ENR_GPIOFEN)
	        ENABLE_GPIO_CLOCK(APB1ENR, GPIOF);
		#elif defined(RCC_APB2ENR_GPIOFEN)
	        ENABLE_GPIO_CLOCK(APB2ENR, GPIOF);
		#endif
	#endif


	// Enable Clock for Port G
	#if (USART2_RX_SELECTED_PORT_ID == USART2_PORT_G_ID)
	    //for f3 series
	    #if defined(RCC_AHBENR_GPIOGEN)
	        ENABLE_GPIO_CLOCK(AHBENR, GPIOG);
	    #elif defined(RCC_AHB1ENR_GPIOGEN)
	        ENABLE_GPIO_CLOCK(AHB1ENR, GPIOG);
		#elif defined(RCC_AHB2ENR_GPIOGEN)
	        ENABLE_GPIO_CLOCK(AHB2ENR, GPIOG);
		#elif defined(RCC_APBENR_GPIOGEN)
	        ENABLE_GPIO_CLOCK(APBENR, GPIOG);
		#elif defined(RCC_APB1ENR_GPIOGEN)
	        ENABLE_GPIO_CLOCK(APB1ENR, GPIOG);
		#elif defined(RCC_APB2ENR_GPIOGEN)
	        ENABLE_GPIO_CLOCK(APB2ENR, GPIOG);
		#endif
	#endif


	// Enable Clock for Port H
	#if (USART2_RX_SELECTED_PORT_ID == USART2_PORT_H_ID)
	    //for f3 series
	    #if defined(RCC_AHBENR_GPIOHEN)
	        ENABLE_GPIO_CLOCK(AHBENR, GPIOH);
	    #elif defined(RCC_AHB1ENR_GPIOHEN)
	        ENABLE_GPIO_CLOCK(AHB1ENR, GPIOH);
		#elif defined(RCC_AHB2ENR_GPIOHEN)
	        ENABLE_GPIO_CLOCK(AHB2ENR, GPIOH);
		#elif defined(RCC_APBENR_GPIOHEN)
	        ENABLE_GPIO_CLOCK(APBENR, GPIOH);
		#elif defined(RCC_APB1ENR_GPIOHEN)
	        ENABLE_GPIO_CLOCK(APB1ENR, GPIOH);
		#elif defined(RCC_APB2ENR_GPIOHEN)
	        ENABLE_GPIO_CLOCK(APB2ENR, GPIOH);
		#endif
	#endif


	// Enable Clock for Port I
	#if (USART2_RX_SELECTED_PORT_ID == USART2_PORT_I_ID)
	    //for f3 series
	    #if defined(RCC_AHBENR_GPIOIEN)
	        ENABLE_GPIO_CLOCK(AHBENR, GPIOI);
	    #elif defined(RCC_AHB1ENR_GPIOIEN)
	        ENABLE_GPIO_CLOCK(AHB1ENR, GPIOI);
		#elif defined(RCC_AHB2ENR_GPIOIEN)
	        ENABLE_GPIO_CLOCK(AHB2ENR, GPIOI);
		#elif defined(RCC_APBENR_GPIOIEN)
	        ENABLE_GPIO_CLOCK(APBENR, GPIOI);
		#elif defined(RCC_APB1ENR_GPIOIEN)
	        ENABLE_GPIO_CLOCK(APB1ENR, GPIOI);
		#elif defined(RCC_APB2ENR_GPIOIEN)
	        ENABLE_GPIO_CLOCK(APB2ENR, GPIOI);
		#endif
	#endif


	// Enable Clock for Port J
	#if (USART2_RX_SELECTED_PORT_ID == USART2_PORT_J_ID)
	    //for f3 series
	    #if defined(RCC_AHBENR_GPIOJEN)
	        ENABLE_GPIO_CLOCK(AHBENR, GPIOJ);
	    #elif defined(RCC_AHB1ENR_GPIOJEN)
	        ENABLE_GPIO_CLOCK(AHB1ENR, GPIOJ);
		#elif defined(RCC_AHB2ENR_GPIOJEN)
	        ENABLE_GPIO_CLOCK(AHB2ENR, GPIOJ);
		#elif defined(RCC_APBENR_GPIOJEN)
	        ENABLE_GPIO_CLOCK(APBENR, GPIOJ);
		#elif defined(RCC_APB1ENR_GPIOJEN)
	        ENABLE_GPIO_CLOCK(APB1ENR, GPIOJ);
		#elif defined(RCC_APB2ENR_GPIOJEN)
	        ENABLE_GPIO_CLOCK(APB2ENR, GPIOJ);
		#endif
	#endif


	/// Enable Clock for Port K
	#if (USART2_RX_SELECTED_PORT_ID == USART2_PORT_K_ID)
	    //for f3 series
	    #if defined(RCC_AHBENR_GPIOKEN)
	        ENABLE_GPIO_CLOCK(AHBENR, GPIOK);
	    #elif defined(RCC_AHB1ENR_GPIOKEN)
	        ENABLE_GPIO_CLOCK(AHB1ENR, GPIOK);
		#elif defined(RCC_AHB2ENR_GPIOKEN)
	        ENABLE_GPIO_CLOCK(AHB2ENR, GPIOK);
		#elif defined(RCC_APBENR_GPIOKEN)
	        ENABLE_GPIO_CLOCK(APBENR, GPIOK);
		#elif defined(RCC_APB1ENR_GPIOKEN)
	        ENABLE_GPIO_CLOCK(APB1ENR, GPIOK);
		#elif defined(RCC_APB2ENR_GPIOKEN)
	        ENABLE_GPIO_CLOCK(APB2ENR, GPIOK);
		#endif
	#endif

	/* --- RX CLOCK CONFIGURATION END --- */

}

/*-------------------------------------------------------------------------------------------------------*/

static inline void Enable_Usart_Clock(void){

	#if (SELECTED_USART2_ID == USART2_ID)
	    #if defined(RCC_AHBENR_USART2EN)
	        ENABLE_USART_CLOCK(AHBENR, USART2);
	    #elif defined(RCC_AHB1ENR_USART2EN)
	        ENABLE_USART_CLOCK(AHB1ENR, USART2);
		#elif defined(RCC_AHB2ENR_USART2EN)
	        ENABLE_USART_CLOCK(AHB2ENR, USART2);
		#elif defined(RCC_APBENR_USART2EN)
	        ENABLE_USART_CLOCK(APBENR, USART2);
		#elif defined(RCC_APB1ENR_USART2EN)
	        ENABLE_USART_CLOCK(APB1ENR, USART2);
		#elif defined(RCC_APB2ENR_USART2EN)
	        ENABLE_USART_CLOCK(APB2ENR, USART2);
		#endif
	#endif

}
