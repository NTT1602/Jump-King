#ifndef _PLATFORM__H
#define _PLATFORM__H

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "defs.h"
#include "Graphics.h"

class Platform {
public:
    SDL_Rect rect;
    Platform(int x, int y, int w, int h)
        : rect({x, y, w, h}) {}
};

class MovingPlatform : public Platform {
public:
    int direction; // 1 for right/down, -1 for left/up
    int speed;
    bool isHorizontal;

    MovingPlatform(int x, int y, int w, int h, int z, int speed, bool isHorizontal)
        : Platform(x, y, w, h), direction(1), speed(speed), isHorizontal(isHorizontal) {}

    void update() {
        if (isHorizontal) {
            rect.x += speed * direction;
            if (rect.x <= 0 || rect.x + rect.w >= 800) { // screen bounds
                direction *= -1;
            }
        } else {
            rect.y += speed * direction;
            if (rect.y <= 0 || rect.y + rect.h >= 600) { // screen bounds
                direction *= -1;
            }
        }
    }
};

std::vector<std::vector<Platform>> platforms = {
    {
        Platform(0, 0, 0, 0),
        Platform(0, 0, 0, 0),
        Platform(0, 0, 0, 0),
        Platform(0, 0, 0, 0)
    },
    {
        Platform(0, 720, 1000, 50),
        Platform(0, 400, 270, 600),
        Platform(720, 400, 270, 600),
        Platform(380, 80, 240, 140)
    },
    {
        //Platform(0, 720, 1000, 50),
        Platform(610, 650, 210, 70),
        Platform(530, 430, 160, 90),
        Platform(850, 430, 200, 80),
        Platform(245, 220, 158, 155),
        Platform(0, 170, 170, 200)
    },
    {
        //Platform(0, 720, 1000, 50),
        Platform(0, 0, 20, SCREEN_HEIGHT),
        Platform(980, 0, 20, SCREEN_HEIGHT),
        Platform(435, 675, 100, 30),
        Platform(670, 675, 110, 40),
        Platform(885, 565, 115, 40),
        Platform(400, 490, 300, 80),
        Platform(595, 460, 105, 30)
    }
};

#endif

