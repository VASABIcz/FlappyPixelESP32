//
// Created by vasabi on 9/11/22.
//

#ifndef UNTITLED13_UTILS_H
#define UNTITLED13_UTILS_H

#include <WiFi.h>

/*
#define WIRE Wire

Adafruit_SSD1306 display;
httpd_handle_t server;

int posX, posY = 0;

esp_err_t upHandle(httpd_req_t *req) {
    posY-=4;
    return ESP_OK;
}

esp_err_t downHandle(httpd_req_t *req) {
    posY+=4;
    return ESP_OK;
}

esp_err_t rightHandle(httpd_req_t *req) {
    posX+=4;
    return ESP_OK;
}

esp_err_t leftHandle(httpd_req_t *req) {
    posX-=4;
    return ESP_OK;
}

httpd_uri_t upGet = {
        .uri      = "/up",
        .method   = HTTP_GET,
        .handler  = upHandle,
        .user_ctx = nullptr
};

httpd_uri_t downGet = {
        .uri      = "/down",
        .method   = HTTP_GET,
        .handler  = downHandle,
        .user_ctx = nullptr
};

httpd_uri_t rightGet = {
        .uri      = "/right",
        .method   = HTTP_GET,
        .handler  = rightHandle,
        .user_ctx = nullptr
};

httpd_uri_t leftGet = {
        .uri      = "/left",
        .method   = HTTP_GET,
        .handler  = leftHandle,
        .user_ctx = nullptr
};


void setupDisplay() {
    display = Adafruit_SSD1306(128, 32, &WIRE);
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // Address 0x3C for 128x32
    display.display();
    delay(1000);
    display.clearDisplay();
    display.display();

    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0,0);
    display.print("Connecting to SSID\n'adafruit':");
    display.print("connected!");
    display.println("IP: 10.0.1.23");
    display.println("Sending val #0");
    display.setCursor(0,0);
    display.display(); // actually display all of the above
    display.clearDisplay();
    display.display();
}

void setupConnectWiFi() {
    WiFi.begin("", ""); // TP-LINK_41D52A
    while (WiFi.status() != WL_CONNECTED) {
        delay(100);
        Serial.print(".");
    }
    WiFi.localIP().printTo(Serial);
}

void setupWebServer() {
    httpd_config_t config = HTTPD_DEFAULT_CONFIG();
    server = nullptr;

    if (httpd_start(&server, &config) == ESP_OK) {
        httpd_register_uri_handler(server, &upGet);
        httpd_register_uri_handler(server, &downGet);
        httpd_register_uri_handler(server, &rightGet);
        httpd_register_uri_handler(server, &leftGet);
    }
}

void displayTask(void* args) {
    setupDisplay();

    while (true) {
        display.clearDisplay();
        display.setCursor(posX,posY);
        display.print("X");
        display.display();
        delay(20);
    }
    vTaskDelete(nullptr);
}

void setup() {
    Serial.begin(115200);

    delay(2000);

    //setupApWiFi();
    setupConnectWiFi();
    setupWebServer();

    xTaskCreate(displayTask, "displayTask", 5000, nullptr, 1, nullptr);
}

void loop() {
    vTaskDelete(nullptr);
}
 */

void pinDebug() {
    pinMode(36, OUTPUT);
    digitalWrite(36, HIGH);
    pinMode(39, OUTPUT);
    digitalWrite(39, HIGH);
    pinMode(34, OUTPUT);
    digitalWrite(34, HIGH);
    pinMode(35, OUTPUT);
    digitalWrite(35, HIGH);
    pinMode(32, OUTPUT);
    digitalWrite(32, HIGH);
    pinMode(33, OUTPUT);
    digitalWrite(33, HIGH);
    pinMode(25, OUTPUT);
    digitalWrite(25, HIGH);
    pinMode(26, OUTPUT);
    digitalWrite(26, HIGH);
    pinMode(27, OUTPUT);
    digitalWrite(27, HIGH);
    pinMode(14, OUTPUT);
    digitalWrite(14, HIGH);
    pinMode(12, OUTPUT);
    digitalWrite(12, HIGH);
    pinMode(13, OUTPUT);
    digitalWrite(13, HIGH);

    pinMode(23, OUTPUT);
    digitalWrite(23, HIGH);
    pinMode(22, OUTPUT);
    digitalWrite(22, HIGH);
    pinMode(21, OUTPUT);
    digitalWrite(21, HIGH);
    pinMode(19, OUTPUT);
    digitalWrite(19, HIGH);
    pinMode(18, OUTPUT);
    digitalWrite(18, HIGH);
    pinMode(5, OUTPUT);
    digitalWrite(5, HIGH);
    pinMode(17, OUTPUT);
    digitalWrite(17, HIGH);
    pinMode(16, OUTPUT);
    digitalWrite(16, HIGH);
    pinMode(4, OUTPUT);
    digitalWrite(4, HIGH);
    pinMode(2, OUTPUT);
    digitalWrite(2, HIGH);
    pinMode(15, OUTPUT);
    digitalWrite(15, HIGH);
}

void setupApWiFi() {
    WiFi.softAP("test");
}

#endif //UNTITLED13_UTILS_H
