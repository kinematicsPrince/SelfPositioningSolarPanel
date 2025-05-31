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

### Solar Panel(s)
|    Pin      | Connected To | Description |
|-------------|--------------|-------------|
| Arduino Pin A5       | Solar Panel(s)  | Red Wire   |
|Arduino Pin GND      |  Solar Panel(s)  | Black Wire  |

## Software Requirements

- Arduino IDE [2.3.3]
- Library:
  - SevSeg

## Usage Instructions

## Troubleshooting

If the voltage given by the solar panel(s) exceeds the reading values of the analog input of the Arduino, a device that steps down voltage can be used

Example (buck converter): https://www.amazon.ca/BULVACK-LM2596-Converter-Module-1-25V-30V/dp/B07VVXF7YX/ref=sr_1_6?crid=K0KV1EOWJDZP&dib=eyJ2IjoiMSJ9.RC-W9MMW4wP1EhYY1tl50bZD3ouf-URFuvuVeLlqfTwFbaxAjldjpx9EBkaDE4Q5Ovca4jpkvg_ub3zznTmZ7EV_lASJl6y_VQU6zQ4dqHnClHaw90AvVRPGzw2KduSwNRxwZJ7dhqORJ9_7EaVZTjBzTW4b_Je0CLpTouLyS0Zl6mIBqSnSg9HNhCJPBi5TFPZhYgop-oagF0xvZxsIpuY4Ul8wIc9aYeIJozfkQYpMqptsEDKw7P_J-ktin6GkMelucrOPBueXxpwQzZJZAKKWA7mSyObmFu3XqjGEjWQ.UYSTfch3m1RunKXyCmxNG11SHiRj1x_ZMV6WpRTG_Sg&dib_tag=se&keywords=buck%2Bconverter%2B3.2V&qid=1748722391&sprefix=buck%2Bconverter%2B3%2B2v%2Caps%2C156&sr=8-6&th=1

## Future Improvements

## References

- https://www.circuitbasics.com/arduino-7-segment-display-tutorial/
- https://www.thingiverse.com/thing:2892903
