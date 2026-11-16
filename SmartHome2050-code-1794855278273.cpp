/* 
 * Projeto: Smart Home 2050 - ESP32
 * UniFECAF - ExpoTech & Engineering 2026.2
 */

#include <WiFi.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Configurações de rede Wi-Fi e pinos principais
const char* ssid = "SUA_REDE_WIFI";
const char* password = "SUA_SENHA";

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(115200);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Smart Home 2050");
  
  // Inicialização de sensores e atuadores
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  lcd.setCursor(0, 1);
  lcd.print(WiFi.localIP());
}

void loop() {
  // Leitura de sensores e envio de dados a cada 1 segundo
  delay(1000);
}