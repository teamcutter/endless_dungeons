#include "../include/Physics/Transform.hpp"

void Transform::TranslateX(float x)
{
    this->_x += x;
}

void Transform::TranslateY(float y)
{
    this->_y += y;
}

void Transform::Translate(Vector2D v)
{
    this->_x += v.GetX();
    this->_y += v.GetY();
}

void Transform::SetX(float x)
{
    this->_x = x;
}

void Transform::SetY(float y)
{
    this->_y = y;
}

float Transform::GetX()
{
    return this->_x;
}

float Transform::GetY()
{
    return this->_y;
}

void Transform::Log(std::string message)
{
    SDL_Log("Message:\t%s\tX: %f\tY: %f", message.c_str(), this->_x, this->_y);
}