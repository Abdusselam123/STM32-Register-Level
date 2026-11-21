/*
 * @file usart3_init.c
 * @brief STM32 USART3 register-level initialization implementation (compile-time, bare-metal, no HAL/LL)
 */

#include "usart3_init.h"

#define ENABLE_GPIO_CLOCK(CLOCK_BUS, CLOCK_PORT) 			RCC->CLOCK_BUS |= RCC_##CLOCK_BUS##_##CLOCK_PORT##EN
#define ENABLE_USART_CLOCK(CLOCK_USART_BUS, CLOCK_USART) 	RCC->CLOCK_USART_BUS |= RCC_##CLOCK_USART_BUS##_##CLOCK_USART##EN
static inline void Enable_Usart_GPIO_Clock(void);
static inline void Enable_Usart_Clock(void);

void USART3_Init(void){

	//CLOCK SETTINGS
	Enable_Usart_GPIO_Clock();
	Enable_Usart_Clock();

	//USART3_TX_PIN RESET & AF
	USART3_TX_PORT->MODER &= ~(3U<<(USART3_TX_PIN*2));
	USART3_TX_PORT->MODER |= (2U<<(USART3_TX_PIN*2));
	//USART3_RX_PIN RESET & AF
	USART3_RX_PORT->MODER &= ~(3U<<(USART3_RX_PIN*2));
	USART3_RX_PORT->MODER |= (2U<<(USART3_RX_PIN*2));

	//TX_PIN AF: AFR[0] for pins 0..7, AFR[1] for pins 8..15
	USART3_TX_PORT->AFR[USART3_TX_PIN >> 3] &= ~(0xFU << ((USART3_TX_PIN & 7U) * 4U));
	USART3_TX_PORT->AFR[USART3_TX_PIN >> 3] |=  ((uint32_t)USART3_AF_VALUE << ((USART3_TX_PIN & 7U) * 4U));
	//RX_PIN AF
	USART3_RX_PORT->AFR[USART3_RX_PIN >> 3] &= ~(0xFU << ((USART3_RX_PIN & 7U) * 4U));
	USART3_RX_PORT->AFR[USART3_RX_PIN >> 3] |=  ((uint32_t)USART3_AF_VALUE << ((USART3_RX_PIN & 7U) * 4U));


	//USART SETTINGS
	USART3->BRR  = (USART3_BUS_CLOCK_HZ + (USART3_TARGET_BAUDRATE/2))/USART3_TARGET_BAUDRATE; //8MHZ/BAUDRATE
	USART3->CR1 |= USART_CR1_TE | USART_CR1_RE;
	USART3->CR1 |= USART_CR1_UE;
	}

