#pragma once
#include "SDL2/SDL.h"
#include "../include/Graphics/Timer/Timer.hpp"

Timer* Timer::_instance = nullptr;

Timer *Timer::Instance()
{
    return _instance = (_instance != nullptr) ? _instance : new Timer();
}

void Timer::Tick()
{
    _deltaTime = (SDL_GetTicks() - _lastTime) * (FPS/1000.0f);

    if(_deltaTime > DELTATIME)
        _deltaTime = DELTATIME;

    _lastTime = SDL_GetTicks();
}

float Timer::GetDeltaTime()
{
    return _deltaTime;
}
