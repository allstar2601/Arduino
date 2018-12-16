void setup() 
{
  attachInterrupt(0 , ISRsteigzeit , RISING);
  Serial.begin(9600);
}

long int steig1 = 0;
long int steig= 0;
int anz = 0;
float velocity = 0;
float streckeproloch = (6,7 / 3,14) / 20;
float strecke = 0;
void loop() 
{
// Serial.println(steig);
 //Serial.print("\t");
 //Serial.println(anz);
 //Serial.print("\t");
 Serial.println(velocity);
 Serial.print("\t");
 Serial.println(strecke);
}

void ISRsteigzeit()
  {
  long int zeitjetzt = millis();
  
  steig = (zeitjetzt - steig1) ; 
  velocity = streckeproloch*1000 / steig;
  strecke = velocity * steig;
 
  steig1 = zeitjetzt;
  }
