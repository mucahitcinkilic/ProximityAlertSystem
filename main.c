#include <stdio.h>
#include <stdint.h>

#include "system.h"
#include "io.h"
#include "lcd.h"
#include "timer.h"
#include "hcsr04.h"


double microseconds;
double cantimeters;

void init(void)
{
  // I/O ports initialization
  Sys_IoInit();
  
  // System Clock Tick initialization
  Sys_TickInit();
  
  // Console initialization
  Sys_ConsoleInit();

  // LCD initialization
  LCD_Init();
  
  // LED initialization
  IO_Init(IOP_OutLED, IO_MODE_OUTPUT);
  
  // Initialize another LED as open-drain output
  IO_Init(IOP_LED, IO_MODE_OUTPUT_OD); 
  
  // Buzzer initialization
  IO_Init(IOP_Buzzer, IO_MODE_OUTPUT);
  
  // HC-SR04 sensor initialization
  HCSR04_Init();
}


void Task_LCD(void)
{
  // Get the duration from the ultrasonic sensor
  duration = HCSR04_Scan();
  microseconds = (double)duration; // Convert duration to microseconds
  cantimeters = microseconds / 58; // Convert microseconds to centimeters
  
  // Display the microseconds on the LCD
  LCD_SetCursor(0);
  LCD_printf("%f", microseconds);
  
  // Display the distance in centimeters on the LCD
  LCD_printf("\n%10f", cantimeters);
}

void Task_Alert(){
  int iCantimeters = (int)cantimeters; // Type conversion made to create delay for buzzer and LED activation timing
  
  // Turn on buzzer and LED
  IO_Write(IOP_Buzzer, 1);
  IO_Write(IOP_LED, 1);
  
  // Delay based on distance in centimeters
  DelayMs(iCantimeters);
  
  // Turn off buzzer and LED
  IO_Write(IOP_Buzzer, 0);
  IO_Write(IOP_LED, 0);
  
  // Short delay before the next alert
  DelayMs(iCantimeters / 4);
}

void main()
{
  // Initial configurations
  init();
  LCD_ClearDisplay();

  // Timer initialization
  Timer_Init(TIMER_1, CLOCK_FREQ / 8000, 2000, 1);
  Timer_Start(TIMER_1, 1);  
  TimerIntConfig(TIMER_1, 3);

  // Task loop
  while (1) 
  {
    Task_LCD(); // Display the sensor readings on the LCD
    Task_Alert(); // Handle the alert system with buzzer and LED
  }
}