#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "Carte.h"
#include <time.h>

coordonnes genPokemon(char** CARTE, DIM dim)
{
    int a,b;
    coordonnes coord;
    srand(time(NULL));
    a=0;
    b=0;
    while((CARTE[b][a] == '#') || (CARTE[b][a] == 'X')){
        a = rand()%dim.colonnes;
        b = rand()%dim.lignes;
    }
        coord.x = a;
        coord.y = b;
        return coord;
}

