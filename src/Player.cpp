#include "Program.h"
Program program;

void Player::drawPlayer(SDL_Renderer* renderer, SDL_Texture* texture)
{
  //SDL_SetRenderDrawColor(renderer, 50, 50, 255, 255); //Color del rectangulo
  SDL_Rect pixelRect;
  pixelRect.x = getPlayer_x();
  pixelRect.y = getPlayer_y();
  pixelRect.w = pixelSize; //Tamaño ancho (width)
  pixelRect.h = pixelSize; //Tamaño alto (height)

  //SDL_RenderFillRect(renderer, &pixelRect); //Dibuja el rectangulo
  SDL_RenderCopy(renderer, texture, NULL, &pixelRect); //Textura personaje
}

void Player::playerMovement()//
{
  const Uint8* keystates = SDL_GetKeyboardState(NULL);
  if (keystates[SDL_SCANCODE_UP])
  {
    setPlayer_y(getPlayer_y() - player_speed);
  }
  else if (keystates[SDL_SCANCODE_LEFT])
  {
    setPlayer_x(getPlayer_x() - player_speed);
  }
  else if (keystates[SDL_SCANCODE_RIGHT])
  {
    setPlayer_x(getPlayer_x() + player_speed);
  }
  else if (keystates[SDL_SCANCODE_DOWN])
  {
    setPlayer_y(getPlayer_y() + player_speed);
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

