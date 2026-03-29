# STM32-Register-Level

STM32 register-level peripheral drivers and examples (no HAL/LL).

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

