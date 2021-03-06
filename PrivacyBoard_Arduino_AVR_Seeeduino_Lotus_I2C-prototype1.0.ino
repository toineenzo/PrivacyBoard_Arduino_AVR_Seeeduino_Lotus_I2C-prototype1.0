#include <LiquidCrystal_I2C.h>           //importeer LCD library
#include <Wire.h>                        //importeer de kabel library tussen de LCD en arduino (i2c converter)
LiquidCrystal_I2C lcd(0x27, 2, 16);      //geef aan wat voor een soort lcd het is
//=====================================================
#define button1 2                        //knop 1 zit op pin 2
#define button2 3                        //knop 1 zit op pin 3
#define buzzer 6                        //buzzer zit op pin 6

int spelmodus = 0;                        //ff wat variabele aanmakon
int dobbelgetal = 0;
int vraag = 0;
int vraagstelling = 0; 

//=====================================================

void setup() {
  pinMode(button1, INPUT);               //knop 1 is een input
  pinMode(buzzer, OUTPUT);               //Buzzer is een output
  //=====================================================
  lcd.init();                            //start lcd opnieuw op
  lcd.backlight();                       //zet backlight van lcd aan
  lcd.clear();                           //maak lcd scherm leeg
  lcd.begin(16, 2);                      //stel het aantal rijen en kolommen in op de lcd die je gaat gebruiken, in dit geval alles
  //=====================================================
  displayLCD("###Welkom bij###", "##PrivacyBoard##"); //titelscherm
  tone(buzzer, 3500);
  delay(300);
  noTone(buzzer);
  tone(buzzer, 4000);
  delay(350);
  noTone(buzzer);
  tone(buzzer, 4500);
  delay(250);
  noTone(buzzer);
  delay(1500);
  displayLCD("Gemaakt door:", "Boudewijn &Toine");
  delay(1500);
  displayLCD("Klas JDE-D04", "HBO CMD HU");
  delay(1500);
  displayLCD("Het spel waar je", "leert over je...");
  delay(2000);
  displayLCD("digital privacy!", "Wil je uitleg?");
  delay(2000);
  displayLCD("Knop 1 = Uitleg", "Knop 2=Sla over");
  lcd.blink();                                              //wait en show blink
}

