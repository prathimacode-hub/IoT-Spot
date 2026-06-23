import sys
import json
import numpy as np
import joblib
import os

# Model path
model_path = os.path.join("models", "pest_prediction_model.joblib")

# Load trained model
model = joblib.load(model_path)

# Read JSON input from Node
input_data = json.loads(sys.argv[1])

# Prepare features
features = np.array([[
    float(input_data.get("temperature", 0)),
    float(input_data.get("humidity", 0)),
    float(input_data.get("moisture", 0)),
    float(input_data.get("light_intensity", 0)),
    float(input_data.get("rainfall", 0))
]])

# Predict pest risk
raw_pred = model.predict(features)[0]

# Normalize output (handle string or numeric models)
if isinstance(raw_pred, (int, float)):
    prediction = int(raw_pred)
    risk_map = {0: "No Pest Detected", 1: "Pest Detected"}
    pest_risk = risk_map.get(prediction, "Unknown")
else:
    # If model outputs strings like 'yes'/'no'
    pest_risk = "Pest Detected" if str(raw_pred).lower() in ["yes", "pest", "true", "1"] else "No Pest Detected"

# Return JSON output
print(json.dumps({"pest_risk": pest_risk}))
