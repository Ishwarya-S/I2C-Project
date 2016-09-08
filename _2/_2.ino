#include <Wire.h>

#define LED_OUT 12
#define BUTTON 3
#define ADDRESS 42
#define ADDRESS 43

void setup() {
  pinMode(BUTTON, INPUT);
  digitalWrite(BUTTON, HIGH);
  pinMode(LED_OUT, OUTPUT);
  digitalWrite(LED_OUT, LOW);
  Serial.begin(112500);
  Wire.begin(43);
  Wire.begin(42);
  
  Wire.onReceive(receiveEvent);
}
boolean last_state = HIGH;

void loop(){
  if (digitalRead(BUTTON) != last_state){
    last_state = digitalRead(BUTTON);
    Serial.println("Start");
    Wire.beginTransmission(43);
    Serial.println("Beginning transmission");
    Wire.write(last_state);
    Serial.println("Sent Data");
    Wire.endTransmission(43);
    Serial.println("Ended transmission");
  }
}

void receiveEvent(int howMany){
  while (Wire.available() > 0){
    boolean b = Wire.read();
    Serial.print(b, DEC);
    digitalWrite(LED_OUT, !b);
  }
  Serial.println(); 
}
