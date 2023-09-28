#pragma once
#include <string>
#include <SDL2/SDL.h>

class Vector2D{
private:
    float _x, _y;
public:
    Vector2D(float x = 0, float y = 0): _x(x), _y(y) {}

    // Getters
    float GetX();
    float GetY();

    // Operators
    Vector2D operator+(const Vector2D& v2) const;
    Vector2D operator-(const Vector2D& v2) const;

    // Debugging
    void Log(std::string message);
};