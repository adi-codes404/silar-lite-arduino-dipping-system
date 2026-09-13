# SILAR-LITE

## Arduino-Controlled Sequential Liquid Dipping System

SILAR-LITE is a low-cost automated liquid dipping system built using an **Arduino Uno R3 SMD**, **two NEMA 17 stepper motors**, and **A4988 stepper motor drivers**.

The machine automatically moves a dipping arm into four liquid-filled beakers in sequence. A rotating platform positions each beaker below the dipping arm, while a GT2 belt-driven mechanism moves the arm vertically.

This project was developed as an **Embedded Systems / Mechatronics** project with a focus on low-cost and reproducible automation.

---

## Project Overview

The system consists of two main mechanical subsystems:

### Rotating Platform

A circular platform holds four beakers positioned at 90-degree intervals.

A NEMA 17 stepper motor rotates the platform to bring each beaker under the dipping arm.

### Vertical Dipping Mechanism

A second NEMA 17 stepper motor drives a GT2 timing belt mechanism.

The belt moves a carriage containing the dipping arm vertically along an 8 mm guide rod using an LM8UU linear bearing.

---

## Hardware

| Component | Specification | Quantity |
|---|---|---:|
| Arduino Uno R3 SMD | ATmega328P, 16 MHz | 1 |
| NEMA 17 Stepper Motor | 17HS4401, 40 N·cm, 1.5 A | 2 |
| A4988 Stepper Driver | Up to 2 A peak | 2 |
| GT2 Pulley | 20 tooth | 2 |
| GT2 Timing Belt | 6 mm width | 1 |
| LM8UU Linear Bearing | 8 mm bore | 1 |
| Smooth Rod | 8 mm steel | 1 |
| Shaft Coupler | 5 mm rigid coupler | 1 |
| Power Supply | 12 V, 5 A | 1 |
| Rotating Platform | 300 mm diameter | 1 |
| Beakers | 250 mL | 4 |

---

## Arduino Pin Configuration

| Arduino Pin | Connected To | Function |
|---|---|---|
| D2 | A4988 #1 and #2 EN | Enable both motors |
| D3 | A4988 #1 STEP | Base motor STEP |
| D4 | A4988 #1 DIR | Base motor direction |
| D5 | A4988 #2 STEP | Vertical motor STEP |
| D6 | A4988 #2 DIR | Vertical motor direction |

---

## Operating Sequence

For each of the four beakers, the system performs:

1. Move the dipping arm down by **300 steps**
2. Wait for **30 seconds**
3. Move the dipping arm back up by **300 steps**
4. Wait for **5 seconds**
5. Rotate the platform by **200 steps**
6. Move to the next beaker

The sequence is performed for all four beakers.

The complete four-beaker sequence is repeated **100 times**, after which the program stops.

---

## Software

The firmware is written in **C++ using the Arduino IDE**.

The project uses the **AccelStepper** library by Mike McCauley for controlling the two stepper motors.

Library documentation:

https://www.airspayce.com/mikem/arduino/AccelStepper/

Arduino documentation:

https://docs.arduino.cc/

---

## Current Motion Parameters

| Parameter | Value |
|---|---:|
| Base maximum speed | 400 steps/s |
| Base acceleration | 150 steps/s² |
| Arm maximum speed | 300 steps/s |
| Arm acceleration | 200 steps/s² |
| Arm downward movement | 300 steps |
| Arm upward movement | 300 steps |
| Dipping time | 30 seconds |
| Post-lift delay | 5 seconds |
| Base rotation | 200 steps |
| Beaker positions | 4 |
| Complete sequences | 100 |

These values can be modified directly in `silar_lite.ino`.

---

## Calibration

### Rotary Platform

The base motor is configured to rotate the platform by approximately 90 degrees using 200 steps.

With 1/4 microstepping:

- 200 full steps × 4 = 800 microsteps per revolution
- 800 / 4 = 200 microsteps per 90 degrees

Therefore:

- **200 steps = 90°**
- **800 steps = 360°**

### Vertical Movement

The dipping arm currently moves 300 steps downward and 300 steps upward.

The actual physical travel should be calibrated on the assembled machine because belt tension, pulley alignment, mechanical tolerances, and motor configuration can affect movement.

---

## Installation

### 1. Install Arduino IDE

Download the Arduino IDE:

https://www.arduino.cc/en/software/

### 2. Install AccelStepper

Open Arduino IDE:

**Sketch → Include Library → Manage Libraries**

Search for:

**AccelStepper**

Install **AccelStepper by Mike McCauley**.

### 3. Open the firmware

Open:

`silar_lite.ino`

### 4. Select the board

Select:

**Tools → Board → Arduino AVR Boards → Arduino Uno**

### 5. Select the COM port

Select the port corresponding to your Arduino Uno:

**Tools → Port**

### 6. Upload

Click the **Upload** button in Arduino IDE.

---

## Repository Structure

```text
silar-lite-arduino-dipping-system/
│
├── README.md
└── silar_lite.ino
