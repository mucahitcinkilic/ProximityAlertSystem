#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#include "io.h"
#include "system.h"
#include "hcsr04.h"

void HCSR04_Init(void){ 
  IO_Init(HCSR_Echo, IO_MODE_INPUT_PD); // Initialize Echo pin as input with pull-down
  IO_Init(HCSR_Trigger, IO_MODE_OUTPUT); // Initialize Trigger pin as output
  IO_Write(HCSR_Trigger, 0); // Set Trigger pin low initially
}

clock_t HCSR04_Scan(void) {
    clock_t t0, t1;
    IO_Write(HCSR_Trigger, 1); // Send Trigger signal
    DelayUs(20); // 20us delay to trigger
    IO_Write(HCSR_Trigger, 0); // Stop Trigger signal
    
    // Wait for the echo to go high
    while (!IO_Read(HCSR_Echo));
    t0 = clock(); // Record the start time when echo is high
    
    // Wait for the echo to go low
    while (IO_Read(HCSR_Echo));
    t1 = clock(); // Record the end time when echo is low
    DelayMs(35); // Delay for 35ms to avoid interference
    return (t1 - t0); // Return the duration
}