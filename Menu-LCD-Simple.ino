#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int upButton = 10;
int downButton = 11;
int selectButton = 12;
int menu = 1;
int LedOut1 = 3;
int LedOut2 = 4;
int LedOut3 = 5;
int Timer = 0;
int Timer_1 = 0;
int Timer2 = 0;


void setup() {
  lcd.init();
  lcd.backlight();
  pinMode(upButton, INPUT_PULLUP);
  pinMode(downButton, INPUT_PULLUP);
  pinMode(selectButton, INPUT_PULLUP);
  pinMode(LedOut1, OUTPUT);
  pinMode(LedOut2, OUTPUT);
  pinMode(LedOut3, OUTPUT);
       
  updateMenu();
}

void loop() {
  if (!digitalRead(downButton)){
    menu++;
    updateMenu();
    delay(100);
    while (!digitalRead(downButton));
  }
  if (!digitalRead(upButton)){
    menu--;
    updateMenu();
    delay(100);
    while(!digitalRead(upButton));
  }
  if (!digitalRead(selectButton)){
    executeAction();
    updateMenu();
    delay(100);
    while (!digitalRead(selectButton));
  }
}

void updateMenu() {
  switch (menu) {
    case 0:
      menu = 1;
      break;
    case 1:
      lcd.clear();
      lcd.print(">LED1");
      lcd.setCursor(0, 1);
      lcd.print(" LED2");
      break;
    case 2:
      lcd.clear();
      lcd.print(" LED1");
      lcd.setCursor(0, 1);
      lcd.print(">LED2");
      break;
    case 3:
      lcd.clear();
      lcd.print(">LED3");
      break;
    case 4:
      menu = 3;
      break;
  }
}

void executeAction() {
  switch (menu) {
    case 1:
      action1();
      break;
    case 2:
      action2();
      break;
    case 3:
      action3();
      break;
  }
}

void action1() {
  lcd.clear();
  lcd.print(">LED1 Cambiado");
  digitalWrite(LedOut1,HIGH);
  Timer++;
  if(Timer ==2){
    digitalWrite(LedOut1,LOW);
  Timer=0;
  }
  else{
    digitalWrite(LedOut1,HIGH);
  }
  delay(1500);
}
void action2() {
  lcd.clear();
  lcd.print(">LED2 Cambiado");
  digitalWrite(LedOut2, HIGH);
    Timer_1++;
  if(Timer_1 ==2){
    digitalWrite(LedOut2,LOW);
  Timer_1=0;
  }
  else{
    digitalWrite(LedOut2,HIGH);
  }
  delay(1500);
}
void action3() {
  lcd.clear();
  lcd.print(">LED3 Cambiado");
  digitalWrite(LedOut3, HIGH);
    Timer2++;
  if(Timer2 ==2){
    digitalWrite(LedOut3,LOW);
  Timer2=0;
  }
  else{
    digitalWrite(LedOut3,HIGH);
  }
  delay(1500);
}
