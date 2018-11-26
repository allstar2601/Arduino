class CBlinkLED{
    private:
      int pinNr;
      bool blinkenAktiv;
      long int letzteBlinkZeit;
      long int blinkZeit;
      bool letzterWert = LOW;
      long int zeitsteig;
      long int zeitfall;
    public:
         CBlinkLED(int pinNr0){
          pinNr = pinNr0;
          blinkenAktiv = false;
          pinMode(pinNr , OUTPUT);
          digitalWrite(pinNr,LOW);
         }

         void ein()
         {
           digitalWrite(pinNr,HIGH);
         }

         void aus()
         {
           digitalWrite(pinNr,LOW);
         }

         void umschalten()
         {
           digitalWrite(pinNr,!digitalRead(pinNr));
         }

         void startBlink(long int blinkZeit0)
         {
           blinkZeit=blinkZeit0;
           blinkenAktiv=true;
         }

         void stopBlink()
         {
           blinkenAktiv=false;
         }

         void check()
         {
           if( blinkenAktiv && (millis()>letzteBlinkZeit+blinkZeit))
           {
             umschalten();
             letzteBlinkZeit=millis();
           }
           bool jetzigerWert = digitalRead(pinNr);
           bool steigendeflanke =!letzterWert && jetzigerWert;
           bool fallendeflanke = letzterWert && !jetzigerWert;
           letzterWert = jetzigerWert;
           if(steigendeflanke) zeitsteig = millis();
           if(fallendeflanke) zeitfall = millis();
         }
       long int zeitein(){
          if(isOn())
          {
            return millis()-zeitsteig;
          }else
          {
            return zeitfall - zeitsteig;
          }
        }
    long int zeitaus(){
      if(!isOn())
        {
          return millis()-zeitfall;
        }
        else
        {
          return zeitsteig - zeitfall;
        }
    }
         boolean isBlinking()
         {
           return blinkenAktiv;
         }

         boolean isOn()
         {
           return digitalRead(pinNr);
         }
};
class CTaster{
  private:
    int pinNr;
    bool steigFlanke;
    bool fallFlanke; 
    boolean letzterWert;
    long int zeitSteigFlanke;
    long int zeitFallFlanke;   
    int AnzahlSteigendeFlanken;  
  public:
    CTaster(int pinNr_){
      pinNr = pinNr_;
      pinMode(pinNr, INPUT);
    }

    boolean istGedrueckt()
    {
      return digitalRead(pinNr);
    }
        
    void check()
    {
      bool jetzigerWert=istGedrueckt();
      steigFlanke = !letzterWert && jetzigerWert;
      fallFlanke = letzterWert && !jetzigerWert; 
      letzterWert = jetzigerWert;
      if (steigFlanke)
      {
        zeitSteigFlanke=millis();
        AnzahlSteigendeFlanken = AnzahlSteigendeFlanken + 1 ;
      }
      if (fallFlanke) zeitFallFlanke=millis();
    }
    int steigendeFlanken()
    {
      return AnzahlSteigendeFlanken;  
    }
    bool steigendeFlanke()
    {
      return steigFlanke;   
    }

    bool fallendeFlanke()
    {
      return fallFlanke;
    }

    long int zeitGedrueckt()
    {
      if (istGedrueckt())
      {
        return millis()-zeitSteigFlanke;
      }
      else
      {
        return zeitFallFlanke - zeitSteigFlanke;
      }
    }

    long int zeitLosgelassen()
    {
      if (!istGedrueckt())
      {
        return millis()-zeitFallFlanke;
      }
      else
      {
        return zeitSteigFlanke - zeitFallFlanke;
      }
    }
    
};

CBlinkLED internalLED(13);
CBlinkLED grueneLED(6);
CTaster taster1(4);

void setup() {
  
  
  //grueneLED.startBlink(200);
  //internalLED.startBlink(1200);
  Serial.begin(9600);
}

void loop() {
 
 
 //internalLED.check();
 grueneLED.check();
 taster1.check();
 //Serial.println(taster1.zeitGedrueckt());
  long int zeit = taster1.zeitGedrueckt();
 if(zeit< 1000){
  grueneLED.startBlink(200); 
 }
 if(zeit >= 1000)
 {
   grueneLED.startBlink(1000);
 }
 //Serial.println(grueneLED.zeitein());
 //Serial.println(grueneLED.zeitaus());
 Serial.println(taster1.steigendeFlanken());

 /*
 if(taster1.fallendeFlanke())
 {
  internalLED.stopBlink();
  grueneLED.stopBlink();  
 } 
 if(taster1.steigendeFlanke())
 {
  grueneLED.startBlink(1500);
  internalLED.startBlink(1000);  
 }*/
}
