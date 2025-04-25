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
Graphics graphics;
int level = 1, low = SCREEN_HEIGHT, high = 0;
Uint32 startTime = SDL_GetTicks();
bool winning = false;
void startGame()
{
    graphics.init();
    Mix_Music *gMusic = graphics.loadMusic("chill.mp3");
    graphics.play(gMusic);
    SDL_Texture* background[10];
    for (int i = 1; i <= totallevel; i++)
    {
        ostringstream filename;
        filename << i << ".png";
        background[i] = graphics.loadTexture(filename.str().c_str());
    }

    SDL_Texture* king = graphics.loadTexture("idle.png");
    SDL_Texture* king2 = graphics.loadTexture("idle2.png");

    SDL_Texture* princess = graphics.loadTexture("Princess.png");

    Sprite runningrightanimation;
    SDL_Texture* kingrunningright = graphics.loadTexture("runningright.png");
    runningrightanimation.init(kingrunningright, char_frames, char_clip);

    Sprite runningleftanimation;
    SDL_Texture* kingrunningleft = graphics.loadTexture("runningleft.png");
    runningleftanimation.init(kingrunningleft, char_frames, char_clip);

    SDL_Texture* kingsquat = graphics.loadTexture("squat.png");

    SDL_Texture* winningscreen = graphics.loadTexture("winning screen.png");


    Mouse player;

    player.x = SCREEN_WIDTH / 2 - 200;
    player.y = SCREEN_HEIGHT / 2 - 4400;

    double power = 0;
    bool quit = false, isright = true;
    SDL_Event event;
    while (!quit && !winning) {
        while (player.y + charheight < high && level != 6)
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

        bool squat = false, isrunningright = false, isrunningleft = false, ouch = false;

        if (currentKeyStates[SDL_SCANCODE_SPACE] && !player.isjumping)
        {
            squat = true;
            power = max (power - 0.5, jumph);
        }

        if (!squat && player.canmove)
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

        for (Platform& platform : platforms[level]) {
            if (player.y <= platform.rect.y + platform.rect.h &&
                player.y >= platform.rect.y + platform.rect.h - acceptable &&
                player.x + charwidth - diff >= platform.rect.x &&
                player.x + diff <= platform.rect.x + platform.rect.w)
            {
                ouch = true;
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

        player.upd(ouch);

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
        if (level == 6)
        {
            graphics.renderTexture(princess, princessx, princessy);
            if (player.x + charwidth > princessx &&
                player.x < princessx &&
                player.y == princessy)
            {
                winning = true;
                graphics.prepareScene(winningscreen);
            }
        }
        graphics.presentScene();
        player.y -= SCREEN_HEIGHT * (level - 1);
        SDL_Delay(0);
    }
}

int main(int argc, char* argv[])
{
    graphics.init();
    SDL_Texture* waitingscreen = graphics.loadTexture("waiting screen.jpg");
    bool running = true;
    SDL_Event event;
    while (running) {
        const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
        graphics.prepareScene(waitingscreen);
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            } else if (currentKeyStates[SDL_SCANCODE_SPACE]) {
                graphics.quit();
                startGame();
                running = false;
            }
        }
        graphics.presentScene();
    }
    Uint32 elapsedTime = SDL_GetTicks() - startTime;
        int minutes = elapsedTime / 60000;
        int seconds = (elapsedTime % 60000) / 1000;
        cout << minutes << " " << seconds << '\n';
    if (winning)
    {
        SDL_Delay(3000);
    }
    graphics.quit();
    graphics.endgame();
    return 0;
}
