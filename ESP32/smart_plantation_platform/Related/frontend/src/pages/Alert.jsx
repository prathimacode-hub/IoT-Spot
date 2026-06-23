import Navbar from "../components/Navbar";

function Alert() {
  // Mock data for alerts
  const mockAlerts = [
    {
      id: 1,
      hashId: "0xabc123",
      date: "2025-09-13",
      time: "22:50:30",
      alert: "Extreme Rainfall",
    },
    {
      id: 2,
      hashId: "0xdef456",
      date: "2025-09-13",
      time: "22:55:10",
      alert: "Fertilizer Requirement",
    },
    {
      id: 3,
      hashId: "0xghi789",
      date: "2025-09-13",
      time: "23:00:45",
      alert: "Pest Detection",
    },
    {
      id: 4,
      hashId: "0xjkl012",
      date: "2025-09-13",
      time: "23:05:15",
      alert: "Water Level Too Low",
    },
    {
      id: 5,
      hashId: "0xmnq345",
      date: "2025-09-13",
      time: "23:10:20",
      alert: "Water Tank Empty",
    },
  ];

  return (
    <div
      className="min-h-screen w-screen bg-cover bg-center bg-fixed"
      style={{ backgroundImage: "url('/bg6.jpeg')" }}
    >
      {/* Navbar */}
      <Navbar />

      {/* Container */}
      <div className="flex flex-col items-center justify-start pt-[5rem] px-6">
        {/* Heading */}
        <h2 className="text-2xl md:text-3xl font-bold text-black bg-white bg-opacity-80 px-6 py-3 rounded-xl shadow-md mb-8">
          Alerts
        </h2>

        {/* Table */}
        <div className="px-6 pb-12 flex justify-center">
          <table className="table-auto border border-gray-300 bg-white bg-opacity-90 shadow-md">
            <thead>
              <tr className="bg-red-700 text-white">
                <th className="px-4 py-2 border">Sr No.</th>
                <th className="px-4 py-2 border">Hash ID</th>
                <th className="px-4 py-2 border">Date</th>
                <th className="px-4 py-2 border">Time</th>
                <th className="px-4 py-2 border">Alert</th>
              </tr>
            </thead>
            <tbody>
            {mockAlerts.map((row) => {
                // ✅ Decide row color based on alert type
                let rowColor = "";
                if (row.alert.includes("Rainfall")) rowColor = "bg-blue-100";
                else if (row.alert.includes("Fertilizer")) rowColor = "bg-orange-100";
                else if (row.alert.includes("Pest")) rowColor = "bg-yellow-100";
                else if (row.alert.includes("Water")) rowColor = "bg-red-100";
                else rowColor = "bg-gray-50"; // default

                return (
                <tr
                    key={row.id}
                    className={`${rowColor} text-center hover:bg-opacity-70 transition`}
                >
                    <td className="px-4 py-2 border">{row.id}</td>
                    <td className="px-4 py-2 border">{row.hashId}</td>
                    <td className="px-4 py-2 border">{row.date}</td>
                    <td className="px-4 py-2 border">{row.time}</td>
                    <td className="px-4 py-2 border font-semibold">{row.alert}</td>
                </tr>
                );
            })}
            </tbody>

          </table>
        </div>
      </div>
    </div>
  );
}

export default Alert;
