#pragma once
#include <SDL.h>
class Game
{
private:
    bool m_isRunning;
    SDL_Window *m_window;
    SDL_Renderer *m_renderer;
    SDL_Event m_event;

public:
    Game() : m_isRunning(false), m_window(nullptr), m_renderer(nullptr){};
    ~Game() { clean(); };

    bool init(const char *title, int width, int height, int x = SDL_WINDOWPOS_UNDEFINED, int y = SDL_WINDOWPOS_UNDEFINED, bool fullscreen = false);
    void clean();
    void handleEvents();
    void render(float deltaTime);
    bool isRunning() { return m_isRunning; };
};