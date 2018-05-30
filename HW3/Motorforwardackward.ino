 int Motor = 11; // motor plug into pin 11

 void setup() {
    pinMode(Motor, OUTPUT);  // pin 11 wire voltage goes OUT
 }


void loop(){
    digitalWrite(Motor, HIGH); // motor turns ON
    delay(2000); // pauses for 2 seconds
    digitalWrite(Motor, LOW); // motor turns OFF
    delay(2000); // pauses for 2 seconds
  
}

