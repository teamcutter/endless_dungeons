#pragma once
#include <SDL2/SDL.h>
#include "IObject.hpp"
#include "../Physics/Transform.hpp"
#include "../Physics/Point.hpp"

struct Properties {
public:
    int width, height;
    float x, y;
    std::string _id;
    SDL_RendererFlip flip;

    Properties(std::string _id, float x, float y, int width, int height, SDL_RendererFlip flip = SDL_FLIP_NONE) {
        this->_id = _id;
        this->x = x;
        this->y = y;
        this->width = width;
        this->height = height;
        this->flip = flip;
    }
};


class GameObject: public IObject {
protected:
    Transform* _transform;
    int _width, _height;
    std::string _id;
    SDL_RendererFlip _flip;
    Point* _origin;
    
public:
    GameObject(Properties* properties): _id(properties->_id), _width(properties->width),
    _height(properties->height), _flip(properties->flip) {
        _transform = new Transform(properties->x, properties->y);
        float point_x = properties->x + properties->width / 2;
        float point_y = properties->y + properties->height / 2;
        _origin = new Point(point_x, point_y);
    }

    Point* GetOrigin();

    virtual void Draw() = 0;
    virtual void Update(float dt) = 0;
    virtual void Delete() = 0;
};