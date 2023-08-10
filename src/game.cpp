#include "game.hpp"

void Game::clean()
{
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}

bool Game::init(const char *title, int width, int height, int x, int y, bool fullscreen)
{
    SDL_Init(SDL_INIT_EVERYTHING);

    glm::vec3 position(1.0f, 2.0f, 3.0f);

    m_window = SDL_CreateWindow(title, x, y, width, height, SDL_WINDOW_ALLOW_HIGHDPI);
    if (!m_window)
    {
        return false;
    }

    // create renderer
    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
    if (!m_renderer)
    {
        return false;
    }

    m_event = SDL_Event();

    m_isRunning = true;
    return true;
}

void Game::render(float deltaTime, int fps)
{
    SDL_SetRenderDrawColor(m_renderer, 33, 33, 33, 255);
    SDL_RenderClear(m_renderer);
    SDL_RenderPresent(m_renderer);
}

void Game::handleEvents()
{
    SDL_PollEvent(&m_event);
    switch (m_event.type)
    {
    case SDL_QUIT:
        m_isRunning = false;
        break;

    case SDL_WINDOWEVENT:
        if (m_event.window.event == SDL_WINDOWEVENT_CLOSE && m_event.window.windowID == SDL_GetWindowID(m_window))
            m_isRunning = false;
        break;

    case SDL_KEYDOWN:
        if (m_event.key.keysym.sym == SDLK_ESCAPE)
        {
            m_isRunning = false;
        }
        break;

    default:
        break;
    }
}
