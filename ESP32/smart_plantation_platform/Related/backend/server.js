const express = require("express");
const mongoose = require("mongoose");
const cors = require("cors");
const { spawn } = require("child_process");
const path = require("path");
const multer = require("multer");
const fs = require("fs");

const app = express();
app.use(cors());
app.use(express.json());

// ------------------ MongoDB Setup ------------------
mongoose.connect("mongodb://localhost:27017/smartplant", {
  useNewUrlParser: true,
  useUnifiedTopology: true,
});

const sensorSchema = new mongoose.Schema({
  "Soil Moisture": Number,
  "Temperature": Number,
  "Humidity": Number,
  "Light Intensity": Number,
  "Water Level": Number,
  "Rain": Number,
  "Previous Hash": String,
  "Current Hash": String,
  "Date": String,
  "Time": String,
});

const Sensor = mongoose.model("Sensor", sensorSchema);

// ------------------ Sensor Routes ------------------

// GET all sensor data
app.get("/api/sensors", async (req, res) => {
  try {
    const data = await Sensor.find();
    res.json(data);
  } catch (error) {
    res.status(500).json({ error: error.message });
  }
});

// POST new sensor data from ESP32
app.post("/api/sensors", async (req, res) => {
  try {
    const newSensor = new Sensor(req.body);
    await newSensor.save();
    res.status(201).json({ message: "Data saved successfully", data: newSensor });
  } catch (error) {
    res.status(400).json({ error: error.message });
  }
});

// ------------------ Helper: Run Python Script ------------------
function runPythonScript(scriptName, inputData) {
  return new Promise((resolve, reject) => {
    const scriptPath = path.join(__dirname, "ml", scriptName);
    const py = spawn("python", [scriptPath, JSON.stringify(inputData)]);

    let result = "";
    let error = "";

    py.stdout.on("data", (data) => (result += data.toString()));
    py.stderr.on("data", (data) => (error += data.toString()));

    py.on("close", (code) => {
      if (error) console.warn("Python stderr:", error);
      try {
        const jsonResult = JSON.parse(result);
        resolve(jsonResult);
      } catch (err) {
        reject(new Error("Invalid JSON from Python script: " + result));
      }
    });
  });
}

// ------------------ ML Prediction Routes ------------------

// Fertilizer Prediction
app.post("/api/predict/fertilizer", (req, res) => {
  try {
    const { ideal_yield = 0, actual_yield = 0 } = req.body;

    const fertilizers = [
      "Urea",
      "DAP (Diammonium Phosphate)",
      "14-35-14",
      "28-28",
      "17-17-17",
      "20-20",
      "10-26-26"
    ];

    let recommendation = "";

    if (actual_yield >= ideal_yield - 100) {
      recommendation = "No fertilizer needed 🌿";
    } else {
      // Pick random fertilizer
      const randomIndex = Math.floor(Math.random() * fertilizers.length);
      recommendation = fertilizers[randomIndex];
    }

    res.json({ fertilizer_recommendation: recommendation });
  } catch (err) {
    console.error(err);
    res.status(500).json({ error: err.toString() });
  }
});

// Ideal Yield Prediction
app.post("/api/predict/ideal_yield", async (req, res) => {
  try {
    const payload = {
      Crop_enc: req.body["Crop_enc"] || 0,
      temperature: req.body["temperature"] || 0,
      humidity: req.body["humidity"] || 0,
      moisture: req.body["moisture"] || 0,
      light_intensity: req.body["light_intensity"] || 0,
      rain: req.body["rain"] || 0,
    };

    const result = await runPythonScript("yield_predict.py", payload);
    res.json({ ideal_yield: result.ideal_yield });
  } catch (err) {
    res.status(500).json({ error: err.toString() });
  }
});

// Pest Prediction from Data
app.post("/api/predict/pest-data", async (req, res) => {
  try {
    const payload = {
      temperature: req.body.temperature || 0,
      humidity: req.body.humidity || 0,
      moisture: req.body.moisture || 0,
      light_intensity: req.body.light_intensity || 0,
      rainfall: req.body.rainfall || 0,
    };

    const result = await runPythonScript("pest_data_predict.py", payload);
    console.log("Pest Detection Result:", result);
    res.json({ pest_risk: result.pest_risk });
  } catch (err) {
    console.error("Error in pest prediction:", err);
    res.status(500).json({ error: err.toString() });
  }
});

// ------------------ Pest Prediction from Image ------------------
const upload = multer({ dest: "uploads/" });

app.post("/api/predict/pest-image", upload.single("image"), async (req, res) => {
  if (!req.file) return res.status(400).json({ error: "No image uploaded" });

  const imagePath = req.file.path;

  try {
    const scriptPath = path.join(__dirname, "ml", "pest_image_predict.py");
    const py = spawn("python", [scriptPath, imagePath]);

    let result = "";
    let error = "";

    py.stdout.on("data", (data) => {
      result += data.toString().trim();
    });

    py.stderr.on("data", (data) => {
      error += data.toString();
    });

    py.on("close", (code) => {
      if (error) console.warn("Python stderr:", error);

      try {
        console.log("Python stdout:", result);
        const jsonResult = JSON.parse(result);
        res.json(jsonResult);
      } catch (err) {
        console.error("Error parsing Python output:", result);
        res.status(500).json({ error: "Invalid JSON from Python script" });
      }

      fs.unlink(imagePath, (unlinkErr) => {
        if (unlinkErr) console.warn("Failed to delete uploaded image:", unlinkErr);
      });
    });
  } catch (err) {
    console.error("Error in /api/predict/pest-image:", err);
    res.status(500).json({ error: err.toString() });
  }
});

app.post("/api/control/update", async (req, res) => {
  try {
    const { pumpOn, automationOn, schedule } = req.body;

    console.log("🛰️ Received Control Update:");
    console.log("Pump:", pumpOn ? "ON" : "OFF");
    console.log("Automation:", automationOn ? "Enabled" : "Disabled");
    console.log("Schedule:", schedule.startTime && schedule.duration ? schedule : "No schedule set");

    // ✅ Your ESP32 IP (make sure static or check Serial Monitor)
    const espUrl = "http://YOUR_ESP32_IP/control";

    // ✅ Send command to ESP32
    const espResponse = await fetch(espUrl, {
      method: "POST",
      headers: { "Content-Type": "application/json" },
      body: JSON.stringify({
        pumpOn,
        automationOn,
        schedule: {
          startTime: schedule?.startTime || "",
          duration: schedule?.duration || "",
        },
      }),
    });

    const espData = await espResponse.text();

    // ✅ Respond to frontend
    res.json({
      success: true,
      message: "✅ Control update sent successfully to ESP32",
      espResponse: espData,
    });
  } catch (err) {
    console.error("❌ Error sending command to ESP32:", err);
    res.status(500).json({ error: "Failed to send control command to ESP32" });
  }
});

// ------------------ Start Server ------------------
app.listen(5000, () => {
  console.log("Server running on http://localhost:5000");
});
