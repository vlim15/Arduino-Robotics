
 void setup() {
Serial.begin(19200);
pinMode(A0, INPUT);
 pinMode (A1, INPUT);
 pinMode (A2, INPUT);
 
}

void loop() {
     int value0;
     int value1;
     int value2;   
     value0 = analogRead(A0);
     value1 = analogRead(A1);
     value2 = analogRead(A2);
 Serial.print("Value0: ");
 Serial.print("Value1: "); 
 Serial.print("Value2: ");
 Serial.println(value0);
 Serial.println(value1);
 Serial.println(value2);
}
