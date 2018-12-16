void setup() 
{
  // put your setup code here, to run once:
pinMode(6,OUTPUT);
pinMode(7,OUTPUT);
pinMode(5,INPUT);
}
int zustand =1;
#define grueneLED 6
#define roteLED 7
#define taste 5
long int startzeit = 0;
 
  void loop() 
{
  
  switch(zustand)
  {
    case 1: rotStart_1();break;
    case 2: rotWarten_2();break;
    case 3: gruenStart_3();break;
    case 4: gruenWarten_4();break;
  }
  
}

  void rotStart_1()
{
  digitalWrite(grueneLED,LOW); digitalWrite(roteLED,HIGH);
  startzeit = millis();
  zustand = 2;
}

  void rotWarten_2()
{
  // es gibt keine auszuführende Befehle
  if (millis() > startzeit + 3000) zustand = 3;
  //if(digitalRead(5)) zustand=3;
}
  void gruenStart_3()
{
  digitalWrite(grueneLED,HIGH); digitalWrite(roteLED,LOW);
  startzeit = millis();
  zustand = 4;
}

void gruenWarten_4()
{
  //if (millis() > startzeit + 5000) zustand = 1;
  if(digitalRead(5)||millis() > startzeit + 5000) zustand = 1;
}

