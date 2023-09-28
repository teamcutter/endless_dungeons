#pragma once
#include <SDL2/SDL.h>
#include "IObject.hpp"
#include "../Physics/Transform.hpp"

struct Properties
{
public:
    int width, height;
    float x, y;
    std::string stripeID;
    SDL_RendererFlip flip;

    Properties(std::string stripeID, float x, float y, int width, int height, SDL_RendererFlip flip = SDL_FLIP_NONE) {
        this->stripeID = stripeID;
        this->x = x;
        this->y = y;
        this->width = width;
        this->height = height;
        this->flip = flip;
    }
};


class GameObject: public IObject {
public:
    GameObject(Properties* properties): _stripeID(properties->stripeID), _width(properties->width),
    _height(properties->height), _flip(properties->flip) {
        _transform = new Transform(properties->x, properties->y);
    }

    virtual void Draw() override;
    virtual void Update(float dt) override;
    virtual void Clean() override;

protected:
    Transform* _transform;
    int _width, _height;
    std::string _stripeID;
    SDL_RendererFlip _flip;
};