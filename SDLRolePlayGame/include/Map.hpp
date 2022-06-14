//
//  Map.hpp
//  SDLRolePlayGame
//
//  Created by Joe on 14/06/2022.
//

#ifndef Map_hpp
#define Map_hpp

#include <stdio.h>
#include "Game.hpp"

class Map{
public:
    Map();
    ~Map();
        
    void loadMap(int[20][25]);
    void drawMap();
    
private:
    SDL_Rect src, dest;
    
    SDL_Texture* dirt;
    SDL_Texture* grass;
    SDL_Texture* water;
    
    int map[20][25];
};




#endif /* Map_hpp */
