# SelfPositioningSolarPanel
Thingiverse link: https://www.thingiverse.com/thing:7053488
## Project Overview

This gimbal automatically rotates solar panels towards the most light.

## Hardware Components

- Arduino Uno/Nano
- 2x SG-90
- 3D printer / 3D plastic
- Solar Panel(s)
- 1x one number segment display
- 1x small breadboard
- External 5V to 6V battery or power supply

## Circuit Diagram

<img src="https://github.com/user-attachments/assets/7ab7a078-482f-4e67-9bad-12e8b4dd839c" alt="Sample Image" style="width:80%; height:auto;">

## Wiring Instructions
### Segment Display Pins

<img src="https://github.com/user-attachments/assets/3f907ac5-af44-4029-b19a-e60036c44dfd" alt="Sample Image" style="width:60%; height:auto;">

### Servo Motors
|    Pin      | Connected To | Description |
|-------------|--------------|-------------|
| Arduino Pin 11       | Bottom Servo  | Orange Wire   |
|Arduino Pin 12       |  Top Servo  | Orange Wire  |
| GND from Battery        | Bottom Servo          |   Black Wire       |
| GND from Battery        | Top Servo          |   Black Wire       |
| + from Battery        | Bottom Servo          |   Red Wire       |
| + from Battery        | Top Servo          |   Red Wire       |

### Solar Panels
|    Pin      | Connected To | Description |
|-------------|--------------|-------------|
| Arduino Pin A5       | Solar Panels  | Red Wire   |
|Arduino Pin GND      |  Solar Panels  | Black Wire  |

## Software Requirements

- Arduino IDE [2.3.3]
- Library:
  - SevSeg

## Usage Instructions

## Troubleshooting

## Future Improvements

## References

- https://www.circuitbasics.com/arduino-7-segment-display-tutorial/
- https://www.thingiverse.com/thing:2892903
