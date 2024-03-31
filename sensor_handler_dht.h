#ifndef SENSOR_HANDLER_DHT
#define SENSOR_HANDLER_DHT
#include <ArduinoJson.h>
#include <DHT.h>
#include <DHT_U.h>

#define D5 14   // Pin D1 para el DHT11
#define D4 2   // Pin D2 para el DHT21

DHT dht(D5, DHT11);
DHT dht2(D4, DHT21);

void initializeDHT() {
  dht.begin();
  dht2.begin();
}

void readDHT(DHT &sensor, const char *sensorName)  {
  
  float temperature = sensor.readTemperature();
  float humidity = sensor.readHumidity();
  
  Serial.print("\n ************Sensor ");
  Serial.print(sensorName);
  Serial.println("************ \n");

  if (!isnan(temperature) && !isnan(humidity)) {
     float temperatureFahrenheit = (temperature * 9.0 / 5.0) + 32.0;
      Serial.print("Tem(°C): ");
      Serial.println(temperature);
      Serial.print("Tem(°F): ");
      Serial.println(temperatureFahrenheit);
      Serial.print("Humedad: ");
      Serial.println(humidity);

// Crear el objeto JSON
    StaticJsonDocument<256> jsonDocument;
    jsonDocument["sensor_id"] = "ff9f61e0-205d-4331-823d-6cea00f4873a";
    jsonDocument["temperatura (°C):"] = temperature;
    jsonDocument["temperatura (°F):"] = temperatureFahrenheit;
   jsonDocument["humedad"] = humidity;

    // Serializar el objeto JSON
  char msgBuffer[256];
  serializeJson(jsonDocument, msgBuffer);
  
String topic = ("Salon/112/"+ String(sensorName) +"/TH");

    if (PublishMqtt(msgBuffer, topic, 2 )) {
      Serial.println("Mensaje publicado con éxito");
    }else {
    Serial.println("**************************");
    Serial.println("Fallo al publicar los datos del sensor" + String(sensorName));
    Serial.println("**************************");
  }
  } else {
    Serial.println("**************************");
    Serial.println("Fallo al leer los datos del sensor DHT");
    Serial.println("**************************");
  }
}
#endif // SENSOR_HANDLER_DHT
