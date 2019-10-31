#ifdef GCODE

void select_GCODE () {
  switch (type) {
      case 'X':
        if (stepper1.distanceToGo() == 0) {
          stepper1.moveTo(value * passo);
        }
        if (stepper4.distanceToGo() == 0) {
          stepper4.moveTo(value * passo);
        }
        break;
      case 'Y':
        if (stepper2.distanceToGo() == 0) {
          stepper2.moveTo(value * passo);
        }
        if (stepper3.distanceToGo() == 0) {
          stepper3.moveTo(value * passo);
        }
        break;
      case 'D':
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
        break;
      case 'Q':
        quadrado();
        break;
      case 'T':
        triangulo();
        break;
      case 'R':
        rotacinar();
        break;
    }
}

#endif
