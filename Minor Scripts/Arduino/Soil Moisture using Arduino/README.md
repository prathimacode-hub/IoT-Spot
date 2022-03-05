# Aim
To detect the Soil Moisture
<br>

# Purpose
Helpful to know the changing soil moisture
<br>

# Component required
Simulation environment - Tinkercad
Arduino UNO
LCD 16 x 2 
Wires
Resistor 220 ohms 
Potentiometer 250 kilo-ohms
Temperature Sensor [TMP36]
<br>


# Workflow
We have completed the setup as per the given images mnetioned in the '/images/'<br>
We take the analog input for temperature sensor with the help of A4 pin in arduino uno.The values for temperature sensor can be fluctuated for demonstration purpose and calculate subsequent percentage using formula:<br>100 - ( (sensor_analog/1023.00) * 100 ). Further we display the percentage in serial port for every 1 second interval.<br>With the help of analog input variety of values could be taken hence we use analog input.
<br>

# Setup 
Connect the circuit diagram as shown in the image and press the simulation button then change the values for temperature sensor to know the soil moisture.

# Output


<br>

Output video and images is added in the /images folder
Video Link: https://github.com/prathimacode-hub/IoT-Spot/blob/6ad5799a44aa93adef54b185650c0081b2015fb2/Minor%20Scripts/Arduino/Soil%20Moisture%20using%20Arduino/Images/Soil%20Moisture%20Video%20Demonstration.mp4
Image Link: https://github.com/prathimacode-hub/IoT-Spot/blob/6ad5799a44aa93adef54b185650c0081b2015fb2/Minor%20Scripts/Arduino/Soil%20Moisture%20using%20Arduino/Images/SS-5.png

<br>

# Author
Siddhant Pawar
