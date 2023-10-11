#pragma once
#include "../include/Map/TileLayer.hpp"

TileLayer::TileLayer(int tileSize, int rowCount, int colCount, TileMap tileMap, TilesetList tilesetList) {
    this->_titleSize = tileSize;
    this->_rowCount = rowCount;
    this->_colCount = colCount;
    this->_tileMap = tileMap;
    this->_tilesetList = tilesetList;
}

void TileLayer::Render() {}

void TileLayer::Update() {}