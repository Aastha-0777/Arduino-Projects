# Color Adder (RGB Mixing)

An Arduino project demonstrating additive color mixing — three push 
buttons individually control the Red, Green, and Blue channels of an 
RGB LED, and pressing combinations of them mixes those colors together 
in real time.

![Circuit Photo](./circuit-photo.jpg)

## Components
- Arduino UNO R4 Minima
- 3x push buttons (Red, Green, Blue channel inputs)
- 1x RGB LED
- Resistors for each button input and each LED channel
- Breadboard + jumper wires

## How it works
Each button is wired to its own digital input pin, and each one 
independently controls one pin of the RGB LED (Red, Green, or Blue). 
Pressing a single button lights just that color; pressing two or three 
buttons together lights multiple channels of the RGB LED at once, which 
visually mix — for example, Red + Green produces Yellow, and all three 
together produce White.

## Color combinations
| Buttons Pressed | Resulting Color |
|---|---|
| Red only | Red |
| Green only | Green |
| Blue only | Blue |
| Red + Green | Yellow |
| Red + Blue | Magenta |
| Green + Blue | Cyan |
| Red + Green + Blue | White |

## What I learned
This project connects digital input logic (buttons) with a new output 
concept — controlling multiple channels of a single RGB LED 
simultaneously, and seeing how individual signals combine into something 
visually different than any one of them alone.
