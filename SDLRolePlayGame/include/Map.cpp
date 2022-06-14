//
//  Map.cpp
//  SDLRolePlayGame
//
//  Created by Joe on 14/06/2022.
//

#include "Map.hpp"
#include "TextureManager.h"


int level1[20][25] = {//rows x cols
    {2,2,2,2,2,1,1,1,1,1,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {2,2,2,2,1,1,1,1,1,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};
    //water = 0
    //grass = 1
    //dirt = 2
Map::Map()
{
    dirt = TextureManager::loadTexture("SDLRolePlayGame/Assets/Map/dirt.png");
    grass = TextureManager::loadTexture("SDLRolePlayGame/Assets/Map/grass.png");
    water = TextureManager::loadTexture("SDLRolePlayGame/Assets/Map/water.png");
    
    loadMap(level1);
    
    src.x = src.y = 0;
    src.w = dest.w = 28;
    src.h = dest.h = 28;
    
    dest.x = dest.y = 0;
}

void Map::loadMap(int arr[20][25])
{
    for(int row = 0; row<20; row++){
        for(int column = 0; column <25; column++){
            map[row][column] = arr[row][column];
        }
    }
    
}

void Map::drawMap()
{
    int type = 0;
    for(int row = 0; row<20; row++){
        for(int column = 0; column <25; column++){
            type = map[row][column];
            dest.x = column*28;
            dest.y = row*28;
            
            switch(type){
                case 0:
                    TextureManager::draw(water, src, dest);
                    break;
                case 1:
                    TextureManager::draw(grass, src, dest);
                    break;
                case 2:
                    TextureManager::draw(dirt, src, dest);
                    break;
                default:
                    break;
            }
        }
    }
    
}
