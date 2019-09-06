
#include <esp_now.h>
#include <WiFi.h>

#define CHANNEL 1
#define ENCRYPTION 0

uint8_t peerMacAddress[] = {0xB4, 0xE6, 0x2D, 0x86, 0x27, 0x21};
esp_now_peer_info_t peer;

void setup() {
  Serial.begin(115200);

  setup_ESP_Now();
  add_Peer(peerMacAddress);
  esp_now_register_send_cb(OnDataSent);
}

void setup_ESP_Now() {
  WiFi.mode(WIFI_STA);

  if (esp_now_init() == ESP_OK) {
    Serial.println("Inicialização: Sucesso");
  }
  else {
    Serial.println("Inicialização: Falha");
    ESP.restart();
  }
}

void add_Peer(uint8_t *peerMacAddress) {
  peer.channel = CHANNEL;
  peer.encrypt = ENCRYPTION;
  memcpy(peer.peer_addr, peerMacAddress, 6);
  esp_now_add_peer(&peer);
}

void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
  Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Envio: Sucesso" : "Envio: Falha");
}

void read_and_send() {
  if (Serial.available() > 0) {
    uint8_t value = Serial.read();
    Serial.println("Value: ");
    Serial.println(value);
    send(&value, peerMacAddress);
  }
}

void send(const uint8_t *value, uint8_t *peerMacAddress) {
  esp_err_t result = esp_now_send(peerMacAddress, value, sizeof(value));
  Serial.println(result == ESP_OK ? "Resposta: Sucesso" : "Resposta: Falha");
}

void loop() {
  read_and_send();
}
