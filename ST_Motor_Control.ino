//www.elegoo.com
//2018.10.25

/*
  Stepper Motor Control - one revolution

  This program drives a unipolar or bipolar stepper motor.
  The motor is attached to digital pins 8 - 11 of the Arduino.

  The motor should revolve one revolution in one direction, then
  one revolution in the other direction.

*/

#include <Stepper.h>

const int stepsPerRevolution = 2048;  // change this to fit the number of steps per revolution
const int rolePerMinute = 5;         // Adjustable range of 28BYJ-48 stepper is 0~17 rpm
float nMinutes = 1/5; //in Minutes
float nRotations = rolePerMinute*nMinutes;
float blowerOn = 2000; //In milliseconds

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);

void setup() {
  myStepper.setSpeed(rolePerMinute);
  pinMode(2, OUTPUT);
  Serial.begin(9600);
}

void loop() {  
  // step one revolution  in one direction:
  Serial.println("clockwise");
  myStepper.step(stepsPerRevolution*nRotations);
  
  digitalWrite(2, HIGH);
  Serial.println("high");
  delay(blowerOn);
  
  digitalWrite(2, LOW);
  Serial.println("low");

}
