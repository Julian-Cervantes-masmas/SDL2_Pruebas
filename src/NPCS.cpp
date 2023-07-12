#include "NPCS.h"

void NPC::drawNPC(SDL_Renderer* renderer, SDL_Texture* textureNPC)
{
  //SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); //Color del rectangulo
  SDL_Rect whiteRect;
  whiteRect = {getWhite_x(), getWhite_y(), pixelSize, pixelSize};

  //SDL_RenderFillRect (renderer, &whiteRect); //Dibuja rectangulo
  SDL_RenderCopy(renderer, textureNPC, NULL, &whiteRect);
}
void NPC::drawNPC_chaser(SDL_Renderer* renderer, SDL_Texture* textureNPC)
{
    //SDL_SetRenderDrawColor(renderer, 255, 50, 50, 255); //Color del rectangulo
    SDL_Rect redRect;
    redRect = {getRed_x(), getRed_y(), pixelSize, pixelSize};

    //SDL_RenderFillRect (renderer, &redRect); // rectangulo
    SDL_RenderCopy(renderer, textureNPC, NULL, &redRect);
}
short int NPC::NPCposition()
{
    std::uniform_int_distribution<short int> dist (0,3);
    return dist(gen);
}
void NPC::whiteChaser()
{
    
}
void NPC::whiteSquareMovement()
{

    static std::chrono::steady_clock::time_point lastMoveTime = std::chrono::steady_clock::now();
    //Get the currrent time
    std::chrono::steady_clock::time_point currentTime = std::chrono::steady_clock::now();
    //Calcula el tiempo que paso desde el ultimo movimiento
    std::chrono::milliseconds timeElapsed = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - lastMoveTime);
    if(timeElapsed.count() >= 200){
        lastMoveTime = currentTime;

        NPCpos = NPCposition();
        std::cout << NPCpos;

        switch (NPCpos)
        {
            case 0:
                setWhite_x (getWhite_x() - pixelSize);
                setWhite_y (getWhite_y() - pixelSize);
                break;
            case 1:
                setWhite_x (getWhite_x() + pixelSize);
                setWhite_y (getWhite_y() - pixelSize);
                break;
            case 2:
                setWhite_x (getWhite_x() + pixelSize);
                setWhite_y (getWhite_y() + pixelSize);
                break;
            case 3:
                setWhite_x (getWhite_x() - pixelSize);
                setWhite_y (getWhite_y() + pixelSize);
                break;
        }

        //Rectangulo aparece al otro lado de la pantalla
        if ( getWhite_x() > SCREEN_WIDTH){
            setWhite_x(0);
        }
        else if (getWhite_x() < 0){
            setWhite_x(SCREEN_WIDTH);
        }
        else if ( getWhite_y() > SCREEN_HEIGHT){
            setWhite_y(0);
        }
        else if (getWhite_y() < 0){
            setWhite_y(SCREEN_HEIGHT);
        }
    }
}