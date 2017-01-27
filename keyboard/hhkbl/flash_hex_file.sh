# Check if you have /dev/ttyACM0 port appears first 8 seconds after keyboard plug
# Run this script in this 8 seconds to flash hhkbl_lufa.hex file 
avrdude -p atmega32u4 -P /dev/ttyACM0  -c avr109  -U flash:w:hhkbl_lufa.hex 
