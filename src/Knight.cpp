#pragma once
#include "SDL2/SDL.h"
#include "../include/Characters/Knight.hpp"
#include "../include/Graphics/SpriteManager.hpp"
#include "../include/Keyboard/KeyboardHandler.hpp"

Knight::Knight(Properties *props) : Character(props)
{
    this->_rigidbody = new RigidBody();
    this->_animation = new Animation();
    this->_animation->SetProperties(this->_id, 0, 10, 80);
}

void Knight::Draw() 
{  
    this->_animation->Draw(this->_transform->GetX(), this->_transform->GetY(), this->_width, this->_height);
}

void Knight::Update(float dt)
{   
    this->_animation->SetProperties("player", 0, 6, 80);
    this->_rigidbody->ResetForce();

    if(KeyboardHandler::Instance()->GetKey(SDL_SCANCODE_D)) {
        this->_rigidbody->ApplyForceX(10*FORWARD);
        this->_animation->SetProperties("player_run_state", 0, 8, 100);
    }
    if(KeyboardHandler::Instance()->GetKey(SDL_SCANCODE_A)) {
        this->_rigidbody->ApplyForceX(10*BACKWARD);
        this->_animation->SetProperties("player_run_state", 0, 8, 100, SDL_FLIP_HORIZONTAL);
    }
    if(KeyboardHandler::Instance()->GetKey(SDL_SCANCODE_W)) {
        this->_rigidbody->ApplyForceY(25*UP);
        this->_transform->TranslateY(this->_rigidbody->GetPosition().GetY());
        this->_animation->SetProperties("player_run_state", 0, 8, 100);
    }
    if(KeyboardHandler::Instance()->GetKey(SDL_SCANCODE_S)) {
        this->_rigidbody->ApplyForceY(10*DOWN);
        this->_transform->TranslateY(this->_rigidbody->GetPosition().GetY());
        this->_animation->SetProperties("player_run_state", 0, 8, 100);
    }


    this->_rigidbody->Update(0.4); // now it's hardcoded

    this->_transform->TranslateX(this->_rigidbody->GetPosition().GetX());

    this->_animation->Update();
}

void Knight::Delete()
{
    SpriteManager::Instance()->Delete(this->_id);
}
