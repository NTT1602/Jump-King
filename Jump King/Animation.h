
#ifndef _ANIMATION__H
#define _ANIMATION__H

#include <bits/stdc++.h>
#include <SDL.h>
#include <SDL_image.h>
#include "defs.h"

struct Sprite {
    SDL_Texture* texture;
    std::vector<SDL_Rect> clips;
    int currentFrame = 0, cnt = 0;

    void init(SDL_Texture* _texture, int frames, const int _clips [][4]) {
        texture = _texture;
        SDL_Rect clip;
        for (int i = 0; i < frames; i++) {
            clip.x = _clips[i][0];
            clip.y = _clips[i][1];
            clip.w = _clips[i][2];
            clip.h = _clips[i][3];
            clips.push_back(clip);
        }
    }
    void tick() {
        cnt++;
        if (cnt == 7)
        {
            currentFrame = (currentFrame + 1) % clips.size();
            cnt = 0;
        }
    }

    const SDL_Rect* getCurrentClip() const {
        return &(clips[currentFrame]);
    }
};


#endif // _GRAPHICS__H

