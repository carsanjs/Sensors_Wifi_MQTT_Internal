
### Instrucciones para Configurar y Ejecutar el Código en Arduino 🛠️
Para ejecutar este código, sigue los pasos a continuación:

## Descarga e instala Arduino IDE 🖥️, preferiblemente la version Arduino IDE 1.8.19
#link: (https://www.arduino.cc/en/software).

### Abre el Código en Arduino IDE 📝
Una vez que hayas descargado e instalado todas las bibliotecas necesarias y configurado el ESP8266 en Arduino IDE, abre el programa y carga los archivos proporcionados en tu repositorio. Los archivos que necesitas abrir son:

### Instala las Bibliotecas Necesarias 📚
Antes de abrir el código en Arduino IDE, necesitas instalar algunas bibliotecas adicionales. Abre Arduino IDE, ve a Sketch -> Incluir Biblioteca -> Administrar Bibliotecas... y busca las siguientes bibliotecas:

#ESP8266WiFi

#PubSubClient

#Adafruit_ADS1X15

#DHT sensor library (by adafruit)

#ArduinoJson (by Benoit Blanchon)

Instala estas bibliotecas si aún no están presentes en tu Arduino IDE.

##Configura el ESP8266 en Arduino IDE 🔌
Para poder cargar el código en un ESP8266, necesitas agregar el siguiente enlace a la configuración adicional de "Gestor de URLs Adicionales de Tarjetas" en Arduino IDE:
#link:(https://arduino.esp8266.com/stable/package_esp8266com_index.json)

Para hacer esto, ve a Archivo -> Preferencias en Arduino IDE, y en el campo Gestor de URLs Adicionales de Tarjetas, añade el enlace proporcionado arriba.

## Conecta tu Placa ESP8266 y Selecciona el Puerto 🛰️
Conecta tu placa ESP8266 a tu computadora mediante un cable USB. Luego, selecciona el puerto correcto en Arduino IDE haciendo clic en Herramientas -> Puerto y seleccionando el puerto al que está conectada tu placa.


## Compila y Carga el Código en tu Placa ESP8266 🚀
Una vez que hayas seleccionado el puerto correcto, simplemente haz clic en el botón "Verificar" (ícono de tilde) para compilar el código. Si la compilación se realiza con éxito, haz clic en el botón "Cargar" (ícono de flecha hacia la derecha) para cargar el código en tu placa ESP8266.

## Observa la Ejecución del Código 🧐
Una vez cargado el código en tu placa ESP8266, observa la ejecución del mismo. Asegúrate de tener correctamente conectados todos los sensores y dispositivos según lo especificado en el código.

¡Eso es todo! Ahora deberías poder ejecutar el código proporcionado en tu placa Arduino sin problemas. Si encuentras algún problema, revisa la consola de Arduino IDE para obtener mensajes de error y realiza las correcciones necesarias en el código.

## Screenshots
#Dht11
![App Screenshot](https://bconsultors.com/wp-content/uploads/2019/05/dht11_ok.jpg)

#ky018
![App Screenshot](https://alltopnotch.co.uk/wp-content/uploads/imported/0/KY-018-Photoresistor-Sensor-Module-LDR-Light-Dependant-Resistor-Arduino-AVR-PIC-362134212140-1080x1080.jpg)

#MG811
![App Screenshot](https://5.imimg.com/data5/SELLER/Default/2023/10/352213590/FS/OL/IE/68547091/mg811-carbon-dioxide-co2-sensor-module-fr-01-679-500x500.webp)

#MQ7
![App Screenshot](https://5.imimg.com/data5/OO/XV/MY-1471353/mq-7-co-gas-sensors-module-500x500.jpg)

#Dht21
![App Screenshot](https://www.makershop.de/wp-content/uploads/2015/12/dht21-dht22-aussen-outdoor-arduino-raspberry-pi-1.jpg)