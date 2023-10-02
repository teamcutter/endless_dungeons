#pragma once
#include "SDL2/SDL.h"
#include "../include/Characters/Knight.hpp"
#include "../include/Graphics/SpriteManager.hpp"

Knight::Knight(Properties *props) : Character(props)
{
    this->_row = 0;
    this->_frameCount = 10;
    this->_animationSpeed = 80;
}

void Knight::Draw()
{  
    SpriteManager::Instance()->DrawFrame(this->_stripeID, this->_transform->GetX(), this->_transform->GetY(), this->_width, this->_height, this->_row, this->_frame);
}

void Knight::Update(float dt)
{
    this->_frame = (SDL_GetTicks64() / this->_animationSpeed) % this->_frameCount;
}

void Knight::Clean()
{
    SpriteManager::Instance()->Delete(this->_stripeID);
}
