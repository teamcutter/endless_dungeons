#pragma once
#include "include/Engine/Engine.hpp"
#include "include/Graphics/Timer/Timer.hpp"

int main(int argc, char* argv[]) {

    Engine::Instance()->Init();
    while(Engine::Instance()->isRunning()){
        Engine::Instance()->Events();
        Engine::Instance()->Update();
        Engine::Instance()->Render();
        Timer::Instance()->Tick();
    }

    Engine::Instance()->Destroy();
    return EXIT_SUCCESS;
}