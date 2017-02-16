#include <LiquidCrystal_I2C.h>

#define LED_ROSSO 10
#define LED_VERDE 9
#define BUZZER 8

LiquidCrystal_I2C lcd(0x3F, 20, 4);

const int sensorpin = 11;
int statosensore = 0;

void setup() {
  lcd.init();
  lcd.backlight();
  pinMode (sensorpin, INPUT);
  pinMode (LED_ROSSO, OUTPUT);
  pinMode (LED_VERDE, OUTPUT);
  pinMode (BUZZER, OUTPUT);
  lcd.setCursor(0, 0);
  lcd.print(" Sensore di fiamma  ");
  lcd.setCursor(0, 1);
  lcd.print("  Pagina Facebook:  ");
  lcd.setCursor(0, 2);
  lcd.print("Progetti & Tutorial");
  lcd.setCursor(0, 3);
  lcd.print("      Ardunio       ");
  delay(4000);
  lcd.clear();
}

void loop() {
  statosensore = digitalRead(sensorpin);

  if (statosensore == HIGH) {
    allarme_sonoro();
    allarme_visivo();
    lcd.setCursor(0, 1);
    lcd.print("A T T E N Z I O N E ");
    lcd.setCursor(0, 2);
    lcd.print("  Fiamma rilevata!  ");
    delay(100);
  }

  else {
    digitalWrite(LED_ROSSO, LOW);
    digitalWrite(LED_VERDE, HIGH);
    noTone(BUZZER);
    lcd.setCursor(0, 1);
    lcd.print("   Nessuna fiamma   ");
    lcd.setCursor(0, 2);
    lcd.print("      rilevata      ");
    delay(100);
  }
}

void allarme_sonoro() {
  tone(BUZZER, 2000);
}

void allarme_visivo() {
  digitalWrite(LED_VERDE, LOW);
  digitalWrite(LED_ROSSO, HIGH);
  delay(100);
  digitalWrite(LED_ROSSO, LOW);
  delay(100);
}

