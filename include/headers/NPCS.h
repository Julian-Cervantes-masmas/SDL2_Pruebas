#pragma once
#include "Utils.h"

class NPC
{
public:
    void drawNPC(SDL_Renderer* renderer, SDL_Texture* texture);
    void drawNPC_chaser(SDL_Renderer* renderer, SDL_Texture* texture);
    void whiteSquareMovement();
    void whiteChaser();
    short int NPCposition(int randomNum);
    

    //SETTERS AND GETTERS
    void setWhite_x(int x){ white_x = x;}
    int getWhite_x() const { return white_x;}
    void setWhite_y(int y){ white_y = y; }
    int getWhite_y() const{ return white_y;}

    void setRed_x(int x){ red_x = x;}
    int getRed_x() const { return red_x;}
    void setRed_y(int y){ red_y = y; }
    int getRed_y() const{ return red_y;}

private:
    int white_x = SCREEN_WIDTH / 2;
    int white_y = SCREEN_HEIGHT / 2;

    int red_x = SCREEN_WIDTH / 2;
    int red_y = SCREEN_HEIGHT / 2;
};
