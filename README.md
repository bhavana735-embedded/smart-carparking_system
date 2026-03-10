# smart-carparking_system
Developed an automated smart parking system using Arduino, ultrasonic sensors, IR sensors, and LED indicators to detect parking slot availability. The system guides vehicles to free spaces and improves parking efficiency. This project enhanced skills in sensor interfacing, embedded programming, and real-time monitoring.

# Aim
To design and implement a smart parking system that automatically detects whether a parking slot is occupied or available and provides visual indication to drivers using sensors and LEDs.

# Components Required

Arduino Uno
HC-SR04 Ultrasonic Sensor
IR Sensors (2 or more)
LEDs (for slot indication)
Resistors (220Ω)
Breadboard
Jumper wires
Power supply

# Connections

# Ultrasonic Sensor
VCC → 5V (Arduino)
GND → GND
TRIG → Digital Pin 9
ECHO → Digital Pin 10

# IR Sensor 1
VCC → 5V
GND → GND
OUT → Digital Pin 2
# IR Sensor 2
VCC → 5V
GND → GND
OUT → Digital Pin 3

# LED Indicators
LED1 → Digital Pin 6
LED2 → Digital Pin 7
Other side of LEDs → GND through resistor

# Procedure
Connect all components to the Arduino according to the circuit diagram.
Upload the Arduino code to the microcontroller.
Place IR sensors in each parking slot to detect vehicle presence.
Ultrasonic sensor detects vehicles entering the parking area.
When a slot is occupied, the LED turns ON indicating the slot is full.
If the slot is empty, the LED remains OFF indicating availability.
The system continuously monitors slot status and updates in real time.
