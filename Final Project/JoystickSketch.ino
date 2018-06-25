#include <Servo.h>

//define servos for first joystick
Servo servo1; //creates servo object inside servo to control a servo
Servo servo2; //creates a second servo object inside servo to control the second servo

//servo for second joystick
Servo servo3; //creates a third servo object inside the top servo to control the third servo

//define servo postions on joystick
int pos = 50; //the position is set to 50. Everything starts at 0 degrees
int pos1 = 50; //Starts at 50 degrees

//define servo positions on second joystick
int pos2 = 50; //Starts at 50 degrees
int pos3 = 50; //Starts at 50 degrees

//variable to read the value from the analog pins and buttonPin 
int joyVal = 0; //value for the value of joystick is at 0
int joyVal2 = 0; //value for the value of joystick is at 0
int buttonState = 0; //value for button is at 0 


//define joystick pins
//const int SW_pin = 2; // digital pin for switch connected to 2
const int VRY_pin = A1; // analog pin connected to Y output
const int VRX_pin = A4; //analog pin connected to X output
const int buttonPin = 2; // digital pin for buttonState

void setup() {
  //servo pins
  servo1.attach(3); //servo1 attached to digital pin 3
  servo2.attach(4); //servo2 attached to digital pin 4

  //servo pin on second joystick
  servo3.attach(12); //servo3 attached to digital pin 12


  //button pins
  pinMode(buttonPin, INPUT); //buttonPin's voltage is at INPUT

  Serial.begin(19200); //opens serial port, sets data rate to 19200 bps 

}

void loop() {

  //first joystick functions

  int joyVal = map(analogRead(VRX_pin), 512, 1023, 0, 1); //remaps fromhigh toHigh, and fromLow toLow.  lower bound to the upper current/target range
  pos = constrain(pos + joyVal, 10, 90); //makes sure that the position position and value of the joystick is at 0 degrees. The lowest speed it starts at is 0, and the highest speed it can rotate to is 180
  servo1.write(pos); //sets the servo position according to the degree of pos
  Serial.println(pos); //prints the position of the servo into the serial monitor

  int joyVal2 = map(analogRead(VRY_pin), 512, 1023, 0, 1); //remaps fromhigh toHigh, and fromLow toLow.  lower bound to the upper current/target range
  pos1 = constrain(pos1 + joyVal2, 10, 90); //makes sure that the position position and value of the joystick is at 0 degrees. The lowest speed it starts at is 0, and the highest speed it can rotate to is 180
  servo2.write(pos1); //set the servo position according to the degree of pos


  buttonState = digitalRead(buttonPin); //the value of buttonState goes into the specified digital pin

  Serial.println(buttonState); //prints the buttonState's value into the serial monitor 
  if (buttonState == 1) { //if Statement for buttonState's value 
    servo3.write(20); //sets the servo's position according to the degree
  }

  else {
    servo3.write(120);  //sets the servo's position according to the degree
  }

}

