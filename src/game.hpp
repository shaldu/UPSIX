#pragma once
#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>
class Game
{
private:
    bool m_isRunning;
    SDL_Window *m_window;
    SDL_Renderer *m_renderer;
    SDL_Event m_event;
    TTF_Font *m_font;

public:
    Game() : m_isRunning(false), m_window(nullptr), m_renderer(nullptr){};
    ~Game() { clean(); };

    bool init(const char *title, int width, int height, int x = SDL_WINDOWPOS_UNDEFINED, int y = SDL_WINDOWPOS_UNDEFINED, bool fullscreen = false);
    void clean();
    void handleEvents();
    void render(float deltaTime, int fps);
    void drawFPS(int fps);
    bool isRunning() { return m_isRunning; };
};