#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64  // change to 32 if you have the smaller display
#define OLED_RESET -1
#define OLED_ADDR 0x3C    // common address; some use 0x3D

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  Serial.begin(115200);
  
  // Initialize I2C on custom pins
  Wire.begin(10, 11);  // SDA=10, SCL=11
  
  if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
    Serial.println("SSD1306 allocation failed");
    while (true) { delay(1000); }
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("OLED Test OK!");
  display.println();
  display.setTextSize(2);
  display.println("Hello!");
  display.display();
  
  Serial.println("OLED initialized");
}

void loop() {
  static uint32_t counter = 0;
  
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("ESP32-S3 SuperMini");
  display.println("------------------");
  display.setTextSize(2);
  display.setCursor(0, 28);
  display.printf("Count: %lu", counter++);
  display.display();
  
  delay(500);
}