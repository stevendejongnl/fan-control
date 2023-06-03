# Fan Control System with Arduino Pro Micro

This project demonstrates how to control two 24V fans using an Arduino Pro Micro. The fans can be turned on and off using a button, and the duration for which they stay on can be increased with each button press. The remaining time is indicated by an LED that blinks a certain number of times. Holding down the button for a specific duration can also perform other actions like displaying the remaining time or turning off everything.

## Circuit Diagram

![Circuit Diagram](circuit-diagram.png)

The circuit consists of the following components:
- Arduino Pro Micro
- 24V 1A Adapter
- Two 24V Fans
- G3VM-61G1 Relays
- 2N2222 A331 Transistors
- 1N4007 DO-41 Diodes
- Mini360 Buck Step Down Modules

Connect the components as shown in the circuit diagram above. Ensure proper connections and pay attention to polarities.

## How to Use

1. Connect the circuit according to the provided circuit diagram.
2. Upload the provided Arduino sketch (`fan_control.ino`) to the Arduino Pro Micro using the Arduino IDE.
3. Open the Serial Monitor in the Arduino IDE to view the system logs (baud rate: 9600).
4. Power on the circuit.
5. Press the button to turn on the fans. Each press increases the duration by one hour.
6. Hold the button for 3 seconds to display the remaining time with LED blinks.
7. Hold the button for 10 seconds to turn off everything.

## Troubleshooting

- If the fans are not turning on/off properly, check the relay connections and ensure the relay pins are correctly connected to the Arduino.
- If the LED does not blink or behaves unexpectedly, check the LED connection and verify the code for the LED control.

## License

This project is licensed under the [MIT License](LICENSE).

