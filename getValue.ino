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
  /* Obtain last value from a variable as float using HTTP */
  float value = ubidots.get(DEVICE_LABEL, "myled");

  // Evaluates the results obtained
  if (value != ERROR_VALUE) {
    Serial.print("Value:");
    Serial.println(value);
  }
  delay(5000);
}
