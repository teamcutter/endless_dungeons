#include <iostream>
#include <SDL2/SDL.h>

const int WIDTH = 800, HEIGHT = 800;

int main(int argc, char* argv[]) {

    if (SDL_Init(SDL_INIT_VIDEO) != 0){
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Window *window = SDL_CreateWindow(
        "Test", 
        0, 
        0, 
        WIDTH, 
        HEIGHT, 
        0
    );

    if(window == NULL) {
        std::cout<<"Error: "<<SDL_GetError()<<std::endl;
        return 1;
    }

    SDL_Renderer* ren = SDL_CreateRenderer(window, -1, 0);
    if(ren == nullptr){
        std::cerr << "SDL_CreateRenderer() Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        return 1;
    }

    //Render something
    SDL_RenderSetLogicalSize(ren,WIDTH,HEIGHT);

    //Set colour of renderer
    SDL_SetRenderDrawColor(ren,0,0,0,255);

    //Clear the screen to the set colour
    SDL_RenderClear(ren);

    //Show all the has been done behind the scenes
    SDL_RenderPresent(ren);

    SDL_Event windowEvent;
    
    while(true) {
        if(SDL_PollEvent(&windowEvent)) {
            if(windowEvent.type == SDL_QUIT) {
                break;
            }
        }
    }

    SDL_DestroyWindow(window); 
    SDL_Quit();

    return EXIT_SUCCESS;
}