#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
class WindowRenderer {
    private:
    SDL_Window* _window;
    SDL_Renderer* _renderer;

    public:
    WindowRenderer(const char*, int, int);
    SDL_Texture* loadStripe(const char*);
    void display();
    void destroy();
    void clear();
    void render();
};