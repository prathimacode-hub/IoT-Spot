import { useEffect, useState } from "react";
import Navbar from "../components/Navbar";

function Data() {
  const [sensorData, setSensorData] = useState([]);
  const [loading, setLoading] = useState(true);
  const [error, setError] = useState(null);

  useEffect(() => {
    const fetchData = async () => {
      try {
        const response = await fetch("http://localhost:5000/api/sensors");
        if (!response.ok) throw new Error("Failed to fetch data");
        const data = await response.json();

        // ✅ Show only the latest 100 readings
        const latest100 = data.slice(-100).reverse();
        setSensorData(latest100);
      } catch (err) {
        setError(err.message);
        console.error("Error fetching sensor data:", err);
      } finally {
        setLoading(false);
      }
    };

    fetchData();
  }, []);

  // ✅ Export selected fields to CSV with exact column names
  const handleExportCSV = () => {
    if (sensorData.length === 0) return;

    const headers = ["temperature", "humidity", "moisture", "light_intensity", "rainfall"];
    const rows = sensorData.map((row) => [
      row["Temperature"],
      row["Humidity"],
      row["Soil Moisture"],
      row["Light Intensity"],
      row["Rain"]
    ]);

    const csvContent = [headers.join(","), ...rows.map((r) => r.join(","))].join("\n");

    const blob = new Blob([csvContent], { type: "text/csv;charset=utf-8;" });
    const url = URL.createObjectURL(blob);
    const a = document.createElement("a");
    a.href = url;
    a.download = `sensor_data_${new Date().toISOString().slice(0,19).replace(/[:T]/g, '-')}.csv`;
    a.click();
    URL.revokeObjectURL(url);
  };

  if (loading) {
    return (
      <div
        className="min-h-screen w-screen bg-cover bg-center bg-fixed flex items-center justify-center"
        style={{ backgroundImage: "url('/bg5.jpeg')" }}
      >
        <Navbar />
        <div className="bg-white bg-opacity-90 px-6 py-4 rounded-xl shadow-md">
          <p className="text-lg font-semibold">Loading sensor data...</p>
        </div>
      </div>
    );
  }

  if (error) {
    return (
      <div
        className="min-h-screen w-screen bg-cover bg-center bg-fixed flex items-center justify-center"
        style={{ backgroundImage: "url('/bg5.jpeg')" }}
      >
        <Navbar />
        <div className="bg-red-100 px-6 py-4 rounded-xl shadow-md">
          <p className="text-lg font-semibold text-red-800">Error: {error}</p>
          <p className="text-sm text-red-600">
            Make sure your backend is running on port 5000
          </p>
        </div>
      </div>
    );
  }

  return (
    <div
      className="min-h-screen w-screen bg-cover bg-center bg-fixed"
      style={{ backgroundImage: "url('/bg5.jpeg')" }}
    >
      <Navbar />
      <div className="flex flex-col items-center justify-start pt-[5rem] px-6 pb-16">
        <h2 className="text-2xl md:text-3xl font-bold text-black bg-white bg-opacity-80 px-6 py-3 rounded-xl shadow-md mb-8">
          Data Records
        </h2>

        {/* ✅ Export Button */}
        <button
          onClick={handleExportCSV}
          className="bg-green-700 text-white px-5 py-2 rounded-lg shadow-md mb-8 hover:bg-green-800 transition"
        >
          Export CSV
        </button>

        <div className="px-6 pb-12 flex justify-center overflow-x-auto">
          <table className="table-auto border border-gray-300 bg-white bg-opacity-90 shadow-md">
            <thead>
              <tr className="bg-green-700 text-white">
                <th className="px-4 py-2 border">Sr No.</th>
                <th className="px-4 py-2 border">Soil Moisture</th>
                <th className="px-4 py-2 border">Temperature</th>
                <th className="px-4 py-2 border">Humidity</th>
                <th className="px-4 py-2 border">Light Intensity</th>
                <th className="px-4 py-2 border">Water Level</th>
                <th className="px-4 py-2 border">Rain</th>
                <th className="px-4 py-2 border">Date</th>
                <th className="px-4 py-2 border">Time</th>
              </tr>
            </thead>
            <tbody>
              {sensorData.map((row, idx) => (
                <tr key={row._id || idx} className="text-center hover:bg-gray-100">
                  <td className="px-4 py-2 border">{idx + 1}</td>
                  <td className="px-4 py-2 border">{row["Soil Moisture"]}%</td>
                  <td className="px-4 py-2 border">{row["Temperature"]}°C</td>
                  <td className="px-4 py-2 border">{row["Humidity"]}%</td>
                  <td className="px-4 py-2 border">{row["Light Intensity"]} lx</td>
                  <td className="px-4 py-2 border">{row["Water Level"]}</td>
                  <td className="px-4 py-2 border">{row["Rain"]}</td>
                  <td className="px-4 py-2 border">{row["Date"]}</td>
                  <td className="px-4 py-2 border">{row["Time"]}</td>
                </tr>
              ))}
            </tbody>
          </table>
        </div>
      </div>
    </div>
  );
}

export default Data;
