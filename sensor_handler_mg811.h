#ifndef SENSOR_HANDLER_MG811
#define SENSOR_HANDLER_MG811
#include <Adafruit_ADS1X15.h>
#include <ArduinoJson.h>
#include <Wire.h>
Adafruit_ADS1115 ads;

 // Definimos los rangos
 int rangoNormalMin = 300;
 int rangoNormalMax = 700;
 int rangoAdvertenciaMin = 701;
 int rangoAdvertenciaMax = 1000;

void initializeMG811() {
  Wire.begin();
  ads.begin();
}

float ReadMG811() {
 int16_t raw = ads.readADC_SingleEnded(0); // Lee el canal A0 (pin A0 en el módulo)
  float co2Value = raw * (2000.0 / 32767.0); // Ajusta el factor de conversión según las especificaciones del sensor
  Serial.print("Valor de CO2: ");
  Serial.println(co2Value);
  return co2Value;
}

void publicDataMG811(const char *sensorName) {
  float valueMG811 = ReadMG811();

   Serial.print("\n ************Sensor ");
  Serial.print(sensorName);
  Serial.println("************ \n");
  Serial.print("Concentración de CO: ");
  Serial.print(valueMG811);
  Serial.println(" ppm");
  
   String message;
 // Definir la escala en función del valor leído
  if (valueMG811 >= rangoNormalMin && valueMG811 <= rangoNormalMax) {
    message = "Nivel de CO2 normal";
  } else if (valueMG811 >= rangoAdvertenciaMin && valueMG811 <= rangoAdvertenciaMax) {
    message = "¡Advertencia! Nivel de CO2 elevado";
  } else {
    message = "¡Peligro! Nivel de CO2 muy alto";
  }
  Serial.println("message: " + message);

// Crear el objeto JSON
  StaticJsonDocument<256> jsonDocument;
  jsonDocument["sensor_id"] = "c4041cbf-2af9-49b7-a7ec-a1e023e8cb09";
  jsonDocument["CO2 (ppm):"] = valueMG811;
  jsonDocument["message"] = message;

  // Serializar el objeto JSON
  char msgBuffer[256];
  serializeJson(jsonDocument, msgBuffer);

    String topic = ("Salon/112/" + String(sensorName) + "/CO2");
  if (!PublishMqtt(msgBuffer,topic,2)) {
    Serial.println("**************************");
    Serial.println("Fallo al publicar los datos del sensor MG811");
    Serial.println("**************************");
  }
  delay(500);
}
#endif
