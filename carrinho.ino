#include "BluetoothSerial.h"

#define M1_IN1 32
#define M1_IN2 33
#define M2_IN1 25
#define M2_IN2 26
#define ENA 27
#define ENB 14
#define LED_BUILTIN 2

BluetoothSerial SerialBT;

int velocidade = 255;
int tempoGiro = 115;
unsigned long tempoUltimoComando = 0;
unsigned long tempoLimite = 200;
bool motoresAtivos = false;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("BaloonZord");

  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(M1_IN1, OUTPUT);
  pinMode(M1_IN2, OUTPUT);
  pinMode(M2_IN1, OUTPUT);
  pinMode(M2_IN2, OUTPUT);

  ledcSetup(0, 1000, 8);
  ledcSetup(1, 1000, 8);
  ledcAttachPin(ENA, 0);
  ledcAttachPin(ENB, 1);

  parar();
}

void loop() {
  while (SerialBT.available()) {
    char c = SerialBT.read();

    if (c == 'V') {
      String valor = SerialBT.readStringUntil(';');
      int novaVel = valor.toInt();
      if (novaVel >= 0 && novaVel <= 255) {
        velocidade = novaVel;
        Serial.println("Velocidade: " + String(velocidade));
      }
    } else if (c == 'G') {
      String valor = SerialBT.readStringUntil(';');
      int novoTempo = valor.toInt();
      if (novoTempo >= 30 && novoTempo <= 500) {  // limitar tempo entre 30ms e 500ms
        tempoGiro = novoTempo;
        Serial.println("Tempo de giro atualizado: " + String(tempoGiro) + " ms");
      }
    } else {
      tempoUltimoComando = millis();
      motoresAtivos = true;
      switch (c) {
        case 'F': frente(); break;
        case 'T': tras(); break;
        case 'D': direita(); break;
        case 'E': esquerda(); break;
        case 'P':
          parar();
          motoresAtivos = false;
          break;
        case 'I':
          virar90('I');
          break;
        case 'O':
          virar90('O');
          break;
      }
    }
  }

  if (motoresAtivos && millis() - tempoUltimoComando > tempoLimite) {
    parar();
    motoresAtivos = false;
  }
}

// ---- Funções de movimento ----
void frente() {
  digitalWrite(M1_IN1, HIGH);
  digitalWrite(M1_IN2, LOW);
  digitalWrite(M2_IN1, HIGH);
  digitalWrite(M2_IN2, LOW);
  ledcWrite(0, velocidade);
  ledcWrite(1, velocidade);
}

void tras() {
  digitalWrite(M1_IN1, LOW);
  digitalWrite(M1_IN2, HIGH);
  digitalWrite(M2_IN1, LOW);
  digitalWrite(M2_IN2, HIGH);
  ledcWrite(0, velocidade);
  ledcWrite(1, velocidade);
}

void esquerda() {
  digitalWrite(M1_IN1, HIGH);
  digitalWrite(M1_IN2, LOW);
  digitalWrite(M2_IN1, LOW);
  digitalWrite(M2_IN2, HIGH);
  ledcWrite(0, velocidade);
  ledcWrite(1, velocidade);
}

void direita() {
  digitalWrite(M1_IN1, LOW);
  digitalWrite(M1_IN2, HIGH);
  digitalWrite(M2_IN1, HIGH);
  digitalWrite(M2_IN2, LOW);
  ledcWrite(0, velocidade);
  ledcWrite(1, velocidade);
}

void parar() {
  digitalWrite(M1_IN1, LOW);
  digitalWrite(M1_IN2, LOW);
  digitalWrite(M2_IN1, LOW);
  digitalWrite(M2_IN2, LOW);
  ledcWrite(0, 0);
  ledcWrite(1, 0);
}

void virar90(char lado) {
  const int velocidadeGiro = 255;

  if (lado == 'I') {
    digitalWrite(M1_IN1, HIGH);
    digitalWrite(M1_IN2, LOW);
    digitalWrite(M2_IN1, LOW);
    digitalWrite(M2_IN2, HIGH);
  } else if (lado == 'O') {
    digitalWrite(M1_IN1, LOW);
    digitalWrite(M1_IN2, HIGH);
    digitalWrite(M2_IN1, HIGH);
    digitalWrite(M2_IN2, LOW);
  } else {
    return;
  }

  ledcWrite(0, velocidadeGiro);
  ledcWrite(1, velocidadeGiro);
  delay(tempoGiro);

  parar();
}
