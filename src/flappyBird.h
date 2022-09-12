//
// Created by vasabi on 9/11/22.
//

#ifndef UNTITLED13_FLAPPYBIRD_H
#define UNTITLED13_FLAPPYBIRD_H

#include <cstdint>
#include "Adafruit_GFX.h"
#include "Adafruit_SSD1306.h"

#define RANDOM (float)esp_random()/(float)UINT32_MAX

void test();

class FlappyBird {
public:
    int width, height, groundHeight;
    int birdWidth, birdHeight;

    int birdX, birdY;
    int velocity;
    int pipeX, pipe1height, pipe2height, pipeWidth = 0;
    int score = 0;
    bool scored = false;
    Adafruit_SSD1306* display;

    FlappyBird(Adafruit_SSD1306* disp) {
        display = disp;
        width = display->width();
        height = display->height();

        birdX = width/3;
        birdY = height/2;

        birdHeight = 2;
        birdWidth = 3;

        velocity = 0;
        groundHeight = 3;
    }

    void drawBird() {
        display->drawRect(birdX, birdY, birdWidth, birdHeight, 1);
    }

    void drawGround() {
        display->drawRect(-1, height-groundHeight, width+2, (groundHeight+1), 1);
    }

    void clearDisplay() {
        display->clearDisplay();
    }

    void displayFlush() {
        display->display();
    }

    bool isColliding() {
        // ground
        if (birdY > height-groundHeight) {
            return true;
        }
        if (birdX >= pipeX && birdX+1 <= pipeX+pipeWidth) {
            // pipe1
            if (birdY < pipe1height) {
                return true;
            }
            else if (birdY > height-pipe2height) {
                return true;
            }
            // pipe2
        }

        return false;
    }

    void handleCollision() {
        if (isColliding()) {
            score = 0;
            pipeX = 0;
            velocity = -4;
            Serial.println("colided");
            birdY = height/3;
        }
    }

    void updateBird() {
        velocity++;

        if (velocity > 1) {
            velocity = 1;
        }
        if (velocity < -3) {
            velocity = -3;
        }

        birdY += velocity;

        if (birdY <= 0) {
            birdY = 0;
        }

        if (birdY > 20) {
            // birdY = 0;
            // jump();
        }
    }

    void updatePipes() {
        if (pipeX <= 0) {
            float x = RANDOM;
            float x1 = RANDOM;
            Serial.println(x);

            pipeX = width;
            pipeWidth = 4;
            pipe1height = 4+6*x;
            pipe2height = 4+6*x1;
            scored = false;
        }
        else {
            if (pipeX < birdX) {
                if (!scored) {
                    score++;
                    scored = true;
                }
            }
            pipeX--;
        }
    }

    void drawPipes() {
        // display->drawRect(pipeX, 10, 5, 5, 1);
        display->drawRect(pipeX, 0, pipeWidth, pipe1height, 1);
        display->drawRect(pipeX, height-pipe2height, pipeWidth, pipe2height, 1);
    }

    void drawScore() {
        display->setCursor(0,0);
        display->setTextColor(1);
        display->print(score);
    }

    void draw() {
        clearDisplay();
        drawPipes();
        drawGround();
        drawBird();
        drawScore();
        displayFlush();
    }

    void update() {
        handleCollision();

        updateBird();
        updatePipes();

        draw();
    }

    void jump() {
        Serial.printf("jump call %d\n", velocity);
        velocity -= 5;
    }
};

#endif //UNTITLED13_FLAPPYBIRD_H
