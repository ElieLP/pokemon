#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "Carte.h"
#include <time.h>

coordonnes genPokemon(char** CARTE, DIM dim)
{
    coordonnes coord;
    srand(time(NULL));
    coord.x = rand()%dim.colonnes;
    coord.y = rand()%dim.lignes;
    if((CARTE[coord.x][coord.y] == "#") || (CARTE[coord.x][coord.y] == "X")){
        return genPokemon(CARTE,dim);
    }
    else return coord;
}
