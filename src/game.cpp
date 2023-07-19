#include "game.hpp"

void Game::clean()
{

}

bool Game::init(const char *title, int width, int height, int x, int y, bool fullscreen)
{

    m_window = SDL_CreateWindow(title, x, y, width, height, SDL_WINDOW_ALLOW_HIGHDPI);
    if (!m_window)
    {
        return false;
    }    

    //create renderer
    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
    if (!m_renderer)
    {
        return false;
    }

    m_event = SDL_Event();

    m_isRunning = true;
    return true;
}

void Game:render(float deltaTime)
{
    SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
    SDL_RenderClear(m_renderer);

    SDL_RenderPresent(m_renderer);
}