#pragma once
#include "../include/Map/TileLayer.hpp"
#include "../include/Graphics/SpriteManager.hpp"
#include "iostream"

TileLayer::TileLayer(int tileSize, int rowCount, int colCount, TileMap tileMap, TilesetList tilesetList): _tileSize(tileSize),
_colCount(colCount), _rowCount(rowCount), _tileMap(tileMap), _tilesetList(tilesetList){

    for(unsigned int i=0; i < _tilesetList.size(); i++)
        SpriteManager::Instance()->Create(_tilesetList[i].Name, "res/assets/maps/" + _tilesetList[i].Src);
}

void TileLayer::Render() 
{
    for(unsigned int i = 0; i < _rowCount; i++){
        for(unsigned int j = 0; j < _colCount; j++){

            int tileID = _tileMap[i][j];
            int temp = tileID;

            if(tileID == 0)
                continue;

            else{
                int index = 0;
                if(_tilesetList.size() > 1){
                    for(unsigned int k = 1; k < _tilesetList.size(); k++){
                        if(tileID > _tilesetList[k].FirstID && tileID < _tilesetList[k].LastID){
                            tileID = tileID + _tilesetList[k].TileCount - _tilesetList[k].LastID;
                            index = k;
                            break;
                        }
                    }
                }

                Tileset ts = _tilesetList[index];
                int tileRow = tileID/ts.ColCount;
                int tileCol = tileID - tileRow*ts.ColCount-1;

                // if this tile is on the last column
                if(tileID % ts.ColCount == 0){
                    tileRow--;
                    tileCol = ts.ColCount - 1;
                }

                SpriteManager::Instance()->DrawTile(ts.Name, ts.TileSize, j*ts.TileSize, i*ts.TileSize, tileRow, tileCol);
            }
        }
    }
}

void TileLayer::Update() 
{

}