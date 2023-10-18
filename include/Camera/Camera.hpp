#pragma once
#include "SDL2/SDL.h"
#include "../Physics/Point.hpp"
#include "../Physics/Vector2D.hpp"

class Camera {
private:
    Camera();
    static Camera* _instance;
    Point* _target;
    Vector2D _pos;
    SDL_Rect _viewArea;


public:
    static Camera* Instance();

    SDL_Rect GetViewArea();
    Vector2D GetPosition();
    void SetTarget(Point* target);
    void Update(float dt);
};