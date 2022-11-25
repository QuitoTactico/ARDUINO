/*
 * PROYECTO FINAL IOT [ELECTRÓNICA] -  HECHO POR:
 * - Esteban Vergara Giraldo
 * - Moisés Arrieta Hernandez
 * - Laura Danniela Zárate Guerrero
 */

#include "Ubidots.h"

const int sensorLuzAmbiente = A0;   //DEFINICIÓN DEL PIN ANÁLOGO DEL NodeMCU

const char* UBIDOTS_TOKEN = "BBFF-rxrFyfTzk2UwkIDIUzLIvOod1z5iDG";  // Put here your Ubidots TOKEN
const char* WIFI_SSID = "Galaxy S20 FE";      // Put here your Wi-Fi SSID
const char* WIFI_PASS = "Enero1890.";      // Put here your Wi-Fi password
const char* DEVICE_LABEL = "proyecto";   //Put here your device label

Ubidots ubidots(UBIDOTS_TOKEN, UBI_HTTP);

unsigned int LUZ = 0;
bool CERRARCORTINA;  // true = Cierra la cortina | false = Abre la cortina

void setup() {  
  Serial.begin(115200);

  // Que se conecte a wifi
  ubidots.wifiConnect(WIFI_SSID, WIFI_PASS);
  ubidots.setDebug(true);  // Uncomment this line for printing debug  messages    
}

void loop() {
  LUZ = analogRead(sensorLuzAmbiente);

  if(LUZ >= 300){
    CERRARCORTINA = true;
  }else if (LUZ < 300 and LUZ >= 100){
    CERRARCORTINA = false;
  }else{
    CERRARCORTINA = true;
  }

  // OUTPUT EN UBIDOTS
  Serial.print(LUZ);
  if(CERRARCORTINA){
    Serial.println(" Cortina Cerrada"); 
  }else{
    Serial.println(" Cortina Abierta"); 
  }
  
  ubidots.add("medicion", LUZ);
  ubidots.add("cortina", CERRARCORTINA);


  // VERIFICA SI SE MANDARON LOS DATOS
  bool bufferSent = false;
  bufferSent = ubidots.send(DEVICE_LABEL);

  if (bufferSent) {
    Serial.println("[ DATOS ENVIADOS CORRECTAMENTE ]");
  }
  delay(200);
}
