#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "Carte.h"

pokemon *pokemons;
pokemon pokemonsJoueur[256];
int tailleListe;
int tailleMenu;

void initPokemons(){
    pokemons = typing(&tailleListe);
    pokemonsJoueur[0].id=7;
    pokemonsJoueur[0].nom="Pikachu";
    pokemonsJoueur[0].element="electricite";
    pokemonsJoueur[0].force=1;
    pokemonsJoueur[0].pv=5;
    tailleMenu=1;
}

pokemon menuPokemon(){
    int i,choix;
    system("cls");
    printf("Numero\tNom\tElement\t\tForce\tPV\n");
    for(i=0;i<tailleMenu;i++){
        printf("%d\t%s\t%s\t%d\t%d\n",i+1,pokemonsJoueur[i].nom,pokemonsJoueur[i].element,pokemonsJoueur[i].force,pokemonsJoueur[i].pv);
    }
    printf("Choisissez le pokemon qui doit combattre (Numéro) : ");
    scanf(&choix);
    choix--;
    return pokemonsJoueur[choix];
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
            break;
        case 'c':
            menuPokemon();
            break;
        default:
            break;
        }
    }
    printf("\nVous prenez la fuite...");
    Sleep(1000);
}
