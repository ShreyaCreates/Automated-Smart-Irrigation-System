#include <LiquidCrystal_I2C.h>

#define SOIL_PIN A0
#define RELAY_PIN 7

LiquidCrystal_I2C lcd(0x27, 16, 2);

int soilValue = 0;
int threshold = 20;

void setup() {
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Soil Moisture:");
}

void loop() {
  soilValue = analogRead(SOIL_PIN);

  lcd.setCursor(0, 1);
  lcd.print("Value: ");
  lcd.print(soilValue);
  lcd.print("   ");

  if (soilValue < threshold) {
    digitalWrite(RELAY_PIN, HIGH);
  } else {
    digitalWrite(RELAY_PIN, LOW);
  }

  delay(1000);
}
