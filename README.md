# Projeto: Sensor de Distância com Arduino, LEDs e Buzzer

## Descrição do Projeto

Este projeto utiliza um sensor ultrassônico para medir a distância de um objeto e aciona diferentes LEDs e um buzzer sonoro com base na proximidade detectada. O sistema é configurado com quatro níveis de alerta, onde LEDs são acionados sequencialmente, e o buzzer emite diferentes tons conforme o objeto se aproxima.

### Componentes Utilizados

- **Arduino UNO** ou qualquer outra placa compatível.
- **Sensor Ultrassônico HC-SR04** para medir a distância.
- **LEDs** (4 unidades) para indicação visual da proximidade.
- **Buzzer** para emitir som de alerta.
- **Resistores** de 220Ω para os LEDs.
- Fios de conexão e uma protoboard para montagem do circuito.

### Funcionamento

- O sensor ultrassônico mede a distância de um objeto.
- Dependendo da distância medida, LEDs são acesos e o buzzer emite sons de diferentes frequências:
  - **Entre 30 cm e 20 cm**: O primeiro LED é aceso, e o buzzer emite um som de 1500 Hz.
  - **Entre 20 cm e 10 cm**: Os dois primeiros LEDs são acesos, e o buzzer emite um som de 2000 Hz.
  - **Entre 10 cm e 5 cm**: Três LEDs são acesos, e o buzzer emite um som de 2750 Hz.
  - **Menor que 5 cm**: Todos os quatro LEDs são acesos, e o buzzer emite um som de 3000 Hz.

### Conexões de Hardware

- **Sensor Ultrassônico (HC-SR04)**:
  - **TRIGGER** -> Pino 7 no Arduino.
  - **ECHO** -> Pino 4 no Arduino.
- **LEDs**:
  - **LED 1** -> Pino 8 no Arduino.
  - **LED 2** -> Pino 6 no Arduino.
  - **LED 3** -> Pino 5 no Arduino.
  - **LED 4** -> Pino 3 no Arduino.
- **Buzzer**:
  - Conectado ao pino 2 no Arduino.
  
### Instruções de Uso

1. **Montagem**:
   - Monte o circuito conforme descrito nas conexões de hardware.
   - Utilize uma protoboard e os resistores para os LEDs.
   
2. **Programação**:
   - Abra o **Arduino IDE**.
   - Copie e cole o código fornecido no arquivo `.ino`.
   - Carregue o código na placa Arduino.

3. **Funcionamento**:
   - Após o upload do código, o sistema estará pronto para medir distâncias e acionar os LEDs e o buzzer de acordo com a proximidade do objeto.
   
4. **Monitor Serial**:
   - Abra o monitor serial na IDE do Arduino para ver a distância medida em tempo real.

### Melhorias Futuras

- Adicionar um display LCD para mostrar a distância medida.
- Ajustar os limites de distância conforme o uso prático.
- Implementar uma funcionalidade para desligar manualmente os alertas.


**Participações:** Iasmin Angel, Daniel Lucas, Lucas Santana e Kauan Nascimento. ( *Para uma equipe do coração* 🥰 )
