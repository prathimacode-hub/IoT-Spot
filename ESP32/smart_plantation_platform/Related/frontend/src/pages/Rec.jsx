import { useState, useEffect } from "react";
import Navbar from "../components/Navbar";

const cropOptions = ["rice", "wheat", "maize", "tea", "coffee", "cocoa", "banana", "sugarcane", "rubber", "cotton"];

// Mapping crop names to numeric encoding (0-9)
const cropEncoding = {
  rice: 0,
  wheat: 1,
  maize: 2,
  tea: 3,
  coffee: 4,
  cocoa: 5,
  banana: 6,
  sugarcane: 7,
  rubber: 8,
  cotton: 9,
};

function Rec() {
  const [averages, setAverages] = useState({});
  const [resultMessage, setResultMessage] = useState("");
  const [showFertilizerInput, setShowFertilizerInput] = useState(false);
  const [actualYield, setActualYield] = useState("");
  const [selectedCrop, setSelectedCrop] = useState("");
  const [showCropSelect, setShowCropSelect] = useState(false);
  const [idealYield, setIdealYield] = useState(null);

  const backendURL = "http://localhost:5000"; // Update if your backend URL is different

  const getNumber = (str) => parseFloat(str.replace(/[^\d.-]/g, "")) || 0;

  // ---------------- Fetch sensor data ----------------
  useEffect(() => {
    const fetchSensorData = async () => {
      try {
        const res = await fetch(`${backendURL}/api/sensors`);
        const data = await res.json();

        if (!data || data.length === 0) return;

        const total = data.reduce(
          (acc, curr) => {
            acc.soilMoisture += curr["Soil Moisture"] || 0;
            acc.temperature += curr["Temperature"] || 0;
            acc.humidity += curr["Humidity"] || 0;
            acc.light += curr["Light Intensity"] || 0;
            acc.waterLevel += curr["Water Level"] || 0;
            acc.rain += curr["Rain"] || 0;
            return acc;
          },
          { soilMoisture: 0, temperature: 0, humidity: 0, light: 0, waterLevel: 0, rain: 0 }
        );

        const count = data.length;
        setAverages({
          "Soil Moisture": (total.soilMoisture / count).toFixed(2),
          "Temperature": (total.temperature / count).toFixed(2),
          "Humidity": (total.humidity / count).toFixed(2),
          "Light Intensity": (total.light / count).toFixed(0),
          "Water Level": (total.waterLevel / count).toFixed(2),
          "Rain": (total.rain / count).toFixed(2),
        });
      } catch (err) {
        console.error("Error fetching sensor data:", err);
      }
    };

    fetchSensorData();
  }, []);

  // ---------------- ML Prediction Handlers ----------------

  const getModelPayload = () => ({
    Crop_enc: cropEncoding[selectedCrop] ?? 0,
    temperature: getNumber(averages["Temperature"]),
    humidity: getNumber(averages["Humidity"]),
    moisture: getNumber(averages["Soil Moisture"]),
    light_intensity: getNumber(averages["Light Intensity"]),
    water_level: getNumber(averages["Water Level"]),
    rain: getNumber(averages["Rain"]),
    ideal_yield: idealYield ?? 0,
    actual_yield: getNumber(actualYield),
  });

  const handlePredictGrowth = async () => {
    if (!selectedCrop) {
      setResultMessage("🌾 Please select a crop first.");
      return;
    }

    try {
      const payload = {
        Crop_enc: cropEncoding[selectedCrop],
        temperature: getNumber(averages["Temperature"]),
        humidity: getNumber(averages["Humidity"]),
        moisture: getNumber(averages["Soil Moisture"]),
        light_intensity: getNumber(averages["Light Intensity"]),
        rain: getNumber(averages["Rain"]),
      };

      const res = await fetch(`${backendURL}/api/predict/ideal_yield`, {
        method: "POST",
        headers: { "Content-Type": "application/json" },
        body: JSON.stringify(payload),
      });

      const data = await res.json();
      const ideal = data.ideal_yield;
      setIdealYield(ideal);
      setResultMessage( `🌱 For ${selectedCrop.toUpperCase()}, ideal yield is approximately: ${Number(ideal).toFixed(2)} units`);
      setShowCropSelect(false);
      setShowFertilizerInput(false);
    } catch (err) {
      console.error(err);
      setResultMessage("Error predicting ideal yield.");
    }
  };

  const handleFertilizerClick = () => {
    setShowCropSelect(false);
    setResultMessage("");

    if (!idealYield) {
      setResultMessage("⚠️ Please predict the ideal yield first.");
      setShowFertilizerInput(false);
      return;
    }

    setShowFertilizerInput(true);
  };

  // ------------------ Fertilizer Input Handler ------------------
  const handleFertilizerSubmit = async () => {
    if (!actualYield) {
      setResultMessage("⚠️ Please enter the actual yield.");
      return;
    }

    // Only send ideal_yield and actual_yield now
    const payload = {
      ideal_yield: idealYield ?? 0,
      actual_yield: getNumber(actualYield),
    };

    try {
      console.log("Submitting payload:", payload); // Debug log
      const res = await fetch(`${backendURL}/api/predict/fertilizer`, {
        method: "POST",
        headers: { "Content-Type": "application/json" },
        body: JSON.stringify(payload),
      });

      if (!res.ok) {
        throw new Error("Server error");
      }

      const data = await res.json();
      setResultMessage(`🧴 Fertilizer Recommendation: ${data.fertilizer_recommendation}`);
      setShowFertilizerInput(false);
    } catch (err) {
      console.error(err);
      setResultMessage("Error generating fertilizer recommendation.");
    }
  };



  const handlePestDetection = async () => {
    setShowCropSelect(false);
    setShowFertilizerInput(false);

    const payload = {
      temperature: getNumber(averages["Temperature"]),
      humidity: getNumber(averages["Humidity"]),
      moisture: getNumber(averages["Soil Moisture"]),
      light_intensity: getNumber(averages["Light Intensity"]),
      rainfall: getNumber(averages["Rain"]),
    };

    try {
      const res = await fetch(`${backendURL}/api/predict/pest-data`, {
        method: "POST",
        headers: { "Content-Type": "application/json" },
        body: JSON.stringify(payload),
      });
      const data = await res.json();
      setResultMessage(`🐛 Pest Detection: ${data.pest_risk}`);
    } catch (err) {
      console.error(err);
      setResultMessage("Error detecting pests.");
    }
  };

  const openCropSelection = () => {
    setShowFertilizerInput(false);
    setResultMessage("");
    setShowCropSelect(true);
  };

  // ---------------- JSX ----------------
  return (
    <div
      className="w-screen bg-cover bg-center bg-fixed min-h-screen"
      style={{ backgroundImage: "url('/bg3.jpeg')" }}
    >
      <Navbar />

      <div className="flex flex-col items-center pt-[6rem] px-4">
        <h2 className="text-2xl md:text-3xl font-bold text-black bg-white bg-opacity-80 px-6 py-3 rounded-xl shadow-md mb-8 text-center">
          Data Records
        </h2>

        {/* Average Sensor Data */}
        <div className="bg-white bg-opacity-90 p-8 rounded-xl shadow-lg w-full max-w-4xl mb-8">
          <h3 className="text-xl font-bold mb-4">🌿 Average Sensor Data</h3>
          <ul className="grid grid-cols-1 md:grid-cols-2 gap-2">
            {Object.entries(averages).map(([key, value]) => (
              <li key={key} className="bg-green-100 p-3 rounded-lg shadow flex justify-between items-center">
                <span>{key}</span>
                <span className="font-semibold">{value}</span>
              </li>
            ))}
          </ul>
        </div>

        {/* Action Buttons */}
        <div className="flex flex-col md:flex-row gap-6 mb-6">
          <button
            onClick={openCropSelection}
            className="bg-purple-600 text-white px-6 py-4 rounded-xl shadow-lg flex items-center gap-2 hover:scale-105 transition"
          >
            🌱 Predict Ideal Yield
          </button>

          <button
            onClick={handleFertilizerClick}
            className="bg-yellow-600 text-white px-6 py-4 rounded-xl shadow-lg flex items-center gap-2 hover:scale-105 transition"
          >
            🧴 Recommend Fertilizer
          </button>

          <button
            onClick={handlePestDetection}
            className="bg-red-600 text-white px-6 py-4 rounded-xl shadow-lg flex items-center gap-2 hover:scale-105 transition"
          >
            🐛 Pest Detection
          </button>
        </div>

        {/* Crop Selection */}
        {showCropSelect && (
          <div className="flex flex-col items-center gap-4 mb-6 bg-white p-6 rounded-xl shadow-lg">
            <select
              value={selectedCrop}
              onChange={(e) => setSelectedCrop(e.target.value)}
              className="p-3 rounded-xl shadow-lg w-64 text-center"
            >
              <option value="">-- Select Crop --</option>
              {cropOptions.map((crop) => (
                <option key={crop} value={crop}>
                  {crop}
                </option>
              ))}
            </select>
            <button
              onClick={handlePredictGrowth}
              className="bg-purple-700 text-white px-6 py-3 rounded-xl shadow-lg hover:scale-105 transition"
            >
              Predict
            </button>
          </div>
        )}

        {/* Fertilizer Input */}
        {showFertilizerInput && (
          <div className="flex flex-col items-center gap-4 mb-6 bg-white p-6 rounded-xl shadow-lg">
            <input
              type="number"
              placeholder="Enter actual yield"
              value={actualYield}
              onChange={(e) => setActualYield(e.target.value)}
              className="p-3 rounded-xl shadow-lg w-64 text-center"
            />
            <button
              onClick={handleFertilizerSubmit}
              className="bg-yellow-700 text-white px-6 py-3 rounded-xl shadow-lg hover:scale-105 transition"
            >
              Submit
            </button>
          </div>
        )}

        {/* Result Display */}
        {resultMessage && (
          <div className="bg-white bg-opacity-90 p-6 rounded-xl shadow-lg w-full max-w-4xl text-center font-semibold text-lg">
            {resultMessage}
          </div>
        )}
      </div>
    </div>
  );
}

export default Rec;
