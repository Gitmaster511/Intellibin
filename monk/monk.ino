//Includes the Arduino Stepper Library

// Defines the number of steps per rotation
const int stepsPerRevolution = 2038;
#include <Stepper.h>
// Creates an instance of stepper class
// Pins entered in sequence IN1-IN3-IN2-IN4 for proper step sequence
Stepper myStepper = Stepper(stepsPerRevolution, 9, 10, 11, 12);

void setup() {
    // Nothing to do (Stepper Library sets pins as outputs)
}

void loop() {
	// Rotate CW slowly at 5 RPM
	myStepper.setSpeed(5);
	myStepper.step(stepsPerRevolution / 2);
	delay(10000);
	
	// Rotate CCW quickly at 10 RPM
	myStepper.setSpeed(30);
	myStepper.step(-stepsPerRevolution / 2);
	delay(1000);
}