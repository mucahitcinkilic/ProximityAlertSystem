# ProximityAlertSystem

	This project utilizes the HC-SR04 ultrasonic sensor to measure distance and display the results on an LCD screen. The system also triggers a buzzer and LED alert based on the detected proximity. It is designed for simple distance monitoring and alert applications, making it suitable for security systems, object detection, or automation projects.

The project has been developed using the C programming language and was compiled using IAR Embedded Workbench, version 7.80. It is designed to run on an STM32 microcontroller, but can be adapted to other platforms with minor modifications.

Please note that only the core project files (hcsr04.c, hcsr04.h, and main.c) have been provided. You will need to implement other necessary configurations, such as IO initialization and RCC enabling, according to your own compiler and library setup. Ensure that the hardware-specific settings are adjusted for your environment.

