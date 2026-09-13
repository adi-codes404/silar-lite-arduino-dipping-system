#include <AccelStepper.h>   // Library to control stepper motors
#include <MultiStepper.h>   // Library for controlling multiple steppers

// Step and direction pins for Motor 1 (Base)
#define M1_STEP 3
#define M1_DIR 4

// Step and direction pins for Motor 2 (Arm)
#define M2_STEP 5
#define M2_DIR 6

// Enable pin for the motor driver
#define EN_PIN 2

// Create two stepper motor objects
AccelStepper base(AccelStepper::DRIVER, M1_STEP, M1_DIR);
AccelStepper arm(AccelStepper::DRIVER, M2_STEP, M2_DIR);

void setup() {
  Serial.begin(9600);  // Start serial communication

  pinMode(EN_PIN, OUTPUT);     // Set enable pin as output
  digitalWrite(EN_PIN, LOW);   // Enable the motor drivers

  // Set maximum speed and acceleration for base motor
  base.setMaxSpeed(400);
  base.setAcceleration(150);

  // Set maximum speed and acceleration for arm motor
  arm.setMaxSpeed(300);
  arm.setAcceleration(200);
}

// Move a motor by the given number of steps
void moveMotor(AccelStepper &m, long steps)
{
  m.move(steps);  // Set the movement distance

  // Keep moving until the target position is reached
  while (m.distanceToGo() != 0)
  {
    m.run();  // Move the motor one step at a time
  }
}

void loop() {

  // Repeat the complete process 100 times
  for (int cycle = 0; cycle < 100; cycle++) {

    // Repeat the arm and base movement 4 times
    for (int i = 0; i < 4; i++) {

      moveMotor(arm, -300);  // Move arm backward 300 steps
      delay(30000);          // Wait 30 seconds

      moveMotor(arm, 300);   // Move arm forward 300 steps
      delay(5000);           // Wait 5 seconds

      moveMotor(base, 200);  // Move base forward 200 steps
    }
  }

  while (true);  // Stop the program after all cycles are complete
}
