#include <IRremote.h>
#include <Servo.h>

const int RECV_PIN = 11; //Define sensor pin for IR Receiver

const int SERVO_PIN = 9;

int pos = 0; //Position of servo starts at 90 degrees. Variable for servo

unsigned long lastCode; //Define variable to store last code received

IRrecv irrecv(RECV_PIN);
decode_results results;

Servo myservo; //Creates a servo object within the current servo
void setup () {
  Serial.begin(9600); //Serial Monitor at 9600 baud
  irrecv.enableIRIn(); // Enable the IR Receiver
  myservo.attach(SERVO_PIN); //Attach the servo to the Arduino

  myservo.write(pos); //Start with Servo in Center
  Serial.println("Setup complete"); //Prints "Setup Complete" into serial monitor
}

void loop() {
  if (irrecv.decode(&results)) { // checks to see if a code has been received
    //Serial.println("Got Value");
    if (results.value == 0x41BE40BF) 
    {
      for (pos = 0; pos <= 90; pos += 1) { // If Servo position is 0 and 0 is less than or equal to 90, position gets added by 1
        myservo.write(pos); //Writes the current position of the servo into the serial port
        delay(15); // Delays by 15 milliseconds 
      }
    }
    else if (results.value == 0x41BEB04F)
    {
      for (pos = 90; pos >= 0; pos -= 1) { // if Servo position is at 90 degrees & position is greater than or equal to 0, Servo minuses by 1 until it hits 0
        myservo.write(pos); // writes the position of the servo into the serial port
        delay(15); // Delays by 15 milliseconds

      }
    }
    if (results.value == 0x41BED02F)
    {
        pos = 45; // Servo position is at 45
        myservo.write(pos); //Writes the current position into the serial port
        delay(15); //Delays by 15 by 15 milliseconds
      }
      else if (results.value == 0x41BED02F)
      {
        pos = 45; //Servo position is at 45
        myservo.write(pos); //Writes the current position into the serial port
        delay(15); //Delays by 15 milliseconds

        } else {
          Serial.print("Unrecognized: 0x"); //If serial monitor does not recognize a value, it prints it as "0x"
          Serial.print(results.value, HEX); //hexadecimals numBers
          Serial.println();
        }
        irrecv.resume();
      }
      delay(100); //Entire sketch delays by 100 milliseconds 
    }
