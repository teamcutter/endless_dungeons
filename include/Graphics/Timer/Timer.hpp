#pragma once

const int FPS = 60;
const float DELTATIME = 1.5f;

class Timer {
private:
    Timer();
    static Timer* _instance;
    float _deltaTime, _lastTime;

public:
    static Timer* Instance();
    void Tick();

    float GetDeltaTime();
};