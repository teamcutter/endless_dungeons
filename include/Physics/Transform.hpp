#pragma once
#include "Vector2D.hpp"

class Transform {
private:
    float _x, _y;
    
public:
    Transform(float x = 0, float y = 0): _x(x), _y(y) {}
    void Log(std::string message);

    void TranslateX(float x);
    void TranslateY(float y);
    void Translate(Vector2D v);

    void SetX(float x);
    void SetY(float y);
    float GetX();
    float GetY();
};