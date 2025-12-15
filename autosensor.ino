#include <Servo.h>

const int flexPins[5] = {A7, A6, A3, A2, A2};      // Sensores de flexão
const int servoPins[5] = {3, 5, 6, 10, 9};         // Pinos dos servos

Servo servos[5];

// Definindo os pinos dos botões
const int buttonPin1 = 2; // Botão 1
const int buttonPin2 = 4; // Botão 2

// Variável de estado dos botões
bool buttonState1 = false;
bool buttonState2 = false;

// Variável para alternar entre os modos
int currentMode = 1;  // 1 para o modo de leitura dos sensores, 2 para o modo de movimento dos servos

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void setup() {
  Serial.begin(9600);

  // Inicializar servos
  for (int i = 0; i < 5; i++) {
    servos[i].attach(servoPins[i]);
  }

  // Inicializar pinos dos botões
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);

  Serial.println("Iniciando leitura dos sensores...\n");
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void loop() {
  // Leitura dos botões
  buttonState1 = digitalRead(buttonPin1) == LOW;  // Botão 1 pressionado
  buttonState2 = digitalRead(buttonPin2) == LOW;  // Botão 2 pressionado
  
  // Se o botão 1 for pressionado, alterna para o modo de controle dos sensores
  if (buttonState1) {
    currentMode = 1;
    delay(200);  // Debounce simples
  }

  // Se o botão 2 for pressionado, alterna para o modo de movimento dos servos
  if (buttonState2) {
    currentMode = 2;
    delay(200);  // Debounce simples
  }

  // Modo 1: Leitura dos sensores e controle dos servos
  if (currentMode == 1) {
    for (int i = 4; i >= 0; i--) {
      delay(10);
      int flexValue = analogRead(flexPins[i]);
      int angle = 0;

      switch (i) {
        case 0:    //--------------------------------------------------------- Mínimo
          angle = map(flexValue, 5, 90, 40, 180);
          angle = constrain(angle, 40, 180);
          angle = 180 - angle; 
          break;

        case 1:    //--------------------------------------------------------- Anelar
          angle = map(flexValue, 5, 40, 30, 180);
          angle = constrain(angle, 30, 180);
          angle = 180 - angle; 
          break;
  
        case 2:    //--------------------------------------------------------- Médio
          angle = map(flexValue, 5, 90, 30, 180);
          angle = constrain(angle, 30, 180);
          angle = 180 - angle; 
          break;
      
        case 3:    //--------------------------------------------------------- Polegar
          angle = map(flexValue, 5, 90, 0, 150);
          angle = constrain(angle, 0, 150);
          break;
      
        case 4:    //--------------------------------------------------------- Indicador
          angle = map(flexValue, 5, 90, 0, 130);
          angle = constrain(angle, 0, 130);
          break;
      }

      servos[i].write(angle);

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
  
  // Modo 2: Movimento dos servos em um padrão de varredura
  if (currentMode == 2) {


    int graumaximo = 150;

    

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

    delay(2000);  // Pausa

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

    delay(2000);  // Pausa

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

    delay(2000);  // Pausa

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

    delay(2000);  // Pausa

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

    delay(2000);  // Pausa

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

    delay(2000);  // Pausa

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

    delay(2000);  // Pausa

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

    delay(2000);  // Pausa
  }
}
