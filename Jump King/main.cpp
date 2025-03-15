#include <bits/stdc++.h>
#include <SDL.h>
#include <SDL_image.h>
#include "defs.h"
#include "Graphics.h"
#include "Movements.h"
#include "Platforms.h"
#include "Animation.h"
#include "Colliding.h"
using namespace std;

int main(int argc, char* argv[])
{
    int level = 1, low = SCREEN_HEIGHT, high = 0;
    Graphics graphics;
    graphics.init();

    SDL_Texture* background[10];

    for (int i = 1; i <= totallevel; i++)
    {
        ostringstream filename;
        filename << i << ".png";
        background[i] = graphics.loadTexture(filename.str().c_str());
    }

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
        while (player.y + charheight < high)
        {
            low = high;
            high -= SCREEN_HEIGHT;
            level++;
        }
        while (player.y + charheight > low)
        {
            high = low;
            low += SCREEN_HEIGHT;
            level--;
        }
        player.y += SCREEN_HEIGHT * (level - 1);
        graphics.prepareScene(background[level]);
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
            if (currentKeyStates[SDL_SCANCODE_LEFT] && !checkcollidleft(player.x, player.y, level))
            {
                player.turnLeft();
                isrunningleft = true;
                isright = false;
                runningleftanimation.tick();
            }
            if (currentKeyStates[SDL_SCANCODE_RIGHT] && !checkcollidright(player.x, player.y, level))
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

        for (Platform& platform : platforms[level]) {
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

        /*for (const Platform& platform : platforms[level]) {
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
        player.y -= SCREEN_HEIGHT * (level - 1);
        SDL_Delay(0);
    }
    SDL_DestroyTexture( king );
    king = NULL;
    SDL_DestroyTexture( background[level] );
    background[level] = NULL;

    graphics.quit();
    return 0;

}
