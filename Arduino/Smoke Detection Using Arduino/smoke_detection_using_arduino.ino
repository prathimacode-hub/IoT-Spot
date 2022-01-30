int buzzer = 6;
int smoke_detector = A0;
int safety_lim = 170; //Sets smoke density safe limit

void setup()
{
    pinMode(buzzer, OUTPUT);
    pinMode(smoke_detector, INPUT);
}

void loop()
{
    int sensor_read = analogRead(smoke_detector);
    //reads and stores the reading from the detector in sensor_read

    if (sensor_read > safety_lim)
        // Checks if reading is beyond safety limit
        tone(buzzer, 500, 100); //piezo rings
    else
        noTone(buzzer); //piezo wont ring
    delay(50);
}