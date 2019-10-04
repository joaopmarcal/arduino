/*******************************************************************************
* RoboCore Kit Iniciante V8 - Trabalhando com Gráficos 1
* Imprime na Serial o valor de tensão na saída do potenciômetro.
*******************************************************************************/

const int pinoPotenciometro = A0; // pino onde o potenciometro está conectado
int leitura = 0; // variável para armazenar o valor lido pelo ADC
float tensao = 0.0; // variável para armazenar a tensão

void setup() {
  // Inicia e configura a Serial
  Serial.begin(9600); // 9600 bps

  // configura o pino com potenciometro como entrada
  pinMode(pinoPotenciometro, INPUT); // pino A0
}

void loop() {
  // le o valor de tensão no pino do potenciometro
  leitura = analogRead(pinoPotenciometro);

  // converte e imprime o valor em tensão elétrica
  tensao = leitura * 5.0 / 1023.0;

  // imprime valor no plotter serial
  Serial.println(tensao);
  
  delay(100); // aguarda 100 milissegundos para uma nova leitura
}