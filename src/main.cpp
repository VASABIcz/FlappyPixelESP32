#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "flappyBird.h"

Adafruit_SSD1306 display = Adafruit_SSD1306(128, 32, &Wire);

#define WIDTH 128
#define HEIGHT 64

int touchValue;

int calibrateTouch(int pin, int n = 10) {
    int sum = 0;
    Serial.printf("started calibration for pin %d\n", pin);
    for (int i = 0; i <= n; i++) {
        int v = touchRead(pin);
        Serial.printf("touch read %d\n", v);
        sum += v;
    }
    Serial.printf("calibrated values is %d\n", sum/n);
    return sum/n;
}

void setup() {
    Serial.begin(115200);
    Wire.begin();
    pinMode(36, INPUT);
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // Address 0x3C for 128x32

    display.display();
    display.clearDisplay();
    touchValue = calibrateTouch(T4, 50);
    pinMode(25, OUTPUT);
    display.setTextSize(2, 2);
}



void loop() {
    static int hasTouched = false;
    static FlappyBird bird = FlappyBird(&display);

    bird.update();

    auto x = touchRead(T4);

    if (x < (touchValue-20)) {
        if (!hasTouched) {
            hasTouched = true;
            bird.jump();
            digitalWrite(25, HIGH);
        }
    } else {
        hasTouched = false;
    }
    delay(30);
    digitalWrite(25, LOW);
}