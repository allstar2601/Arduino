#include <Wire.h>

void setup() {
  Serial.begin(9600);
  Wire.begin(8);                // join i2c bus with address #8
  Wire.onRequest(requestEvent); // register event
  pinMode(5,INPUT);
  Wire.onReceive(receiveEvent);
}
int zeit = 0;
byte eins = 0;
byte zwei = 0;
void loop() 

{
  
  delay(100);
  if(digitalRead(5))
  {
   zeit = zeit + 1;
  }
  eins = zeit/256;
  zwei = zeit%256;
  Serial.println(zeit);
}
void receiveEvent(){
  char c = Wire.read();

  if(c == 'N')
  {
  zeit = 0;  
  }
  
}
// function that executes whenever data is requested by master
// this function is registered as an event, see setup()
void requestEvent() {
  Wire.write(eins); // respond with message of 6 bytes
  Wire.write(zwei);
  // as expected by master
}
