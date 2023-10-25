#pragma once
#include "../include/Engine/Engine.hpp"
#include "../include/Graphics/SpriteManager.hpp"
#include "../include/Keyboard/KeyboardHandler.hpp"
#include "../include/Characters/Knight.hpp"
#include "../include/Graphics/Timer/Timer.hpp"
#include "../include/Map/MapParser.hpp" 
#include "../include/Camera/Camera.hpp" 

Engine* Engine::_instance = nullptr;
Knight* player = nullptr;

Engine::Engine(){}

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

    SDL_WindowFlags window_flags = (SDL_WindowFlags) (SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);

    _window = SDL_CreateWindow("Endless Dungeons", 
    SDL_WINDOWPOS_CENTERED, 
    SDL_WINDOWPOS_CENTERED, 
    SCREEN_WIDTH, 
    SCREEN_HEIGHT, 
    window_flags);

    if(_window == nullptr) {
        SDL_Log("Window creation failed: %s", SDL_GetError());
        return false;
    }

    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if(_renderer == nullptr) {
        SDL_Log("Renderer creation failed: %s", SDL_GetError());
        return false;
    }

    if(!MapParser::Instance()->Load()) {
        std::cout<< "Faild to load map" << std::endl;
    }

    _levelMap = MapParser::Instance()->GetMap("map");

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
    SpriteManager::Instance()->Create("player_jump_state", "res/assets/knight/sprites/_Jump.png");
    
    Camera::Instance()->SetTarget(player->GetOrigin());

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
    float dt = Timer::Instance()->GetDeltaTime();
    player->Update(dt);
    _levelMap->Update();
    Camera::Instance()->Update(dt);
}

void Engine::Render()
{
    SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
    SDL_RenderClear(_renderer);

    _levelMap->Render();

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
