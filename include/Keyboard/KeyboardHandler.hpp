#pragma once
#include "SDL2/SDL.h"

class KeyboardHandler {
private:
    KeyboardHandler();
    static KeyboardHandler* _instance;
    const Uint8* _keyStates;
    void KeyUp();
    void KeyDown();

public:
    static KeyboardHandler* Instance();
    void Listen();
    bool GetKey(SDL_Scancode key);
};