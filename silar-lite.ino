#include <AccelStepper.h>
#include <MultiStepper.h>

#define M1_STEP 3
#define M1_DIR 4

#define M2_STEP 5
#define M2_DIR 6

#define EN_PIN 2

AccelStepper base(AccelStepper::DRIVER, M1_STEP, M1_DIR);
AccelStepper arm(AccelStepper::DRIVER, M2_STEP, M2_DIR);

void setup() {
   Serial.begin(9600);                  
  
  pinMode(EN_PIN, OUTPUT);              
  digitalWrite(EN_PIN, LOW); 

  base.setMaxSpeed(400);
  base.setAcceleration(150);

  arm.setMaxSpeed(300);
  arm.setAcceleration(200);
}

void moveMotor(AccelStepper &m, long steps)
{
    m.move(steps);

    while(m.distanceToGo() != 0)
    {
        m.run();
    }
}

void loop() {

  for(int cycle = 0; cycle < 100; cycle++) {

    for(int i = 0; i < 4; i++) {

      moveMotor(arm, -300);
      delay(30000);

      moveMotor(arm, 300);
      delay(5000);

      moveMotor(base, 200);
    }
  }

  while(true);
}