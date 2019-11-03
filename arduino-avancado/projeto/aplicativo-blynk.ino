/*************************************************************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest

  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Follow us:                  http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************

  This example shows how to use ESP8266 Shield (with AT commands)
  to connect your project to Blynk.

  WARNING!
    It's very tricky to get it working. Please read this article:
    http://help.blynk.cc/hardware-and-libraries/arduino/esp8266-with-at-firmware

  Change WiFi ssid, pass, and Blynk auth token to run :)
  Feel free to apply it to any other example. It's simple!
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial


#include "ESP8266_Lib.h"
#include "BlynkSimpleShieldEsp8266.h"
#include <Servo.h> 
#include "DHT.h"
Servo servo_motor;
// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "tr0SUjcbp-z1gbviMXnyiMPUpz7sgfXh";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Net-Virtua-4057";
char pass[] = "3327140570";
//char ssid[] = "AndroidAP77EA";
//char pass[] = "wwpv7714";

// Hardware Serial on Mega, Leonardo, Micro...
//#define EspSerial Serial1

// or Software Serial on Uno, Nano...
#include "SoftwareSerial.h"
SoftwareSerial EspSerial(10, 11); // RX, TX

#define DHTPIN 7
#define DHTTYPE DHT11
DHT dht(DHTPIN,DHTTYPE);

BlynkTimer timerDHT11;
//BlynkTimer timerLDR;

// Your ESP8266 baud rate:
#define ESP8266_BAUD 9600

ESP8266 wifi(&EspSerial);

void lerSensorDHT11()
{
  float temperatura = dht.readTemperature();
  float umidade = dht.readHumidity();
  if(isnan(temperatura)|| isnan(umidade)){
    return;
  }
  Blynk.virtualWrite(V4, temperatura);
  Blynk.virtualWrite(V5, umidade);
}
/*
void lerLDR(){
  int valorLDR = analogRead(A1);
  valorLDR = map(valorLDR,0,1023,0,100);
  Blynk.virtualWrite(V6, valorLDR);
}
*/
void setup()
{
  // Debug console
  Serial.begin(9600);
  dht.begin();
  delay(10);

  // Set ESP8266 baud rate
  EspSerial.begin(ESP8266_BAUD);
  delay(10);

  Blynk.begin(auth, wifi, ssid, pass);

  timerDHT11.setInterval(2000L, lerSensorDHT11);
  //timerLDR.setInterval(100L, lerLDR);
  
}

void loop()
{
  Blynk.run();
  timerDHT11.run();
  //timerLDR.run();
}
