#include <bits/stdc++.h>
#include <SDL.h>
#include <SDL_image.h>
#include "defs.h"
#include "Graphics.h"
#include "Movements.h"
#include "Platforms.h"
#include "Animation.h"

using namespace std;

void waitUntilKeyPressed()
{
    SDL_Event e;
    while (true) {
        if ( SDL_PollEvent(&e) != 0 &&
             e.type == SDL_QUIT)
            return;
        SDL_Delay(10);
    }
}

int main(int argc, char* argv[])
{
    Graphics graphics;
    graphics.init();

    SDL_Texture* background = graphics.loadTexture("1.png");

    SDL_Texture* king = graphics.loadTexture("idle.png");
    SDL_Texture* king2 = graphics.loadTexture("idle2.png");

    Sprite runningrightanimation;
    SDL_Texture* kingrunningright = graphics.loadTexture("runningright.png");
    runningrightanimation.init(kingrunningright, char_frames, char_clip);

    Sprite runningleftanimation;
    SDL_Texture* kingrunningleft = graphics.loadTexture("runningleft.png");
    runningleftanimation.init(kingrunningleft, char_frames, char_clip);

    SDL_Texture* kingsquat = graphics.loadTexture("squat.png");

    graphics.presentScene();

    Mouse player;

    player.x = SCREEN_WIDTH / 2;
    player.y = 620;

    double power = 0;

    bool quit = false, isright = true;
    SDL_Event event;
    while (!quit) {
        graphics.prepareScene(background);
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) quit = true;
        }
        const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

        bool squat = false, isrunningright = false, isrunningleft = false;

        if (currentKeyStates[SDL_SCANCODE_SPACE] && !player.isjumping)
        {
            squat = true;
            power = max (power - 0.5, jumph);
        }
        if (!squat)
        {
            if (currentKeyStates[SDL_SCANCODE_LEFT])
            {
                player.turnLeft();
                isrunningleft = true;
                isright = false;
                runningleftanimation.tick();
            }
            if (currentKeyStates[SDL_SCANCODE_RIGHT])
            {
                player.turnRight();
                isrunningright = true;
                isright = true;
                runningrightanimation.tick();
            }
        }

        if (!squat && power != 0)
        {
            player.jump(power);
            power = 0;
        }


        bool check = false;

        for (Platform& platform : platforms) {
            if (player.y + charheight >= platform.rect.y &&
                player.y + charheight <= platform.rect.y + acceptable &&
                player.x + charwidth - diff >= platform.rect.x &&
                player.x + diff <= platform.rect.x + platform.rect.w &&
                player.grav >= 0)
            {
                check = true;
                player.y = platform.rect.y - charheight;
                player.isjumping = false;
                player.grav = 0;
            }
        }

        if (!check && !player.isjumping)
        {
            player.isjumping = true;
            player.grav = 1;
        }

        /*for (const Platform& platform : platforms) {
            SDL_RenderFillRect(graphics.renderer, &platform.rect);
        }*/


        player.upd();

        if (squat)
            graphics.renderTexture(kingsquat, player.x, player.y);
        else
            if(isrunningright && !player.isjumping)
                graphics.render(runningrightanimation, player.x, player.y);
                else
                    if(isrunningleft && !player.isjumping)
                        graphics.render(runningleftanimation, player.x, player.y);
                    else
                        if(isright)
                            graphics.renderTexture(king, player.x, player.y);
                        else
                            graphics.renderTexture(king2, player.x, player.y);
        graphics.presentScene();
        SDL_Delay(0);
    }

    SDL_DestroyTexture( king );
    king = NULL;
    SDL_DestroyTexture( background );
    background = NULL;

    graphics.quit();
    return 0;

}
