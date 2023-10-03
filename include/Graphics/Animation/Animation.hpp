#pragma once
#include "SDL2/SDL.h"
#include <string>

class Animation {
private:
    int _spriteRow, _spriteFrame, _speed, _frameCount;
    std::string _id;
    SDL_RendererFlip _flip;

public:
    Animation() {}

    void Update();
    void Draw(float x, float y, int spriteWidth, int spriteHeight);
    void SetProperties(std::string id, int spriteRow, int frameCount, int speed, SDL_RendererFlip flip = SDL_FLIP_NONE);
};