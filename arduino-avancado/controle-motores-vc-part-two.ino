const int pwm = 3;
const int pot = A0;
int ValorLidoPot_Real = 0;
int ValorLidoPot_Mapeado = 0;

void setup(){
  Serial.begin(9600);
  pinMode(pwm, OUTPUT);
  pinMode(pot, INPUT);
} 

void loop(){
  ValorLidoPot_Real = analogRead(pot);
  ValorLidoPot_Mapeado = map(ValorLidoPot_Real, 0, 1023, 0, 255);
  analogWrite(pwm, ValorLidoPot_Mapeado); 
  Serial.println(ValorLidoPot_Mapeado);
}