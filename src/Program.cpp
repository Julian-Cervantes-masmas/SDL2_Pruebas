#include "Program.h"
#include "NPCS.h"

bool Program::ProgramInit()
{
  SDL_Init(SDL_INIT_VIDEO);
  IMG_Init(IMG_INIT_PNG);

  window = SDL_CreateWindow("Programa", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
  if (window == nullptr)
  {
  SDL_Quit();
  return -1;
  }
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
  if (renderer == nullptr)
  {
    SDL_DestroyWindow(window);
    SDL_Quit();
    return -1;
  }
  return 0;
}

void Program::ProgramLoop()
{
    while(programIsRunning){
        HandleEvents();
        Update();
        Draw();
    }
}


void Program::HandleEvents()
{
  /*  Event Handler  */
  SDL_Event event;
  while(SDL_PollEvent(&event)){
    if(event.type == SDL_QUIT){
      programIsRunning = false;
    }
    else if (event.type == SDL_KEYDOWN){
      switch(event.key.keysym.sym)
      {
        case SDLK_UP:
            blue_y -= 10;
            break;
        case SDLK_LEFT:
            blue_x -= 10;
            break;
        case SDLK_RIGHT:
            blue_x += 10;
            break;
        case SDLK_DOWN:
            blue_y += 10;
            break;
      }
    }
    else if(event.type == SDL_KEYUP){
      switch (event.key.keysym.sym)
      {
      case SDLK_UP:
        break;
      case SDLK_LEFT:
        break;
      case SDLK_RIGHT:
        break;
      case SDLK_DOWN:
        break;
      }
    }
  }
}

void Program::Update()
{

    //Generar movimiento random en el rectangulo blanco
    npc.whiteSquareMovement();
    //Hacer que el rectangulo aparezca por el otro lado:
    if ( blue_x > SCREEN_WIDTH){
        blue_x = 0;
    }
    else if (blue_x < 0){
        blue_x = SCREEN_WIDTH;
    }
    else if ( blue_y > SCREEN_HEIGHT){
        blue_y = 0;
    }
    else if (blue_y < 0){
        blue_y = SCREEN_HEIGHT;
    }

}

void Program::Draw()
{
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_RenderClear(renderer);

  SDL_SetRenderDrawColor(renderer, 50, 50, 255, 255);

    /*      RECTANGULO AZUL       */
  SDL_Rect pixelRect;
  pixelRect.x = blue_x;
  pixelRect.y = blue_y;
  pixelRect.w = pixelSize; //Tamaño ancho (width)
  pixelRect.h = pixelSize; //Tamaño alto (height)
  SDL_RenderFillRect(renderer, &pixelRect); //Dibuja el rectangulo

    /*      RECTANGULO BLANCO       */
  SDL_SetRenderDrawColor(renderer, 250, 255, 255, 255);
  SDL_Rect whiteRect;
  whiteRect = {npc.getWhite_x(), npc.getWhite_y(), pixelSize, pixelSize};
  SDL_RenderFillRect (renderer, &whiteRect);

  SDL_RenderPresent(renderer);


}

void Program::Close()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
