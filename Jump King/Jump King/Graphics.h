#ifndef _GRAPHICS__H
#define _GRAPHICS__H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include "defs.h"
#include "Animation.h"

struct Graphics {
    SDL_Renderer *renderer;
	SDL_Window *window;

	void logErrorAndExit(const char* msg, const char* error);
	void init();
	void prepareScene();
	void prepareScene(SDL_Texture * background);
    void presentScene();
    SDL_Texture *loadTexture(const char *filename);
    Mix_Music *loadMusic(const char* path);
    void renderTexture(SDL_Texture *texture, int x, int y);
    void render(const Sprite& sprite, int x, int y);
    void blitRect(SDL_Texture *texture, SDL_Rect *src, int x, int y);
    void play(Mix_Music *gMusic);
    void quit();
    void endgame();
};

#endif // _GRAPHICS__H
