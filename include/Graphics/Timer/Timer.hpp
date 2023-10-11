#pragma once

const int FPS = 60;
const float DELTATIME = 0.6f;

class Timer {
private:
    Timer(){}
    static Timer* _instance;
    float _deltaTime, _lastTime;

public:
    static Timer* Instance();
    void Tick();

    float GetDeltaTime();
};