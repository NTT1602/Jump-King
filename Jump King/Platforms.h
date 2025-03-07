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

std::vector<Platform> platforms = {
        Platform(0, 720, 1000, 50),
        Platform(0, 400, 270, 600),
        Platform(720, 400, 270, 600),
        Platform(380, 80, 240, 140)
};

#endif

