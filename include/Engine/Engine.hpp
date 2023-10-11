#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "../Map/Map.hpp"

#define SCREEN_WIDTH 1240
#define SCREEN_HEIGHT 960

class Engine {
private:
    Engine();
    static Engine* _instance;
    bool running;
    SDL_Window* _window;
    SDL_Renderer* _renderer;
    Map* _levelMap;

public:
    // Base
    static Engine* Instance();
    bool Init();
    void Destroy();
    void Quit();

    // In-game handling
    void Update();
    void Render();
    void Events();

    // States
    bool isRunning();

    // Getters and Setters
    SDL_Renderer* GetRenderer();

};