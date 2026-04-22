# 🚗 ESP32 Dual-Mode Smart Car

A Dual-Mode Smart Robotic Car built using ESP32, capable of being controlled via **hand gestures** and **WiFi-based web interface**.  
This project demonstrates real-time embedded control, wireless communication, and hardware-software integration.

---

## 📌 Features

- ✋ Gesture Control using MPU6050 (Accelerometer + Gyroscope)
- 📡 Low-latency communication using ESP-NOW protocol
- 🌐 WiFi Control via ESP32 Web Server (HTTP-based interface)
- ⚙️ Bidirectional motor control using L298N H-Bridge
- 🔄 Dual-mode switching (Gesture / WiFi)

---

## 🧠 System Overview

### 🔹 Gesture Control Mode
- MPU6050 captures tilt (pitch & roll)
- ESP32 processes sensor data
- Data transmitted via **ESP-NOW (peer-to-peer protocol)**
- Receiver ESP32 controls motors accordingly

### 🔹 WiFi Control Mode
- ESP32 configured as **Soft Access Point (AP)**
- Hosts a web server
- Smartphone sends **HTTP requests**
- Commands mapped to motor movement

---

## 🛠️ Tech Stack

- **Microcontroller:** ESP32  
- **Sensor:** MPU6050 (6-axis IMU)  
- **Motor Driver:** L298N Dual H-Bridge  
- **Protocols:** ESP-NOW, WiFi (802.11), HTTP  
- **Programming:** Arduino IDE (C/C++)

---

## 🔌 Hardware Components

- ESP32 Dev Module  
- MPU6050 Sensor  
- L298N Motor Driver  
- DC Motors + Chassis  
- 18650 Battery Pack  
- Jumper Wires  

---

## ⚡ Engineering Challenges

- ⚠️ Voltage drop under load affecting motor performance  
- 🔌 Power supply instability  
- 🔄 Sensor noise in gesture control  

### ✅ Solutions
- Improved battery configuration  
- Ensured common grounding  
- Systematic debugging (hardware → power → logic)

---

## 📊 Observations

- Gesture control offers **intuitive interaction (HCI)**  
- WiFi control provides **better stability and reliability**  
- Power management plays a critical role in embedded systems  

---

## 📸 Demo & Images
<img width="3024" height="4032" alt="WhatsApp Image 2026-04-20 at 10 37 56 PM" src="https://github.com/user-attachments/assets/ceb15566-dc1e-43cd-bffb-a6087b87ecc5" />
<img width="1080" height="657" alt="WhatsApp Image 2026-04-21 at 1 35 29 PM" src="https://github.com/user-attachments/assets/e3d54313-f457-457c-adb1-b017e5732dd5" />


https://github.com/user-attachments/assets/c369ea61-3b51-4caf-8588-142c63c1ceed



https://github.com/user-attachments/assets/0090ffd0-b39d-4edb-862c-d7326c967bd5



https://github.com/user-attachments/assets/9af501ca-dcf5-4028-95a7-cbf77c64f39a


