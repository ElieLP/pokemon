#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "Carte.h"
#include <time.h>

coordonnes genPokemon(char** CARTE)
{
    coordonnes coord;
    DIM dim;
    int i = 0;
    srand(time(NULL));
    coord.x = rand()%dim.colonnes;
    coord.y = rand()%dim.lignes;
    if(CARTE[coord.x][coord.y] == "#"){
        return genPokemon(CARTE);
    }
    else return coord;
}


