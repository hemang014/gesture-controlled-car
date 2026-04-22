#include <WiFi.h>
#include <esp_now.h>

#define ENB 14
#define IN3 12
#define IN4 13

char command;


void OnDataRecv(const esp_now_recv_info *info, const uint8_t *incomingData, int len) {
  command = incomingData[0];

  Serial.print("Received: ");
  Serial.println(command);

  moveCar(command);
}

void moveCar(char cmd) {

  if (cmd == 'F') {
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    analogWrite(ENB, 200);
  }

  else if (cmd == 'B') {
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    analogWrite(ENB, 200);
  }

  else {
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    analogWrite(ENB, 0);
  }
}

void setup() {
  Serial.begin(115200);

  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);

  WiFi.mode(WIFI_STA);

  if (esp_now_init() != ESP_OK) {
    Serial.println("ESP-NOW Init Failed");
    return;
  }

  esp_now_register_recv_cb(OnDataRecv);

  Serial.println("Receiver Ready!");
}

void loop() {}