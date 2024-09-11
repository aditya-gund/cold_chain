# **Cold Chain - A Supply Unit**

## **Overview**
Cold Chain - A Supply Unit is a monitoring system designed to track and manage the conditions of cold-chain goods using IoT devices. The platform provides real-time updates on critical parameters like temperature, humidity, and other environmental factors, ensuring compliance with safety standards throughout the supply chain. This solution improves decision-making, enhances visibility, and helps reduce potential spoilage of perishable goods.

The system includes a cloud-based dashboard to visualize the data and monitor conditions in real-time, facilitating better control over the cold chain and minimizing risks.

---

## **Features**

### 1. **IoT-Driven Real-Time Monitoring**
- IoT sensors deployed across the supply chain to continuously monitor the conditions of cold-chain goods.
- Tracks key metrics such as temperature, humidity, and other relevant environmental factors.
- Provides instant notifications for any deviations from safety standards.

### 2. **Cloud-Based Dashboard**
- A user-friendly dashboard (Blynk IoT) for visualizing data from IoT devices.
- Real-time graphs and charts for quick and easy monitoring of current conditions.
- Historical data tracking and reporting to assist in compliance and analysis.

### 3. **Safety Compliance**
- Ensures cold-chain goods meet safety regulations by providing real-time data to decision-makers.
- Automated alerts when conditions deviate from safety thresholds, reducing the risk of spoilage or non-compliance.

### 4. **Improved Decision-Making**
- Provides actionable insights based on real-time and historical data to help managers make informed decisions.
- Enhances the ability to react promptly to potential risks or issues in the supply chain.

---

## **Tech Stack**

- **C++**: Used for programming the Arduino to interface with the IoT sensors.
- **Arduino**: Hardware platform for connecting the sensors and collecting data.
- **Blynk IoT**: A cloud-based platform used to display real-time data on the dashboard and manage alerts.
  
---

## **Installation Guide**

### **Prerequisites**
- Arduino IDE
- Blynk App
- Necessary IoT hardware (e.g., temperature and humidity sensors)

### **Arduino Setup**
1. Install the necessary libraries (Blynk, DHT Sensor, etc.) in the Arduino IDE.
2. Upload the Arduino code to the microcontroller to collect sensor data and send it to the Blynk cloud.
3. Connect the IoT sensors to the Arduino and set up the hardware according to the circuit diagram.

### **Blynk Setup**
1. Download the Blynk app from the Play Store or App Store.
2. Create a project in the Blynk app, and get the Auth Token.
3. Add widgets in the app to visualize real-time data (e.g., temperature, humidity).
4. Use the Blynk Auth Token in your Arduino code to link the microcontroller to the Blynk cloud.

---

## **Usage**

1. **Real-Time Monitoring**: The system continuously tracks the conditions of cold-chain goods and updates the Blynk dashboard in real-time.
2. **Notifications**: Automated alerts are sent when monitored conditions deviate from pre-set safety thresholds.
3. **Historical Data Access**: Users can view historical data and generate reports for analysis and compliance.
4. **Visual Dashboard**: The Blynk IoT dashboard displays real-time data in graphs and charts for quick monitoring.

---

## **Screenshots**
- System Flow Diagram
![image](https://github.com/user-attachments/assets/afb3c344-0ba9-44b4-89e0-19fc24dcb494)
- Email Notification
![image](https://github.com/user-attachments/assets/2cf783f9-3de7-4ddf-a9f2-1710f1ce5b00)
- Application Dashboard
![image](https://github.com/user-attachments/assets/0defb26f-5e69-45bc-8ab0-f91027b95360)

---

## **Future Enhancements**

- **Mobile App Expansion**: Further enhance the Blynk app functionalities for mobile monitoring.
- **Machine Learning Predictions**: Use machine learning algorithms to predict potential issues or deviations before they happen.
- **Expanded IoT Integration**: Support for additional IoT devices to monitor more conditions like air quality or vibration levels.

---
