#pragma once
#include "Vector2D.hpp"

class Transform {
private:
    float _x, _y;
    void TranslateX(float x);
    void TranslateY(float y);
    void Translate(Vector2D v);
    
public:
    Transform(float x = 0, float y = 0): _x(x), _y(y) {}
    void Log(std::string message);
};