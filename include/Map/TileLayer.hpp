#pragma once
#include "Layer.hpp"
#include <string>
#include <vector>

struct Tileset {
    int First, LastID, RowCount, ColCount, TileCount, TileSize;
    std::string Name, Src;
};

using TileSet = std::vector<Tileset>;
using TileMap = std::vector<std::vector<int>>;

class TileLayer {
private:
    int _titleSize, _rowCount, _colCount;

public:
    TileLayer(){}
};