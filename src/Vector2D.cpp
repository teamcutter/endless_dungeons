#pragma once
#include "../include/Physics/Vector2D.hpp"

float Vector2D::GetX() 
{
    return this->_x;
}

float Vector2D::GetY() 
{
    return this->_y;
}

void Vector2D::SetX(float x)
{
    this->_x = x;
}

void Vector2D::SetY(float y)
{
    this->_y = y;
}

Vector2D Vector2D::operator+(const Vector2D &v2) const
{
    return Vector2D(this->_x + v2._x, this->_y + v2._y);
}

Vector2D Vector2D::operator-(const Vector2D& v2) const 
{
    return Vector2D(this->_x - v2._x, this->_y-v2._y);
}

Vector2D Vector2D::operator*(const float scal) const
{
    return Vector2D(this->_x * scal, this->_y * scal);
}

void Vector2D::Log(std::string message)
{
    SDL_Log("Message:\t%s\tX: %f\tY: %f", message.c_str(), this->_x, this->_y);
}