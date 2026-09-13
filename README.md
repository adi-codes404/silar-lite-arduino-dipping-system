SILAR-LITE
Arduino-Controlled Sequential Liquid Dipping System

SILAR-LITE is a low-cost automated liquid dipping system built using an Arduino Uno R3 SMD, two NEMA 17 stepper motors, and A4988 stepper motor drivers.

The machine is designed to automatically move a dipping arm into four liquid-filled beakers in sequence. A rotating platform positions each beaker below the dipping arm, while a belt-driven vertical mechanism moves the arm into and out of the liquid.

This project was developed as an Embedded Systems / Mechatronics project with a focus on low-cost, simple, and reproducible automation.

Project Overview

The system consists of two main mechanical subsystems:

Rotating Platform

A circular platform holds four beakers positioned at 90-degree intervals.

A NEMA 17 stepper motor rotates the platform to bring each beaker under the dipping arm.

Vertical Dipping Mechanism

A second NEMA 17 stepper motor drives a GT2 timing belt mechanism.

The belt moves a carriage containing the dipping arm vertically along an 8 mm guide rod using an LM8UU linear bearing.

System Architecture
                    ┌─────────────────────┐
                    │    Arduino Uno      │
                    │       R3 SMD        │
                    └──────────┬──────────┘
                               │
                ┌──────────────┴──────────────┐
                │                             │
             STEP/DIR                      STEP/DIR
                │                             │
        ┌───────▼───────┐             ┌──────▼───────┐
        │    A4988 #1    │             │   A4988 #2   │
        └───────┬────────┘             └──────┬───────┘
                │                             │
        ┌───────▼───────┐             ┌──────▼───────┐
        │   NEMA 17 #1  │             │  NEMA 17 #2  │
        │ Base Rotation │             │ Vertical Arm │
        └───────────────┘             └──────────────┘

Operating Sequence

For each of the four beakers, the system performs the following sequence:

        Start
          │
          ▼
   Move arm DOWN
      300 steps
          │
          ▼
   Wait 30 seconds
          │
          ▼
    Move arm UP
      300 steps
          │
          ▼
     Wait 5 seconds
          │
          ▼
 Rotate base 200 steps
          │
          ▼
    Next beaker


The sequence is repeated for all four beakers.

The complete four-beaker sequence is repeated 100 times, after which the program stops.

Hardware
Component	Specification	Quantity
Arduino Uno R3 SMD	ATmega328P, 16 MHz	1
NEMA 17 Stepper Motor	17HS4401, 40 N·cm, 1.5 A	2
A4988 Stepper Driver	Up to 2 A peak	2
GT2 Pulley	20 tooth	2
GT2 Timing Belt	6 mm width	1
LM8UU Linear Bearing	8 mm bore	1
Smooth Rod	8 mm steel	1
Shaft Coupler	5 mm rigid coupler	1
Power Supply	12 V, 5 A	1
Rotating Platform	300 mm diameter	1
Beakers	250 mL	4
Arduino Pin Configuration
Arduino Pin	Connected To	Function
D2	A4988 #1 and #2 EN	Enable both motors
D3	A4988 #1 STEP	Base motor step
D4	A4988 #1 DIR	Base motor direction
D5	A4988 #2 STEP	Vertical motor step
D6	A4988 #2 DIR	Vertical motor direction
Power
12 V Power Supply
       │
       ├── A4988 #1 VMOT
       │
       ├── A4988 #2 VMOT
       │
       └── Arduino Power Input


The Arduino provides the logic-level control signals to the A4988 drivers.

Software

The firmware is written in C++ using the Arduino IDE.

The project uses the AccelStepper library for controlling both stepper motors.

Library documentation:

https://www.airspayce.com/mikem/arduino/AccelStepper/

Arduino documentation:

https://docs.arduino.cc/

Firmware

The main firmware file is:

silar_lite.ino


The program creates two AccelStepper motor objects:

AccelStepper base(AccelStepper::DRIVER, M1_STEP, M1_DIR);
AccelStepper arm(AccelStepper::DRIVER, M2_STEP, M2_DIR);


The base motor controls the rotary platform, while the arm motor controls the vertical dipping mechanism.

Current Motion Parameters

The current firmware uses the following parameters:

Parameter	Value
Base maximum speed	400 steps/s
Base acceleration	150 steps/s²
Arm maximum speed	300 steps/s
Arm acceleration	200 steps/s²
Arm downward movement	-300 steps
Arm upward movement	+300 steps
Dipping time	30 seconds
Post-lift delay	5 seconds
Base rotation	200 steps
Beaker positions	4
Number of complete sequences	100

These values can be modified directly in the Arduino source code.

Calibration
Rotary Platform

The base motor uses 200 steps for each 90-degree movement.

With 1/4 microstepping and a 200-step NEMA 17 motor:

200 full steps × 4 = 800 microsteps/revolution

800 / 4 = 200 microsteps per 90°


Therefore:

200 steps = 90°
800 steps = 360°

Vertical Movement

The dipping arm uses 300 steps for the downward movement and 300 steps for the return movement.

