#pragma once

// interface
class IObject {
public:
    virtual void Draw() = 0;
    virtual void Update(float dt) = 0;
    virtual void Delete() = 0;
};