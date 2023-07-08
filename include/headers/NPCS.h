#pragma once
#include "Utils.h"

class NPC
{
public:
    void whiteSquareMovement();
    int NPCposition();

    //SETTERS AND GETTERS
    void setWhite_x(int x){ white_x = x;}
    int getWhite_x() const { return white_x;}
    void setWhite_y(int y){ white_y = y; }
    int getWhite_y() const{ return white_y;}

private:
    
    int white_x = SCREEN_WIDTH / 2;
    int white_y = SCREEN_HEIGHT / 2;
};
