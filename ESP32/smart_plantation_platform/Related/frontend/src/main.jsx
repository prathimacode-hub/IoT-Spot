import { StrictMode } from "react";
import { createRoot } from "react-dom/client";
import { BrowserRouter, Routes, Route } from "react-router-dom";
import "./index.css";
import App from "./App.jsx";
import Monitoring from "./pages/Monitoring.jsx"; 
import Analysis from "./pages/Analysis.jsx";
import Control from "./pages/Control.jsx";
import Data from "./pages/Data.jsx";
import Alert from "./pages/Alert.jsx";
import EE from "./pages/EE.jsx";
import Geog from "./pages/Geog.jsx"
import Rec from "./pages/Rec.jsx"
import Ent from "./pages/Ent.jsx"


createRoot(document.getElementById("root")).render(
  <StrictMode>
    <BrowserRouter>
      <Routes>
        <Route path="/" element={<App />} />
        <Route path="/monitoring" element={<Monitoring />} />
        <Route path="/analysis" element={<Analysis />} />
        <Route path="/control" element={<Control />} />
        <Route path="/data" element={<Data />} />
        <Route path="/alert" element={<Alert />} />
        <Route path="/ee" element={<EE />} />
        <Route path="/geog" element={<Geog />} />
        <Route path="/rec" element={<Rec />} />
        <Route path="/ent" element={<Ent />} />
      </Routes>
    </BrowserRouter>
  </StrictMode>
);
