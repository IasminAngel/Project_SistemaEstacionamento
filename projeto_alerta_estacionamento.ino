const int LED1 = 8; 
const int LED2 = 6;
const int LED3 = 5;
const int LED4 = 3;
const int TRIGGER = 7;
const int ECHO = 4;
const int BUZZER = 2;

const float som = 34300.0;  
const float limite1 = 30.0;
const float limite2 = 20.0;
const float limite3 = 10.0;
const float limite4 = 5.0;

void desligarLEDs();
void alertas(float distancia);
float calcularDistancia();
void inicializarTrigger();

void setup() {
   
    pinMode(LED1, OUTPUT);
    pinMode(LED2, OUTPUT);
    pinMode(LED3, OUTPUT);
    pinMode(LED4, OUTPUT);
    pinMode(ECHO, INPUT);
    pinMode(TRIGGER, OUTPUT);
    pinMode(BUZZER, OUTPUT);

    // Desliga os LEDs no início
    desligarLEDs();
  
  	Serial.begin(9600);
  
}

void loop() {
    // Inicializa o sensor ultrassônico
    inicializarTrigger();

    // Obtém a distância
    float distancia = calcularDistancia();

    // Desliga os LEDs antes de avaliar a distância
    desligarLEDs();

    // Aciona os alertas conforme a distância
    if (distancia < limite1) {
        alertas(distancia);
    }

    delay(100);
}

// Função para desligar todos os LEDs
void desligarLEDs() {
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
}

// Função para gerenciar os alertas de LEDs e som
void alertas(float distancia) {
    // Se a distância estiver entre o limite1 e o limite2
    if (distancia < limite1 && distancia >= limite2) {
        digitalWrite(LED1, HIGH);
        tone(BUZZER, 1500, 50);
    }
    // Se a distância estiver entre o limite2 e o limite3
    else if (distancia < limite2 && distancia >= limite3) {
        digitalWrite(LED1, HIGH);
        digitalWrite(LED2, HIGH);
        tone(BUZZER, 2000, 100);
    }
    // Se a distância estiver entre o limite3 e o limite4
    else if (distancia < limite3 && distancia >= limite4) {
        digitalWrite(LED1, HIGH);
        digitalWrite(LED2, HIGH);
        digitalWrite(LED3, HIGH);
        tone(BUZZER, 2750, 150);
    }
    // Se a distância for menor que o limite4
    else if (distancia < limite4) {
        digitalWrite(LED1, HIGH);
        digitalWrite(LED2, HIGH);
        digitalWrite(LED3, HIGH);
        digitalWrite(LED4, HIGH);
        tone(BUZZER, 3000, 200);
    }
}

// Função para calcular a distância com o sensor ultrassônico
float calcularDistancia() {
    unsigned long time = pulseIn(ECHO, HIGH);
    float distancia = time * 0.000001 * som / 2.0; // Calcula a distância em cm
    Serial.print(distancia);
    Serial.print(" cm");
    Serial.println();
    return distancia;
}

// Função para inicializar o pulso do TRIGGER
void inicializarTrigger() {
    digitalWrite(TRIGGER, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIGGER, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIGGER, LOW);
}