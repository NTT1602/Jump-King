#ifndef _COLLIDING__H
#define _COLLIDING__H

#include <SDL.h>
#include <SDL_image.h>
#include "defs.h"
#include "platforms.h"
void bounceback()
{

}

bool checkcollidright(int x, int y, int level)
{
    for (Platform& platform : platforms[level]) {
        if (x + charwidth > platform.rect.x &&
            x + charwidth < platform.rect.x + platform.rect.w &&
            y + charheight > platform.rect.y &&
            y + charheight < platform.rect.y + platform.rect.h)
        {
            return true;
        }
    }
    return false;
}

bool checkcollidleft(int x, int y, int level)
{
    for (Platform& platform : platforms[level]) {
        if (x < platform.rect.x + platform.rect.w &&
            x > platform.rect.x &&
            y + charheight > platform.rect.y &&  // Character is below the platform (standing on it)
            y + charheight < platform.rect.y + platform.rect.h)  // Character is not deeper than platform
        {
            return true;
        }
    }
    return false;
}

#endif // _GRAPHICS__H

