#ifndef _MOVEMENTS__H
#define _MOVEMENTS__H

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "defs.h"
#include "Graphics.h"
struct Mouse {
    double x, y, nonstop = 0;
    bool canmove = true;
    double speed = INITIAL_SPEED;
    double grav = 0;
    bool isjumping = false;
    void turnLeft() {
        x -= speed;
    }
    void turnRight() {
        x += speed;
    }
    void jump(double power)
    {
        if (!isjumping)
        {
            isjumping = true;
            grav += power;
        }
    }
    void upd(bool ouch)
    {
        if(isjumping)
        {
            grav += 1;
            if (grav > gravmax)
                grav = gravmax;
            if (!ouch) y += grav;
            else
            {
                y += bouncing;
                if (grav < 0)
                    grav = 0;
            }
        }
    }
};

#endif
