#include "Keyboard.h"
int boutonP = 2;
const int buttonPin2 = 2;
const int buttonPin4 = 4;
const int buttonPin6 = 6;

const int led3 = 3;
const int led5 = 5;     // la broche 5 devient led
const int led7 = 7;
bool tmp2 = LOW;
bool tmp4 = LOW;
bool tmp6 = LOW;
bool tmpled3 = LOW;
bool tmpled5 = LOW;
bool tmpled7 = LOW;


String commandes[] = { "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "" };
String fr2en(String text) {
  int i = 0;
  String _en = " =qwertyuiopasdfghjkl;zxcvbnQWERTYUIOPASDFGHJKL:ZXCVBNm,./M<>?1234567890!@#$%^&*()",
         _fr = " =azertyuiopqsdfghjklmwxcvbnAZERTYUIOPQSDFGHJKLMWXCVBN,;:!?./ & \"'(- _  1234567890",
         str = "";
  while (text[i] != 0) {
    str = str + (String)_en[_fr.indexOf((String)text[i++])];
  }
  return str;
}
char fr2enC(char text) {
  int i = 0;
  String _en = " =qwertyuiopasdfghjkl;zxcvbnQWERTYUIOPASDFGHJKL:ZXCVBNm,./M<>?1234567890!@#$%^&*()";
  String fr = " =azertyuiopqsdfghjklmwxcvbnAZERTYUIOPQSDFGHJKLMWXCVBN,;:!?./ & \"'(- _  1234567890";
  char str = "";
  str = _en[fr.indexOf((String)text)];
  return str;
}
void setup() {
  Serial.begin(115200);
  Keyboard.begin();
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(buttonPin4, INPUT_PULLUP);
  pinMode(buttonPin6, INPUT_PULLUP);

  pinMode(led3, OUTPUT);   // Initialise la broche 5 comme sortie
  pinMode(led5, OUTPUT);
  pinMode(led7, OUTPUT);
  digitalWrite(led3, LOW);  // éteint la LED
  digitalWrite(led5, LOW);
  digitalWrite(led7, LOW);
  delay(550);
}

void loop() {
  
  if (digitalRead(buttonPin2) != tmp2) { // détection changement état pin
    tmp2=digitalRead(buttonPin2);
    delay(150); // faut contat de l'interrupteur, ne pas relire valeur moment apppuie
    if (digitalRead(buttonPin2) == HIGH){
      Keyboard.press(KEY_LEFT_GUI);
      Keyboard.print(fr2en("r"));
      Keyboard.releaseAll();
      delay(200);
      Keyboard.println(fr2en("C:/Users/YOUR_PATH/Interaction_Teams/mute.exe"));
      tmpled3 = !tmpled3;
      digitalWrite(led3, tmpled3);  // inverse la led allumé-éteint
    }
  }



  if (digitalRead(buttonPin4) != tmp4) {
    tmp4=digitalRead(buttonPin4);
    delay(150); // faut contat de l'interrupteur, ne pas relire valeur moment apppuie
    if (digitalRead(buttonPin4)==HIGH){
      Keyboard.press(KEY_LEFT_GUI);
      Keyboard.print(fr2en("r"));
      Keyboard.releaseAll();
      delay(200);
      Keyboard.println(fr2en("C:/Users/YOUR_PATH/Interaction_Teams/video.exe"));
      tmpled5 = !tmpled5;
      digitalWrite(led5, tmpled5);  // inverse la led allumé-éteint
    }
  }

  if (digitalRead(buttonPin6) != tmp6) {
    tmp6=digitalRead(buttonPin6);
    delay(150); // faut contat de l'interrupteur, ne pas relire valeur moment apppuie
    if (digitalRead(buttonPin6)==LOW){
      Keyboard.press(KEY_LEFT_GUI);
      Keyboard.print(fr2en("r"));
      Keyboard.releaseAll();
      delay(200);
      Keyboard.println(fr2en("C:/Users/YOUR_PATH/Interaction_Teams/screen.exe"));
      tmpled7 = !tmpled7;
      digitalWrite(led7, tmpled7);  // inverse la led allumé-éteint
    }
  }
  
}
