#ifdef OLED

#include <Wire.h>
#include "SSD1306Wire.h"

#define SDA 3
#define SCL 5

SSD1306Wire display(0x3c, SDA, SCL);

void setup_OLED() {
  display.init();
  display.flipScreenVertically();
  display.setFont(ArialMT_Plain_16);
  display.setTextAlignment(TEXT_ALIGN_CENTER);
}

void init_ESP_Now (char init) {
  if (init == ESP_OK) {
    display.drawString(64, 22, "Pronto Para Uso");
    display.display();
  }
  else {
    ESP.restart();
  }
}

void print_OLED() {
  display.end();
  setup_OLED();
  display.drawString(64, 22, gcode);
  display.display();
}

#endif
