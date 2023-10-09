#pragma once
#include "../include/Map/Map.hpp"

void Map::Render()
{
    for(auto layer: _mapLayers)
        layer->Render();
}

void Map::Update()
{
    for(auto layer: _mapLayers)
        layer->Update();
}

std::vector<Layer *> Map::GetMapLayers()
{
    return _mapLayers;
}
