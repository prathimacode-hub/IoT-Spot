# COLOR DETECTOR ON LCD USING ADURINO

## AIM:COLOR DETECTOR ON LCD USING ADURINO



## Purpose:
Its to make detection of colour using TCS3200 and then print it on LCD. 

## Short Description:

**Requirements:**

- Arduino UNO
- 1 (16X2) LCD
- 1  Rotatary Potentiometer
- 9V Battery
-  USB
- TCS3200/TCS2300 Color Detector
- 10K Variable Resistor 
  (Fritzing can also be used)

## Workflow:
- We will connect battery(9V) to Arduino 
- We connect the LCD & color sensor to Arduino UNO.
- Present the color in front of TCS2300 Sensor.
- LCD will be show values of R,G,B using S2,S3 in TCS3200(<a href = "https://www.elprocus.com/wp-content/uploads/Block-Diagram-of-TCS3200.jpg">[working of TCS3200]</a>)  within the R,G,B.
- Then we will find colour according using some conditions and will give the output as Colour. 
<a href= "LCD Color Detector/Circui-Setup/Circuit.png">[The circuit will look like this]</a>

## Setup instructions:

-Intall Fritzing for stimulation.
-Install the library for TCS3200 sensor<a href= "LCD Color Detector/Circui-Setup/TCS3200.fzpz" >[here]</a>
- Upload the code provided <a href = "LCD Color Detector/lcd_color_detector.ino">[here]</a>
- Run to see the project in action!

---

## Output:
For Circuit output <a href = "LCD Color Detector/Circuit-Setup/Circuit.fzz">[here]</a>
And how the work you can see it in <a href = "LCD Color Detector/DEMO.mp4">"[here]"</a>

## Author:
<a href="https://github.com/CS50X-RGB">Rohan Chatterjee</a>

