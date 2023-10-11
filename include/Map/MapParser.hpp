#pragma once
#include <string>
#include <map>
#include "Map.hpp"
#include "TileLayer.hpp"
#include "../../Vendor/tinyxml/tinyxml.h"

class MapParser {
public:
    MapParser(){}
    static MapParser* _instance;
    std::map<std::string, Map*> _maps;

    bool Parse(std::string id, std::string src);
    Tileset ParseTileset(TiXmlElement* xmlTileset);
    TileLayer* ParseTileLayer(TiXmlElement* xmlLayer, TilesetList tiles, int tileSize, int rowCount, int colCount);

public:
    static MapParser* Instance();
    bool Load();
    void Clean();

    Map* GetMaps();
};