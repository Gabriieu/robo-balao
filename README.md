# 🤖 BaloonZord – Robô Bluetooth com ESP32

Este é um projeto de um robô controlado via Bluetooth utilizando um ESP32. O robô é capaz de se mover em diferentes direções, ajustar sua velocidade e realizar giros de 90 graus com velocidade fixa.

## 📱 Funcionalidades

- Controle por comandos Bluetooth via celular
- Movimentos: frente, atrás, esquerda e direita
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

## 🧠 Lógica de funcionamento

- Os motores são controlados via PWM nos pinos `ENA` e `ENB`.
- A comunicação Bluetooth é feita através da biblioteca `BluetoothSerial`.

## 🧰 Hardware utilizado

- Placa ESP32
- 2 motores DC com driver ponte H (L298N)
- Fonte de alimentação (bateria)
- Jumpers, protoboard, fios
- Opcional: antena
