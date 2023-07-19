#include <iostream>
#include <SDL.h>
#include <entt.hpp>
#include "src/game.hpp"

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
    
    bool isRunning = game->init("Game", 800, 600);

    while (isRunning)
    {
        frameStart = SDL_GetTicks();

        game->render(deltaTime);

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

        if (SDL_GetTicks() - frameCounterStart >= 1000) {
            std::cout << "FPS: " << fpsSum / frameCount << "\n";
            frameCounterStart = SDL_GetTicks();
            fpsSum = 0.0f;
            frameCount = 0;
        }
    }

    return EXIT_SUCCESS;
}
