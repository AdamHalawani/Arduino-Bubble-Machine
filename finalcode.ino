#include <Servo.h>










void setup() {

  Serial.begin(9600);
  pinMode(motor1, OUTPUT);
  pinMode(sensorPin, INPUT);

  pinMode(motorPin, OUTPUT); // Set up DC motor pin

  panServo.attach(8); //pan servo on pin 8
  tiltServo.attach(9); //tilt servo on pin 9
}

void loop() {
  sensorValue = analogRead(sensorPin);

  sensorValue = map(sensorValue, 0, 1023, 170, 250);
  Serial.println (sensorValue);
  pinMode(motor1, OUTPUT);
  pinMode(sensorPin, INPUT);
  analogWrite(motor1, sensorValue);
  analogWrite(motor2, sensorValue);
  analogWrite(motor3, sensorValue);
  analogWrite(motor4, sensorValue);

  for (pos = 0; pos < 95; pos += 1) { //servo moves from 0 degrees to 95 degrees in steps of 1 degree
    tiltServo.write(pos); // tell servo to go to position in variable 'pos'
    delay(15);
  }
  motorOnThenOff();
  for (pos = 95; pos >= 1; pos -= 1) { // tilt servo raises and levels off
    tiltServo.write(pos);
    delay(15);
  }
  for (pos = 0; pos < 90; pos += 1) { //servo moves 0 degrees to 90 degrees in steps of 1 degree
    panServo.write(pos); // tell servo to go to position in variable 'pos'
    delay(15);
  }

  for (pos = 90; pos >= 1; pos -= 1)
  { // pan servo swings wand around
    panServo.write(pos);
    delay(15);
  }
}
void motorOnThenOff() {
for (int i = 0; i < 200; i++)
{
  analogWrite(motorPin, i); // turns the motor On
}
  delay(2000); // waits for 2 seconds
  analogWrite(motorPin, 0); // turns the motor Off
  delay(500); // waits for 0.5 second
}
