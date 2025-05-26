# Wah Pedal Application with Arduino Nano

## Objective
The goal of this project is to implement a guitar pedal using an IIR filter that produces a “Wah” effect. An audio signal from an electret microphone is sampled via an external ADC, processed through filters with eight different center frequencies, and output via a buzzer.

---

## Project Modules and Workflow

### Internal ADC
- Utilizes the Arduino Nano’s onboard ADC.
- Reads data from a potentiometer.
- Determines a filter index for selecting the center frequency.
- Corresponding filter coefficients are selected from 2D float arrays (`a_array` and `b_array`).

### External ADC
- Uses MCP3008 ADC chip to sample audio from a MAX4466 electret microphone at 200kHz.
- 12-bit resolution allows 44kHz bandwidth without aliasing.
- SPI communication protocol is used for interfacing.
- Raw 12-bit data (0–1023) is converted to voltage.
- Data follows the MCP3008 SPI bitstream protocol.

### Filter Module
- Voltage values are stored in an input array, acting as a buffer.
- Arrays shift to accommodate new data.
- Filter coefficients determined by the potentiometer control the processing.
- The filter is implemented using biquad IIR filters.
- Coefficients are calculated using normalized angular frequency and Q factor.
- Code files: `Filter.h`, `Filter.c`.
- MATLAB script (`ELE362_Proje.m`) used to generate filter coefficients.

**Note:**  
Although FIR filters are more stable with less phase distortion, they are computationally expensive. IIR filters are preferred for efficiency.

### Output and PWM Module
- Output value is converted to an analog signal using a timer module.
- Played through a buzzer.
- PWM signal calculated and written to OCR in `main.c`.
- Timer1 configured in Fast PWM mode with a non-inverting output.

---

## Operation Loop
1. New audio signal is received.
2. Sampled and digitized.
3. Processed using filter coefficients.
4. Output is generated via PWM and played through the buzzer.
5. Loop repeats.

---

## Source Code Files
- `main.c`: Main program loop.
- `ADC.h`, `ADC.c`: Handles internal and external ADCs.
- `Filter.h`, `Filter.c`: Contains filter logic and coefficients.
- `SPI.h`, `SPI.c`: SPI communication setup.
- `Timer.h`, `Timer.c`: Timer and PWM configuration.
- `UART.h`, `UART.c`: UART communication functions.
- `ELE362_Proje.m`: MATLAB code for filter coefficient generation.

---
