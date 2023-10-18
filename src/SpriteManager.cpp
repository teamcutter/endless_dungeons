#pragma once
#include "../include/Graphics/SpriteManager.hpp"
#include "../include/Engine/Engine.hpp"
#include "../include/Camera/Camera.hpp"

SpriteManager* SpriteManager::_instance = nullptr;

SpriteManager::SpriteManager() {};

SpriteManager* SpriteManager::Instance() 
{
    return _instance = (_instance != nullptr) ? _instance : new SpriteManager();
}

bool SpriteManager::Create(std::string id, std::string path) {
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

    _sprites[id] = stripe;

    return true;
}

void SpriteManager::Draw(std::string id, float x, float y, int width, int height, SDL_RendererFlip flip)
{
    SDL_Rect src = {0, 0, width, height};
    Vector2D camera = Camera::Instance()->GetPosition();
    SDL_Rect dist = {x - camera.GetX(), y - camera.GetY(), width, height};
    SDL_RenderCopyEx(Engine::Instance()->GetRenderer(), _sprites[id], &src, &dist, 0, nullptr, flip);
}

void SpriteManager::DrawFrame(std::string id, float x, float y, int width, int height, int row, int frame, SDL_RendererFlip flip)
{
    SDL_Rect src = {width*frame, height*row, width, height};
    Vector2D camera = Camera::Instance()->GetPosition();
    SDL_Rect dist = {x - camera.GetX(), y - camera.GetY(), width, height};
    SDL_RenderCopyEx(Engine::Instance()->GetRenderer(), _sprites[id], &src, &dist, 0, nullptr, flip);
}

void SpriteManager::DrawTile(std::string tilesetID, int tileSize, float x, float y, int row, int frame, SDL_RendererFlip flip){
    SDL_Rect src = {tileSize*frame, tileSize*row, tileSize, tileSize};
    Vector2D camera = Camera::Instance()->GetPosition();
    // x - camera.GetX() because camera moves in both directions and when x > camera x then is right, x < camera x is left
    SDL_Rect dist = {x - camera.GetX(), y - camera.GetY(), tileSize, tileSize};
    SDL_RenderCopyEx(Engine::Instance()->GetRenderer(), _sprites[tilesetID], &src, &dist, 0, 0, flip);
}

void SpriteManager::Delete(std::string id)
{
    SDL_DestroyTexture(_sprites[id]);
    _sprites.erase(id);
}

void SpriteManager::Destroy(){
    for(auto [_, v]: _sprites) {
        SDL_DestroyTexture(v);
    }
    _sprites.clear();

    SDL_Log("Stripes destroyed.");
}