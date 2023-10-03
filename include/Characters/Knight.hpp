#pragma once
#include "Character.hpp"
#include "../Graphics/Animation/Animation.hpp"

class Knight: public Character {
private:
    Animation* _animation;

public:
    Knight(Properties* props);
    virtual void Draw() override;
    virtual void Update(float dt) override;
    virtual void Delete() override;
};