// OLED
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

#define OUT_PIN 4
#define OUT_LED_PIN 13

void setup() {
  // OLED
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3D (for the 128x64)
  display.clearDisplay();
  display.display();
  
  pinMode(OUT_PIN, OUTPUT);
  pinMode(OUT_LED_PIN, OUTPUT);
}

void loop() {
  int upTime = 500;
  int downTime = 500;
  
  digitalWrite(OUT_PIN, HIGH);
  digitalWrite(OUT_LED_PIN, HIGH);
  delay(upTime);
  digitalWrite(OUT_PIN, LOW);
  digitalWrite(OUT_LED_PIN, LOW);
  delay(downTime);


  // OLED
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  
  //上下時間
  display.println("u:" + String(upTime));
  display.println("d:" + String(downTime));
  
  //作業時間
  
  display.display();

}
