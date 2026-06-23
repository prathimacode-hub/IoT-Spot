import { Activity, Sliders, BarChart2, Database, Bell } from "lucide-react";
import Navbar from "./components/Navbar";
import { useNavigate } from "react-router-dom";

function App() {
  const navigate = useNavigate();

  return (
    <div
      className="min-h-screen bg-cover bg-center"
      style={{ backgroundImage: "url('/bg.jpeg')" }}
    >
      {/* Navbar always visible */}
      <Navbar />

      {/* Content shifted down so it doesn’t hide under navbar */}
      <div className="flex flex-col items-center justify-center pt-24">
        <div className="bg-white bg-opacity-70 p-10 rounded-2xl shadow-lg">
          <h1 className="text-4xl font-bold text-green-800 mb-12 text-center">
            🌱 Smart Plantation Platform
          </h1>

          <div className="grid grid-cols-1 md:grid-cols-5 gap-8 text-center">
            {/* Monitoring → navigates to /monitoring */}
            <button
              onClick={() => navigate("/monitoring")}
              className="flex flex-col items-center hover:scale-110 transition"
            >
              <Activity className="w-16 h-16 mx-auto text-green-700" />
              <p className="mt-2 text-xl font-semibold">Monitoring</p>
            </button>

            <button
              onClick={() => navigate("/control")}
              className="flex flex-col items-center hover:scale-110 transition"
            >
              <Sliders className="w-16 h-16 mx-auto text-blue-700" />
              <p className="mt-2 text-xl font-semibold">Control</p>
            </button>

            <button 
              onClick={() => navigate("/analysis")}
              className="flex flex-col items-center hover:scale-110 transition"
            >
              <BarChart2 className="w-16 h-16 mx-auto text-purple-700" />
              <p className="mt-2 text-xl font-semibold">Analysis</p>
            </button>

            <button
              onClick={() => navigate("/data")} 
              className="flex flex-col items-center hover:scale-110 transition"
            >
              <Database className="w-16 h-16 mx-auto text-yellow-700" />
              <p className="mt-2 text-xl font-semibold">Data</p>
            </button>

            <button 
              onClick={() => navigate("/alert")} 
              className="flex flex-col items-center hover:scale-110 transition">
              <Bell className="w-16 h-16 mx-auto text-red-700" />
              <p className="mt-2 text-xl font-semibold">Alerts</p>
            </button>
          </div>
        </div>
      </div>
    </div>
  );
}

export default App;
