/* 28BYJ-48 stepper control*/
#include <Stepper.h>

#define Steps_per_motor_revolution  64       // 64 steps per rotor revolution
#define Steps_per_output_revolution 64 * 32  // 32:1 reduction gearing

// Wiring 8 = In1, 9 = In2, 10 = In3, 11 = In4
// 28BYJ-48 Pin 'firing' order 1-3-2-4
Stepper small_stepper(Steps_per_motor_revolution, 8, 10, 9, 11);

int  Steps_travel;

void setup()
{
  // Stepper Library sets up pins 8-11 as outputs
}

void loop()
{
  Steps_travel  =  Steps_per_output_revolution;    // Rotate clockwise 360°
  small_stepper.setSpeed(500);                     // ~500 max speed
  small_stepper.step(Steps_travel);
  delay(1000);
  
  Steps_travel  =  - Steps_per_output_revolution;  // Rotate anti-clockwise 360°  
  small_stepper.setSpeed(500);       
  small_stepper.step(Steps_travel);
  delay(1000);
}

