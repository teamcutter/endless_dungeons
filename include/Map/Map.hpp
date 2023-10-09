#pragma once
#include <vector>
#include "Layer.hpp"

class Map {
public: 
    void Render();
    void Update();

    std::vector<Layer*> GetMapLayers();
private:
    std::vector<Layer*> _mapLayers;
};