void loop() {
  randomSeed(analogRead(0));                                //HOU DIE RANDOM FUNCTIE NOU VERDOMME RANDOM!!!!!!!!!!

  if (digitalRead(button1) == HIGH) {
    if (spelmodus == 0) {
      tone(buzzer, 2600);               //Laat piepje horen van 2600Hz
      delay(200);                       //voor 200ms
      noTone(buzzer);                   //zet dat stomme piepje uit pls
      lcd.noBlink();                     //set blinking cursor uit
      lcd.clear();                       //leeg scherm voordat de button 1 aan gaat
      spelmodus = 1;                     //Als knop wordt ingedrukt, zet hem aan
    }

    else {
      spelmodus == 0;                    //Als knop niet wordt ingedrukt, houd het uit
    }

    delay(250);                          //Even wachten totdat je verdergaat
  }


  if (digitalRead(button2) == HIGH) {    //doe skippen naar direct start spel
    if (spelmodus == 0) {
      tone(buzzer, 2600);
      delay(200);
      noTone(buzzer);
      lcd.noBlink();                     //set blinking cursor uit
      lcd.clear();                       //leeg scherm voordat de button 1 aan gaat
      spelmodus = 2;                     //ga naar dobbel/vraag scherm
    }

    else {
      spelmodus == 0;                    //Als knop niet wordt ingedrukt, houd het uit
    }
    delay(250);                          //Even wachten totdat je verdergaat
  }

  if (spelmodus == 1) {                                 //UITLEG SCHERM
    displayLCD("Max. 4 spelers.", "DOEL: als eerste");
    delay(3000);
    displayLCD("op vakje 63", "terecht komen.");
    delay(3000);
    displayLCD("==Blauwe vakje==", "Vraag (Knop 2)");
    delay(3000);
    displayLCD("===Rood vakje===", "Speciaal vakje");
    delay(3000);
    displayLCD("==Groen vakje==", "Dobbel nog eens!");
    delay(3000);
    tone(buzzer, 1000);
    delay(200);
    noTone(buzzer);
    tone(buzzer, 200);
    delay(500);
    noTone(buzzer);
    lcd.clear();
    spelmodus = 2;                        //ga naar dobbel/vraag scherm
  }

  if (spelmodus == 2) {                 // VRAAG DOBBEL MAINSCREEN - IDLE
    lcd.setCursor(0, 0);
    lcd.print(F("Knop 1 = DOBBEL"));
    lcd.setCursor(0, 1);
    lcd.print(F("Knop 2 = VRAAG "));
    lcd.blink();
    delay(1000);
  }


  if (digitalRead(button1) == HIGH) {
    if (spelmodus == 2) {               //ja ga maar door als je vanuit het main menu komt (dobbel.vraag)
      lcd.noBlink();
      lcd.setCursor(0, 0);
      lcd.clear();
      dobbelgetal = random(1, 7);     //genereer dobbelgetal
      tone(buzzer, 1000);
      delay(100);
      noTone(buzzer);
      displayLCD("Je gooide...", "5456132156464948");     //coole dobbel effectjes
      tone(buzzer, 1200);
      delay(100);
      noTone(buzzer);
      displayLCD("Je gooide...", "6541986451986414");
      tone(buzzer, 1400);
      delay(100);
      noTone(buzzer);
      displayLCD("Je gooide...", "8997231987958676");
      tone(buzzer, 1600);
      delay(100);
      noTone(buzzer);
      displayLCD("Je gooide...", "1458922858882478");
      tone(buzzer, 1800);
      delay(100);
      noTone(buzzer);
      displayLCD("Je gooide...", "3298498577909878");
      tone(buzzer, 2000);
      delay(100);
      noTone(buzzer);
      displayLCD("Je gooide...", "2348089948784998");
      tone(buzzer, 2200);
      delay(100);
      noTone(buzzer);
      displayLCD("Je gooide...", "3457869832748758");
      tone(buzzer, 2400);
      delay(100);
      noTone(buzzer);
      displayLCD("Je gooide...", "2359847902000287");
      delay(100);
      tone(buzzer, 2600);
      delay(100);
      noTone(buzzer);
      displayLCD("Je gooide...", "2384576879035967");
      delay(100);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(F("Je gooide..."));
      lcd.setCursor(7, 1);                      //plaats getal in het midden van het scherm
      lcd.print(dobbelgetal);                 //dit heb je gegooid, laat zien
      lcd.setCursor(0, 0);
      tone(buzzer, 3000);
      delay(100);
      noTone(buzzer);
      delay(100);
      tone(buzzer, 4000);
      delay(100);
      noTone(buzzer);
      delay(1500);
      spelmodus = 2;
    }

    else {
      spelmodus == 2;               //Als knop niet wordt ingedrukt, houd het uit
    }
    delay(250);                         //Even wachten totdat je verdergaat
  }



  if (digitalRead(button2) == HIGH) {       //geef vraag
    if (spelmodus == 2) {               //als je je in dobbel/vraag menu bevind, doe dan:....
      lcd.noBlink();
      tone(buzzer, 2600);
      delay(200);
      noTone(buzzer);
      spelmodus = 10;                //Ga naar vragencyclus

    } else {
      spelmodus == 2;               //Als knop niet wordt ingedrukt, houd het uit

    }
    delay(250);                         //Even wachten totdat je verdergaat
  }



  //=================================================

  if (spelmodus == 10) {
    vraag = random(1, 3);                             //omdat we nu maar 2 vragen hebben, niet echt nuttig maar oke

    if (vraag == 1) {
      vraagGenerate();                  //ff spannend maken
      delay(1000);
      displayLCD("Sleepwet=een wet", "die tmakkelijker");
      delay(2500);
      displayLCD("maakt voor ANWB", "om auto's van de");
      delay(2500);
      displayLCD("weg te slepen.", "");
      delay(2500);
      vraagstelling = 1;

      if (vraagstelling == 1) {
        displayLCD("Knop 1 = WAAR", "Knop 2 = ONWAAR");

        while (digitalRead(button1) == LOW && digitalRead(button2) == LOW) {//Zolang de knoppen niet worden ingedrukt, wacht dan pls
          //doe niks
        }
        if (digitalRead(button1) == HIGH) {
          vraagFout();
          displayLCD("Sleepwet=een wet", "die de overheid");
          delay(2500);
          displayLCD("meer macht geeft", "om groots online");
          delay(2500);
          displayLCD("communicatie af", "te luisteren.");
          delay(2500);
          vraag = 2;                                                     //doe hierna vraag 2
          vraagBack();                                                  //ga terug naar DOBBEL / VRAAG MENU en laat piepje horen

        }
        if (digitalRead(button2) == HIGH) {
          vraagGoed();
          displayLCD("Sleepwet=een wet", "die de overheid");
          delay(2500);
          displayLCD("meer macht geeft", "om groots online");
          delay(2500);
          displayLCD("communicatie af", "te luisteren.");
          delay(2500);
          vraag = 2;                                                    //doe hierna vraag 2
          vraagBack();                                                   //ga terug naar DOBBEL / VRAAG MENU en laat piepje horen

        }
        else {
          //idle
        }
        delay(250);                         //Even wachten totdat je verdergaat
      }
    }


    //======================================================================================


    if (vraag == 2) {
      vraagGenerate();    //ff spannend maken
      delay(1000);
      displayLCD("Een VPN staat", "voor:...");
      delay(2500);
      displayLCD("A: Virtual", "Pirate Network");
      delay(2500);
      displayLCD("Wordt gebruikt", "op de deepweb");
      delay(2500);
      displayLCD("      OF      ", "");
      delay(1000);
      displayLCD("B: Virtual", "Private Network");
      delay(2500);
      displayLCD("Gebruikt voor", "veilig internet");
      delay(2500);
      vraagstelling = 2;

      if (vraagstelling == 2) {
        displayLCD("Knop 1 = A", "Knop 2 = B");

        while (digitalRead(button1) == LOW && digitalRead(button2) == LOW) { //Zolang de knoppen niet worden ingedrukt, wacht dan pls
          //doe niks
        }

        if (digitalRead(button1) == HIGH) {
          vraagFout();
          displayLCD("Een VPN kan je", "gebruiken als je");
          delay(2500);
          displayLCD("op openbare WiFi", "zit, om wel een");
          delay(2500);
          displayLCD("versleutelde", "verbinding");
          delay(2500);
          displayLCD("te krijgen.", "");
          delay(2500);
          vraag = 1;                                                //doe hierna vraag 1
          vraagBack();                                              //ga terug naar DOBBEL / VRAAG MENU en laat piepje horen

        }

        if (digitalRead(button2) == HIGH) {
          vraagGoed();
          displayLCD("Een VPN kan je", "gebruiken als je");
          delay(2500);
          displayLCD("op openbare WiFi", "zit, om wel een");
          delay(2500);
          displayLCD("versleutelde", "verbinding");
          delay(2500);
          displayLCD("te krijgen.", "");
          delay(2500);
          vraag = 1;                       //doe hierna vraag 1
          vraagBack();          //ga terug naar DOBBEL / VRAAG MENU en laat piepje horen

        }

        else {
          //idle
        }
        delay(250);                         //Even wachten totdat je verdergaat
      }
    }
  }



}//loop

