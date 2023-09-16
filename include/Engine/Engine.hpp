#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#define SCREEN_WIDTH 1240
#define SCREEN_HEIGHT 960

class Engine {
private:
    Engine();
    static Engine* _instance;
    bool running;
    SDL_Window* _window;
    SDL_Renderer* _renderer;

public:
    // Base
    static Engine* Instance();
    bool Init();
    bool Clean();
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