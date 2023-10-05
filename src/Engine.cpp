#pragma once
#include "../include/Engine/Engine.hpp"
#include "../include/Graphics/SpriteManager.hpp"
#include "../include/Keyboard/KeyboardHandler.hpp"
#include "../include/Characters/Knight.hpp"

Engine* Engine::_instance = nullptr;
Knight* player = nullptr;

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

    SpriteManager::Instance()->Create("player", "res/assets/knight/sprites/_Idle.png");
    // 120x80 - for only Knight's sprites
    player = new Knight(new Properties(
        "player",
        100,
        200,
        120,
        80
    ));

    SpriteManager::Instance()->Create("player_run_state", "res/assets/knight/sprites/_Run.png");
    
    return running = true;
}

void Engine::Destroy()
{
    SpriteManager::Instance()->Destroy();
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
    IMG_Quit();
    SDL_Quit();
}

void Engine::Quit()
{
    running = false;
}

void Engine::Update()
{
    if(KeyboardHandler::Instance()->GetKey(SDL_SCANCODE_W)) {
        SDL_Log("W!");
    }

    player->Update(0);
}

void Engine::Render()
{
    SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
    SDL_RenderClear(_renderer);

    player->Draw();
    SDL_RenderPresent(_renderer);
}

void Engine::Events()
{
    KeyboardHandler::Instance()->Listen();
}
bool Engine::isRunning()
{
    return running;
}
SDL_Renderer *Engine::GetRenderer()
{
    return _renderer;
}
