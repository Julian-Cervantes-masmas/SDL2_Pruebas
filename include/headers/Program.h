#pragma once
#include "Utils.h"
#include "NPCS.h"

class Program
{
public:
    bool ProgramInit();
    void HandleEvents();
    void ProgramLoop();
    void Update();
    void Draw();
    void Close();

private:
    SDL_Renderer* renderer = nullptr;
    SDL_Window* window = nullptr;
    bool programIsRunning = true;
    
    const int pixelSize = 10;
    int blue_x = SCREEN_WIDTH / 2;
    int blue_y = SCREEN_HEIGHT / 2;

    NPC npc;
};