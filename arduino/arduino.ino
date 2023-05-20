const int trigPin = 5;
const int echoPin = 6;
#define LED_PIN 7
#define GREEN_PIN 4
#define RED_PIN 2
#define BLUE_PIN 3
String incomingByte = "";
#include <Stepper.h>
const int stepsPerRevolution = 2038;

// Creates an instance of stepper class
// Pins entered in sequence IN1-IN3-IN2-IN4 for proper step sequence
Stepper myStepper = Stepper(stepsPerRevolution, 9, 10, 11, 12);


float duration, distance;

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
  Serial.write('H'); // You can use any character or value to represent the activation signal
  delay(1000); // Delay for 1 second
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
  myStepper.setSpeed(5);
	myStepper.step(stepsPerRevolution / 2);
	delay(10000);
	
	// Rotate CCW quickly at 10 RPM
	myStepper.setSpeed(30);
	myStepper.step(-stepsPerRevolution / 2);
  if (Serial.available() > 0) {
  incomingByte = Serial.readString(); // read the incoming byte:
  Serial.println(incomingByte);
  delay(500);
  //1000 works

if(incomingByte.indexOf("Biodegradables") != -1) {
  digitalWrite(BLUE_PIN, HIGH);
  delay(5000);  // Delay for 5 seconds (5000 milliseconds)

}
else if (incomingByte.indexOf("Non_biodegradable-Recyclable") != -1 || incomingByte.indexOf("Non_Biodegradable-Recyclable") != -1) {
  digitalWrite(GREEN_PIN, HIGH);
  delay(5000);  // Delay for 5 seconds (5000 milliseconds)


}
else if (incomingByte.indexOf("Non_Biodegradable") != -1) {
  digitalWrite(RED_PIN, HIGH);
  delay(5000);  // Delay for 5 seconds (5000 milliseconds)


}
else if (incomingByte.indexOf("Biodegradable-Recyclable") != -1) {
  digitalWrite(GREEN_PIN, HIGH);
  digitalWrite(BLUE_PIN, HIGH);
  delay(5000);  // Delay for 5 seconds (5000 milliseconds)

}
else {
    //digitalWrite(RED_PIN, LOW);
    //digitalWrite(GREEN_PIN, LOW);
    //digitalWrite(BLUE_PIN, LOW);
}
Serial.println(incomingByte);
  }
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration * .0343) / 2;

  //Serial.println(distance);


}