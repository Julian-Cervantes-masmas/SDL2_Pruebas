#include "Program.h"
Program program;

void Player::drawPlayer(SDL_Renderer* renderer)
{
  SDL_SetRenderDrawColor(renderer, 50, 50, 255, 255);
  SDL_Rect pixelRect;
  pixelRect.x = getPlayer_x();
  pixelRect.y = getPlayer_y();
  pixelRect.w = pixelSize; //Tamaño ancho (width)
  pixelRect.h = pixelSize; //Tamaño alto (height)

  SDL_RenderFillRect(renderer, &pixelRect); //Dibuja el rectangulo
}

void Player::playerMovement(SDL_Keycode keyCode)
{
    switch (keyCode)
    {
        case SDLK_UP:
          setPlayer_y(getPlayer_y() - pixelSize);
          break;
        case SDLK_LEFT:
          setPlayer_x(getPlayer_x() - pixelSize);
          break;
        case SDLK_RIGHT:
          setPlayer_x(getPlayer_x() + pixelSize);
          break;
        case SDLK_DOWN:
          setPlayer_y(getPlayer_y() + pixelSize);
          break;
    }
}
void Player::playerPosition()
{
    //Hacer que el rectangulo aparezca por el otro lado:
    if ( getPlayer_x() > SCREEN_WIDTH){
        setPlayer_x(0);
    }
    else if (getPlayer_x() < 0){
        setPlayer_x(SCREEN_WIDTH);
    }
    else if ( getPlayer_y() > SCREEN_HEIGHT){
       setPlayer_y(0);
    }
    else if (getPlayer_y() < 0){
        setPlayer_y(SCREEN_HEIGHT);
    }

}