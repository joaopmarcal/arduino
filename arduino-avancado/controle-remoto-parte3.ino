#include "IRremote.h"

const int RECV_PIN = 11;
IRrecv irrecv(RECV_PIN);
decode_results results;
const int rele = 12;

void setup()
{
  pinMode(rele, OUTPUT);
  digitalWrite(rele, LOW);
  Serial.begin(9600);
  irrecv.enableIRIn(); //começa a receber
}

void loop() {
  if (irrecv.decode(&results)) {
    //Serial.println(results.value, HEX);
  
  if (results.value == 0xFF30CF){
      Serial.println("liga"); 
      digitalWrite(rele, HIGH);
    }
  if (results.value == 0xFF18E7){
      Serial.println("desliga"); 
      digitalWrite(rele, LOW);
    }
   
    irrecv.resume(); // Recebe o próximo valor
  }
}