Ultrasonic Distance Measurement System Using HC-SR04 with STM32
This project demonstrates how to measure distance using the HC-SR04 ultrasonic sensor with an STM32 microcontroller. The system calculates the distance by triggering the ultrasonic sensor and measuring the time it takes for the echo signal to return. Based on the measured distance, a buzzer and LED alert system is triggered for immediate feedback.

Features
Distance Measurement: Utilizes the HC-SR04 ultrasonic sensor to measure distance in centimeters.
Buzzer and LED Alert System: If the distance falls within a specified range, the system activates a buzzer and LED for visual and audio alerts.
Configurable Timing: The timing of the alerts (buzzer and LED) is dynamically adjusted based on the measured distance.
How It Works
Ultrasonic Sensor (HC-SR04) Operation:

The HC-SR04 sensor is triggered with a 20µs pulse.
The system measures the time between the emitted pulse and the returned echo to calculate the distance.
Distance is calculated using the formula: Distance (cm) = Time (µs) / 58.
Alert System:

If the object is within a certain range, a buzzer and LED are activated for a duration proportional to the measured distance.
Interrupts and Timers:

The system uses the STM32's timer functionality for handling delays and the SysTick for system timing.
Code Structure
main.c:

Initializes the system components (buzzer, LEDs, HC-SR04 sensor).
Runs the distance measurement and alert tasks in a loop.
Manages the alert system based on the sensor data.
hcsr04.c:

Contains functions for initializing and triggering the HC-SR04 sensor.
Measures the echo time and returns the result for distance calculation.
Prerequisites
STM32 Microcontroller (e.g., STM32F103, STM32F401)
HC-SR04 Ultrasonic Sensor
Buzzer and LED for alert signals
STM32CubeIDE or IAR Embedded Workbench for compiling and flashing the project.
How to Use
Clone the repository and open the project in your STM32 development environment.
Build and flash the project onto your STM32 microcontroller.
Connect the HC-SR04 sensor, buzzer, and LED to the corresponding GPIO pins as defined in the code.
Modify the Task_Alert() function if necessary to change the alert behavior based on the measured distance.
Key Connections:
Trigger Pin: Connected to the GPIO pin for sending the trigger signal to the HC-SR04.
Echo Pin: Connected to the GPIO pin for receiving the echo signal from the HC-SR04.
Buzzer and LED: Connected to GPIO pins for the alert system.
License
This project is licensed under the MIT License - see the LICENSE file for details.

The project has been developed using the C programming language and was compiled using IAR Embedded Workbench, version 7.80. It is designed to run on an STM32 microcontroller, but can be adapted to other platforms with minor modifications.

Please note that only the core project files (hcsr04.c, hcsr04.h, and main.c) have been provided. You will need to implement other necessary configurations, such as IO initialization and RCC enabling, according to your own compiler and library setup. Ensure that the hardware-specific settings are adjusted for your environment.

The project also includes the design of the electronic circuit schematic, outlining the components and their connections. However, it does not include a PCB (Printed Circuit Board) design.

Demonstration Video Link: https://youtu.be/x4yFbcswlf8?si=LInVZ5xhLx6ZsRmP