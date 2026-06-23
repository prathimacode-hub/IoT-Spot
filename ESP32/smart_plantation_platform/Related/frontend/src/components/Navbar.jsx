import { useState } from "react";
import Sidebar from "./Sidebar";

function Navbar() {
  const [isOpen, setIsOpen] = useState(false);

  return (
    <>
      {/* Top Navbar */}
      <nav className="w-full bg-green-700 text-white py-4 px-8 flex items-center shadow-md fixed top-0 left-0 z-50">
        <button
          onClick={() => setIsOpen(true)}
          className="text-2xl font-bold flex items-center gap-2"
        >
          🌱4Jhaad Platform
        </button>
      </nav>

      {/* Sidebar */}
      <Sidebar isOpen={isOpen} onClose={() => setIsOpen(false)} />
    </>
  );
}

export default Navbar;
