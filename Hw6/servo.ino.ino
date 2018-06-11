#include <IRremote.h>      //must copy IRremote library to arduino libraries
#include <Servo.h>
#define plus 0xA3C8EDDB   //clockwise rotation button
#define minus 0xF076C13B  //counter clockwise rotation button

int RECV_PIN = 2;       //IR receiver pin
int servoPin = 9;
Servo servo;
int val;                //rotation angle
bool cwRotation, ccwRotation;  //the states of rotation

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  servo.attach(9);     //servo pin
}

void loop() 
{
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    irrecv.resume(); // Receive the next value

    if (results.value == plus)
    {
      cwRotation = !cwRotation;      //toggle the rotation value
      ccwRotation = false;         //no rotation in this direction
    }

    if (results.value == minus)
    {
      ccwRotation = !ccwRotation;   //toggle the rotation value
      cwRotation = false;            //no rotation in this direction
    }
  }
  if (cwRotation && (val != 175))  {
    val++;                         //for colockwise button
  }
  if (ccwRotation && (val != 0))  {
    val--;                         //for counter colockwise button
  }
  servo.write(val);
  delay(20);          //General speed
}
