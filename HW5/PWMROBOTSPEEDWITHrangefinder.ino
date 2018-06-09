#include <IRremote.h>
const int RECV_PIN = 2; // INTEGER at pin 2
int triggerPin = 6; // triggerPin on ultrasonic rangefinder goes into 6
int echoPin = 5; // echoPin on ultraSonic rangefinder goes into 5
int button = A0; // button goes into A0
int led = 13; // ledPin goes into 13
int motorPWMA = 9; // motorPWMA goes into 9
int motorPWMB = 10; // motorPWMB goes into 10
float inches; // approximate analog read 
int motspeed = 255; // motspeed's maximum reach is at 225


IRrecv irrecv(RECV_PIN);
decode_results results;

int AIN1 = 7;// motor A  goes into AIN2 and connect to pin7 on right side
int AIN2 = 8;// motor A goes into Ain2 and connects to pin8 on left side
int NIN1 = 4; // motor N goes into BIN2 and connects to pin4
int NIN2 = 12; // motor N goes into BIN2 and connects to pin12

void setup() {
  Serial.begin(19200);
  Serial.println(19200);
  pinMode(AIN1, OUTPUT); // THE AIN1 wire that connects to pin 7's power goes outside
  pinMode(AIN2, OUTPUT); // The AIN2 wire that connects to pin 8's power goes outside
  pinMode(NIN1, OUTPUT); // The NIN1 wire that connects to pin 4's power goes outside
  pinMode(NIN2, OUTPUT); // the NIN 2 wire that connects to pin 12's power goes outside
  pinMode(button, INPUT_PULLUP); // the input of the button 
  pinMode(led, OUTPUT); // power of LED goes outside
  pinMode(triggerPin, OUTPUT); // 
  pinMode(echoPin, INPUT);
  digitalWrite(triggerPin, LOW);
  irrecv.enableIRIn(); // Start the receiver

}

float ping() { // determine the time for the triggerPin to locate/give power to robot from the rangefinder
  unsigned long maxTime = 20000;
  unsigned long us;
  float inches;
  // Hold triggerPin high for at least 10us
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  // Measure length of high pulse on echoPin
  us = pulseIn(echoPin, HIGH, maxTime);
  // pulseIn returns 0 on timeout. Assume worst case.
  if (us == 0) {
    us = maxTime;
  }
  // Convert roundtrip microseconds to inches
  inches = us * 0.013504 / 2;
  return inches;
}


void loop() {
  inches = ping();
  //Serial.println(inches);
  
  delay(60);
  /*
     Triggers a ping on the ultrasonic range sensor. Waits
     up to 20ms for an echo and returns distance in inches.
     Datasheet recommends waiting 60ms between readings.
  */
  remote();
  if (digitalRead(button) == LOW){
    //Serial.println("Button pressed");
    digitalWrite(led, HIGH);
   }
  else {
    //Serial.println("Button not pressed");
    digitalWrite(led, LOW);
  }
  
}

void remote(){

  analogWrite(led, 128);

  if (irrecv.decode(&results)) {
    irrecv.resume(); // Receive the next value

    if (results.value == 0x41BED02F && inches>1) {
      Serial.println("Button Up");
      forward(motspeed);
      delay(1000);

    }

    else if (results.value == 0x41BE609F) {
      Serial.println("Button Down");
      backward(motspeed);
      delay(1000);

    }
    else if (results.value == 0x41BEB04F) {
      Serial.println("Button Right");
      right(motspeed);


    }
    else if (results.value == 0x41BE40BF) {
      Serial.println("Button Left");
      left(motspeed);
      Serial.println(motspeed);
      delay(1000);
    } else if(results.value == 0x41BE10EF && motspeed < 255){
      Serial.println("SpeedUp");
      motspeed += 10;
    
    } else if(results.value == 0x41BE708F && motspeed < 255){
      Serial.println("SpeedDown");
      motspeed -= 10;
    }
    else{
      Serial.print("Unrecognized: ");
      Serial.print(results.value, HEX);
      Serial.println();
      stop();
    }

    irrecv.resume(); // Receive the next value
  }
  delay(100);
}

void forward(int howFast) {
  analogWrite(motorPWMA, howFast);
  analogWrite(motorPWMB, howFast);
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  digitalWrite(NIN1, HIGH);
  digitalWrite(NIN2, LOW);
}

void backward(int howFast) {
  analogWrite(motorPWMA, howFast);
  analogWrite(motorPWMB, howFast);
  digitalWrite(AIN1, LOW); // Motor A 1st wire turn ON
  digitalWrite(AIN2, HIGH); // Motor A 2nd wire turn oFF
  digitalWrite(NIN1, LOW); // Motor B wire turn ON
  digitalWrite(NIN2, HIGH); // Motor B wire turn oFF
}

void stop() {
  digitalWrite(AIN1, LOW); // Motor A wire 1 stop turn OFF
  digitalWrite(AIN2, LOW); // Motor A wire 2  stop turn OFF
  digitalWrite(NIN1, LOW); // Motor B wire 1 turn oFF
  digitalWrite(NIN2, LOW); // Motor B wire 2 turn OFF
}


void right(int howFast) {
  analogWrite(motorPWMA, howFast);
  analogWrite(motorPWMB, howFast);
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, HIGH);
  digitalWrite(NIN1, HIGH);
  digitalWrite(NIN2, LOW);

}

void left(int howFast) {
  analogWrite(motorPWMA, howFast);
  analogWrite(motorPWMB, howFast);
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  digitalWrite(NIN1, LOW);
  digitalWrite(NIN2, HIGH);

}


