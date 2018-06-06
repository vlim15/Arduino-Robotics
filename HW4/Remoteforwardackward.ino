#include <IRremote.h>
const int RECV_PIN = 2; // INTEGER at pin 2
IRrecv irrecv(RECV_PIN);
decode_results results;

int AIN1 = 7;// motor A  goes into AIN2 and connect to pin7 on right side
int AIN2 = 8;// motor A goes into Ain2 and connects to pin8 on left side
int NIN1 = 4; // motor N goes into BIN2 and connects to pin4
int NIN2 = 12; // motor N goes into BIN2 and connects to pin12

void setup() {
  Serial.begin(19200);
  pinMode(AIN1, OUTPUT); // THE AIN1 wire that connects to pin 7's power goes outside
  pinMode(AIN2, OUTPUT); // The AIN2 wire that connects to pin 8's power goes outside
  pinMode(NIN1, OUTPUT); // The NIN1 wire that connects to pin 4's power goes outside
  pinMode(NIN2, OUTPUT); // the NIN 2 wire that connects to pin 12's power goes outside
  irrecv.enableIRIn(); // Start the receiver
  //irrecv.blink13(true);
}

void loop() {


  if (irrecv.decode(&results)) {
    irrecv.resume(); // Receive the next value
  
    if (results.value == 0x41BED02F) {
      Serial.println("Button Up");
      forward();
      delay(1000);
  
    }
    else if (results.value == 0x41BE609F) {
      Serial.println("Button Down");
      backward();
      delay(1000);
  
  
    }
    else if (results.value == 0x41BEB04F) {
      Serial.println("Button Right");
      right();
      delay(1000);
  
    }
    else if (results.value == 0x41BE40BF) {
      Serial.println("Button Left");
      left();
      delay(1000);
    }
  
    else {
      Serial.print("Unrecognized: ");
      Serial.print(results.value, HEX);
      Serial.println();
      stop();
    }

  irrecv.resume(); // Receive the next value
  }
  delay(100);
}



void backward() {
  digitalWrite(AIN1, HIGH); // Motor A 1st wire turn ON
  digitalWrite(AIN2, LOW); // Motor A 2nd wire turn oFF
  digitalWrite(NIN1, HIGH); // Motor B wire turn ON
  digitalWrite(NIN2, LOW); // Motor B wire turn oFF
}

void forward() {
  digitalWrite(AIN1, LOW); // Motor A backwards OFF
  digitalWrite(AIN2, HIGH); // Motor A move backwards ON
  digitalWrite(NIN1, LOW); // Motor B move backwards OFF
  digitalWrite(NIN2, HIGH); // Motor B move backwards ON
}

void stop() {
  digitalWrite(AIN1, LOW); // Motor A wire 1 stop turn OFF
  digitalWrite(AIN2, LOW); // Motor A wire 2  stop turn OFF
  digitalWrite(NIN1, LOW); // Motor B wire 1 turn oFF
  digitalWrite(NIN2, LOW); // Motor B wire 2 turn OFF
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


