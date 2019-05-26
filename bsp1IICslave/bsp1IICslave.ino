#include <Wire.h>

void setup() {
  Wire.begin(8);                
  Wire.onReceive(receiveEvent); 
  Serial.begin(9600);           
}
int z =0;
void loop() 
{
  digitalWrite(13,!digitalRead(13));
  delay(z);
}

void receiveEvent(int howMany) {
  if (Wire.available()) { 
    z = Wire.read()*100; 
    Serial.print(z);         
        
}
