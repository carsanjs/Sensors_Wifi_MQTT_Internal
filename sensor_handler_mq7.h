#ifndef SENSOR_HANDLER_MQ7
#define SENSOR_HANDLER_MQ7
#include <Adafruit_ADS1X15.h>
#include <ArduinoJson.h>
#include <Wire.h>
Adafruit_ADS1115 ads1;

void initializeMQ7() {
  Wire.begin();
  ads1.begin();
}

float readMQ7() {
  // Lectura del valor analógico del sensor MQ-7
  int16_t raw = ads1.readADC_SingleEnded(1); // Lee el canal A1 (pin A1 en el módulo)

  // Conversión del valor leído a ppm (partes por millón)
  float ppm = raw * (1800.0 / 32767.0); // Ajusta el factor de conversión según las especificaciones del sensor

  return ppm;
}

void publicDataMQ7(const char *sensorName) {
  float valueMQ7 = readMQ7();

  Serial.print("\n ************Sensor ");
  Serial.print(sensorName);
  Serial.println("************ \n");

  Serial.print("Concentración de C0: ");
  Serial.print(valueMQ7);
  Serial.println(" ppm");
  String message;
  if (valueMQ7 < 100) {
    message = "Nivel de CO bajo";
  } else if (valueMQ7 < 500) {
    message = "Nivel de CO moderado";
  } else if (valueMQ7 < 1000) {
    message = "Nivel de CO alto";
  } else {
    message = "Nivel de CO muy alto";
  }
   Serial.println("message C0" + message);
  ;
  // Crear el objeto JSON
  StaticJsonDocument<256> jsonDocument;
  jsonDocument["sensor_id"] = "1d80fb2d-3ad2-4dbf-b340-800ed9f9c849";
  jsonDocument["CO (ppm):"] = valueMQ7;
  jsonDocument["message"] = message;

  // Serializar el objeto JSON
  char msgBuffer[256];
  serializeJson(jsonDocument, msgBuffer);

  String topic = ("Salon/112/" + String(sensorName) + "/CO");
  if (!PublishMqtt(msgBuffer, topic, 2)) {
    Serial.println("**************************");
    Serial.println("Fallo al publicar los datos del sensor MQ-7 en MQTT");
    Serial.println("**************************");
  }
  delay(500);
}
#endif
