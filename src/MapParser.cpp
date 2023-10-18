#pragma once
#include "../include/Map/MapParser.hpp"

MapParser* MapParser::_instance = nullptr;

MapParser *MapParser::Instance()
{
    return _instance = (_instance != nullptr) ? _instance : new MapParser();
}

bool MapParser::Load()
{
   return Parse("map", "res/assets/maps/map2.tmx");
}


Map *MapParser::GetMap(std::string id)
{
    return _maps[id];
}

bool MapParser::Parse(std::string id, std::string src)
{
    TiXmlDocument xml;
    xml.LoadFile(src);
    if(xml.Error()) {
        std::cerr << "Failed to load: " << src << std::endl;
        return false;
    }

    TiXmlElement* root = xml.RootElement();
    int rowCount, colCount, tilesize = 0;
    root->Attribute("width", &colCount);
    root->Attribute("height", &rowCount);
    root->Attribute("tilewidth", &tilesize);

    TilesetList tilesets;

    for(TiXmlElement* e=root->FirstChildElement(); e!= nullptr; e=e->NextSiblingElement()){
        if(e->Value() == std::string("tileset")){
            tilesets.push_back(ParseTileset(e));
        }
    }

    Map* gameMap = new Map();
    for(TiXmlElement* e=root->FirstChildElement(); e!= nullptr; e=e->NextSiblingElement()){
        if(e->Value() == std::string("layer")){
            TileLayer* tilelayer = ParseTileLayer(e, tilesets, tilesize, rowCount, colCount);
            gameMap->_mapLayers.push_back(tilelayer);
        }
    }

    _maps[id] = gameMap;
    return true;
}

Tileset MapParser::ParseTileset(TiXmlElement *xmlTileset)
{
    Tileset tileset;
    tileset.Name = xmlTileset->Attribute("name");
    xmlTileset->Attribute("firstgid", &tileset.FirstID);

    xmlTileset->Attribute("tilecount", &tileset.TileCount);
    tileset.LastID = (tileset.FirstID + tileset.TileCount) - 1;

    xmlTileset->Attribute("columns", &tileset.ColCount);
    tileset.RowCount = tileset.TileCount / tileset.ColCount;
    xmlTileset->Attribute("tilewidth", &tileset.TileSize);

    TiXmlElement* img = xmlTileset->FirstChildElement();
    tileset.Src = img->Attribute("source");
    return tileset;
}

TileLayer *MapParser::ParseTileLayer(TiXmlElement *xmlLayer, TilesetList tiles, int tileSize, int rowCount, int colCount)
{
    TiXmlElement* data;
    for(TiXmlElement* e = xmlLayer->FirstChildElement(); e != nullptr; e = e->NextSiblingElement()) {
        if(e->Value() == std::string("data")) {
            data = e;
            break;
        }
    }

    std::string matrix(data->GetText());
    std::istringstream iss(matrix);
    std::string id;

    TileMap tilemap(rowCount, std::vector<int>(colCount, 0));

    for(int row = 0; row < rowCount; row++) {
        for(int col = 0; col < colCount; col++) {
            getline(iss, id, ',');
            std::stringstream convertor(id);
            convertor >> tilemap[row][col];

            if(!iss.good())
                break;
        }
    }

    return (new TileLayer(tileSize, rowCount, colCount, tilemap, tiles));
}

void MapParser::Clean()
{
    for(auto it = _maps.begin(); it != _maps.end(); it++) {
        it->second = nullptr;
    }

    _maps.clear();
}
