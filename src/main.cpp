#pragma once
#include "../include/Engine/Engine.hpp"

int main(int argc, char* argv[]) {

    Engine::Instance()->Init();
    while(Engine::Instance()->isRunning()){
        Engine::Instance()->Events();
        Engine::Instance()->Update();
        Engine::Instance()->Render();
    }

    Engine::Instance()->Clean();
    return EXIT_SUCCESS;
}