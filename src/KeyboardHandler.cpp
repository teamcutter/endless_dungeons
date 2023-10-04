#include "../include/Keyboard/KeyboardHandler.hpp"
#include "../include/Engine/Engine.hpp"

KeyboardHandler* KeyboardHandler::_instance = nullptr;

KeyboardHandler::KeyboardHandler() 
{
    _keyStates = SDL_GetKeyboardState(nullptr);
}

KeyboardHandler *KeyboardHandler::Instance() 
{
    return _instance = (_instance != nullptr) ? _instance : new KeyboardHandler();
}

void KeyboardHandler::KeyUp()
{
    _keyStates = SDL_GetKeyboardState(nullptr);
}

void KeyboardHandler::KeyDown()
{
    _keyStates = SDL_GetKeyboardState(nullptr);
}

void KeyboardHandler::Listen()
{
    SDL_Event event;

    while(SDL_PollEvent(&event)) {
        switch(event.type) {
            case SDL_QUIT: Engine::Instance()->Quit(); break;
            case SDL_KEYDOWN: KeyDown(); break;
            case SDL_KEYUP: KeyUp(); break;
        }
    }
}

bool KeyboardHandler::GetKey(SDL_Scancode key)
{
    return (_keyStates[key] == 1) ? true : false;
}
