# STM32-Register-Level

This repository contains two independent parts: compile-time abstraction drivers and bare-metal peripheral initialization examples for STM32.
The examples focus on direct register-level programming without any abstraction layers, while the drivers use static, header-only configuration to provide compile-time optimized hardware abstraction.


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

