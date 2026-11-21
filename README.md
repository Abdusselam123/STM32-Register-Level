# STM32-Register-Level

This repository contains two independent parts: compile-time abstraction drivers and bare-metal peripheral initialization examples for STM32.
The examples focus on direct register-level programming without any abstraction layers, while the drivers are configured statically in their header files (user settings section) to provide compile-time optimized hardware abstraction.

Tested on: NUCLEO-F302R8 (STM32F302R8). The drivers use MODER/AFR style GPIO registers, so STM32F1 is not supported.
The examples assume the reset default clock (HSI 8 MHz, bus prescalers 1).


---------- Repository Structure ---------
```text
└── F3-Series/
    └── Nucleo-f302r8/
        └── Drivers/
        │    ├── USART/
        │    │   ├── USART1/
        │    │   │   ├── Clock-Abstracted/
        │    │   │   │   ├── usart1_init.c
        │    │   │   │   ├── usart1_init.h
        │    │   │   │   └── README.txt
        │    │   │   └── ...
        │    │   │       
        │    │   ├── USART2/
        │    │   │   └── ...
        │    │   └── ...
        │    │
        │    └──...
        │ 
        └── Examples/             
            └── USART/
            │    └── USART2/          
            │        ├── main.c       
            │        └── README.txt
            └── I2C/
            │    └── I2C2/          
            │        ├── main.c       
            │        └── README.txt
            │ 
            └──...
```

CHANGELOG
- USART drivers: compile-time #error checks for invalid port/pin/AF/baud rate and for STM32F1 (not supported).
- USART drivers: USARTx_Init(void) prototype added to the header; shifts use unsigned constants.
- README files: corrected statements about supported families, clock handling and HAL usage in the examples.
