/*******************************************************************************
* RoboCore Kit Iniciante V8 - 16. - Pisca-Pisca 2
* Usar um potenciômetro para controlar a intensidade de um LED.
*******************************************************************************/

const int pinoPotenciometro = A0; // pino onde o pontenciômetro está conectado
const int pinoLED = 11; // pino onde o LED está conectado
int leitura = 0; // variável para armazenar o valor lido pelo ADC
int pwm = 0; // variável para armazenar o valor da razão cíclica (duty cycle) 

void setup() {
  pinMode(pinoPotenciometro, INPUT); // configura o pino com potenciômetro como entrada
  pinMode(pinoLED, OUTPUT); // configura o pino com o LED como saída
}

void loop() {
  // le o valor de tensão no pino do potenciômetro
  leitura = analogRead(pinoPotenciometro);
  
  // converte o valor do potenciômetro, de 0 a 1023, em um valor de 0 a 255
  pwm = map(leitura, 0, 1023, 0, 255); 
  
  // atualiza a razão cíclica do pino 11, variando a intensidade do LED
  analogWrite(pinoLED, pwm);
  
}