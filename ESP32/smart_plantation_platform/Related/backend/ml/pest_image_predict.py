import os
os.environ["TF_CPP_MIN_LOG_LEVEL"] = "3"  # hide TensorFlow warnings

import sys
import json
import pickle
import numpy as np
from tensorflow.keras.models import load_model
from tensorflow.keras.preprocessing import image

# ------------------ Load model and classes ------------------
model = load_model("models/pest_model.h5")

with open("models/pest_classes.pkl", "rb") as f:
    pest_classes = pickle.load(f)

# ------------------ Load image from argument ------------------
img_path = sys.argv[1]
img = image.load_img(img_path, target_size=(224, 224))
img_array = image.img_to_array(img) / 255.0
img_array = np.expand_dims(img_array, axis=0)

# ------------------ Make prediction ------------------
pred = model.predict(img_array, verbose=0)  # silent mode
predicted_class = np.argmax(pred)
pest_name = pest_classes[predicted_class]

# ------------------ Print JSON output ------------------
print(json.dumps({"pest_name": pest_name}), flush=True)
