#include <Servo.h>
/********************************************************************************/
Servo BottomServo; // create servo object to control the pan servo
Servo TopServo;  // create servo object to control the tilt servo
/********************************************************************************/
// Set the motors to their pins.
const int Motor1 = 3;
const int Motor2 = 4;
const int Motor3 = 6;
const int Motor4 = 11;
const int MainMotor = 13;
/********************************************************************************/
int Potentiometer = A0;    // select the input pin for the potentiometer
int Value = 0;  // variable to store the value coming from the potentiometer
byte pos = 0; // variable to store starting servo positions
/********************************************************************************/

void setup() 
{
// Set the motors pins as outputs.
pinMode(MainMotor, OUTPUT);
pinMode(Motor1, OUTPUT);
pinMode(Motor2, OUTPUT);
pinMode(Motor3, OUTPUT);
pinMode(Motor4, OUTPUT);

// Set the motors pins as Input.
pinMode(Potentiometer, INPUT); //
BottomServo.attach(8);// Bottom servo set to pin 8
TopServo.attach(9);   // Top servo set to pin 9
}

void loop() 
{
  
  Value = analogRead(Potentiometer); // making value equal to the reading from the potentiometer.
  map(Value, 0,1023,90,254); //Mapping the Value to write it on the 4 Motors.
/********************************************************************************/
 // Writing the Value on the Motors.
  analogWrite(Motor1, Value); 
  analogWrite(Motor2, Value);
  analogWrite(Motor3, Value);
  analogWrite(Motor4, Value);
/********************************************************************************/
for(pos = 0; pos < 95; pos += 1)//servo moves from 0 degrees to 95 degrees in steps of 1 degree
{ 
    TopServo.write(pos); // tell servo to go to position in variable 'pos'
    delay(30);
}
 motorOnThenOff();
for (pos = 95; pos >= 1; pos -= 1) { // tilt servo raises and levels off
    TopServo.write(pos);
    delay(30);
}
for (pos = 0; pos < 90; pos += 1) { //servo moves 0 degrees to 90 degrees in steps of 1 degree
    BottomServo.write(pos); // tell servo to go to position in variable 'pos'
    delay(30);
  }
   for (pos = 90; pos >= 1; pos -= 1)
  { // pan servo swings wand around
    BottomServo.write(pos);
    delay(30);
  }


}
void motorOnThenOff(){

  analogWrite(MainMotor, 225); // turns the motor On
  delay(3000); // waits for 3 seconds.
  analogWrite(MainMotor, 0); // turns the motor Off
  delay(500); // waits for 0.5 second.
}
