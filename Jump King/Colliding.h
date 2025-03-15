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
        // Check if the character's right edge is colliding with the platform's left edge
        if (x + charwidth > platform.rect.x &&  // Character is to the right of the platform
            x + charwidth < platform.rect.x + platform.rect.w &&  // Character is to the left of the platform
            y + charheight > platform.rect.y &&  // Character is below the platform (standing on it)
            y + charheight < platform.rect.y + platform.rect.h)  // Character is not deeper than platform
        {
            return true;
        }
    }
    return false;
}

bool checkcollidleft(int x, int y, int level)
{
    for (Platform& platform : platforms[level]) {
        // Check if the character's left edge is colliding with the platform's right edge
        if (x < platform.rect.x + platform.rect.w &&  // Character is to the left of the platform
            x > platform.rect.x &&  // Character's right edge is to the right of the platform's left edge
            y + charheight > platform.rect.y &&  // Character is below the platform (standing on it)
            y + charheight < platform.rect.y + platform.rect.h)  // Character is not deeper than platform
        {
            return true;
        }
    }
    return false;
}

#endif // _GRAPHICS__H

