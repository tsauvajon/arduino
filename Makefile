dht22:
	arduino-cli compile --fqbn arduino:avr:nano:cpu=atmega328 ~/dev/Arduino/dht22
	arduino-cli upload  --fqbn arduino:avr:nano:cpu=atmega328old -p /dev/ttyUSB0 ~/dev/Arduino/dht22

ntc:
	arduino-cli compile --fqbn arduino:avr:nano:cpu=atmega328 ~/dev/Arduino/ntc_digital_temp
	arduino-cli upload  --fqbn arduino:avr:nano:cpu=atmega328old -p /dev/ttyUSB0 ~/dev/Arduino/ntc_digital_temp

cc1101:
	arduino-cli compile --fqbn arduino:avr:nano:cpu=atmega328 ~/dev/Arduino/cc1101_433mhz
	arduino-cli upload  --fqbn arduino:avr:nano:cpu=atmega328old -p /dev/ttyUSB0 ~/dev/Arduino/cc1101_433mhz

monitor:
	arduino-cli monitor -p /dev/ttyUSB0 -c baudrate=9600

list:
	arduino-cli board list
