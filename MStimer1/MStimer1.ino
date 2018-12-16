
#include <MsTimer2.h>

// Switch on LED on and off each half second

#if ARDUINO >= 100
const int led_pin = LED_BUILTIN;	// 1.0 built in LED pin var
#else
const int led_pin = 13;			// default to pin 13
#endif


int zaehler = 0;

void flash()
{  
  static boolean output = HIGH;
  
  digitalWrite(led_pin, output);
  output = !output;
// zaehler++;
  
/*  if(zaehler > 10 )
  { // 10 wegen 5 mal umschalten
    MsTimer2::stop();
    zaehler = 0;
  }
*/
}

long int steigZ = 0;
long int Zeit = 0;
long int fallZ=0;

void ISRwiederholen(){
  
// static int steigZ=0;
// static int fallZ=0;    
  if(digitalRead(3) == HIGH)
  {
     steigZ = millis();   
  }
  else
  {
    fallZ = millis();  
    if(fallZ - steigZ >200)
    {
    MsTimer2::stop(); MsTimer2::set(fallZ-steigZ, flash); 
    MsTimer2::start();
    }  
  }
  Serial.print(steigZ); Serial.print("  ");
  Serial.println(fallZ);
}

void setup()
{
  pinMode(3,INPUT);
  pinMode(led_pin, OUTPUT);
  attachInterrupt(1 , ISRwiederholen , CHANGE);

  MsTimer2::set(500, flash); // 500ms period
  MsTimer2::start();
  Serial.begin(9600);
}

void loop()
{  
}
