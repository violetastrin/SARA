#include <Servo.h>
#define graumaximo 150

Servo servos[5];
int pinoservos[] = {9, 10, 6, 3, 5};

void setup() {
  for (int i = 0; i < 5; i++) {
    servos[i].attach(pinoservos[i]);
  }
}

void loop() {
 
  for (int pos = 0; pos <= graumaximo; pos++) {
    for (int i = 0; i < 5; i++) {
      int angulo;
      if (i == 3 || i == 4) {
        angulo = graumaximo - pos;
      } else {
        angulo = pos;
      }
            servos[i].write(angulo);
    }
    delay(20);
  }

  delay(3000);  // Pausa 

  for (int pos = graumaximo; pos >= 0; pos--) {
    for (int i = 0; i < 5; i++) {
      int angulo;

      if (i == 3 || i == 4) {
        angulo = graumaximo - pos;
      } else {
        angulo = pos;
      }

      servos[i].write(angulo);
    }
    delay(20);
  }

  delay(3000);  // Pausa
}
