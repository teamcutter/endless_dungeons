#pragma once
#include "../include/Graphics/Animation/Animation.hpp"
#include "../include/Graphics/SpriteManager.hpp"

void Animation::Update()
{
    this->_spriteFrame = (SDL_GetTicks() / this->_speed) % this->_frameCount;
}

void Animation::Draw(float x, float y, int spriteWidth, int spriteHeight)
{
    SpriteManager::Instance()->DrawFrame(this->_id, x, y, spriteWidth, spriteHeight, this->_spriteRow, this->_spriteFrame, this->_flip);
}

void Animation::SetProperties(std::string id, int spriteRow, int frameCount, int speed, SDL_RendererFlip flip)
{
    this->_id = id;
    this->_spriteRow = spriteRow;
    this->_frameCount = frameCount;
    this->_speed = speed;
    this->_flip = flip;
}
