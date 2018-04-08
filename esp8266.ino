#include "ESP8266WiFi.h"

const char* ssid = "YOUR WIFI NETWORK NAME";
const char* password = "YOUR WIFI PASSWARD";

void setup() {
    Serial.begin(9600);

    setupWiFi();
    
    pinMode(D0, OUTPUT);
    pinMode(D1, OUTPUT);
    pinMode(D2, OUTPUT);
    pinMode(D3, OUTPUT);

    digitalWrite(D0, HIGH);
    digitalWrite(D1, HIGH);
    digitalWrite(D2, HIGH);
    digitalWrite(D3, HIGH);
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