void vraagGoed() {                          //Dit doe je als je de vraag goed hebt beantwoord
  displayLCD("Je antwoord is...", "");
  tone(buzzer, 3000);
  delay(100);
  tone(buzzer, 3500);
  delay(100);
  tone(buzzer, 4000);
  delay(100);
  tone(buzzer, 4500);
  delay(100);
  tone(buzzer, 5000);
  delay(500);
  noTone(buzzer);
  delay(100);
  displayLCD("Je antwoord is...", "GOED");
  tone(buzzer, 3000);
  delay(100);
  noTone(buzzer);
  tone(buzzer, 4000);
  delay(400);
  noTone(buzzer);
  delay(1000);
}


void vraagFout() {
  displayLCD("Je antwoord is...", "");      //Dit doe je als je de vraag fout hebt beantwoord :(((((((((((
  tone(buzzer, 3000);
  delay(100);
  tone(buzzer, 3500);
  delay(100);
  tone(buzzer, 4000);
  delay(100);
  tone(buzzer, 4500);
  delay(100);
  tone(buzzer, 5000);
  delay(500);
  noTone(buzzer);
  delay(100);
  displayLCD("Je antwoord is...", "FOUT");
  tone(buzzer, 1000);
  delay(1000);
  noTone(buzzer);
  delay(500);
  displayLCD("Ga weer terug", "> vorige positie");
  delay(2000);
}

void vraagBack() {
  lcd.clear(); tone(buzzer, 2600); delay(500); noTone(buzzer); vraag = 0; vraagstelling = 0; //RESET ALLE VARIABELE
  spelmodus = 2;
}

void vraagGenerate() {
  displayLCD("Je vraag is...", "################");  //SPANNEND AFWACHTEN todat je vraag wordt laten zien
  tone(buzzer, 3000);
  delay(200);
  tone(buzzer, 3500);
  delay(200);
  tone(buzzer, 4000);
  delay(200);
  tone(buzzer, 4500);
  delay(200);
  tone(buzzer, 5000);
  delay(500);
  noTone(buzzer);
}


// Dit moet je doen voor deze functie om text op het lced schermpje te laten zien. vet handig.
void displayLCD( char* line1, char* line2) {    //De variabele doet het volgende
  lcd.clear();                                  //scherm leeghalen
  lcd.setCursor(0, 0);                          //cursor plaatsen op 1e blokje, 1e regel
  lcd.print(line1);                             //print 1e tekst op 1e regel
  lcd.setCursor(0, 1);                          //cursor plaatsen op 1e blokje, 2e regel
  lcd.print(line2);                             //print 2e tekst op 1e regel
}
