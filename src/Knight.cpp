#pragma once
#include "SDL2/SDL.h"
#include "../include/Characters/Knight.hpp"
#include "../include/Graphics/SpriteManager.hpp"

Knight::Knight(Properties *props) : Character(props)
{
    this->_animation = new Animation();
    this->_animation->SetProperties(this->_id, 0, 10, 80);
}

void Knight::Draw()
{  
    this->_animation->Draw(this->_transform->GetX(), this->_transform->GetY(), this->_width, this->_height);
}

void Knight::Update(float dt)
{
    this->_animation->Update();
}

void Knight::Delete()
{
    SpriteManager::Instance()->Delete(this->_id);
}
