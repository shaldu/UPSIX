#include <iostream>
#include <SDL.h>
#include <entt.hpp>
#include <chrono>

int main(int argc, char *argv[])
{
    const int FRAMES_PER_SECOND = 60;
    const int FRAME_DELAY = 1000 / FRAMES_PER_SECOND;

    Uint32 frameStart, frameTime;
    Uint32 frameCounterStart = SDL_GetTicks();

    int frameCount = 0;
    float fpsSum = 0.0f;

    bool isRunning = true;

    while (isRunning)
    {
        frameStart = SDL_GetTicks();

        std::cout << "Hello, world!\n";

        frameTime = SDL_GetTicks() - frameStart;

        if(FRAME_DELAY > frameTime)
        {
            SDL_Delay(FRAME_DELAY - frameTime);
        }

        frameTime = SDL_GetTicks() - frameStart; // update frameTime after potential delay

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
