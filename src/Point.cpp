#pragma once
#include "SDL2/SDL.h"
#include "../include/Physics/Point.hpp"

float Point::GetX()
{
    return this->_x;
}
float Point::GetY()
{
    return this->_y;
}

void Point::SetX(float x)
{
    this->_x = x;
}

void Point::SetY(float y)
{
    this->_y = y;
}

Point Point::operator+(const Point &p2) const
{
    return Point(this->_x + p2._x, this->_y + p2._y);
}

Point Point::operator-(const Point &p2) const
{
    return Point(this->_x - p2._x, this->_y - p2._y);
}

Point operator+=(Point &p1, const Point &p2)
{
    p1._x += p2._x;
    p1._y += p2._y;
    return p1;
}

Point operator-=(Point &p1, const Point &p2)
{
    p1._x -= p2._x;
    p1._y -= p2._y;
    return p1;
}

Point Point::operator*(const float scal) const
{
    return Point(this->_x * scal, this->_y * scal);
}

void Point::Log(std::string message)
{
    SDL_Log("Message:\t%s\tX: %f\tY: %f", message.c_str(), this->_x, this->_y);
}
