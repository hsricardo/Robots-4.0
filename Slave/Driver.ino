#ifdef DRIVER

#include <AccelStepper.h>

AccelStepper stepper1(AccelStepper::DRIVER, 13, 12); // step, dir
AccelStepper stepper2(AccelStepper::DRIVER, 27, 14); // step, dir
AccelStepper stepper3(AccelStepper::DRIVER, 26, 25); // step, dir
AccelStepper stepper4(AccelStepper::DRIVER, 33, 32); // step, dir

void setup_DRIVER() {
  stepper1.setMaxSpeed(200);
  stepper1.setAcceleration(200);
  stepper2.setMaxSpeed(200);
  stepper2.setAcceleration(200);
  stepper3.setMaxSpeed(200);
  stepper3.setAcceleration(200);
  stepper4.setMaxSpeed(200);
  stepper4.setAcceleration(200);
}

void run_DRIVER () {
  while (stepper1.distanceToGo() != 0 || stepper2.distanceToGo() != 0 || stepper3.distanceToGo() != 0 || stepper4.distanceToGo() != 0) {
    stepper1.run();
    stepper2.run();
    stepper3.run();
    stepper4.run();
  }
}

void quadrado() {
  if (stepper1.distanceToGo() == 0) {
    stepper1.moveTo(value * passo);
  }
  if (stepper4.distanceToGo() == 0) {
    stepper4.moveTo(value * passo);
  }
  run_DRIVER ();
  if (stepper2.distanceToGo() == 0) {
    stepper2.moveTo(value * passo);
  }
  if (stepper3.distanceToGo() == 0) {
    stepper3.moveTo(value * passo);
  }
  run_DRIVER ();
  if (stepper1.distanceToGo() == 0) {
    stepper1.moveTo(0);
  }
  if (stepper4.distanceToGo() == 0) {
    stepper4.moveTo(0);
  }
  run_DRIVER ();
  if (stepper2.distanceToGo() == 0) {
    stepper2.moveTo(0);
  }
  if (stepper3.distanceToGo() == 0) {
    stepper3.moveTo(0);
  }
  run_DRIVER ();
}

void triangulo() {
  if (stepper1.distanceToGo() == 0) {
    stepper1.moveTo(value * passo);
  }
  if (stepper2.distanceToGo() == 0) {
    stepper2.moveTo(value * passo);
  }
  if (stepper3.distanceToGo() == 0) {
    stepper3.moveTo(value * passo);
  }
  if (stepper4.distanceToGo() == 0) {
    stepper4.moveTo(value * passo);
  }
  run_DRIVER ();
  if (stepper1.distanceToGo() == 0) {
    stepper1.moveTo(value * passo * 2);
  }
  if (stepper2.distanceToGo() == 0) {
    stepper2.moveTo(0);
  }
  if (stepper3.distanceToGo() == 0) {
    stepper3.moveTo(0);
  }
  if (stepper4.distanceToGo() == 0) {
    stepper4.moveTo(value * passo * 2);
  }
  run_DRIVER ();
  if (stepper1.distanceToGo() == 0) {
    stepper1.moveTo(0);
  }
  if (stepper4.distanceToGo() == 0) {
    stepper4.moveTo(0);
  }
  run_DRIVER ();
}

void rotacinar() {
  if (stepper1.distanceToGo() == 0) {
    stepper1.moveTo(value * passo / 2);
  }
  if (stepper2.distanceToGo() == 0) {
    stepper2.moveTo(value * passo / 2);
  }
  if (stepper3.distanceToGo() == 0) {
    stepper3.moveTo(value * passo / 2);
  }
  if (stepper4.distanceToGo() == 0) {
    stepper4.moveTo(value * passo / 2);
  }
  run_DRIVER ();
  if (stepper1.distanceToGo() == 0) {
    stepper1.moveTo(value * passo);
  }
  if (stepper2.distanceToGo() == 0) {
    stepper2.moveTo(value * passo);
  }
  if (stepper3.distanceToGo() == 0) {
    stepper3.moveTo(0);
  }
  if (stepper4.distanceToGo() == 0) {
    stepper4.moveTo(0);
  }
  run_DRIVER ();
  if (stepper1.distanceToGo() == 0) {
    stepper1.moveTo(value * passo / 2);
  }
  if (stepper2.distanceToGo() == 0) {
    stepper2.moveTo(value * passo / 2);
  }
  if (stepper3.distanceToGo() == 0) {
    stepper3.moveTo(value * passo / 2);
  }
  if (stepper4.distanceToGo() == 0) {
    stepper4.moveTo(value * passo / 2);
  }
  run_DRIVER ();
  if (stepper1.distanceToGo() == 0) {
    stepper1.moveTo(0);
  }
  if (stepper2.distanceToGo() == 0) {
    stepper2.moveTo(0);
  }
  if (stepper3.distanceToGo() == 0) {
    stepper3.moveTo(0);
  }
  if (stepper4.distanceToGo() == 0) {
    stepper4.moveTo(0);
  }
  run_DRIVER ();
}

#endif
