# Smart-Plantation
The Smart Plantation Platform integrates IoT, Blockchain, and Machine Learning to optimize farming. Using ESP32 sensors, it monitors soil moisture, temperature, and rain in real-time. The system features automated irrigation, crop yield prediction, pest detection, and CSV data export. Developed with React, Node.js, and Python for smart agriculture.


# 🌱 Smart Plantation Platform

A state-of-the-art, IoT-driven agriculture platform integrated with **Machine Learning** for precision farming and **Blockchain-like data integrity** for secure sensor logging. This platform offers real-time monitoring, automated irrigation, and intelligent crop insights.

---

## 🚀 Key Features

### 📡 Real-time IoT Monitoring
Monitors critical environmental parameters every 5 seconds:
- **Temperature & Humidity** (DHT22)
- **Soil Moisture**
- **Light Intensity** (LDR)
- **Water Level** (Float Switch)
- **Rain Intensity**

### 🔐 Blockchain Data Integrity
- Implements a cryptographic hashing mechanism (SHA256).
- Every data block contains the hash of the previous block, creating an immutable ledger of sensor readings.
- Prevents data tampering and ensures reliable research records.

### 💧 Precision Irrigation Control
- **Manual Mode**: Toggle the water pump directly from the dashboard.
- **Auto Mode**: Self-regulating system that triggers the pump based on soil moisture thresholds.
- **Scheduling**: Set specific start times and durations for irrigation.

### 🧠 AI/ML Intelligent Insights
- **Ideal Yield Prediction**: Predicts potential crop yield based on climate and soil data.
- **Fertilizer Recommendation**: Suggests the optimal fertilizer type to close the gap between actual and ideal yields.
- **Pest Detection**: 
    - **Data-based**: Risk assessment using environmental trends.
    - **Image-based**: Convolutional Neural Network (CNN) model to identify pests from uploaded crop images.

### 📊 Data Management
- Normalized visual trends via interactive charts.
- **Export to CSV**: Download historical sensor data for offline analysis.

---

## 🛠️ Tech Stack

- **Frontend**: React (Vite), Tailwind CSS, Recharts, Lucide React, Leaflet.
- **Backend*: Node.js, Express, MongoDB (Mongoose).
- **Machine Learning**: Python 3, TensorFlow/Keras, Scikit-Learn, Joblib, Numpy.
- **Hardware**: ESP32, DHT22, LDR, Soil Moisture Sensor, Rain Sensor, Relay Module.

---

## ⚙️ Installation & Setup

### 1. Prerequisites
- **Node.js** (v18+)
- **MongoDB** (Local or Atlas)
- **Python** (v3.10+)
- **Arduino IDE** (for ESP32 upload)

### 2. Backend Setup
```bash
cd backend
npm install
```
- Ensure **MongoDB** is running on `mongodb://localhost:27017/smartplant`.
- Start the server:
```bash
node server.js
```

### 3. Machine Learning Setup
Install the required Python libraries:
```bash
pip install tensorflow numpy joblib scikit-learn pillow
```
*Note: Ensure your Python executable is in your system PATH as the backend spawns python processes.*

### 4. Frontend Setup
```bash
cd frontend
npm install
npm run dev
```
- The dashboard will be available at `http://localhost:5173`.

### 5. Hardware Setup (ESP32)
1. Open `ardu_code/ardu_code.ino` in Arduino IDE.
2. Install required libraries: `DHT`, `Crypto`, `ArduinoJson`.
3. Update specific constants in the code:
   - `ssid`: Your WiFi name.
   - `password`: Your WiFi password.
   - `serverName`: The IP address of your machine running the backend (e.g., `http://192.168.1.5:5000/api/sensors`).
4. Upload to your ESP32.

---

## 📁 Project Structure

- `smart_plantation_platform.ino`: ESP32 source code and hashing logic.
- `/Related/backend`: Node.js server, API routes, and ML integration scripts.
- `/Related/backend/ml`: Python scripts for prediction models.
- `/Related/backend/models`: Trained Models for Prediction.
- `/Related/frontend`: React application and dashboard components.
- `/requirements.txt`: Python dependencies.
- `/docs`: Documentation and related files.

---

### 6. Screenshots

## Architecture

<img width="1459" height="941" alt="block_diagram" src="https://github.com/user-attachments/assets/ca44c176-cdf3-4f14-a476-f5d1bd71bfbb" />

## Home Page

<img width="1087" height="528" alt="image" src="https://github.com/user-attachments/assets/5e547917-0af2-4e64-99e5-624d804922fe" />

## Dashboard

<img width="1093" height="520" alt="image" src="https://github.com/user-attachments/assets/e31b9ea2-7ce1-4c1c-af28-c24885da5727" />

<img width="1092" height="506" alt="image" src="https://github.com/user-attachments/assets/f92f5e47-685f-4ef1-ad26-1c3395deefa9" />

## Irrigation Control

<img width="1083" height="520" alt="image" src="https://github.com/user-attachments/assets/166229e2-c2c3-4d2e-9daa-13377631efcc" />

## ML Predictions

<img width="1042" height="439" alt="image" src="https://github.com/user-attachments/assets/3b96bbf6-5b56-40e6-be5c-2c5cc8316b2a" />

## Circuit Diagaram

<img width="492" height="468" alt="image" src="https://github.com/user-attachments/assets/43ba99ff-3e4a-4751-8d7b-14865d0e2e06" />

<img width="343" height="315" alt="image" src="https://github.com/user-attachments/assets/b181e93b-232b-4e15-a2c2-db4e9e482dc1" />

<img width="1113" height="549" alt="image" src="https://github.com/user-attachments/assets/edd4595a-2c20-48ab-8606-870bfe33000a" />

---














