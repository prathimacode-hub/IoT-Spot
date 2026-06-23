import { useEffect, useState } from "react";
import {
  LineChart, Line, XAxis, YAxis, CartesianGrid, Tooltip, Legend,
  BarChart, Bar, ResponsiveContainer
} from 'recharts';
import Navbar from "../components/Navbar";

function Monitoring() {
  const [sensorData, setSensorData] = useState([]);
  const [loading, setLoading] = useState(true);

  // ✅ Updated max values for normalization
  const maxValues = {
    Temperature: 50,
    "Soil Moisture": 3000,
    Humidity: 100,
    "Light Intensity": 1200,
    "Water Level": 100,
    Rain: 1023
  };

  useEffect(() => {
    const fetchData = async () => {
      try {
        const response = await fetch("http://localhost:5000/api/sensors");
        const data = await response.json();

        // Normalize values for line chart only
        const normalizedData = data.map((d) => ({
          ...d,
          tempPercent: ((parseFloat(d["Temperature"]) / maxValues.Temperature) * 100).toFixed(2),
          moistPercent: ((parseFloat(d["Soil Moisture"]) / maxValues["Soil Moisture"]) * 100).toFixed(2),
          humidPercent: ((parseFloat(d["Humidity"]) / maxValues.Humidity) * 100).toFixed(2),
          lightPercent: ((parseFloat(d["Light Intensity"]) / maxValues["Light Intensity"]) * 100).toFixed(2)
        }));

        // ✅ Keep only the latest 5 readings for the graphs
        const latestFive = normalizedData.slice(-5).reverse();

        setSensorData(latestFive);
      } catch (err) {
        console.error("Error fetching sensor data:", err);
      } finally {
        setLoading(false);
      }
    };

    fetchData();
  }, []);


  if (loading) {
    return (
      <div
        className="min-h-screen w-screen bg-cover bg-center bg-fixed flex items-center justify-center"
        style={{ backgroundImage: "url('/bg2.jpeg')" }}
      >
        <Navbar />
        <div className="bg-white bg-opacity-90 px-6 py-4 rounded-xl shadow-md">
          <p className="text-lg font-semibold">Loading monitoring data...</p>
        </div>
      </div>
    );
  }

  return (
    <div
      className="min-h-screen w-screen bg-cover bg-center bg-fixed"
      style={{ backgroundImage: "url('/bg2.jpeg')" }}
    >
      <Navbar />

      <div className="pt-[7.75rem] px-4 pb-10">
        <h2 className="text-2xl md:text-3xl font-bold text-center text-black bg-white bg-opacity-80 px-6 py-3 rounded-xl shadow-md mb-8 mx-auto max-w-fit">
          Real-time Monitoring Dashboard
        </h2>

        {/* ✅ Line Chart without Rain */}
        <div className="bg-white bg-opacity-90 p-6 rounded-xl shadow-lg mb-6">
          <h3 className="text-xl font-semibold mb-4 text-center">
            Temperature, Moisture, Humidity & Light Trends (Normalized %)
          </h3>
          <ResponsiveContainer width="100%" height={300}>
            <LineChart data={sensorData}>
              <CartesianGrid strokeDasharray="3 3" />
              <XAxis dataKey="Time" />
              <YAxis domain={[0, 100]} label={{ value: "Percentage (%)", angle: -90, position: "insideLeft" }} />
              <Tooltip />
              <Legend />
              <Line type="monotone" dataKey="tempPercent" stroke="#ff4c4c" name="Temperature" strokeWidth={2} />
              <Line type="monotone" dataKey="moistPercent" stroke="#8884d8" name="Soil Moisture" strokeWidth={2} />
              <Line type="monotone" dataKey="humidPercent" stroke="#82ca9d" name="Humidity" strokeWidth={2} />
              <Line type="monotone" dataKey="lightPercent" stroke="#f5c542" name="Light Intensity" strokeWidth={2} />
            </LineChart>
          </ResponsiveContainer>
        </div>

        <div className="grid grid-cols-1 lg:grid-cols-2 gap-6 mb-6">
          {/* Water Level Bar Chart */}
          <div className="bg-white bg-opacity-90 p-6 rounded-xl shadow-lg">
            <h3 className="text-xl font-semibold mb-4 text-center">Water Level (%)</h3>
            <ResponsiveContainer width="100%" height={300}>
              <BarChart data={sensorData}>
                <CartesianGrid strokeDasharray="3 3" />
                <XAxis dataKey="Time" />
                <YAxis />
                <Tooltip />
                <Legend />
                <Bar dataKey="Water Level" fill="#82ca9d" name="Water Level" />
              </BarChart>
            </ResponsiveContainer>
          </div>

          {/* Rain Level Bar Chart (Analog) */}
          <div className="bg-white bg-opacity-90 p-6 rounded-xl shadow-lg">
            <h3 className="text-xl font-semibold mb-4 text-center">Rain Level (Analog)</h3>
            <ResponsiveContainer width="100%" height={300}>
              <BarChart data={sensorData}>
                <CartesianGrid strokeDasharray="3 3" />
                <XAxis dataKey="Time" />
                <YAxis />
                <Tooltip />
                <Legend />
                <Bar dataKey="Rain" fill="#4fa3f7" name="Rain Value" />
              </BarChart>
            </ResponsiveContainer>
          </div>
        </div>

        {/* Latest Readings */}
        <div className="bg-white bg-opacity-90 p-6 rounded-xl shadow-lg">
          <h3 className="text-xl font-semibold mb-4 text-center">Latest Readings</h3>
          {sensorData.length > 0 && (
            <div className="grid grid-cols-2 gap-3 text-sm">
              {[
                { label: "Soil Moisture", value: sensorData[sensorData.length - 1]["Soil Moisture"], unit: "", color: "bg-brown-100" },
                { label: "Temperature", value: sensorData[sensorData.length - 1]["Temperature"], unit: "°C", color: "bg-red-100" },
                { label: "Humidity", value: sensorData[sensorData.length - 1]["Humidity"], unit: "", color: "bg-blue-100" },
                { label: "Light", value: sensorData[sensorData.length - 1]["Light Intensity"], unit: " lx", color: "bg-yellow-100" },
                { label: "Water Level", value: sensorData[sensorData.length - 1]["Water Level"], unit: "", color: "bg-cyan-100" },
                { label: "Rain", value: sensorData[sensorData.length - 1]["Rain"], unit: "", color: "bg-gray-100" }
              ].map((sensor) => (
                <div key={sensor.label} className={`${sensor.color} p-3 rounded-lg text-center shadow`}>
                  <p className="font-medium text-xs">{sensor.label}</p>
                  <p className="text-lg font-bold">{sensor.value}{sensor.unit}</p>
                </div>
              ))}
            </div>
          )}
        </div>
      </div>
    </div>
  );
}

export default Monitoring;
