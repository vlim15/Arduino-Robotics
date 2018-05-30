int led = 13;//led goes into pin13
int AIN1 = 7;// motor A  goes into AIN2 and connect to pin7 on right side
int AIN2 = 8;// motor A goes into Ain2 and connects to pin8 on left side
int NIN1 = 4; // motor N goes into BIN2 and connects to pin4 
int NIN2 = 12; // motor N goes into BIN2 and connects to pin12


void setup() {
 Serial.begin(19200); // Running at 19200 milliseconds
 pinMode(led, OUTPUT); // The power of the LED that goes into pin 13 goes OUT
 pinMode(AIN1, OUTPUT); // THE AIN1 wire that connects to pin 7's power goes outside
 pinMode(AIN2, OUTPUT); // The AIN2 wire that connects to pin 8's power goes outside
 pinMode(NIN1, OUTPUT); // The NIN1 wire that connects to pin 4's power goes outside
 pinMode(NIN2, OUTPUT); // the NIN 2 wire that connects to pin 12's power goes outside
}
void forward() {
 digitalWrite(led, HIGH); // Led turn ON 
 digitalWrite(AIN1, HIGH); // Motor A 1st wire turn ON
 digitalWrite(AIN2, LOW); // Motor A 2nd wire turn oFF
 digitalWrite(NIN1, HIGH); // Motor B wire turn ON
 digitalWrite(NIN2, LOW); // Motor B wire turn oFF
}
void backward() {
 digitalWrite(led, HIGH); // LED ON
 digitalWrite(AIN1, LOW); // Motor A backwards OFF
 digitalWrite(AIN2, HIGH); // Motor A move backwards ON
 digitalWrite(NIN1, LOW); // Motor B move backwards OFF
 digitalWrite(NIN2, HIGH); // Motor B move backwards ON
}

void stop() {
 digitalWrite(led, LOW); // led stop OFF
 digitalWrite(AIN1, LOW); // Motor A wire 1 stop turn OFF 
 digitalWrite(AIN2, LOW); // Motor A wire 2  stop turn OFF
 digitalWrite(NIN1, LOW); // Motor B wire 1 turn oFF
 digitalWrite(NIN2, LOW); // Motor B wire 2 turn OFF
}
void loop() {
 char c = Serial.read(); // Character C will function in the robot. Serial.read will read the function after Char C happens
 Serial.println(c); // prints Char C to the serial port in human language, not code
 if (c == 'l') {    // if Char C equals to L
 digitalWrite(led, HIGH); // led turns ON
 Serial.println("left"); // prints data to the "left"
 left(); // when motor turns left
 delay(1000); // delay by 1 second
 }else if (c == 'r') { // motor turns left or else if C equals R
 Serial.println("Right"); // motor turns to the right
 right();
 delay(1000); // delays by 1 second when turning to the right
 } else if (c == 'f') { // Motor turns to the Right and delays by 1 second, or else C equals F
 Serial.println("Forward"); // Motor goes Forward after it turns to the right by 1 second
 forward();
 delay(1000); // stops for 1 second
 }else if (c == 'n') { // or else C equals N
 Serial.println("backward"); // motor goes backward
 backward();
 delay(1000); // pauses for 1 second 
 } else{ // pauses for 1 second after going back ward or else the motor
  stop(); // the motor stops

 }
  
 
}

void left() {
 digitalWrite(AIN1, LOW);
 digitalWrite(AIN2, HIGH);
 digitalWrite(NIN1, HIGH);
 digitalWrite(NIN2, LOW);
  
}

void right() {
 digitalWrite(AIN1, HIGH);
 digitalWrite(AIN2, LOW);
 digitalWrite(NIN1, LOW);
 digitalWrite(NIN2, HIGH);
  
}




 
