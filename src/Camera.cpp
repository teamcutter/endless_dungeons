#pragma once
#include "../include/Camera/Camera.hpp"
#include "../include/Engine/Engine.hpp"

Camera* Camera::_instance = nullptr;

Camera::Camera() {
    this->_viewArea = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
}

Camera *Camera::Instance()
{
    return _instance = (_instance != nullptr) ? _instance : new Camera();
}

SDL_Rect Camera::GetViewArea()
{
    return _viewArea;
}

Vector2D Camera::GetPosition()
{
    return _pos;
}

void Camera::SetTarget(Point *target)
{
    _target = target;
}

void Camera::Update(float dt)
{
    if(_target != nullptr) {
        _viewArea.x = static_cast<int>(_target->GetX() - SCREEN_WIDTH / 2);
        _viewArea.y = static_cast<int>(_target->GetY() - SCREEN_HEIGHT / 2);

        if(_viewArea.x < 0) {
            _viewArea.x = 0;
        }

        if(_viewArea.y < 0) {
            _viewArea.y = 0;
        }

        if(_viewArea.x > (2 * SCREEN_WIDTH - _viewArea.w)) {
            _viewArea.x = (2 * SCREEN_WIDTH - _viewArea.w);
        }

        if(_viewArea.y > (2 * SCREEN_HEIGHT - _viewArea.h)) {
            _viewArea.y = (2 * SCREEN_HEIGHT - _viewArea.h);
        }

        _pos = Vector2D(_viewArea.x, _viewArea.y);
    }
}
