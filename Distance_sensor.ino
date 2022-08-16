#include <LiquidCrystal.h>
// załączona biblioteka LiquidCrystal
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int animationSpeed = 0;
int Trig = 7;  
int Echo = 6;

void setup() {
  
  Serial.begin(9600);   //inicjalizaja monitora szeregowego
  pinMode(Trig, OUTPUT);  // wyjście czujnika                 
  pinMode(Echo, INPUT);    // wejscie czujnika
  
  pinMode(10, OUTPUT); //Dioda czerwona
  pinMode(9, OUTPUT); //Dioda żółta
  pinMode(8, OUTPUT); //Dioda zielona
  
  digitalWrite(10, LOW); //Wyłączenie diod
  digitalWrite(9, LOW);  //Wyłączenie diod
  digitalWrite(8, LOW);	 //Wyłączenie diod
  
}

void loop() {
		zakres(100, 300); // zakres w jakim czujnik podaje odczyt
  		  delay(100);
	}

 int zmierzOdleglosc() { // funkcja mierzaca odleglosc 
  long czas, dystans;
 
  digitalWrite(Trig, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);
 
  czas = pulseIn(Echo, HIGH);
  dystans = czas / 58;
 
  return dystans;
}

void zakres(int a, int b) { // funkcja podajaca odczytany zakres 
  int jakDaleko = zmierzOdleglosc();
  if (jakDaleko < a) {   // jezeli bardzo blisko 
      		 lcd.clear();

        digitalWrite(8, HIGH); //Czerwona wlacz
            lcd.print("Bardzo blisko");
		delay(100);		//Opoznienie 
		digitalWrite(8, LOW); //Czerwona wyłącz
		delay(100);		//Opoznienie 
			
  }
  else if ((jakDaleko >= a)&&(jakDaleko <= b)){ // jezeli blisko 
         		 lcd.clear();

    	  digitalWrite(9, HIGH); //Zolta wlacz
            lcd.print("Blisko");
		delay(100);		//Opoznienie 
		digitalWrite(9, LOW); //Zolta wyłącz
		delay(100);		//Opoznienie 
  }
  else if (jakDaleko > b){ //jezeli daleko 
        		 lcd.clear();

    digitalWrite(10, HIGH); //Zielona wlacz
      lcd.print("Daleko");
		delay(100);           //Opoznienie 
		digitalWrite(10, LOW); //Zielona wyłącz
		delay(100);			//Opoznienie 
    
  }
   
}
