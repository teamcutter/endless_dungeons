#pragma once
#include "Vector2D.hpp"

#define MASS 1.0f
#define G 9.8f

class RigidBody {
private:
    float _mass, _gravity;
    Vector2D _force, _friction, _pos, _velocity, _acceleration;

public:
    RigidBody();

    // Setters
    void SetMass(float mass);
    void SetGravity(float gravity);

    float GetMass();
    Vector2D GetVelocity();
    Vector2D GetAcceleration();
    Vector2D GetPosition();

    void ApplyForce(Vector2D force);
    void ApplyForceX(float fX);
    void ApplyForceY(float fY);
    void ResetForce();

    void ApplyFriction(Vector2D friction);
    void ResetFriction();

    void Update(float dt);
};