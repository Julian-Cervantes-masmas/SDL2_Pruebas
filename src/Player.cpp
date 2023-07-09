#include "Program.h"
Program program;

void Player::drawPlayer(SDL_Renderer* renderer)
{
  SDL_Rect pixelRect;
  pixelRect.x = getPlayer_x();
  pixelRect.y = getPlayer_y();
  pixelRect.w = program.pixelSize; //Tamaño ancho (width)
  pixelRect.h = program.pixelSize; //Tamaño alto (height)

  SDL_RenderFillRect(renderer, &pixelRect); //Dibuja el rectangulo
}

void Player::playerMovement(SDL_Keycode keyCode)
{
    switch (keyCode)
    {
        case SDLK_UP:
          setPlayer_y(getPlayer_y() - 10);
          break;
        case SDLK_LEFT:
          setPlayer_x(getPlayer_x() - 10);
          break;
        case SDLK_RIGHT:
          setPlayer_x(getPlayer_x() + 10);
          break;
        case SDLK_DOWN:
          setPlayer_y(getPlayer_y() + 10);
          break;
    }
}