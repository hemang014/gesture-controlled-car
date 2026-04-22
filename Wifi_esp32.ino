#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "ESP32_CAR";
const char* password = "12345678";

WebServer server(80);

#define IN1 25
#define IN2 26
#define IN3 33
#define IN4 32

unsigned long lastCommandTime = 0;
const int timeout = 300; // tighter fail-safe

// ===== MOTOR CONTROL =====
void stopCar() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void forward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void backward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void left() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void right() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

// ===== HANDLER =====
void handleCommand() {
  if (!server.hasArg("cmd")) {
    server.send(400, "text/plain", "No cmd");
    return;
  }

  String cmd = server.arg("cmd");

  if (cmd == "F") forward();
  else if (cmd == "B") backward();
  else if (cmd == "L") left();
  else if (cmd == "R") right();
  else if (cmd == "S") stopCar();

  lastCommandTime = millis();

  server.send(200, "text/plain", "OK");
}

// ===== IMPROVED UI =====
String html = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
<meta name="viewport" content="width=device-width, initial-scale=1">
<style>
body {
  text-align: center;
  font-family: Arial;
  background: #111;
  color: white;
}

h2 {
  margin-top: 20px;
}

.btn {
  width: 90px;
  height: 90px;
  font-size: 24px;
  margin: 10px;
  border-radius: 15px;
  border: none;
  background: #333;
  color: white;
}

.btn:active {
  background: #00c3ff;
}

.row {
  display: flex;
  justify-content: center;
}
</style>
</head>

<body>

<h2>RC CAR CONTROL</h2>

<div class="row">
  <button class="btn" id="fwd">↑</button>
</div>

<div class="row">
  <button class="btn" id="left">←</button>
  <button class="btn" onclick="send('S')">■</button>
  <button class="btn" id="right">→</button>
</div>

<div class="row">
  <button class="btn" id="back">↓</button>
</div>

<script>
let interval = null;

function start(cmd) {
  send(cmd);
  interval = setInterval(() => send(cmd), 80);
}

function stop() {
  clearInterval(interval);
  send('S');
}

function send(cmd) {
  fetch('/cmd?cmd=' + cmd);
}

// Touch + Mouse support
['fwd','left','right','back'].forEach(id => {
  let btn = document.getElementById(id);

  btn.onmousedown = () => start(idToCmd(id));
  btn.onmouseup = stop;
  btn.onmouseleave = stop;

  btn.ontouchstart = (e) => { e.preventDefault(); start(idToCmd(id)); };
  btn.ontouchend = stop;
});

function idToCmd(id){
  if(id==='fwd') return 'F';
  if(id==='back') return 'B';
  if(id==='left') return 'L';
  if(id==='right') return 'R';
}
</script>

</body>
</html>
)rawliteral";

void handleRoot() {
  server.send(200, "text/html", html);
}

// ===== SETUP =====
void setup() {
  Serial.begin(115200);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  stopCar();

  WiFi.softAP(ssid, password);
  Serial.println(WiFi.softAPIP());

  server.on("/", handleRoot);
  server.on("/cmd", handleCommand);

  server.begin();
}

// ===== LOOP =====
void loop() {
  server.handleClient();

  // FAIL-SAFE
  if (millis() - lastCommandTime > timeout) {
    stopCar();
  }
}