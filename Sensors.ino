#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <WiFiClient.h>

#include "config.h"
#include "MQTT.hpp"
#include "ESP8266_Utils.hpp"
#include "ESP8266_Utils_MQTT_Async.hpp"
#include "sensor_handler_mg811.h" // archivo de la funcion del sensor de dioxido de carbono
#include "sensor_handler_dht.h"  //archivo de las funciones con los sensores dht11, dht22
#include "sensor_handle_ky018.h"  //archivo de las funciones con el fotoresistor LDR
#include "sensor_handler_mq7.h"  //archivo de las funciones con el sensor oxigeno MQ-7

#define D0 16  // Pin D0 para el LED 
void setup() {
//  inializedledwifi();
  pinMode(D0, OUTPUT);
  initializeDHT();
  initializeMG811();
  initializeMQ7();
  Serial.begin(9600);
  SPIFFS.begin();
  
  ConnectWiFi_STA(true);
  // Conecta MQTT en el setup
 InitMqtt();
}

void loop() {
  blinkLED(100);
  HandleMqtt();
  delay(100);
  readLRDSensor("LDR");
  readDHT(dht,"DHT11");
  readDHT(dht2,"DHT21");
  publicDataMQ7("MQ7");
publicDataMG811("MG811");
}

void blinkLED(int duration) {
  digitalWrite(D0, HIGH);
  delay(duration / 2);
  digitalWrite(D0, LOW);
  delay(duration / 2);
}
