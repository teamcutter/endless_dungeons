#pragma once
#include "Layer.hpp"
#include <string>
#include <vector>

struct Tileset {
    int First, LastID, RowCount, ColCount, TileCount, TileSize;
    std::string Name, Src;
};

using TilesetList = std::vector<Tileset>;
using TileMap = std::vector<std::vector<int>>;

class TileLayer: public Layer {
private:
    int _tileSize, _rowCount, _colCount;
    TileMap _tileMap;
    TilesetList _tilesetList;

public:
    TileLayer(int tileSize, int rowCount, int colCount, TileMap tileMap, TilesetList tilesetList);

    virtual void Render();
    virtual void Update();
    TileMap GetTileMap();
};