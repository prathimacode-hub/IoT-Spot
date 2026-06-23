import { useState } from "react";
import Navbar from "../components/Navbar";

function Control() {
  const [pumpOn, setPumpOn] = useState(false);
  const [automationOn, setAutomationOn] = useState(false);
  const [showSchedule, setShowSchedule] = useState(false);
  const [startTime, setStartTime] = useState("");
  const [duration, setDuration] = useState("");
  const [message, setMessage] = useState("");

  // ✅ Function to send updates to backend
  const sendControlUpdate = async (updatedData = {}) => {
    try {
      const res = await fetch("http://localhost:5000/api/control/update", {
        method: "POST",
        headers: { "Content-Type": "application/json" },
        body: JSON.stringify({
          pumpOn,
          automationOn,
          schedule: {
            startTime,
            duration,
            ...updatedData.schedule,
          },
          ...updatedData, // merge overrides (pumpOn/automationOn)
        }),
      });

      const data = await res.json();
      if (data.success) {
        setMessage("✅ Control update sent successfully!");
      } else {
        setMessage("❌ Failed to send update.");
      }
    } catch (err) {
      console.error("Error sending control update:", err);
      setMessage("⚠️ Error communicating with backend.");
    }
  };

  // 🟢 Pump Toggle
  const handlePumpToggle = async () => {
    if (automationOn) return; // Disable manual toggle during automation
    const newPumpState = !pumpOn;
    setPumpOn(newPumpState);
    await sendControlUpdate({ pumpOn: newPumpState });
  };

  // 🟢 Automation Toggle
  const handleAutomationToggle = async () => {
    const newAutomationState = !automationOn;
    setAutomationOn(newAutomationState);

    // safety: disable pump when automation is turned on
    const newPumpState = newAutomationState ? false : pumpOn;
    setPumpOn(newPumpState);

    await sendControlUpdate({
      automationOn: newAutomationState,
      pumpOn: newPumpState,
    });
  };

  // 🟢 Schedule Save
  const handleSaveSchedule = async () => {
    if (!startTime || !duration) {
      setMessage("⚠️ Please enter both start time and duration.");
      return;
    }
    await sendControlUpdate({ schedule: { startTime, duration } });
  };

  return (
    <div
      className="min-h-screen w-screen bg-cover bg-center bg-fixed"
      style={{ backgroundImage: "url('/bg4.jpeg')" }}
    >
      {/* Navbar */}
      <Navbar />

      {/* Heading */}
      <div className="pt-[7.75rem] flex justify-center">
        <h2 className="text-lg md:text-xl font-bold text-black bg-white bg-opacity-80 px-6 py-2 rounded-md shadow-md">
          The following controls are available
        </h2>
      </div>

      {/* Controls */}
      <div className="flex flex-col gap-8 p-8 items-center justify-center">

        {/* Pump Control */}
        <div className="bg-white bg-opacity-80 p-6 rounded-xl shadow-lg flex flex-col items-center w-full max-w-md">
          <h2 className="text-lg font-semibold mb-4">Pump Control</h2>
          <p className="text-sm text-center mb-3">
            Use this switch to manually turn the water pump{" "}
            <strong>ON</strong> or <strong>OFF</strong>. <br />
            <span className="text-red-600 font-semibold">
              (Disabled when Automation is Enabled)
            </span>
          </p>
          <button
            onClick={handlePumpToggle}
            disabled={automationOn}
            className={`px-6 py-2 rounded-full font-bold transition ${
              automationOn
                ? "bg-gray-400 text-gray-700 cursor-not-allowed"
                : pumpOn
                ? "bg-green-500 text-white"
                : "bg-gray-300 text-black"
            }`}
          >
            {pumpOn ? "ON" : "OFF"}
          </button>
        </div>

        {/* Automation Control */}
        <div className="bg-white bg-opacity-80 p-6 rounded-xl shadow-lg flex flex-col items-center w-full max-w-md">
          <h2 className="text-lg font-semibold mb-4">Automation</h2>
          <p className="text-sm text-center mb-3">
            Enable or disable the <strong>automated irrigation system</strong>.
          </p>
          <button
            onClick={handleAutomationToggle}
            className={`px-6 py-2 rounded-full font-bold transition ${
              automationOn ? "bg-green-500 text-white" : "bg-gray-300 text-black"
            }`}
          >
            {automationOn ? "Enabled" : "Disabled"}
          </button>
        </div>

        {/* Schedule Control */}
        <div className="bg-white bg-opacity-80 p-6 rounded-xl shadow-lg flex flex-col items-center w-full max-w-md">
          <h2 className="text-lg font-semibold mb-4">Schedule</h2>
          <button
            onClick={() => setShowSchedule(!showSchedule)}
            className="px-6 py-2 rounded-full font-bold bg-blue-500 text-white hover:bg-blue-600 transition"
          >
            {showSchedule ? "Hide Options" : "Set Schedule"}
          </button>

          {showSchedule && (
            <div className="mt-4 space-y-4 w-full">
              <div className="flex flex-col">
                <label className="font-medium mb-1">Start Time:</label>
                <input
                  type="time"
                  value={startTime}
                  onChange={(e) => setStartTime(e.target.value)}
                  className="p-2 border rounded-md focus:outline-none focus:ring-2 focus:ring-blue-400"
                />
              </div>
              <div className="flex flex-col">
                <label className="font-medium mb-1">Duration (mins):</label>
                <input
                  type="number"
                  value={duration}
                  onChange={(e) => setDuration(e.target.value)}
                  placeholder="Enter minutes"
                  className="p-2 border rounded-md focus:outline-none focus:ring-2 focus:ring-blue-400"
                />
              </div>
              <button
                onClick={handleSaveSchedule}
                className="w-full py-2 bg-green-500 text-white font-bold rounded-md hover:bg-green-600 transition"
              >
                Save Schedule
              </button>
            </div>
          )}
        </div>

        {/* Feedback */}
        {message && (
          <p className="text-center text-black bg-white bg-opacity-80 px-4 py-2 rounded-md shadow">
            {message}
          </p>
        )}
      </div>
    </div>
  );
}

export default Control;
