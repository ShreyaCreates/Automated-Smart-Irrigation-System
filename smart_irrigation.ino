#define SOIL_PIN A0
#define RELAY_PIN 7

LiquidCrystal_I2C lcd(0x27, 16, 2);  // I2C address may vary (0x27 or 0x3F)

int soilValue = 0;
int threshold = 20; // Adjust threshold according to soil moisture

void setup() {
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW); // Relay off initially (active LOW)
  
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Soil Moisture:");
}

void loop() {
  soilValue = analogRead(SOIL_PIN);
    // Display soil value on LCD
  lcd.setCursor(0, 1);
  lcd.print("Value: ");
  lcd.print(soilValue);
  lcd.print("   "); // Clear remaining chars
  
  // Control relay based on threshold
  if (soilValue < threshold) {
    digitalWrite(RELAY_PIN, HIGH); // Turn on pump
  } else {
    digitalWrite(RELAY_PIN, LOW); // Turn off pump
  }
  
  delay(1000); // 1-second delay
}
