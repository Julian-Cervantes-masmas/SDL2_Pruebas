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
      player.playerMovement(event.key.keysym.sym);
      switch(event.key.keysym.sym)
      {
        case SDLK_ESCAPE:
          programIsRunning = false;
          break;
      }
    }
    else if(event.type == SDL_KEYUP){
      switch (event.key.keysym.sym)
      {
      case SDLK_UP:
      case SDLK_LEFT:
      case SDLK_RIGHT:
      case SDLK_DOWN:
        break;
      }
    }
  }
}

void Program::Update()
{

    npc.whiteSquareMovement();
    player.playerPosition();

}

void Program::Draw()
{
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_RenderClear(renderer);

    /*  MAPA                    */
  world.drawWorld(renderer, world.getWorldData());
    /*  JUGADOR                 */
  player.drawPlayer(renderer);
    /*  RECTANGULO BLANCO  (npc)*/
  npc.drawNPC(renderer);

  SDL_RenderPresent(renderer);

}

void Program::Close()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}