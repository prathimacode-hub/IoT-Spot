# Aim
To build API for LCD To provide The following functionality:
<br>
<br>
/* LCD Initialize function for any mode */
<br>
void LCD_Init(void);

/* LCD send commands function to configure LCD for any mode */
<br>
void LCD_SendCommand(uint8 cmd);

/* LCD send char function to put on LCD display (panel) for any mode */
<br>
void LCD_SendChar(uint8 data);

/* LCD send string function to put on LCD display (panel) */
<br>
void LCD_SendString(uint8* data);

/* go to xy position */
<br>
void LCD_Goto_xy(uint8 row,uint8 col);

/* write a string into LCD in x-y position */
<br>
void LCD_String_xy (uint8 row, uint8 pos, uint8* data);

/* write number into LCD */
<br>
void LCD_SendNumber(uint16 Number);

/* clear LCD display */
<br>
void LCD_Clear(void);

<br>

# Purpose
To Test this API in a build a sample app which write Mohamed Ismail then new line ahmed and number 30 
not a string its an integer number.
<br>

# Component required
Simulation environment - Proteus 8
Atmega 32
LCD screen
Wires
Power source - Laptop or battery
Potentiometer 1K
<br>

# Description
Used The made API (Driver) to configure the LCD. This Driver makes it easier to operate with the LCD since it consists for many functions like LCD_String_xy, LCD_SendNumber etc.
<br>

# Workflow
write Mohamed Ismail then new line ahmed and number 30 not a string its an integer number.
<br>

# Setup 
Connect the circuit diagram as shown in the image and press the simulation button

# Output
Output video and images is added in the Gallery folder
<br>

# Author
Mohamed Ismail