static inline void Enable_Usart_GPIO_Clock(void){

	/* --- TX CLOCK CONFIGURATION START --- */

	// Enable Clock for Port A
	#if (USART3_TX_SELECTED_PORT_ID == USART3_PORT_A_ID)
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
		#else
			#error "GPIOA clock enable bit not found for this MCU."
		#endif
	#endif


	// Enable Clock for Port B
	#if (USART3_TX_SELECTED_PORT_ID == USART3_PORT_B_ID)
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
		#else
			#error "GPIOB clock enable bit not found for this MCU."
		#endif
	#endif


	// Enable Clock for Port C
	#if (USART3_TX_SELECTED_PORT_ID == USART3_PORT_C_ID)
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
		#else
			#error "GPIOC clock enable bit not found for this MCU."
		#endif
	#endif


	// Enable Clock for Port D
	#if (USART3_TX_SELECTED_PORT_ID == USART3_PORT_D_ID)
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
		#else
			#error "GPIOD clock enable bit not found for this MCU."
		#endif
	#endif


	// Enable Clock for Port E
	#if (USART3_TX_SELECTED_PORT_ID == USART3_PORT_E_ID)
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
		#else
			#error "GPIOE clock enable bit not found for this MCU."
		#endif
	#endif


	// Enable Clock for Port F
	#if (USART3_TX_SELECTED_PORT_ID == USART3_PORT_F_ID)
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
		#else
			#error "GPIOF clock enable bit not found for this MCU."
		#endif
	#endif


	// Enable Clock for Port G
	#if (USART3_TX_SELECTED_PORT_ID == USART3_PORT_G_ID)
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
		#else
			#error "GPIOG clock enable bit not found for this MCU."
		#endif
	#endif


	// Enable Clock for Port H
	#if (USART3_TX_SELECTED_PORT_ID == USART3_PORT_H_ID)
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
		#else
			#error "GPIOH clock enable bit not found for this MCU."
		#endif
	#endif


	// Enable Clock for Port I
	#if (USART3_TX_SELECTED_PORT_ID == USART3_PORT_I_ID)
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
		#else
			#error "GPIOI clock enable bit not found for this MCU."
		#endif
	#endif


	// Enable Clock for Port J
	#if (USART3_TX_SELECTED_PORT_ID == USART3_PORT_J_ID)
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
		#else
			#error "GPIOJ clock enable bit not found for this MCU."
		#endif
	#endif


	// Enable Clock for Port K
	#if (USART3_TX_SELECTED_PORT_ID == USART3_PORT_K_ID)
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
		#else
			#error "GPIOK clock enable bit not found for this MCU."
		#endif
	#endif

	/* --- TX CLOCK CONFIGURATION END --- */





	/* --- RX CLOCK CONFIGURATION START --- */

	// Enable Clock for Port A
	#if (USART3_RX_SELECTED_PORT_ID == USART3_PORT_A_ID)
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
		#else
			#error "GPIOA clock enable bit not found for this MCU."
		#endif
	#endif


	// Enable Clock for Port B
	#if (USART3_RX_SELECTED_PORT_ID == USART3_PORT_B_ID)
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
		#else
			#error "GPIOB clock enable bit not found for this MCU."
		#endif
	#endif


	// Enable Clock for Port C
	#if (USART3_RX_SELECTED_PORT_ID == USART3_PORT_C_ID)
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
		#else
			#error "GPIOC clock enable bit not found for this MCU."
		#endif
	#endif


	// Enable Clock for Port D
	#if (USART3_RX_SELECTED_PORT_ID == USART3_PORT_D_ID)
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
		#else
			#error "GPIOD clock enable bit not found for this MCU."
		#endif
	#endif


	// Enable Clock for Port E
	#if (USART3_RX_SELECTED_PORT_ID == USART3_PORT_E_ID)
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
		#else
			#error "GPIOE clock enable bit not found for this MCU."
		#endif
	#endif


	// Enable Clock for Port F
	#if (USART3_RX_SELECTED_PORT_ID == USART3_PORT_F_ID)
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
		#else
			#error "GPIOF clock enable bit not found for this MCU."
		#endif
	#endif


	// Enable Clock for Port G
	#if (USART3_RX_SELECTED_PORT_ID == USART3_PORT_G_ID)
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
		#else
			#error "GPIOG clock enable bit not found for this MCU."
		#endif
	#endif


	// Enable Clock for Port H
	#if (USART3_RX_SELECTED_PORT_ID == USART3_PORT_H_ID)
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
		#else
			#error "GPIOH clock enable bit not found for this MCU."
		#endif
	#endif


	// Enable Clock for Port I
	#if (USART3_RX_SELECTED_PORT_ID == USART3_PORT_I_ID)
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
		#else
			#error "GPIOI clock enable bit not found for this MCU."
		#endif
	#endif


	// Enable Clock for Port J
	#if (USART3_RX_SELECTED_PORT_ID == USART3_PORT_J_ID)
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
		#else
			#error "GPIOJ clock enable bit not found for this MCU."
		#endif
	#endif


	/// Enable Clock for Port K
	#if (USART3_RX_SELECTED_PORT_ID == USART3_PORT_K_ID)
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
		#else
			#error "GPIOK clock enable bit not found for this MCU."
		#endif
	#endif

	/* --- RX CLOCK CONFIGURATION END --- */

}

/*-------------------------------------------------------------------------------------------------------*/

static inline void Enable_Usart_Clock(void){

	#if (SELECTED_USART3_ID == USART3_ID)
	    #if defined(RCC_AHBENR_USART3EN)
	        ENABLE_USART_CLOCK(AHBENR, USART3);
	    #elif defined(RCC_AHB1ENR_USART3EN)
	        ENABLE_USART_CLOCK(AHB1ENR, USART3);
		#elif defined(RCC_AHB2ENR_USART3EN)
	        ENABLE_USART_CLOCK(AHB2ENR, USART3);
		#elif defined(RCC_APBENR_USART3EN)
	        ENABLE_USART_CLOCK(APBENR, USART3);
		#elif defined(RCC_APB1ENR_USART3EN)
	        ENABLE_USART_CLOCK(APB1ENR, USART3);
		#elif defined(RCC_APB2ENR_USART3EN)
	        ENABLE_USART_CLOCK(APB2ENR, USART3);
		#else
			#error "USART3 clock enable bit not found for this MCU."
		#endif
	#endif

}
