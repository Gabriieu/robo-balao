# 🤖 BaloonZord – Robô Bluetooth com ESP32

Este é um projeto de um robô controlado via Bluetooth utilizando um ESP32. O robô é capaz de se mover em diferentes direções e permite o controle de velocidade.

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


## 🧰 Hardware utilizado

- 1 placa ESP32
- 2 motores DC
- 1 ponte H (L298N)
- 1 fonte de alimentação 3V para o ESP32
- 1 fonte de alimentação 6V a 12V para os motores
- Opcional: antena
