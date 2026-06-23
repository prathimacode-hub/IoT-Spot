  import Navbar from "../components/Navbar";
  import { BarChart2, FileEdit, Map, BookOpen } from "lucide-react";
  import { useNavigate } from "react-router-dom";

  function Analysis() {
    const navigate = useNavigate();
    
    return (
      <div
        className="min-h-screen w-screen bg-cover bg-center bg-fixed"
        style={{ backgroundImage: "url('/bg3.jpeg')" }}
      >
        {/* Navbar */}
        <Navbar />

        {/* Full screen container for centering */}
        <div className="flex flex-col items-center justify-center min-h-screen pt-[4rem]">
          {/* Heading */}
          <h2 className="text-2xl md:text-3xl font-bold text-black bg-white bg-opacity-80 px-6 py-3 rounded-xl shadow-md mb-10">
              Choose from the following
          </h2>


          {/* Buttons Grid */}
          <div className="grid grid-cols-1 md:grid-cols-2 gap-12">
            {/* Data Records Button */}
            <button onClick={() => navigate("/rec")}
              className="bg-white bg-opacity-80 p-10 rounded-xl shadow-lg flex flex-col items-center hover:scale-105 transition">
              <BarChart2 className="w-16 h-16 text-purple-700 mb-4" />
              <span className="text-xl font-bold">Data Records</span>
            </button>

            {/* Data Entry Button */}
            <button onClick={() => navigate("/ent")}
              className="bg-white bg-opacity-80 p-10 rounded-xl shadow-lg flex flex-col items-center hover:scale-105 transition">
              <FileEdit className="w-16 h-16 text-red-700 mb-4" />
              <span className="text-xl font-bold">Data Entry</span>
            </button>

            {/* Geographical Data Button */}
            <button onClick={() => navigate("/geog")}
              className="bg-white bg-opacity-80 p-10 rounded-xl shadow-lg flex flex-col items-center hover:scale-105 transition">
              <Map className="w-16 h-16 text-green-700 mb-4" />
              <span className="text-xl font-bold">Geographical Data</span>
            </button>

            {/* Empirical Evidence Button */}
            <button onClick={() => navigate("/ee")} 
              className="bg-white bg-opacity-80 p-10 rounded-xl shadow-lg flex flex-col items-center hover:scale-105 transition"
            >
              <BookOpen className="w-16 h-16 text-blue-700 mb-4" />
              <span className="text-xl font-bold">Empirical Evidence</span>
            </button>
          </div>
        </div>
      </div>
    );
  }

  export default Analysis;
