#include <stdio.h>
#include <stdlib.h>
<<<<<<< HEAD
#include "Carte.h"
#include <windows.h>

void attaque(pokemon joueur,pokemon ia,pokemon* joueurS,pokemon* iaS)
 {
     if(joueur.element == 'electricite' || ia.element == 'Eau')
     {
         iaS->pv = ia.pv - (2 + joueur.force);
         printf("C'est très efficaces");
         printf("L'attaque inflige %d points de dégats. Il reste %d points de vie a %c",2+joueur.force,iaS->pv,iaS->nom);
     }
     if(joueur.element == 'Eau' || ia.element == 'Feu')
     {
         iaS->pv = ia.pv - (2 + joueur.force);
         printf("C'est très efficaces");
         printf("L'attaque inflige %d points de dégats. Il reste %d points de vie a %c",2+joueur.force,iaS->pv,iaS->nom);
     }
     if(joueur.element == 'Feu' || ia.element == 'Air')
     {
         iaS->pv = ia.pv - (2 + joueur.force);
         printf("C'est très efficaces");
         printf("L'attaque inflige %d points de dégats. Il reste %d points de vie a %c",2+joueur.force,iaS->pv,iaS->nom);
     }
     if(joueur.element == 'Air' || ia.element == 'Terre')
     {
         iaS->pv = ia.pv - (2 + joueur.force);
         printf("C'est très efficaces");
         printf("L'attaque inflige %d points de dégats. Il reste %d points de vie a %c",2+joueur.force,iaS->pv,iaS->nom);
     }
     if(joueur.element == 'Terre' || ia.element == 'electricite')
     {
         iaS->pv = ia.pv - (2 + joueur.force);
         printf("C'est très efficaces");
         printf("L'attaque inflige %d points de dégats. Il reste %d points de vie a %c",2+joueur.force,iaS->pv,iaS->nom);
     }
     else
     {
         iaS->pv = ia.pv -joueur.force;
         printf("C'est peu efficace, un joueur plus stratégique aurait changé de pokémon.");
         printf("L'attaque inflige %d points de dégats. Il reste %d points de vie a %c",joueur.force,iaS->pv,iaS->nom);
     }
     return;

 }




 echec()
 {
     printf("Il ne vous reste aucun Pokemon. Vous avez ECHOUÉ. Retenttez votre chance pour vous améliorer.");
     Sleep(1000);
     printf("GAME OVER!");
     printf("You better improve yourself!");
     Sleep(1000);
     exit(0);
 }
=======
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
>>>>>>> af396ffcb17b234d8d1ecdb8d8f807e05a36bdb8
