Livestock Health and Activity Monitoring Using IoT-Based Sensor System
- Dedan Kimathi University of Technology  
- Department of Electrical and Electronics Engineering 
- Telecomunication and Information Engineering
- Final Year Project – 2024
---
Project Description

This project introduces a smart livestock monitoring system that leverages wearable IoT sensors and machine learning to monitor cattle health and activity in real time. Data collected from sensors is processed locally on an ESP32 device, anomalies are detected using a Random Forest classifier, and results are visualized via a mobile app using AWS cloud infrastructure.

 Key Technologies Used
- Hardware
- ESP32 Devkit V1 (nodes & gateway)
- MPU6050 (accelerometer + temperature)
- Custom PCB (KiCad)
- 3.7V LiPo Battery
---
 Software
- Arduino IDE (ESP32 programming)
-  ESP-NOW & Wi-Fi (data transmission)
 - Python + Scikit-learn (model training)
- `micromlgen` (ML model conversion to C)
- AWS IoT Core & DynamoDB
- Java & Android Studio (mobile app)
- Firebase (auth)
---
Project Objectives

- Design attachable IoT device to gather health metrics (temp + motion)
- Enable real-time transmission using ESP-NOW and Wi-Fi
- Build and deploy ML model on ESP32 gateway for anomaly detection
- Develop a mobile dashboard for real-time cattle health visualization
  
Flash ESP32 Nodes
1. Open Arduino IDE
2. Upload code for nodes (e.g., `Rx_code.ino`Latest_tx_code)
3. Ensure correct MAC address of the gateway is set

Setup Gateway ESP32
1. Load `random_forest_model2_for_ESP32.c`
2. Include AWS credentials and certificates
3. Ensure required libraries are installed:
   - `ESP-NOW`
   - `WiFi`
   - `PubSubClient`
   - `ArduinoJson`
  ---
AWS Setup
- Register the ESP32 gateway as an IoT Thing
- Create a DynamoDB table
- Setup MQTT rules to store incoming data
---
Mobile App
- Open in Android Studio
- Set your AWS region, identity pool, and database
- Use Firebase for login functionality
---
  Results

ML Model Accuracy: 92% (Random Forest)
Sensor Accuracy: 
  - Temperature deviation: ±0.2°C  
  - Activity classification accuracy: 95%
  Cloud Integration: Data successfully sent and retrieved via AWS
  Mobile Dashboard:Real-time metrics per animal available
---
Acknowledgements
Supervisor:Dr. Joseph Muguro  
Chief Technologist: Mr. Mathenge  
Project Team:
  - Wachuka Miano
  - Pascal Ochieng’
  - Courtney Ndanu
  - Fredrick Mulang’a
