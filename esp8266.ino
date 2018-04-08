#include "ESP8266WiFi.h"

const char* ssid = "YOUR WIFI NETWORK NAME";
const char* password = "YOUR WIFI PASSWARD";

void setup() {
    Serial.begin(9600);

    setupWiFi();
}

void loop() {

}

void setupWiFi() {
    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    
    Serial.println("");
    Serial.println("WiFi connected");
    Serial.print("IP Adress: ");
    Serial.println(WiFi.localIP());
}
