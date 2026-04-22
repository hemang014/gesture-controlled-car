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

> Add your images here
