#include <iostream>
#include <SDL2/SDL.h>
#include "../include/WindowRenderer.hpp"

const int WIDTH = 800, HEIGHT = 800;

int main(int argc, char* argv[]) {

    if (SDL_Init(SDL_INIT_VIDEO) != 0){
        std::cout << "Failed to init: " << SDL_GetError() << std::endl;
        return 1;
    }
    
    WindowRenderer window("Test", 800, 900);
    window.render();
    SDL_Event windowEvent;
    
    while(true) {
        if(SDL_PollEvent(&windowEvent)) {
            if(windowEvent.type == SDL_QUIT) {
                break;
            }
        }
    }

    window.destroy();
    SDL_Quit();

    return EXIT_SUCCESS;
}