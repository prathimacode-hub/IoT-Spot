MAIN_FILES = avr_rtc.c Related/RTC_Prog.c Related/I2C_Prog.c Related/UART_Prog.c 
COMPILER = avr-gcc
TARGET_NAME = Clock
TARGET = atmega32
DEVICE = m32
PORT = usb
PROGRAMMER = usbasp

all:
	build upload

build:
	${COMPILER} ${MAIN_FILES} -o ${TARGET_NAME}.elf -mmcu=${TARGET} -DF_CPU=8000000UL -Os
	avr-objcopy ${TARGET_NAME}.elf -O ihex ${TARGET_NAME}.hex

upload:
	avrdude -c ${PROGRAMMER} -p ${DEVICE} -U flash:w:"${TARGET_NAME}.hex":a -P ${PORT}

clean:
	rm -f *.hex
	rm -f *.elf