# Micro-controller Programs

###  MSP430
This directory contains all the programs written for the MSP430 or its booster pack.
1) Four Bit Counter interfacing a BCD converter to seven-segment displays.
2) Eight Bit Analog to Digital Conversion interfacing a joystick input to two BCD converters to seven-segment displays.

### ESP32
This directory contains all the programs written for the ESP32 development board.
1) A simple blink program that interfaces with the on-board programmable led.
2) An interrupt program to execute code on a button press using interrupts in Arduino interfacing with on-board reset push button and led.
3) A poll program performing the same functions as the interrupt sequence interfacing with the on-board push button and led.
4) An interrupt based sleep mode explorer to explore the different sleep modes available for the ESP32 interfacing the on-board push button and led.


### RP2040
This directory contains all the programs written for the RP2040 board.

1) A simple blink program to explore the on-board neopixel led and the Adafruit neopixel library interfacing with just the on-board led.
2) An interrupt routine to display different states for the on-board led interfacing with the push button and neopixel led.
3) A polling program that is a counter part to the interrupt routine, this interfaces with the push button and neopixel led.