#pragma once
#include "Utils.h"

class NPC
{
public:
    void drawNPC(SDL_Renderer* renderer);
    void whiteSquareMovement();
    short int NPCposition(int randomNum);
    

    //SETTERS AND GETTERS
    void setWhite_x(int x){ white_x = x;}
    int getWhite_x() const { return white_x;}
    void setWhite_y(int y){ white_y = y; }
    int getWhite_y() const{ return white_y;}

private:
    //TODO: Change the values to make the start of the NPC random -> Usando el mismo codigo de NPC position
    //Con los valores a generar entre 0 y SCREEN_HEIGHT para que sean por ejemplo valores entre (0, 720)p
    //GetPosition SetPosition
    int white_x = SCREEN_WIDTH / 2;
    int white_y = SCREEN_HEIGHT / 2;
};
