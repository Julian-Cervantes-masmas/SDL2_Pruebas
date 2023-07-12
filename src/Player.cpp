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
  SDL_RenderCopyEx(renderer, texture, NULL, &pixelRect, rotationAngle, NULL, SDL_FLIP_NONE); //Textura personaje
}

void Player::playerMovement()//
{
const Uint8* keystates = SDL_GetKeyboardState(NULL);

  // Resetea el movimiento del jugador
  int dx = 0; //Delta_x
  int dy = 0; //Delta_y

  if (keystates[SDL_SCANCODE_UP])
  {
    dy -= player_speed;
  }
  if (keystates[SDL_SCANCODE_DOWN])
  {
    dy += player_speed;
  }
  if (keystates[SDL_SCANCODE_LEFT])
  {
    dx -= player_speed;
  }
  if (keystates[SDL_SCANCODE_RIGHT])
  {
    dx += player_speed;
  }

  // Checkea movimiento en diagonal
  if (dx != 0 && dy != 0)
  {
    //Divide la velocidad de movimiento para mantener la velocidad en diagonal
    dx = static_cast<int>(dx * 0.7071);
    dy = static_cast<int>(dy * 0.7071);
  }

  // Actualiza la posicion del jugador 
  /* setPlayer -> setea el valor a player_x -> getPlayer obtiene el valor de "player_x" y le suma el valor de "dx"
    por ejemplo si dx es -5 (player_speed = -5) y el valor de player_x es 0 -> entonces -> 0 + (-5) -> Es -5 nuevo valor de player_x
    que se va a renderizar en el SDL_RenderCopyEx de drawPlayer()*/
  setPlayer_x(getPlayer_x() + dx);
  setPlayer_y(getPlayer_y() + dy);

  // Rotation
  if (keystates[SDL_SCANCODE_E])
  {
    rotationAngle += 5.0f;
  }
  else if (keystates[SDL_SCANCODE_Q])
  {
    rotationAngle -= 5.0f;
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
