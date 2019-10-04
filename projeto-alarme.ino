/*******************************************************************************
* Kit Iniciante para Arduino v8 - Utilizando o DHT11
* Mostrar os valores de Tempartura e Umidade no Monitor Serial.
*******************************************************************************/

// Inclui a biblioteca DHT que possui as funções dos sensores do tipo DHT
#include "DHT.h"

// Define os pinos de cada componente conectado
const int pino_dht = 9; // DHT
const int pinoLEDR = 11; // LED RGB (vermelho)
const int pinoLEDG = 12; // LED RGB (verde)
const int pinoLEDB = 13; // LED RGB (azul)
const int pinoBuzzer = 10; // buzzer

// variável para armazenar o valor de temperatura e umidade
float temperatura; 
float umidade;

DHT dht(pino_dht, DHT11); // define o pino e o tipo de DHT

void setup() {
  dht.begin(); // inicializa o sensor DHT

  // Configura os pinos dos LEDs e buzzer
  pinMode(pinoLEDB, OUTPUT);
  pinMode(pinoLEDG, OUTPUT);
  pinMode(pinoLEDR, OUTPUT);
  pinMode(pinoBuzzer, OUTPUT);
}

void loop() {
  // Aguarda alguns segundos entre uma leitura e outra
  delay(2000); // 2 segundos (Datasheet)

  // A leitura da temperatura ou umidade pode levar 250ms
  // O atraso do sensor pode chegar a 2 segundos
  temperatura = dht.readTemperature(); // lê a temperatura em Celsius
  umidade = dht.readHumidity(); // lê a umidade
  
  // Se ocorreu alguma falha durante a leitura
  if (isnan(umidade) || isnan(temperatura)) {
    // Acende branco
    digitalWrite(pinoLEDR, HIGH);
    digitalWrite(pinoLEDG, HIGH);
    digitalWrite(pinoLEDB, HIGH);
  }
  else { // Se não
    
    if (temperatura > 35 || temperatura < 15) {
      // Acende vermelho e aciona buzzer a 2000Hz
      digitalWrite(pinoLEDR, HIGH);
      digitalWrite(pinoLEDG, LOW);
      digitalWrite(pinoLEDB, LOW);
      tone(pinoBuzzer, 2000);
      delay(1000);
    }
    else if (temperatura > 30 || temperatura < 20) {
      // Acende azul e aciona buzzer a 1000Hz
      digitalWrite(pinoLEDR, LOW);
      digitalWrite(pinoLEDG, LOW);
      digitalWrite(pinoLEDB, HIGH);
      tone(pinoBuzzer, 1000);
      delay(500);
    }
    else {
      // Acende verde
      digitalWrite(pinoLEDR, LOW);
      digitalWrite(pinoLEDG, HIGH);
      digitalWrite(pinoLEDB, LOW);
    }

    // Desliga o buzzer
    noTone(pinoBuzzer);
  }
}