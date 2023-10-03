#pragma once
#include "../Object/GameObject.hpp"

class Character: public GameObject {
protected: 
    std::string _name;

public:
    Character(Properties* props): GameObject(props) {}

    virtual void Draw() = 0;
    virtual void Update(float dt) = 0;
    virtual void Delete() = 0;
};