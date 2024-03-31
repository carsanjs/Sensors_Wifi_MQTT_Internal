#ifndef SENSOR_HANDLE_KY018
#define SENSOR_HANDLE_KY018
#include <ArduinoJson.h>

int ADCO = A0;
int value, data;

const int THRESHOLD_POOR = 1000;
const int THRESHOLD_FAIR = 800;
const int THRESHOLD_MODERATE = 600;
const int THRESHOLD_GOOD = 400;
const int THRESHOLD_EXCELLENT = 200;

void readLRDSensor(const char *sensorName) {

  if (value != -1) {
    value = analogRead(ADCO);
    data = map(value, 0, 1023, 0, 255);
    Serial.print("\n ************Sensor ");
    Serial.print(sensorName);
    Serial.println("************ \n");
    Serial.println("Valor del sensor LDR data: " + String(data) + "Valor del sensor LDR value: " + String(value));
    String lightMessage;

    if (data < THRESHOLD_EXCELLENT) {
      lightMessage = "Muy bien iluminado";
    } else if (data < THRESHOLD_GOOD) {
      lightMessage = "Bien iluminado";
    } else if (data < THRESHOLD_MODERATE) {
      lightMessage = "Moderadamente iluminado";
    } else if (data < THRESHOLD_FAIR) {
      lightMessage = "Oscuro";
    } else if (data < THRESHOLD_POOR) {
      lightMessage = "Muy oscuro";
    } else {
      lightMessage = "Extremadamente oscuro";
    }

    Serial.println(lightMessage);

    //  // Crear el objeto JSON
    StaticJsonDocument<256> jsonDocument;
    jsonDocument["sensor_id"] = "070a1701-eb44-4f92-b251-9ec0e41a3b47";
    jsonDocument["ldr"] = data;
    jsonDocument["mensaje"] = lightMessage;
    
    char msgBuffer[256];
    serializeJson(jsonDocument, msgBuffer);

    String topic = ("Salon/112/"+ String(sensorName) +"/Ldr");

    if (!PublishMqtt(msgBuffer, topic, 2)) {
      Serial.println("**************************");
      Serial.println("Fallo al publicar los datos del sensor LDR en MQTT");
      Serial.println("**************************");
    }

  }
  else {
    Serial.println("**************************");
    Serial.println("Fallo al leer los datos del sensor LDR");
    Serial.println("**************************");
  }
  delay(100);
}
#endif