The actual physical travel should be calibrated on the assembled machine because mechanical tolerances, belt tension, pulley alignment, and motor configuration can affect the movement.

Installation
1. Install Arduino IDE

Download the Arduino IDE from:

https://www.arduino.cc/en/software/

2. Install AccelStepper

Open Arduino IDE and go to:

Sketch
    ↓
Include Library
    ↓
Manage Libraries


Search for:

AccelStepper


Install AccelStepper by Mike McCauley.

3. Open the project

Open:

silar_lite.ino

4. Select the board

In Arduino IDE select:

Tools → Board → Arduino AVR Boards → Arduino Uno

5. Select the COM port

Go to:

Tools → Port


and select the COM port corresponding to your Arduino Uno.

6. Upload

Click the Upload button in Arduino IDE.

Repository Structure
silar-lite-arduino-dipping-system/
│
├── README.md
│
└── silar_lite.ino


Additional folders can be added later for mechanical drawings, wiring diagrams, photographs, and videos.

For example:

silar-lite-arduino-dipping-system/
│
├── README.md
├── silar_lite.ino
│
├── images/
│   ├── machine-front.jpg
│   ├── machine-side.jpg
│   └── wiring.jpg
│
└── docs/
    ├── mechanical/
    └── electrical/

Bill of Materials

Approximate prototype cost:

₹2,904 INR

Item	Quantity	Unit Cost (INR)	Total (INR)
NEMA 17 Stepper Motor	2	650	1,300
A4988 Motor Driver	2	100	200
A4988 Controller Board	2	70	140
Arduino Uno R3 SMD	1	253	253
GT2 Belt	1	90	90
GT2 Pulley 20T	2	90	180
LM8UU Linear Bearing	1	44	44
L Bracket	1	100	100
Circular MDF/Plywood Platform	1	179	179
8 mm Smooth Rod	1	163	163
Rigid Shaft Coupler	1	55	55
Screws, bolts and wires	—	—	200
Total			₹2,904
Results

The prototype was tested for sequential operation of the four-beaker system.

Observed results included:

Consistent 90-degree platform rotation.
Repeatable vertical arm movement after calibration.
Reliable sequential dipping.
GT2 belt remained tensioned during operation.
A4988 drivers became warm during extended operation.
Motor noise was present but acceptable for the intended application.
No driver failures were observed during testing.
Limitations

The current version has several limitations:

No position feedback.
Open-loop stepper motor control.
Motor step loss can cause position errors.
No liquid-level sensing.
Fixed dipping depth.
Parameters must be changed in the source code.
Power interruption requires restarting the program.
Dipping arm stability can be improved.
No display or user interface.
No automatic homing mechanism.
Future Improvements

Planned or possible improvements include:

Add homing and position sensors.
Implement closed-loop position verification.
Add a 16×2 LCD display.
Add EEPROM for saving system state.
Add liquid-level sensing.
Add beaker-presence detection.
Add start/stop controls.
Allow runtime adjustment of dipping parameters.
Improve mechanical stability of the dipping arm.
Support more than four beaker positions.
Applications

SILAR-LITE can be adapted for applications such as:

Laboratory sample dipping
Chemical coating experiments
Staining procedures
Surface treatment experiments
Educational mechatronics projects
Embedded systems demonstrations
Small-scale laboratory automation
Sequential liquid processing

The system should only be used with liquids and materials that are compatible with the machine's mechanical, electrical, and structural components.

Project Specifications
Specification	Details
Project Name	SILAR-LITE
Project Type	Embedded Systems / Mechatronics
Controller	Arduino Uno R3 SMD
Motors	2 × NEMA 17
Motor Drivers	2 × A4988
Drive Mechanism	GT2 Belt
Number of Beakers	4
Platform Index	90°
Power Supply	12 V, 5 A
Firmware	Arduino C++
Stepper Library	AccelStepper
Estimated Cost	₹2,904
Project Status	Working Prototype
Safety

This project involves moving mechanical components, stepper motors, motor drivers, and a 12 V power supply.

Before operating the machine:

Check all electrical connections.
Verify the A4988 current-limit settings.
Ensure the motor drivers have adequate cooling.
Verify common ground connections.
Keep hands and loose objects away from moving parts.
Do not operate the machine unattended.
Use appropriate containers and materials for the liquids being processed.
References

Arduino Documentation
https://docs.arduino.cc/

AccelStepper Library — Mike McCauley
https://www.airspayce.com/mikem/arduino/AccelStepper/

Allegro MicroSystems — A4988 Stepper Motor Driver Datasheet

Trinamic Motion Control — NEMA 17 / 17HS4401 Stepper Motor Documentation

Ossila — Introduction to Dip Coating
https://www.ossila.com/pages/dip-coating

Leica Biosystems — Autostainer XL Product Documentation

Biolin Scientific / KSV NIMA — Dip Coater Technical Specifications

Groover, M. P. — Fundamentals of Modern Manufacturing, 5th Edition, Wiley, 2015.

License

This project is intended primarily as an educational and experimental open-source project.

A specific open-source license can be added to this repository if you plan to allow others to freely modify and redistribute the project.
