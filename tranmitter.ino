#include <Wire.h>
#include <WiFi.h>
#include <esp_now.h>

const int MPU = 0x68;

int16_t ax, ay, az;

uint8_t receiverAddress[] = {};

void setup() {
  Serial.begin(115200);
  Wire.begin(21, 22);

  // MPU6050 wake
  Wire.beginTransmission(MPU);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);

  WiFi.mode(WIFI_STA);

  if (esp_now_init() != ESP_OK) {
    Serial.println("ESP-NOW Init Failed");
    return;
  }

  esp_now_peer_info_t peerInfo;
  memcpy(peerInfo.peer_addr, receiverAddress, 6);
  peerInfo.channel = 0;
  peerInfo.encrypt = false;
  peerInfo.ifidx = WIFI_IF_STA;  

  if (esp_now_add_peer(&peerInfo) != ESP_OK) {
    Serial.println("Peer add failed");
    return;
  }

  Serial.println("Transmitter Ready!");
}

void loop() {

  // Read MPU6050
  Wire.beginTransmission(MPU);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU, 6, true);

  ax = Wire.read() << 8 | Wire.read();
  ay = Wire.read() << 8 | Wire.read();
  az = Wire.read() << 8 | Wire.read();

  char cmd = 'S';

  if (ax > 13000) cmd = 'F';
  else if (ax < 5000) cmd = 'B';
  else cmd = 'S';

  esp_now_send(receiverAddress, (uint8_t *) &cmd, sizeof(cmd));

  Serial.print("Sent: ");
  Serial.println(cmd);

  delay(200);
}