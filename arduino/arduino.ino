const int trigPin = 5;
const int echoPin = 6;
#define LED_PIN 7
#define GREEN_PIN 4
#define RED_PIN 2
#define BLUE_PIN 3

#include <Stepper.h>
const int stepsPerRevolution = 2038;

// Creates an instance of stepper class
// Pins entered in sequence IN1-IN3-IN2-IN4 for proper step sequence
Stepper Trash = Stepper(stepsPerRevolution, 9, 10, 11, 12);
Stepper Recycle = Stepper(stepsPerRevolution, 4, 5, 6, 7);
Stepper Bio = Stepper(stepsPerRevolution, A5, A4, A3, A2);

float duration, distance;

String string_in;

void setup() {
  Serial.begin(9600);
  pinMode(A5, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);


}

void loop() {
  //myStepper.setSpeed(5);
	//myStepper.step(stepsPerRevolution / 2);
	
	// Rotate CCW quickly at 10 RPM
	//myStepper.setSpeed(30);
	//myStepper.step(-stepsPerRevolution / 2);






  if (Serial.available() > 0) {

    String incomingByte = Serial.readString(); // read the incoming byte:
    //incomingByte.trim();
    //incomingByte = incomingByte.replace("\r\n", "").replace("\r", "").replace("\n", "").replace("b", "");
    Serial.println(incomingByte);

  if (incomingByte == "0") {
     Serial.println("Trash");

  Trash.setSpeed(5);
	Trash.step(stepsPerRevolution);
  delay(5000);
  Trash.setSpeed(30);
	Trash.step(-stepsPerRevolution);
  }
  else if (incomingByte == "2") {

  Recycle.setSpeed(5);
	Recycle.step(stepsPerRevolution);
  delay(5000);
  Recycle.setSpeed(30);
	Recycle.step(-stepsPerRevolution);

  }
  else if (incomingByte == "1") {

  Bio.setSpeed(5);
	Bio.step(stepsPerRevolution);
  delay(5000);
  Bio.setSpeed(30);
	Bio.step(-stepsPerRevolution);
  }
  else {
  }
  }
  //Serial.println(distance);


}