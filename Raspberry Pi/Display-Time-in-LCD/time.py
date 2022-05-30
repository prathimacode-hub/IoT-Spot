#impoting GPIO which is Rasberry-pi module 
 import RPi.GPIO as GPIO 
#importing Adafruit_CharLCD module LCD module  
from Adafruit_CharLCD import Adafruit_CharLCD
from subprocess import *
#importing strtime <Converting date into String> and sleep <suspends the dealay for seconds>
from time import sleep, strftime
#Importing datetime module 
from datetime import datetime

lcd = Adafruit_CharLCD()
 #Set the dimensions for the LCD
lcd.begin(16,1)
#Setting the pins
GPIO.setup(18, 0)
#Getting the output
GPIO.output(18, 1)

while 1:
            lcd.clear()
            #Printing the message in from string %H -> Hour,%M -> Minute,%S->Seconds %b-> For months name %d-> Day of month 
            lcd.message(datetime.now().strftime('%b %d  %H:%M:%S\n'))
            #Function suspends for 0.95
            sleep(0.95)