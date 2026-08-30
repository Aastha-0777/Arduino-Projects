# Binary Counter

An Arduino project that counts in binary using LEDs — each LED represents 
a bit, lighting up in the pattern of an incrementing binary number.

![Demo](./BinaryCounter.jpg)

## Components
- Arduino UNO R4 Minima
- 4x LEDs
- 4x 220Ω resistors
- Breadboard + jumper wires

## How it works
Each LED corresponds to one bit of a binary number. As a counter variable 
increments, `digitalWrite()` sets each LED HIGH or LOW based on that bit's 
value — turning the abstract idea of binary counting into something 
visible and physical.

## What I learned
Builds directly on the LED Blink project — same digital output control, 
but combined with bitwise logic to represent multi-bit values physically.
