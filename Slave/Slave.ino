#include <esp_now.h>
#include <WiFi.h>

#define DRIVER
#define OLED

#define CHANNEL 1

String gcode = "";

void setup() {
  Serial.begin(115200);

  setup_OLED();
  setup_ESP_Now();
  esp_now_register_recv_cb(onDataRecv);
}

void setup_ESP_Now() {
  WiFi.mode(WIFI_STA);
  init_ESP_Now(esp_now_init());
}

void onDataRecv(const uint8_t *mac_addr, const uint8_t *value, int len) {
  char input = (char) * value;
  Serial.println("Input: " + input);

  if (input == 10) {
    print_OLED();
    Serial.println("GCode: " + gcode);
    gcode = "";
  }
  else {
    gcode += input;
  }

}

void loop() {
}
