import sys
import json
import numpy as np
import pickle
import os

# Load model
model_path = os.path.join("models", "Ideal_Yield_Model.pkl")
with open(model_path, "rb") as f:
    obj = pickle.load(f)

# Extract model (and scaler if available)
if isinstance(obj, dict):
    model = obj.get("model")
    scaler = obj.get("scaler")
else:
    model = obj
    scaler = None

# Read input from Node.js
input_data = json.loads(sys.argv[1])

# Prepare features in correct order
features = np.array([[ 
    float(input_data.get("Crop_enc", 0)),       # Crop encoding (0-9)
    float(input_data.get("temperature", 0)),    # Temperature
    float(input_data.get("humidity", 0)),       # Humidity
    float(input_data.get("moisture", 0)),  # Moisture
    float(input_data.get("light_intensity", 0)),# Light Intensity
    float(input_data.get("rain", 0)),           # Rainfall
]])

# Scale features if scaler exists
if scaler:
    features = scaler.transform(features)

# Predict
prediction = model.predict(features)[0]  # raw model output

# Return JSON directly (no rounding)
print(json.dumps({"ideal_yield": prediction}))
