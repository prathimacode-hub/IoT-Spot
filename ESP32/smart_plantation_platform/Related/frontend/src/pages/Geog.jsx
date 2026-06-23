import { useState, useEffect } from "react";
import Navbar from "../components/Navbar";

const states = [
  // States
  "Andhra Pradesh", "Arunachal Pradesh", "Assam", "Bihar", "Chhattisgarh",
  "Goa", "Gujarat", "Haryana", "Himachal Pradesh", "Jharkhand",
  "Karnataka", "Kerala", "Madhya Pradesh", "Maharashtra", "Manipur",
  "Meghalaya", "Mizoram", "Nagaland", "Odisha", "Punjab",
  "Rajasthan", "Sikkim", "Tamil Nadu", "Telangana", "Tripura",
  "Uttar Pradesh", "Uttarakhand", "West Bengal",

  // Union Territories
  "Andaman and Nicobar Islands", "Chandigarh", "Dadra and Nagar Haveli and Daman and Diu",
  "Delhi", "Jammu and Kashmir", "Ladakh", "Lakshadweep", "Puducherry"
];

const months = ["January","February","March","April","May","June","July","August","September","October","November","December"];

function Geog() {
  const [selectedState, setSelectedState] = useState("");
  const [selectedMonth, setSelectedMonth] = useState("");
  const [geoData, setGeoData] = useState({});
  const [result, setResult] = useState(null);

  useEffect(() => {
    fetch("/geoData.json")
      .then((res) => res.json())
      .then((data) => setGeoData(data))
      .catch((err) => console.error("Failed to load geo data:", err));
  }, []);

  const handleGenerate = () => {
    if (!selectedState || !selectedMonth) return;
    const data = geoData[selectedState]?.[selectedMonth];
    setResult(data || { parameters: {}, nutrients: [], crops: [] });
  };

  return (
    <div
      className="w-screen bg-cover bg-center bg-fixed min-h-screen"
      style={{ backgroundImage: "url('/bg3.jpeg')" }}
    >
      <Navbar />

      {/* Container just below navbar */}
      <div className="flex flex-col items-center pt-[6rem] px-4">
        <h2 className="text-2xl md:text-3xl font-bold text-black bg-white bg-opacity-80 px-6 py-3 rounded-xl shadow-md mb-8 text-center">
          Geographical Plantation Data
        </h2>

        {/* Selection Inputs */}
        <div className="flex flex-col md:flex-row gap-6 mb-8">
          <select
            value={selectedState}
            onChange={(e) => setSelectedState(e.target.value)}
            className="p-4 rounded-xl shadow-lg bg-white bg-opacity-80"
          >
            <option value="">Select State</option>
            {states.map((state) => (
              <option key={state} value={state}>{state}</option>
            ))}
          </select>

          <select
            value={selectedMonth}
            onChange={(e) => setSelectedMonth(e.target.value)}
            className="p-4 rounded-xl shadow-lg bg-white bg-opacity-80"
          >
            <option value="">Select Month</option>
            {months.map((month) => (
              <option key={month} value={month}>{month}</option>
            ))}
          </select>

          <button
            onClick={handleGenerate}
            className="bg-green-700 text-white px-6 py-4 rounded-xl shadow-lg hover:scale-105 transition"
          >
            Generate
          </button>
        </div>

        {/* Display Results */}
        {result && (
          <div className="bg-white bg-opacity-90 p-8 rounded-xl shadow-lg w-full max-w-4xl animate-fadeIn mb-8">
            
            <h3 className="text-xl font-bold mb-4">🌿 CLimate Data:</h3>
            <ul className="grid grid-cols-1 md:grid-cols-2 gap-2 mb-4">
              {Object.entries(result.parameters).map(([key, value]) => (
                <li key={key} className="bg-green-100 p-3 rounded-lg shadow flex justify-between items-center">
                  <span>{key}</span>
                  <span className="font-semibold">{value}</span>
                </li>
              ))}
            </ul>

            <h3 className="text-xl font-bold mb-4">🧪 Nutrients Commonly Found:</h3>
            <div className="flex flex-wrap gap-2 mb-4">
              {result.nutrients.map((nutrient) => (
                <span key={nutrient} className="bg-yellow-200 px-3 py-1 rounded-full font-semibold shadow">
                  {nutrient}
                </span>
              ))}
            </div>

            <h3 className="text-xl font-bold mb-4">🌾 Recommended Crops / Plantation:</h3>
            <div className="flex flex-wrap gap-2">
              {result.crops.map((crop) => (
                <span key={crop} className="bg-blue-200 px-3 py-1 rounded-full font-semibold shadow">
                  {crop}
                </span>
              ))}
            </div>
          </div>
        )}
      </div>
    </div>
  );
}

export default Geog;
