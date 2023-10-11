#pragma once
#include "../include/Map/MapParser.hpp"

MapParser *MapParser::Instance()
{
    return _instance = (_instance != nullptr) ? _instance : new MapParser();
}

bool MapParser::Load()
{

}

void MapParser::Clean()
{
    
}

Map *MapParser::GetMaps()
{
    return nullptr;
}

bool MapParser::Parse(std::string id, std::string src)
{
    return false;
}

Tileset MapParser::ParseTileset(TiXmlElement *xmlTileset)
{
    return Tileset();
}

TileLayer *MapParser::ParseTileLayer(TiXmlElement *xmlLayer, TilesetList tiles, int tileSize, int rowCount, int colCount)
{
    return nullptr;
}

