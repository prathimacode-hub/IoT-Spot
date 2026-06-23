  import Navbar from "../components/Navbar";

  function EmpiricalEvidence({ content }) {
    return (
      <div
        className="min-h-screen w-screen bg-cover bg-center bg-fixed"
        style={{ backgroundImage: "url('/bg3.jpeg')" }}
      >
        {/* Navbar */}
        <Navbar />

        {/* Full screen container for centering */}
        <div className="flex flex-col items-center justify-start min-h-screen pt-[6rem] px-4">
          {/* Heading */}
          <h2 className="text-2xl md:text-3xl font-bold text-black bg-white bg-opacity-80 px-6 py-3 rounded-xl shadow-md mb-10 text-center">
            Empirical Evidence
          </h2>

        {/* Content Section */}
          <div className="bg-white bg-opacity-80 p-8 rounded-xl shadow-md w-full max-w-4xl space-y-6 mb-16">
          <p>
              This section presents empirical evidence supporting the selection of soil moisture, temperature, humidity, light intensity, and rainfall as key parameters for predicting crop growth, detecting pests, and recommending fertilizers. The evidence is drawn from multiple scientific studies and research articles, showing that these environmental factors significantly influence plant development, pest dynamics, and nutrient requirements.
          </p>

          {/* Growth Prediction */}
          <div>
              <h3 className="text-xl font-semibold mb-2">🌱 Growth Prediction</h3>
              <p><strong>Function:</strong> Growth Prediction</p>
              <p>
              <strong>Study:</strong> The studies considered include "Crop yield prediction in agriculture: A comprehensive review", "Prediction of Crop Yield Based-on Soil Moisture using Machine Learning Algorithms", and "Crop Prediction Model Using Machine Learning Algorithms".
              </p>
              <p><strong>Source:</strong> ScienceDirect, ResearchGate, MDPI</p>
              <p>
              <strong>Summary:</strong> These studies collectively show that crop growth and yield are strongly influenced by environmental parameters. The first review highlights temperature, rainfall, soil type, humidity, and vegetation indices like NDVI as key determinants of crop yield. The second study demonstrates that soil moisture data, when combined with machine learning algorithms, can effectively predict crop yield, enabling better agricultural planning. The third study emphasizes that soil properties—including NPK levels, temperature, rainfall, moisture, pH, and humidity—play a significant role in predicting crop outcomes using machine learning models.
              </p>
          </div>

          {/* Pest Detection */}
          <div>
              <h3 className="text-xl font-semibold mb-2">🐛 Pest Detection</h3>
              <p><strong>Function:</strong> Pest Detection</p>
              <p>
              <strong>Study:</strong> The studies include "Deep learning based agricultural pest monitoring and classification", "Survey on crop pest detection using deep learning and computer vision", and "An intelligent identification for pest and disease detection in wheat crops".
              </p>
              <p><strong>Source:</strong> Nature, PMC, Frontiers</p>
              <p>
              <strong>Summary:</strong> These studies demonstrate the importance of environmental parameters in detecting pests and diseases. The first paper uses a deep learning approach for pest monitoring and classification, leveraging environmental data to enhance detection accuracy. The second survey reviews modern pest detection methods and highlights the influence of environmental factors on pest occurrence and identification. The third study integrates sensor data such as temperature, humidity, soil moisture, and light intensity with image data to enable early detection of pests and diseases in wheat crops.
              </p>
          </div>

          {/* Fertilizer Recommendation */}
          <div>
              <h3 className="text-xl font-semibold mb-2">🌾 Fertilizer Recommendation</h3>
              <p><strong>Function:</strong> Fertilizer Recommendation</p>
              <p>
              <strong>Study:</strong> The studies considered are "AI-Powered Adaptive Fertilizer Recommendation System Using Soil And Weather Data", "Site-specific fertilizer recommendation using data-driven models for wheat", and "The Fertilizer Recommendation Support Tool: A relational decision aid for phosphorus and potassium management".
              </p>
              <p><strong>Source:</strong> ResearchGate, ScienceDirect, ACSess</p>
              <p>
              <strong>Summary:</strong> These studies show that soil and weather parameters are critical for accurate fertilizer recommendations. The first study presents an AI-driven system that uses real-time soil and weather data to optimize fertilizer recommendations with high accuracy. The second evaluates machine learning-generated site-specific fertilizer recommendations for wheat, demonstrating improved nutrient use efficiency and profitability. The third presents a decision aid tool that utilizes soil test and crop fertilization research data to estimate phosphorus and potassium requirements, guiding effective fertilizer application.
              </p>
          </div>
          </div>

        </div>
      </div>
    );
  }

  export default EmpiricalEvidence;
