⚠️ Note:
Only one implementation (Clock-Abstracted or Low-Level; the Low-Level variant is not part of this repository) should be included in a project. Including both may lead to symbol conflicts and multiple definition errors.

⚠️ Note:
A simplified integer-based BRR calculation is used instead of the full fractional USARTDIV method. This reduces implementation complexity while maintaining acceptable baud rate accuracy for standard communication speeds. For production-grade or high-precision communication, the full STM32 fractional BRR calculation method should be used.

• This driver is designed using a compile-time configuration principle. Instead of increasing CPU load at runtime, all hardware parameters are determined at compile time.
• Unlike the low-level implementation, this driver includes a clock abstraction layer: the correct RCC enable register for the GPIO ports and the USART is selected at compile time. The system clock (PLL, bus prescalers) is NOT configured by this driver; BUS_CLOCK_HZ must match the actual bus clock.
• The user only needs to configure the parameters in the user settings section of the header file based on application requirements.

• Invalid settings (unknown port, pin > 15, too high baud rate, STM32F1) stop the build with a #error message.
