/* 28BYJ-48 stepper control - modified from code found at 
   https://www.arduino.cc/en/Tutorial/StepperOneRevolution
   Using full steps, this motor has 32 steps per rotor revolution
   but it also has a 64:1 reduction gearbox onboard
   Wiring 11 = In1, 10 = In2, 9 = In3, 8 = In4 
*/
#include <Stepper.h>
#define Steps_per_motor_revolution  32       // 32 steps per rotor revolution
#define Steps_per_output_revolution 32 * 64  // 64:1 reduction gearing
int  Steps_travel;

// 28BYJ-48 Pin 'firing' order 1-3-2-4
Stepper small_stepper(Steps_per_motor_revolution, 11, 9, 10, 8);

void setup()
{
  // Stepper Library sets up pins 8-11 as outputs
}

void loop()
{
  Steps_travel  =  Steps_per_output_revolution;    // Rotate clockwise 360°
  small_stepper.setSpeed(500);                     // Set RPM ~500 max speed
  small_stepper.step(Steps_travel);
  delay(1000);
  
  Steps_travel  =  - Steps_per_output_revolution;  // Rotate anti-clockwise 360°  
  small_stepper.setSpeed(500);       
  small_stepper.step(Steps_travel);
  delay(1000);
}

