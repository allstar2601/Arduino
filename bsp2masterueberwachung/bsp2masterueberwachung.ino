#include <Wire.h>

void setup() {
  Wire.begin();        // join i2c bus (address optional for master)
  Serial.begin(9600);  // start serial for output
  pinMode(4,INPUT);
}
long int letzteZeit = 0;
long int startWert = 2000;
int zeit = 0;
void loop() {


  
  Wire.requestFrom(8, 2);    // request 6 bytes from slave device #8
  letzteZeit = millis();  
  
  while (Wire.available()) 
  { // slave may send less than requested
    byte eins = Wire.read(); // receive a byte as character
    byte zwei = Wire.read();
    zeit = eins *256 + zwei;
    Serial.println(zeit);         // print the character
   
   }
  if(digitalRead(4))
  {
    Wire.beginTransmission(8); 
    Wire.write('N');
    Wire.endTransmission(8); 
  }
  delay(1000);
}
