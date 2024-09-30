// Definindo os pinos dos LEDs, TRIGGER, ECHO e BUZZER
const int LED1 = 8;  // LED 1 conectado ao pino 8
const int LED2 = 6;  // LED 2 conectado ao pino 6
const int LED3 = 5;  // LED 3 conectado ao pino 5
const int LED4 = 3;  // LED 4 conectado ao pino 3
const int TRIGGER = 7;  // Pino TRIGGER do sensor ultrassônico
const int ECHO = 4;     // Pino ECHO do sensor ultrassônico
const int BUZZER = 2;   // Buzzer conectado ao pino 2

// Definindo constantes para o cálculo de distância e os limites de alerta
const float som = 34300.0;  // Velocidade do som em cm/s
const float limite1 = 30.0; // Limite de 30 cm para o primeiro alerta
const float limite2 = 20.0; // Limite de 20 cm para o segundo alerta
const float limite3 = 10.0; // Limite de 10 cm para o terceiro alerta
const float limite4 = 5.0;  // Limite de 5 cm para o alerta máximo

// Declaração das funções que serão usadas no programa
void desligarLEDs(); // Função para desligar os LEDs
void alertas(float distancia); // Função para acionar os alertas de LED e buzzer com base na distância
float calcularDistancia(); // Função que calcula a distância entre o sensor e um objeto
void inicializarTrigger(); // Função para inicializar o TRIGGER do sensor ultrassônico

// Função setup() que roda uma vez quando o Arduino é inicializado
void setup() {
    // Configuração dos pinos como saída (OUTPUT) ou entrada (INPUT)
    pinMode(LED1, OUTPUT);
    pinMode(LED2, OUTPUT);
    pinMode(LED3, OUTPUT);
    pinMode(LED4, OUTPUT);
    pinMode(ECHO, INPUT);
    pinMode(TRIGGER, OUTPUT);
    pinMode(BUZZER, OUTPUT);

    // Desliga os LEDs no início do programa
    desligarLEDs();
  
    // Inicia a comunicação Serial para monitoramento da distância no computador
    Serial.begin(9600);
}

// Função loop() que roda continuamente enquanto o Arduino está ligado
void loop() {
    // Inicializa o sensor ultrassônico (envia o sinal TRIGGER)
    inicializarTrigger();

    // Obtém a distância medida pelo sensor ultrassônico
    float distancia = calcularDistancia();

    // Desliga os LEDs antes de tomar qualquer ação
    desligarLEDs();

    // Se a distância for menor que o limite1, ativa os alertas correspondentes
    if (distancia < limite1) {
        alertas(distancia);
    }

    // Pequeno atraso para evitar leituras muito rápidas e garantir precisão
    delay(100);
}

// Função para desligar todos os LEDs
void desligarLEDs() {
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
}

// Função para gerenciar os alertas visuais (LEDs) e sonoros (buzzer) com base na distância
void alertas(float distancia) {
    // Se a distância estiver entre limite1 (30 cm) e limite2 (20 cm)
    if (distancia < limite1 && distancia >= limite2) {
        digitalWrite(LED1, HIGH); // Liga LED1
        tone(BUZZER, 1500, 50);   // Toca o buzzer com 1500Hz por 50ms
    }
    // Se a distância estiver entre limite2 (20 cm) e limite3 (10 cm)
    else if (distancia < limite2 && distancia >= limite3) {
        digitalWrite(LED1, HIGH);
        digitalWrite(LED2, HIGH); // Liga LED2 também
        tone(BUZZER, 2000, 100);  // Toca o buzzer com 2000Hz por 100ms
    }
    // Se a distância estiver entre limite3 (10 cm) e limite4 (5 cm)
    else if (distancia < limite3 && distancia >= limite4) {
        digitalWrite(LED1, HIGH);
        digitalWrite(LED2, HIGH);
        digitalWrite(LED3, HIGH); // Liga LED3 também
        tone(BUZZER, 2750, 150);  // Toca o buzzer com 2750Hz por 150ms
    }
    // Se a distância for menor que limite4 (5 cm)
    else if (distancia < limite4) {
        digitalWrite(LED1, HIGH);
        digitalWrite(LED2, HIGH);
        digitalWrite(LED3, HIGH);
        digitalWrite(LED4, HIGH); // Liga LED4 também
        tone(BUZZER, 3000, 200);  // Toca o buzzer com 3000Hz por 200ms
    }
}

// Função para calcular a distância utilizando o sensor ultrassônico
float calcularDistancia() {
    // Envia um pulso ultrassônico pelo ECHO e recebe o tempo de resposta
    unsigned long time = pulseIn(ECHO, HIGH);
    
    // Calcula a distância em cm com base no tempo e na velocidade do som
    float distancia = time * 0.000001 * som / 2.0;
    
    // Imprime a distância medida no monitor serial
    Serial.print(distancia);
    Serial.print(" cm");
    Serial.println();
    
    return distancia;
}

// Função para inicializar o TRIGGER do sensor ultrassônico
void inicializarTrigger() {
    digitalWrite(TRIGGER, LOW);      // Coloca o TRIGGER em LOW para limpar o sinal anterior
    delayMicroseconds(2);            // Pequeno atraso de 2 microssegundos
    digitalWrite(TRIGGER, HIGH);     // Sinal de TRIGGER em HIGH por 10 microssegundos para enviar o pulso
    delayMicroseconds(10);           // Atraso de 10 microssegundos
    digitalWrite(TRIGGER, LOW);      // Volta o TRIGGER para LOW
}
