# 🤖 BaloonZord – Robô Bluetooth com ESP32

Este é um projeto de um robô controlado via Bluetooth utilizando um ESP32. O robô é capaz de se mover em diferentes direções, ajustar sua velocidade e realizar giros de 90 graus com velocidade fixa.

## 📱 Funcionalidades

- Controle por comandos Bluetooth (usando celular ou computador)
- Movimentos: frente, trás, esquerda, direita e parar
- Giro preciso de 90° (esquerda ou direita) com velocidade fixa
- Ajuste da velocidade geral via comando

## 🎮 Comandos via Bluetooth

| Comando | Descrição                          |
|--------|------------------------------------|
| `F`    | Frente                             |
| `T`    | Trás                               |
| `E`    | Esquerda                           |
| `D`    | Direita                            |
| `P`    | Parar                              |
| `V###;`| Define a velocidade (ex: `V200;`)  |
| `V90;E;` | Girar 90° para a esquerda        |
| `V90;D;` | Girar 90° para a direita         |

## 🧠 Lógica de funcionamento

- Os motores são controlados via PWM nos pinos `ENA` e `ENB`.
- O tempo de giro de 90° é calibrado com base na velocidade fixa (200).
- Após `200 ms` sem receber comandos, o robô para automaticamente.
- A comunicação Bluetooth é feita através da biblioteca `BluetoothSerial`.

## 🧰 Hardware necessário

- ESP32
- 2 motores DC com driver ponte H (L298N, por exemplo)
- Fonte de alimentação (bateria)
- Jumpers, protoboard, fios
- Opcional: buzzer, LED, sensores (ultrassom, IR)

## 📌 Pinos utilizados

| Função   | Pino ESP32 |
|----------|------------|
| M1_IN1   | 32         |
| M1_IN2   | 33         |
| M2_IN1   | 25         |
| M2_IN2   | 26         |
| ENA      | 27         |
| ENB      | 14         |
| LED      | 2 (padrão) |

## 🚀 Como usar

1. Faça upload do código para o ESP32 via Arduino IDE.
2. Emparelhe o dispositivo Bluetooth com seu celular/computador.
3. Use um app como **Serial Bluetooth Terminal** para enviar comandos.
4. Controle o robô com os comandos listados acima.

## 🛠️ Próximas melhorias

- Sensor ultrassônico para evitar obstáculos
- Controle por aplicativo com interface gráfica
- Feedback por som e LED
- Giros calibrados com giroscópio (MPU6050)

---

Feito com ❤️ e muita vontade de ver robôs andando por aí.
