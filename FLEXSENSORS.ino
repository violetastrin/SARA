#include <Servo.h>

// Sensores nos pinos A1,A2,A3,A6,A7
const int flexPins[5] = {A1,A2,A3,A6,A7};
// Servos nos pinos digitais 5,3,6,10,9
const int servoPins[5] = {3,5,6,10,9};

// Cria 5 objetos servo
Servo servos[5];

void setup() {
  Serial.begin(9600);

  for (int i = 0; i < 5; i++) {
    servos[i].attach(servoPins[i]);
  }

  Serial.println("Iniciando leitura dos sensores...\n");
}

void loop() {
  for (int i = 0; i < 5; i++) {
    int flexValue = analogRead(flexPins[i]);
    int angle;

    // Mapeamento individual por sensor
    if (i == 0) {
      angle = map(flexValue, 920, 1010, 0, 140)  ; // mínimo
      angle = constrain(angle, 0, 140);
    } else if (i == 1) {
      angle = map(flexValue, 820, 1000, 30, 170); // anelar
      angle = constrain(angle, 10, 140);
    }  else if (i == 2) {
      angle = map(flexValue, 700, 820, 30, 170); // dedo do meio
      angle = constrain(angle, 10, 140);
    }  else if (i == 3) {
      angle = map(flexValue, 870, 1020, 30, 170); // indicador
      angle = constrain(angle, 30, 180);
      angle = 180 - angle;  // Inverte movimento
    } else {
      angle = map(flexValue, 770, 970, 50, 180); // polegar
      angle = constrain(angle, 50, 180);
      angle = 180 - angle;  // Inverte movimento
    }

    servos[i].write(angle);

    // Impressão detalhada
    Serial.print("Sensor A");
    Serial.print(flexPins[i] - A0);
    Serial.print(" | Valor lido: ");
    Serial.print(flexValue);
    Serial.print(" | Ângulo enviado: ");
    Serial.print(angle);
    Serial.print(" | Servo: ");
    Serial.println(i + 1);
  }

  Serial.println("-");
  delay(300);
}
