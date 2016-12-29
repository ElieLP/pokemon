#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Carte.h"

pokemon *pokemons;
int tailleListe;

void initPokemons(){
    pokemons = typing(&tailleListe);
}

void demarrerCombat(){
    srand(time(NULL));
    int touche=0;
    int attaquant=rand()%tailleListe;
    system("cls");
    printf("Un %s vous attaque\n",pokemons[attaquant].nom);
    while(touche!='f')
    {
        touche = getch();
        switch(touche)
        {
        case 'a':
            printf("Attaque !\n");
        default:
            break;
        }
    }
}
