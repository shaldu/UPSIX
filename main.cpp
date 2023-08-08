#include <iostream>
#include <SDL.h>
#include <entt.hpp>
#include "./src/game.hpp"

int main(int argc, char *argv[])
{
    const int FRAMES_PER_SECOND = 60;
    const int FRAME_DELAY = 1000 / FRAMES_PER_SECOND;

    Uint32 frameStart, frameTime;
    Uint32 frameCounterStart = SDL_GetTicks();
    double deltaTime = 0.0f;
    int frameCount = 0;
    float fpsSum = 0.0f;

    Game *game = new Game();
    game->init("Game", 800, 600);

    while (game->isRunning())
    {
        frameStart = SDL_GetTicks();

        game->handleEvents();
        game->render(deltaTime, fpsSum / frameCount);

        frameTime = SDL_GetTicks() - frameStart;

        if(FRAME_DELAY > frameTime)
        {
            SDL_Delay(FRAME_DELAY - frameTime);
        }

        frameTime = SDL_GetTicks() - frameStart; // update frameTime after potential delay
        deltaTime = frameTime / 1000.0f; // convert to seconds
        
        // calculate fps
        if (frameTime > 0) {
            fpsSum += 1000.0f / frameTime;
            frameCount++;
        }
    }

    game->clean();
    return EXIT_SUCCESS;
}
