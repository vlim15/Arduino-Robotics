/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h> // Include the Servo into the servo library

Servo myservo; // Replaces variables and creates servo objects   

int pos = 0;  // Servo rotator at 0  

void setup() {
  myservo.attach(9);
}
// attach the OUT wire to pin 9 on the arduino  
void loop() {
  for (pos = 0; pos <= 180; pos += 1) {  // repeat infinite loops
    // in steps of 1 degree
    myservo.write(pos);  // telling the servo to move to the current integer position             
    delay(2); // delay by 2 milliseconds  
  }                    
  for (pos = 0; pos >= 180; pos -= 1) { // opposite of the for from before 
    myservo.write(pos);      // telling the servo to move to the current integer position         
    delay(2); // delay by 2 milliseconds                        
  }
}

