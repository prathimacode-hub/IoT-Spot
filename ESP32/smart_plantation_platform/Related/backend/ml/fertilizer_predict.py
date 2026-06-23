# fertilizer_predict.py
import json
import sys

# Fertilizer mapping
fertilizer_map = {
    0: "Urea",
    1: "DAP (Diammonium Phosphate)",
    2: "14-35-14",
    3: "28-28",
    4: "17-17-17",
    5: "20-20",
    6: "10-26-26"
}

def recommend_fertilizer(temperature, humidity, moisture, light_intensity, rain, ideal_yield, actual_yield):
    """
    Returns a fertilizer recommendation code based on yield difference and environmental factors.
    """
    yield_diff = ideal_yield - actual_yield

    if yield_diff <= 0:
        return 0  # No additional fertilizer needed, default to Urea (0)

    # Heuristic rules
    if yield_diff < 200:
        return 0  # Urea
    elif yield_diff < 500:
        return 6  # 10-26-26
    elif moisture < 30:
        return 1  # DAP
    elif humidity < 40:
        return 3  # 28-28
    else:
        return 2  # 14-35-14

def main():
    # Read JSON payload from stdin
    input_text = sys.stdin.read()
    input_data = json.loads(input_text)

    # Extract all required values
    temperature = float(input_data.get("temperature", 0))
    humidity = float(input_data.get("humidity", 0))
    moisture = float(input_data.get("moisture", 0))
    light_intensity = float(input_data.get("light_intensity", 0))
    rain = float(input_data.get("rain", 0))
    ideal_yield = float(input_data.get("ideal_yield", 0))
    actual_yield = float(input_data.get("actual_yield", 0))

    # Get fertilizer code
    fertilizer_code = recommend_fertilizer(
        temperature, humidity, moisture, light_intensity, rain, ideal_yield, actual_yield
    )

    # Map to fertilizer name
    fertilizer_name = fertilizer_map.get(fertilizer_code, "Urea")

    # Output JSON for server.js
    print(json.dumps({"fertilizer_recommendation": fertilizer_name}))

if __name__ == "__main__":
    main()
