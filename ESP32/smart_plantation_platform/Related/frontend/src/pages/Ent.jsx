import { useState } from "react";
import Navbar from "../components/Navbar";
import Papa from "papaparse";

function Ent() {
  const [mode, setMode] = useState("upload");
  const [file, setFile] = useState(null);
  const [parameters, setParameters] = useState({
    soilMoisture: "",
    temperature: "",
    humidity: "",
    light: "",
    waterLevel: "",
    rain: "",
  });
  const [resultMessage, setResultMessage] = useState("");
  const [showFertilizerInput, setShowFertilizerInput] = useState(false);
  const [actualYield, setActualYield] = useState("");
  const [showCropSelect, setShowCropSelect] = useState(false);
  const [selectedCrop, setSelectedCrop] = useState("");
  const [idealYield, setIdealYield] = useState(null);
  const [pestMode, setPestMode] = useState(null);
  const [pestImage, setPestImage] = useState(null);

  const backendURL = "http://localhost:5000";

  const cropOptions = [
    "rice", "wheat", "maize", "tea", "coffee", "cocoa",
    "banana", "sugarcane", "rubber", "cotton"
  ];

  const cropEncoding = {
    rice: 0, wheat: 1, maize: 2, tea: 3, coffee: 4,
    cocoa: 5, banana: 6, sugarcane: 7, rubber: 8, cotton: 9
  };

  const getNumber = (str) => parseFloat(str.toString().replace(/[^\d.-]/g, "")) || 0;

  // ---------------- CSV Upload Handler ----------------
  const handleFileUpload = (e) => {
    const uploadedFile = e.target.files[0];
    setFile(uploadedFile);
    if (uploadedFile) {
      Papa.parse(uploadedFile, {
        header: true,
        dynamicTyping: true,
        complete: (result) => {
          const data = result.data;
          if (!data || data.length === 0) return;

          const keys = ["temperature", "humidity", "moisture", "light_intensity", "rainfall"];
          const sums = {};
          keys.forEach((k) => (sums[k] = 0));

          data.forEach((row) => {
            keys.forEach((k) => (sums[k] += parseFloat(row[k]) || 0));
          });

          const count = data.length;
          setParameters({
            temperature: (sums.temperature / count).toFixed(2),
            humidity: (sums.humidity / count).toFixed(2),
            soilMoisture: (sums.moisture / count).toFixed(2),
            light: (sums.light_intensity / count).toFixed(2),
            rain: (sums.rainfall / count).toFixed(2),
            waterLevel: parameters.waterLevel || 0,
          });
        },
      });
    }
  };

  // ---------------- Ideal Yield Prediction ----------------
  const handlePredictGrowth = async () => {
    if (!selectedCrop) {
      setResultMessage("🌾 Please select a crop first.");
      setShowCropSelect(true);
      return;
    }

    setShowFertilizerInput(false);
    setPestMode(null);

    const payload = {
      Crop_enc: cropEncoding[selectedCrop],
      temperature: getNumber(parameters.temperature),
      humidity: getNumber(parameters.humidity),
      moisture: getNumber(parameters.soilMoisture),
      light_intensity: getNumber(parameters.light),
      rain: getNumber(parameters.rain),
    };

    try {
      const res = await fetch(`${backendURL}/api/predict/ideal_yield`, {
        method: "POST",
        headers: { "Content-Type": "application/json" },
        body: JSON.stringify(payload),
      });
      const data = await res.json();
      setIdealYield(data.ideal_yield);
      setResultMessage(`🌱 Ideal Yield for ${selectedCrop.toUpperCase()}: ${Number(data.ideal_yield).toFixed(2)} units`);
      setShowCropSelect(false);
    } catch (err) {
      console.error(err);
      setResultMessage("Error predicting ideal yield.");
    }
  };

  // ---------------- Fertilizer Prediction ----------------
  const handleFertilizerClick = () => {
    setShowCropSelect(false);
    setPestMode(null);
    setResultMessage("");

    if (!idealYield) {
      setResultMessage("⚠️ Please predict the ideal yield first.");
      return;
    }

    setShowFertilizerInput(true);
  };

  const handleFertilizerSubmit = async () => {
    const payload = {
      ideal_yield: idealYield ?? 0,
      actual_yield: getNumber(actualYield),
    };

    try {
      const res = await fetch(`${backendURL}/api/predict/fertilizer`, {
        method: "POST",
        headers: { "Content-Type": "application/json" },
        body: JSON.stringify(payload),
      });
      const data = await res.json();
      setResultMessage(`🧴 Fertilizer Recommendation: ${data.fertilizer_recommendation}`);
      setShowFertilizerInput(false);
    } catch (err) {
      console.error(err);
      setResultMessage("Error generating fertilizer recommendation.");
    }
  };

  // ---------------- Pest Detection ----------------
  const handlePestDetection = () => {
    setShowCropSelect(false);
    setShowFertilizerInput(false);
    setResultMessage("");
    setPestMode(pestMode ? null : "select");
  };

  const handlePestDataPredict = async () => {
    const payload = {
      temperature: getNumber(parameters.temperature),
      humidity: getNumber(parameters.humidity),
      moisture: getNumber(parameters.soilMoisture),
      light_intensity: getNumber(parameters.light),
      rainfall: getNumber(parameters.rain),
    };

    try {
      const res = await fetch(`${backendURL}/api/predict/pest-data`, {
        method: "POST",
        headers: { "Content-Type": "application/json" },
        body: JSON.stringify(payload),
      });
      const data = await res.json();
      setResultMessage(`🐛 Pest Detection (Data): ${data.pest_risk}`);
      setPestMode(null); // Hide the button after prediction
    } catch (err) {
      console.error(err);
      setResultMessage("Error detecting pests from data.");
    }
  };

  const handlePestImagePredict = async () => {
    if (!pestImage) {
      setResultMessage("Please upload an image first!");
      return;
    }

    const formData = new FormData();
    formData.append("image", pestImage);

    try {
      const res = await fetch(`${backendURL}/api/predict/pest-image`, {
        method: "POST",
        body: formData,
      });
      const data = await res.json();
      setResultMessage(`🐛 Pest Detection (Image): ${data.pest_name || data.result}`);
      setPestMode(null); // Hide after prediction
    } catch (err) {
      console.error(err);
      setResultMessage("Error detecting pest from image.");
    }
  };

  return (
    <div
      className="w-screen bg-cover bg-center bg-fixed min-h-screen"
      style={{ backgroundImage: "url('/bg3.jpeg')" }}
    >
      <Navbar />

      <div className="flex flex-col items-center pt-[6rem] px-4">
        <h2 className="text-2xl md:text-3xl font-bold text-black bg-white bg-opacity-80 px-6 py-3 rounded-xl shadow-md mb-8 text-center">
          Data Entry
        </h2>

        {/* Mode Toggle */}
        <div className="flex gap-4 mb-6">
          <button
            onClick={() => setMode("upload")}
            className={`px-6 py-3 rounded-xl shadow-lg transition ${mode === "upload" ? "bg-green-600 text-white" : "bg-white bg-opacity-80"}`}
          >
            Upload CSV
          </button>
          <button
            onClick={() => setMode("enter")}
            className={`px-6 py-3 rounded-xl shadow-lg transition ${mode === "enter" ? "bg-green-600 text-white" : "bg-white bg-opacity-80"}`}
          >
            Manual Entry
          </button>
        </div>

        {/* Upload Mode */}
        {mode === "upload" && (
          <div className="flex flex-col items-center gap-4 mb-6 w-full max-w-md">
            <label className="w-full bg-white bg-opacity-80 p-4 rounded-xl shadow-lg text-center cursor-pointer hover:bg-opacity-90 transition">
              {file ? file.name : "Choose CSV File"}
              <input type="file" accept=".csv" onChange={handleFileUpload} className="hidden" />
            </label>
          </div>
        )}

        {/* Manual Entry */}
        {mode === "enter" && (
          <div className="bg-white bg-opacity-90 p-6 rounded-xl shadow-lg w-full max-w-4xl mb-6 grid grid-cols-1 md:grid-cols-2 gap-4">
            {Object.entries(parameters).map(([key, value]) => (
              <div key={key}>
                {key === "soilMoisture" && "🌱 Soil Moisture (%):"}
                {key === "temperature" && "🌡 Temperature (°C):"}
                {key === "humidity" && "💧 Humidity (%):"}
                {key === "light" && "☀️ Light Intensity (lx):"}
                {key === "waterLevel" && "💦 Water Level (%):"}
                {key === "rain" && "🌧 Rain (mm):"}
                <input
                  type="number"
                  value={value}
                  onChange={(e) => setParameters({ ...parameters, [key]: e.target.value })}
                  className="w-full p-2 rounded-xl shadow mt-1"
                />
              </div>
            ))}
          </div>
        )}

        {/* Action Buttons */}
        <div className="flex flex-col md:flex-row gap-6 mb-6">
          <button
            onClick={() => {
              setShowCropSelect(true);
              setShowFertilizerInput(false);
              setPestMode(null);
              setResultMessage("");
            }}
            className="bg-purple-600 text-white px-6 py-4 rounded-xl shadow-lg hover:scale-105 transition"
          >
            🌱 Predict Ideal Yield
          </button>

          <button
            onClick={handleFertilizerClick}
            className="bg-yellow-600 text-white px-6 py-4 rounded-xl shadow-lg hover:scale-105 transition"
          >
            🧴 Recommend Fertilizer
          </button>

          <button
            onClick={handlePestDetection}
            className="bg-red-600 text-white px-6 py-4 rounded-xl shadow-lg hover:scale-105 transition"
          >
            🐛 Pest Detection
          </button>
        </div>

        {/* Crop Selection Box (white box) */}
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
          <div className="flex flex-col items-center gap-4 mb-6">
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

        {/* Pest Detection Mode */}
        {pestMode === "select" && (
          <div className="flex gap-6 mb-6">
            <button
              onClick={() => setPestMode("data")}
              className="bg-green-600 text-white px-6 py-3 rounded-xl shadow-lg hover:scale-105 transition"
            >
              📊 Use Data
            </button>
            <button
              onClick={() => setPestMode("image")}
              className="bg-blue-600 text-white px-6 py-3 rounded-xl shadow-lg hover:scale-105 transition"
            >
              🖼 Upload Image
            </button>
          </div>
        )}

        {pestMode === "data" && (
          <button
            onClick={handlePestDataPredict}
            className="bg-green-700 text-white px-6 py-3 rounded-xl shadow-lg hover:scale-105 transition mb-6"
          >
            Predict Pest from Data
          </button>
        )}

        {pestMode === "image" && (
          <div className="flex flex-col items-center gap-4 mb-6">
            <input
              type="file"
              accept="image/*"
              onChange={(e) => setPestImage(e.target.files[0])}
              className="bg-white p-3 rounded-xl shadow-lg w-80"
            />
            <button
              onClick={handlePestImagePredict}
              className="bg-blue-700 text-white px-6 py-3 rounded-xl shadow-lg hover:scale-105 transition"
            >
              Predict Pest from Image
            </button>
          </div>
        )}

        {/* Result */}
        {resultMessage && (
          <div className="bg-white bg-opacity-90 p-6 rounded-xl shadow-lg w-full max-w-4xl text-center font-semibold text-lg">
            {resultMessage}
          </div>
        )}
      </div>
    </div>
  );
}

export default Ent;
