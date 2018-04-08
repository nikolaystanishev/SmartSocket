#include "ESP8266WiFi.h"
#include <ESP8266WebServer.h>

const char* ssid = "YOUR WIFI NETWORK NAME";
const char* password = "YOUR WIFI PASSWARD";

ESP8266WebServer server(80);

void setup() {
    Serial.begin(9600);

    setupWiFi();
    startServer();

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
    server.handleClient();
}

void setupWiFi() {
    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println("");
    Serial.print("WiFi connected to: ");
    Serial.println(ssid);
    Serial.print("IP Adress: ");
    Serial.println(WiFi.localIP());
}

void startServer() {
    server.on("/", HTTP_POST, std::bind(&handler));

    server.begin();
    Serial.println("HTTP server started.");
}

void handler() {
    int pin = atoi(server.arg("pin").c_str());
    int value = atoi(server.arg("value").c_str());

    Serial.println(pin);
    Serial.println(value);
    server.send(200);
}
