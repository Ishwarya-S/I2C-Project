#include <Wire.h>

#define LED_OUT 11
#define ADDRESS 43

void setup() {
  pinMode(LED_OUT, OUTPUT);
  digitalWrite(LED_OUT, LOW);
  Serial.begin(112500);
  Wire.begin(43);
  Wire.onReceive(receiveEvent);
}
boolean last_state = HIGH;

void loop(){

}
void receiveEvent(int howMany){
  while (Wire.available() > 0){
    boolean b = Wire.read();
    Serial.print(b, DEC);
    digitalWrite(LED_OUT, !b);
  }
  Serial.println(); 
}
