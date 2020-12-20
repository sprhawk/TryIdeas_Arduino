#include <Arduino.h>

// #include <Adafruit_ST7789.h>
// #include <Adafruit_GFX.h>
// #include <Fonts/FreeMono12pt7b.h>
#include <SPI.h>
#include <TFT_eSPI.h>
#define WROVER_CS               22
// #define WROVER_DC               21
// #define WROVER_RST              18
// #define WROVER_SCLK             19
// #define WROVER_MOSI             23
// #define WROVER_MISO             25
// #define WROVER_BL               5

// #define WROVER_WIDTH       240
// #define WROVER_HEIGHT      320

// Adafruit_ST7789 tft = Adafruit_ST7789(WROVER_CS, WROVER_DC, WROVER_MOSI, WROVER_SCLK, WROVER_RST);

TFT_eSPI tft = TFT_eSPI();

void setup() {
  Serial.begin(115200);
  Serial.println("Hello TFT");

  // setup for Adafruit_GFX
  // pinMode(WROVER_BL, OUTPUT);
  // digitalWrite(WROVER_BL, LOW);
  // tft.init(WROVER_WIDTH, WROVER_HEIGHT, SPI_MODE1);
  // tft.fillScreen(ST77XX_YELLOW);
  // tft.setFont(&FreeMono12pt7b);
  // tft.setTextColor(ST77XX_BLUE);
  // tft.setTextSize(12);
  // tft.invertDisplay(false);

  // setup for TFT_eSPI
  tft.init();
  tft.initDMA();
  tft.setRotation(1);
  tft.fillScreen(TFT_BLUE);
}

unsigned char c = 'A';
void loop() {
  // tft.fillScreen(TFT_BLUE);
  // put your main code here, to run repeatedly:
  // tft.setTextSize(TFTP_YELLOW);
  // tft.drawChar(10, 200, c, ST77XX_GREEN, ST77XX_BLACK, 12);

  tft.setTextColor(TFT_YELLOW, TFT_BLUE);
  // tft.drawString("Hello World", 10, 10);
  tft.drawNumber(c, 80, 2);
  
  c ++;
  if ( c > 'Z' ) {
    c = 'A';
  }
  // Serial.println("Hello World");
  delay(1000);
  // tft.fillRect(10, 200, 12, 12, TFT_CYAN);
  // tft.fillRect(144 - 10, 200 - 144, 144, 144, ST77XX_BLACK);
}