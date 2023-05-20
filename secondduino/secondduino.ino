
#include <Stepper.h>
const int stepsPerRevolution = 2038;

Stepper myStepper = Stepper(stepsPerRevolution, 9, 10, 11, 12);
float duration, distance;

void setup() {
  Serial.begin(9600); // Initialize serial communication
}

void loop() {
      /*
      myStepper.setSpeed(5);
	     myStepper.step(stepsPerRevolution / 2);
	    delay(1000);
	
	// Rotate CCW quickly at 10 RPM
	    myStepper.setSpeed(30);
	    myStepper.step(-stepsPerRevolution / 2);
      delay(1000);
      */
  if (Serial.available()) {
    char receivedChar = Serial.read(); // Read the incoming serial data
    Serial.println(receivedChar);
    if (receivedChar == 'H') { // Check if the received character is the activation signal
      // Activate the motor
        Serial.print("H si detected");
        myStepper.setSpeed(5);
	      myStepper.step(stepsPerRevolution / 2);
	      delay(10000);
	
	// Rotate CCW quickly at 10 RPM
	    myStepper.setSpeed(30);
	    myStepper.step(-stepsPerRevolution / 2);
      delay(1000);
    }
  }
}
