#include "../include/Physics/RigidBody.hpp"

RigidBody::RigidBody()
{
    this->_mass = MASS;
    this->_gravity = G;
}

void RigidBody::SetMass(float mass)
{
    this->_mass = mass;
}

void RigidBody::SetGravity(float gravity) {
    this->_gravity = gravity;
}

float RigidBody::GetMass()
{
    return this->_mass;
}

Vector2D RigidBody::GetVelocity()
{
    return this->_velocity;
}

Vector2D RigidBody::GetAcceleration()
{
    return this->_acceleration;
}

Vector2D RigidBody::GetPosition()
{
    return this->_pos;
}

void RigidBody::ApplyForce(Vector2D force)
{
    this->_force = force;
}

void RigidBody::ApplyForceX(float fX)
{
    this->_force.SetX(fX);
}

void RigidBody::ApplyForceY(float fY)
{
    this->_force.SetY(fY);
}

void RigidBody::ResetForce()
{
    this->_force = Vector2D(0, 0);
}

void RigidBody::ApplyFriction(Vector2D friction)
{
    this->_friction = friction;
}

void RigidBody::ResetFriction()
{
    this->_friction = Vector2D(0, 0);
}

void RigidBody::Update(float dt)
{   
    // F = ma => a = F/m
    this->_acceleration.SetX((this->_force.GetX() + this->_friction.GetX()) / this->_mass);
    // F = ma => a = F/m => a + g
    this->_acceleration.SetY(this->_gravity + this->_force.GetY() / this->_mass);
    this->_velocity = this->_acceleration * dt;
    this->_pos = this->_velocity * dt;
}
