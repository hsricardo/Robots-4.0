#include <esp_now.h>
#include <WiFi.h>

#define DRIVER
#define GCODE
#define OLED

#define CHANNEL 1

String inputChar = "";
String inputValue = "";
int value;
char type;
float passo = 1.26; //mm

void setup() {
  Serial.begin(115200);

  setup_DRIVER();
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

  if (input == 10) {
    print_OLED();
//    select_GCODE();
//    run_DRIVER ();

    inputChar = "";
    inputValue = "";
  }
  else {
    if (isDigit (input)) {
      inputValue += input;
    }
    else {
      inputChar += input;
    }
  }
}

void loop() {
}
