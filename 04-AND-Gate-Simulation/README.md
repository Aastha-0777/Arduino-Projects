# AND Gate Simulation

An Arduino project simulating a digital AND gate using two push buttons 
as inputs and an LED as the output — the LED only turns on when both 
buttons are pressed simultaneously.

![Circuit Photo](./circuit-photo.jpg)

## Components
- Arduino UNO R4 Minima
- 2x push buttons
- 1x LED
- Resistors for each input and the LED
- Breadboard + jumper wires

## How it works
Each button is wired to its own digital input pin. The Arduino reads 
both states with `digitalRead()` and only sets the LED pin HIGH when 
both inputs are HIGH — replicating AND gate logic in hardware.

## What I learned
This connects directly to what I'm studying in Digital Electronics this 
semester — instead of just reading about logic gates on paper, I built 
one physically and watched the truth table play out in real time.
