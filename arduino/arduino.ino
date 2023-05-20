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
Stepper myStepper = Stepper(stepsPerRevolution, 9, 10, 11, 12);


float duration, distance;

String string_in;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
}

void loop() {
  
  /*
  if (distance < 300) {
    digitalWrite(LED_PIN, HIGH);
    //digitalWrite(RED_PIN, HIGH);
    //digitalWrite(GREEN_PIN, HIGH);
    //digitalWrite(BLUE_PIN, HIGH);

  } else {
    digitalWrite(LED_PIN, LOW);
    digitalWrite(RED_PIN, LOW);
    digitalWrite(GREEN_PIN, LOW);
    digitalWrite(BLUE_PIN, LOW);
  }
  delay(100);
  */


  //myStepper.setSpeed(5);
	//myStepper.step(stepsPerRevolution / 2);
	//delay(10000);
	
	// Rotate CCW quickly at 10 RPM
	//myStepper.setSpeed(30);
	//myStepper.step(-stepsPerRevolution / 2);
  if (Serial.available() > 0) {
    String incomingByte;
    incomingByte = Serial.readString(); // read the incoming byte:
    incomingByte.trim();
  Serial.println(incomingByte);
  if (incomingByte == "0") {
  Serial.println("5");

  myStepper.setSpeed(5);
	myStepper.step(stepsPerRevolution / 2);
	delay(10000);
	
	//Rotate CCW quickly at 10 RPM
	myStepper.setSpeed(30);
	myStepper.step(-stepsPerRevolution / 2);
  }
  else if (incomingByte == "1") {
    Serial.write("1");
  }
  else if (incomingByte == "2") {
    Serial.write("2");
  }
  else {


  }
  }
  //Serial.println(distance);


}