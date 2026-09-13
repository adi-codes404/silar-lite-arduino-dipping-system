SILAR-LITE
Arduino-Controlled Sequential Liquid Dipping System

SILAR-LITE is a low-cost, Arduino-controlled automated rotary dipping machine designed to sequentially dip a probe, hand, or sample into four liquid-filled beakers.

The system uses two NEMA 17 stepper motors: one for rotating the beaker platform and another for vertically moving the dipping arm.

Project Overview

The machine consists of two main motion systems:

Rotating platform — indexes four beakers at 90° intervals.
Vertical dipping arm — moves the probe into and out of the liquid using a GT2 belt mechanism.

Both motors are controlled by an Arduino Uno R3 SMD through A4988 stepper motor drivers.

Hardware
Component	Quantity
Arduino Uno R3 SMD	1
NEMA 17 Stepper Motor	2
A4988 Stepper Driver	2
GT2 20T Pulley	2
GT2 Timing Belt	1
LM8UU Linear Bearing	1
8 mm Smooth Rod	1
Rigid Shaft Coupler	1
12 V 5 A Power Supply	1
Rotating Platform	1
Beakers	4
Arduino Pin Configuration
Arduino Pin	Function
D2	Enable — both A4988 drivers
D3	Base motor STEP
D4	Base motor DIR
D5	Vertical arm motor STEP
D6	Vertical arm motor DIR
Software

The firmware is written in C++ using the Arduino IDE.

The project uses the AccelStepper library for controlling the two stepper motors with acceleration and deceleration.

Library documentation:

{"fallbackMarkdown":"AccelStepper Documentation
","reference":{"matched_text":"","prefix":null,"start_idx":3339,"end_idx":3425,"safe_urls":[],"refs":[],"alt":"AccelStepper Documentation
","prompt_text":"AccelStepper Documentation
","type":"url","title":"AccelStepper Documentation","item":{"title":"AccelStepper Documentation","url":"https://www.airspayce.com/mikem/arduino/AccelStepper/?utm_source=chatgpt.com","attribution":"airspayce.com","pub_date":null,"snippet":null,"attribution_segments":null,"supporting_websites":null,"refs":[],"hue":null,"attributions":null},"layout":null,"logo":null},"showLoginRequiredCard":false}

Current Motion Parameters

The current firmware is configured with:

Parameter	Value
Base maximum speed	400 steps/s
Base acceleration	150 steps/s²
Arm maximum speed	300 steps/s
Arm acceleration	200 steps/s²
Downward movement	300 steps
Upward movement	300 steps
Dipping time	30 seconds
Post-lift delay	5 seconds
Base rotation	200 steps
Beaker positions	4
Complete cycles	100
Operating Sequence

For each of the four beakers, the Arduino performs:

Move arm down 300 steps
        ↓
Wait 30 seconds
        ↓
Move arm up 300 steps
        ↓
Wait 5 seconds
        ↓
Rotate platform 200 steps
        ↓
Move to next beaker


This sequence is repeated for four beaker positions.

The complete four-beaker sequence is then repeated 100 times.

After 100 cycles, the Arduino stops execution.

Stepper Motor Configuration

The project uses two A4988 stepper motor drivers.

The drivers are configured externally for the required microstepping mode.

The firmware itself generates the STEP and DIR signals through the AccelStepper library.

Project Structure
SILAR-LITE/
├── README.md
└── silar_lite.ino

Installation
1. Install Arduino IDE

Download and install the Arduino IDE from the official Arduino website:

{"fallbackMarkdown":"Arduino IDE / Documentation
","reference":{"matched_text":"","prefix":null,"start_idx":4766,"end_idx":4824,"safe_urls":[],"refs":[],"alt":"Arduino IDE / Documentation
","prompt_text":"Arduino IDE / Documentation
","type":"url","title":"Arduino IDE / Documentation","item":{"title":"Arduino IDE / Documentation","url":"https://docs.arduino.cc/?utm_source=chatgpt.com","attribution":"docs.arduino.cc","pub_date":null,"snippet":null,"attribution_segments":null,"supporting_websites":null,"refs":[],"hue":null,"attributions":null},"layout":null,"logo":null},"showLoginRequiredCard":false}

2. Install AccelStepper

In Arduino IDE:

Sketch
→ Include Library
→ Manage Libraries
→ Search "AccelStepper"
→ Install

3. Open the firmware

Open:

silar_lite.ino


in Arduino IDE.

4. Select the board

Select:

Arduino Uno


from:

Tools → Board


Select the appropriate COM port from:

Tools → Port

5. Upload

Click the Upload button in Arduino IDE.

Safety

This project controls stepper motors and uses a 12 V power supply.

Before powering the machine:

Check motor-driver wiring carefully.
Verify the motor current limit on the A4988 drivers.
Ensure all grounds are connected correctly.
Keep hands and loose objects away from moving mechanisms.
Do not operate the machine unattended.
Make sure the dipping material and liquids are compatible with the mechanical components.
Limitations

The current version is an open-loop system and does not have position feedback.

Current limitations include:

No homing or position sensor.
Motor step loss can cause position errors.
No liquid-level sensing.
Fixed dipping depth.
Parameters must be changed in the source code.
Power interruption requires restarting the program.
The dipping arm requires improved mechanical stability.
No LCD or user interface.
Future Improvements

Possible improvements include:

Position/homing sensors
Closed-loop position verification
16×2 LCD display
EEPROM-based state storage
Liquid-level sensing
Beaker-presence detection
Start/stop controls
Runtime parameter adjustment
Improved dipping-arm stability
Support for more than four beakers
Project Cost

Approximate prototype component cost:

₹2,904 INR

The actual cost may vary depending on supplier, location, and component availability.

Applications

SILAR-LITE can be adapted for:

Laboratory sample dipping
Chemical coating experiments
Staining procedures
Surface treatment experiments
Educational mechatronics
Embedded systems projects
Small-scale automation
Sequential liquid processing
Project Status

Working Prototype

The current firmware successfully controls the rotating platform and vertical dipping mechanism through two stepper motors.

License

This project is intended as an open-source educational and experimental project.

You may add a specific open-source license to the repository depending on how you want others to use, modify, and distribute the project.