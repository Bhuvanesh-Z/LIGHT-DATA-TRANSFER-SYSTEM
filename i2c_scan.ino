#include <Wire.h>

void setup() {
  Serial.begin(115200);
  delay(100);
  
  Serial.println("I2C Scanner - Scanning for devices...");
  
  Wire.begin(GPIO_NUM_21, GPIO_NUM_22); // SDA, SCL for ESP32
  
  int count = 0;
  for (int addr = 0; addr < 127; addr++) {
    Wire.beginTransmission(addr);
    if (Wire.endTransmission() == 0) {
      Serial.print("Found device at address: 0x");
      Serial.println(addr, HEX);
      count++;
    }
  }
  
  Serial.print("Total I2C devices found: ");
  Serial.println(count);
}

void loop() {
  delay(1000);
}