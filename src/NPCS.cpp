#include "NPCS.h"


void NPC::whiteSquareMovement()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<short int> dist (0,3);

    short int randomNum = dist(gen); //LA UNICA PARTE QUE VA EN EL LOOP
    //Genera un numero del 0 al 3, modificando la posicion del rectangulo
    std::cout << randomNum;
    switch (randomNum)
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
    SDL_Delay(50);
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
