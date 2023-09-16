#pragma once
#include "../include/Engine/Engine.hpp"

Engine* Engine::_instance = nullptr;

Engine::Engine(){};

Engine* Engine::Instance()
{
    return _instance = (_instance != nullptr) ? _instance : new Engine();
}
bool Engine::Init()
{
    if(SDL_Init(SDL_INIT_VIDEO) != 0 && SDL_Init(IMG_INIT_JPG | IMG_INIT_JPG) != 0) {

        SDL_Log("Initialization failed: %s", SDL_GetError());
        return false;
    }

    _window = SDL_CreateWindow("Test", 
    SDL_WINDOWPOS_CENTERED, 
    SDL_WINDOWPOS_CENTERED, 
    SCREEN_WIDTH, 
    SCREEN_HEIGHT, 
    0);

    if(_window == nullptr) {
        SDL_Log("Window creation failed: %s", SDL_GetError());
        return false;
    }

    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if(_renderer == nullptr) {
        SDL_Log("Renderer creation failed: %s", SDL_GetError());
        return false;
    }

    return running = true;
}

bool Engine::Clean()
{
    return false;
}

void Engine::Quit()
{
    running = false;
}

void Engine::Update()
{
}

void Engine::Render()
{
    SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
    SDL_RenderPresent(_renderer);
}

void Engine::Events()
{
    SDL_Event event;
    SDL_PollEvent(&event);
    switch(event.type)
    {
    case SDL_QUIT:
        Quit();
        break;
    
    default:
        break;
    }
}
bool Engine::isRunning()
{
    return running;
}
SDL_Renderer *Engine::GetRenderer()
{
    return _renderer;
}
