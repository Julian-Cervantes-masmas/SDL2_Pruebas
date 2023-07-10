#pragma once
#include "Utils.h"

class Player
{
public:
    void drawPlayer(SDL_Renderer* renderer);
    void playerMovement(SDL_Keycode keyCode);
    void playerPosition();
    void collidesWithWall();

    //SETTERS AND GETTERS
    void setPlayer_x(int x){ player_x = x;}
    int getPlayer_x() const { return player_x;}
    void setPlayer_y(int y){ player_y = y; }
    int getPlayer_y() const{ return player_y;}
    void setPlayer_speed(double speed){ player_speed = speed;}
    int getPlayer_speed() const{ return player_speed;}

private:
    int player_x = SCREEN_WIDTH / 2;
    int player_y = SCREEN_HEIGHT / 2;
    double player_speed = 0;

    const double max_acceleration = 3;
    const double min_aceleration = 0;
};