#include "NPCS.h"

short int NPC::NPCposition(int randomNum)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<short int> dist (0,3);

    return randomNum = dist(gen);

}
void NPC::whiteSquareMovement()
{

    static std::chrono::steady_clock::time_point lastMoveTime = std::chrono::steady_clock::now();
    //Get the currrent time
    std::chrono::steady_clock::time_point currentTime = std::chrono::steady_clock::now();
    //Calcula el tiempo pasado desde el ultimo movimiento
    std::chrono::milliseconds timeElapsed = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - lastMoveTime);
    if(timeElapsed.count() >= 200){
        lastMoveTime = currentTime;
        int r;
        switch (NPCposition(r))
        {
            case 0:
                setWhite_x (getWhite_x() - 10);
                setWhite_y (getWhite_y() - 10);
                break;
            case 1:
                setWhite_x (getWhite_x() + 10);
                setWhite_y (getWhite_y() - 10);
                break;
            case 2:
                setWhite_x (getWhite_x() + 10);
                setWhite_y (getWhite_y() + 10);
                break;
            case 3:
                setWhite_x (getWhite_x() - 10);
                setWhite_y (getWhite_y() + 10);
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