#pragma once
#include "../include/Graphics/StripeManager.hpp"
#include "../include/Engine/Engine.hpp"

StripeManager* StripeManager::_instance = nullptr;

StripeManager::StripeManager() {};

StripeManager* StripeManager::Instance() 
{
    return _instance = (_instance != nullptr) ? _instance : new StripeManager();
}

bool StripeManager::Create(std::string id, std::string path) {
    // c_str() because SDL written on C and param is const char*
    SDL_Surface* surface = IMG_Load(path.c_str());
    if(surface == nullptr){
        SDL_Log("Surface creation failed: %s, %s", path.c_str(), SDL_GetError());
        return false;
    }

    SDL_Texture* stripe = SDL_CreateTextureFromSurface(Engine::Instance()->GetRenderer(), surface);
    if(stripe == nullptr){
        SDL_Log("Stripe creation failed: %s", SDL_GetError());
        return false; 
    }

    _stripes[id] = stripe;

    return true;
}

void StripeManager::Draw(std::string id, int x, int y, int width, int height, SDL_RendererFlip flip)
{
    SDL_Rect src = {0, 0, width, height};
    SDL_Rect dist = {x, y, width, height};
    SDL_RenderCopyEx(Engine::Instance()->GetRenderer(), _stripes[id], &src, &dist, 0, nullptr, flip);
}

void StripeManager::Delete(std::string id)
{
    SDL_DestroyTexture(_stripes[id]);
    _stripes.erase(id);
}

void StripeManager::Destroy(){
    for(auto [_, v]: _stripes) {
        SDL_DestroyTexture(v);
    }
    _stripes.clear();

    SDL_Log("Stripes destroyed.");
}