#pragma once
#include <iostream>
#include "../include/WindowRenderer.hpp"

WindowRenderer::WindowRenderer(const char* title, int width, int height) : _window(NULL), _renderer(NULL)
{
    this->_window = SDL_CreateWindow(
        title, 
        SDL_WINDOWPOS_UNDEFINED, 
        SDL_WINDOWPOS_UNDEFINED, 
        width, 
        height, 
        SDL_WINDOW_SHOWN
        );
    if (this->_window == NULL) {
        std::cout << "Failed to create window: " << SDL_GetError << std::endl;
    }
    this->_renderer = SDL_CreateRenderer(this->_window, -1, SDL_RENDERER_ACCELERATED);
}

SDL_Texture *WindowRenderer::loadStripe(const char* path)
{
    SDL_Texture* stripe = NULL;
    stripe = IMG_LoadTexture(this->_renderer, path);
    if (stripe == NULL) {
        std::cout << "Failed to load stripe: " << SDL_GetError << std::endl;
    }
    return stripe;
}

void WindowRenderer::display()
{
    SDL_RenderPresent(this->_renderer);
}

void WindowRenderer::destroy()
{
    SDL_DestroyWindow(this->_window);
}

void WindowRenderer::clear()
{
    SDL_RenderClear(this->_renderer);
}

void WindowRenderer::render()
{
    //Render something
    SDL_RenderSetLogicalSize(this->_renderer, 800, 900);

    //Set colour of renderer
    SDL_SetRenderDrawColor(this->_renderer,0,0,0,255);

    //Clear the screen to the set colour
    SDL_RenderClear(this->_renderer);

    //Show all the has been done behind the scenes
    SDL_RenderPresent(this->_renderer);
}
