#include <Wire.h>

#define BUTTON 2
#define ADDRESS 42

void setup() {
  Serial.begin(112500);           // start serial for output
  pinMode(BUTTON, INPUT);
  digitalWrite(BUTTON, HIGH);
  Wire.begin();
}

boolean last_state = HIGH;
void loop() {
  if (digitalRead(BUTTON) != last_state){
    last_state = digitalRead(BUTTON);
    Serial.println("Start");
    Wire.beginTransmission(42);
    Serial.println("Beginning transmission");
    Wire.write(last_state);
    Serial.println("Sent Data");
    Wire.endTransmission(42);
    Serial.println("Ended transmission");
  }
}
