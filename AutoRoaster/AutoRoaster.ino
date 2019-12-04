// OLED
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

// ロータリーエンコーダ
#include <Encoder.h>
Encoder lEnc(2, 4);
Encoder rEnc(3, 5);

// ピン定義
#define OUT_PIN 12
#define OUT_LED_PIN 13


#define UP_TIME_INIT 250
#define DOWN_TIME_INIT 250

int upTime = UP_TIME_INIT;
int downTime = DOWN_TIME_INIT;

bool ledState = HIGH;
unsigned long turnTime = 0;

void setup() {
  Serial.begin(9600);
    
  // OLED
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3D (for the 128x64)
  display.clearDisplay();
  display.display();
  
  pinMode(OUT_PIN, OUTPUT);
  pinMode(OUT_LED_PIN, OUTPUT);
}

void loop() {
  long lEncVal = lEnc.read()+UP_TIME_INIT;
  if (lEncVal != upTime) {
    upTime = lEncVal;
    Serial.println(upTime);
  }
  
  long rEncVal = rEnc.read()+DOWN_TIME_INIT;
  if (rEncVal != downTime) {
    downTime = rEncVal;
    Serial.println(downTime);
  }

  // 時間になったらON/OFFを逆転させる
  unsigned long nowTime = millis();
  if(turnTime < nowTime){
    if(ledState){
      ledState = LOW;
      turnTime = nowTime + downTime;
    }else{
      ledState = HIGH;
      turnTime = nowTime + upTime;
    }
    digitalWrite(OUT_PIN, ledState);
    digitalWrite(OUT_LED_PIN, ledState);
  }

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
