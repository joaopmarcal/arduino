/*******************************************************************************
* RoboCore Arduino Pocket Kit - Servo Motor
* Posiciona o eixo do servo em função do potenciometro.
*******************************************************************************/
    
#include <Servo.h> // Inclui a biblioteca para servos motores

const int pot = A5; 
int leitura;

Servo servo_motor;  // Cria um objeto para o controle do servo

void setup() {
  pinMode(pot,INPUT);
  servo_motor.attach(9);  // Informa qual pino será usado para o servo declarado anteriormente
}

void loop() {
  leitura = analogRead(pot); // Faz a leitura do potenciometro
  leitura = map(leitura,0,1023,10,170); // Ajusta a posição do servomotor de acordo com o potenciometro
  servo_motor.write(leitura); // Informa ao servo a posição em função da leitura do potenciometro
  delay(100);
}