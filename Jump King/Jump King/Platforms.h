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
        Platform(400, 490, 300, 50),
        Platform(595, 460, 105, 30),
        Platform(330, 260, 120, 110),
        Platform(0, 210, 135, 35),
        Platform(285, 0, 145, 40)
    },
    {
        //Platform(0, 720, 1000, 50),
        Platform(0, 0, 20, SCREEN_HEIGHT),
        Platform(980, 0, 20, SCREEN_HEIGHT),
        Platform(280, 705, 155, 95),
        Platform(285, 480, 145, 40),
        Platform(0, 480, 140, 40),
        Platform(285, 195, 80, 180),
        Platform(285, -100, 35, 400),
        Platform(615, 355, 100, 160),
        Platform(680, 160, 35, 300),
        Platform(680, 160, 150, 40),
        Platform(900, 280, 100, 40),
        Platform(680, 0, 35, 35)
    },
    {
        //Platform(0, 720, 1000, 50),
        Platform(0, 0, 20, SCREEN_HEIGHT),
        Platform(980, 0, 20, SCREEN_HEIGHT),
        Platform(235, 695, 80, 40),
        Platform(685, 695, 80, 40),
        Platform(275, 695, 40, 105),
        Platform(685, 695, 40, 105),
        Platform(685, 530, 80, 35),
        Platform(0, 530, 80, 40),
        Platform(80, 190, 80, 40),
        Platform(920, 355, 80, 40),
        Platform(600, 195, 65, 35),
        Platform(470, 155, 65, 40),
        Platform(335, 120, 65, 35),
        Platform(315, 0, 365, 40)
    },
    {
        //Platform(0, 660, 1000, 50),
        Platform(315, 725, 368, 75),
        Platform(0, 0, 20, SCREEN_HEIGHT),
        Platform(980, 0, 20, SCREEN_HEIGHT),
        Platform(265, 535, 100, 35),
        Platform(605, 180, 395, 390),
        Platform(0, 405, 115, 40),
        Platform(117, 160, 85, 35),
        Platform(165, 160, 37, 125),
        Platform(165, 250, 235, 35),
        Platform(0, 0, 400, 35),
        Platform(285, 0, 110, 125),
        Platform(600, 0, 290, 52),
        Platform(685, 0, 205, 90),
        Platform(0, 0, 800, 10)
    },
    {
    }
};

#endif

