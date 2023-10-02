#pragma once
#include "Character.hpp"

class Knight: public Character {
private:
    int _row, _frame, _frameCount, _animationSpeed;
public:
    Knight(Properties* props);
    virtual void Draw() override;
    virtual void Update(float dt) override;
    virtual void Clean() override;
};