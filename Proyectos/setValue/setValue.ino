/****************************************
* Include Libraries
****************************************/

#include "Ubidots.h"

/****************************************
* Define Instances and Constants
****************************************/   
 
const char* UBIDOTS_TOKEN = "BBFF-e2mfAslWVRP96PMzPZ6cHNzFoQtSJU";  // Put here your Ubidots TOKEN
const char* WIFI_SSID = "Juan";      // Put here your Wi-Fi SSID
const char* WIFI_PASS = "abcd1234*";      // Put here your Wi-Fi password 
const char* DEVICE_LABEL = "Ejemplo";   //Put here your device label

Ubidots ubidots(UBIDOTS_TOKEN, UBI_HTTP);

/****************************************
* Auxiliar Functions
****************************************/

// Put here your auxiliar functions

/****************************************
* Main Functions
****************************************/  

void setup() {                       

  Serial.begin(115200);
  ubidots.wifiConnect(WIFI_SSID, WIFI_PASS);
  // ubidots.setDebug(true);  // Uncomment this line for printing debug  messages                     
}

void loop() {

  float value1 = random(16, 33);
  ubidots.add("mypot", value1);// Change for your variable name  
  
  bool bufferSent = false;
  bufferSent = ubidots.send(DEVICE_LABEL); // Will send data to a device label that matches the device Id

  if (bufferSent) {
  // Do something if values were sent properly
   Serial.println("Values sent by the device");
  }
  delay(5000);
}
