#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
//For Using 16 MHz mode in Arduino IDE
#include <avr/power.h>
#endif

#define PIN 6

//The following code defines a Adafruit_NeoPixel object the has 12 LEDs where the data is sourced from pin 6 of the Arduino device, and the LED type is NEO_KHZ800+NEO_GRB
//for NeoPixels expecting an 800 KHz data stream with color bytes expressed in green, red, blue order per pixel.
Adafruit_NeoPixel strip = Adafruit_NeoPixel(12, PIN, NEO_GRB + NEO_KHZ800);

void setup()
{

    //We can activate the 16MHz clock 'in software' simply by asking the chip to set the clock prescale.
    if (F_CPU == 16000000)
        clock_prescale_set(clock_div_1);

    //Configuring NeoPixel pin for output.
    strip.begin();
    //Transmiting pixel data in RAM to NeoPixels.
    strip.show();
}

void loop()
{
    //Two different rainbow functions to implement mood light
    rainbow(20);
    rainbowCycle(20);
}

//Function to slowly morph one color into another, filling NeoPixel strip with one or more cycles of hues.
void rainbow(uint8_t wait)
{
    uint16_t i, j;

    for (j = 0; j < 256; j++)
    {
        //strip.numPixels returns the number of pixels in an Adafruit_NeoPixel strip object.
        for (i = 0; i < strip.numPixels(); i++)
        {
            //Setting a pixel's color using separate red, green and blue components.
            strip.setPixelColor(i, Wheel((i + j) & 255));
        }
        strip.show();
        delay(wait);
    }
}

// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle(uint8_t wait)
{
    uint16_t i, j;

    for (j = 0; j < 256 * 5; j++)
    { // 5 cycles of all colors on wheel
        for (i = 0; i < strip.numPixels(); i++)
        {
            //Setting a pixel's color using separate red, green and blue components.
            strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
        }
        strip.show();
        delay(wait);
    }
}

uint32_t Wheel(byte WheelPos)
{
    //Breaking the possible 255 choices of the wheel input into 3 sections of 85
    WheelPos = 255 - WheelPos;
    //Converting separate red, green and blue values into a single "packed" 32-bit RGB color.
    if (WheelPos < 85)
    {
        //Fading two of the 3 colors (red and blue) from all one to all the other over 85 steps
        return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
    }
    if (WheelPos < 170)
    {
        //next 85 steps fading between another pair of colors (blue and green)
        WheelPos -= 85;
        return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
    }
    WheelPos -= 130;
    //the last 85 steps fading between the final pair (green and red).
    return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}
