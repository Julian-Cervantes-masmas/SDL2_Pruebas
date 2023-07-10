#pragma once
#include "Utils.h"  

class World
{
public:
    World(){
        readWorld_txt();
    }
    void drawRectWall(SDL_Renderer *renderer, int x, int y);
    void drawRectTree(SDL_Renderer *renderer, int x, int y);
    void drawRectFloor(SDL_Renderer *renderer, int x, int y);
    void drawWorld (SDL_Renderer *renderer, const std::vector<std::string> &worldData);
    
    //Getter
    const std::vector<std::string>& getWorldData() const{return worldData;}

private:
    std::vector<std::string> worldData;
    void readWorld_txt();
};  