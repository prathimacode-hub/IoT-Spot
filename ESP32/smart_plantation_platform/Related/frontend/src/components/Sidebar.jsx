import { Activity, Sliders, BarChart2, Database, Bell, X } from "lucide-react";
import { Link } from "react-router-dom"; // ✅ import Link

function Sidebar({ isOpen, onClose }) {
  return (
    <div
      className={`fixed top-0 left-0 h-full w-64 bg-green-800 text-white transform ${
        isOpen ? "translate-x-0" : "-translate-x-full"
      } transition-transform duration-300 z-50 shadow-lg`}
    >
      {/* Header with Close Button */}
      <div className="flex items-center justify-between px-6 py-4 bg-green-900">
        <h2 className="text-xl font-bold">🌱4Jhaad Platform</h2>
        <button onClick={onClose}>
          <X className="w-6 h-6 text-white" />
        </button>
      </div>

      {/* Sidebar Menu */}
      <nav className="mt-6 flex flex-col space-y-6 px-6">
        {/* ✅ Monitoring with routing */}
        <Link
          to="/"
          onClick={onClose}
          className="flex items-center gap-3 text-lg hover:text-green-300"
        >
          <span className="text-xl">🏠</span> Home
        </Link>

        <Link
          to="/monitoring"
          onClick={onClose}
          className="flex items-center gap-3 text-lg hover:text-green-300"
        >
          <span className="text-xl">📊</span> Monitoring
        </Link>

        <Link
          to="/control"
          onClick={onClose}
          className="flex items-center gap-3 text-lg hover:text-green-300"
        >
          <span className="text-xl">⚙️</span> Control
        </Link>

        <Link
          to="/analysis"
          onClick={onClose}
          className="flex items-center gap-3 text-lg hover:text-green-300"
        >
          <span className="text-xl">🔍</span> Analysis
        </Link>

        <Link
          to="/data"
          onClick={onClose}
          className="flex items-center gap-3 text-lg hover:text-green-300"
        >
          <span className="text-xl">💾</span> Data
        </Link>

        <Link
          to="/alert"
          onClick={onClose}
          className="flex items-center gap-3 text-lg hover:text-green-300">
          <span className="text-xl">🚨</span> Alerts
        </Link>
      </nav>
    </div>
  );
}

export default Sidebar;
