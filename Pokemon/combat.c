#include <stdio.h>
#include <stdlib.h>
#include "Carte.h"
#include <windows.h>

void attaque(pokemon joueur,pokemon ia,pokemon* joueurS,pokemon* iaS)
 {
     if(joueur.element == 'electricite' || ia.element == 'Eau')
     {
         iaS->pv = ia.pv - (2 + joueur.force);
         printf("C'est tr�s efficaces");
         printf("L'attaque inflige %d points de d�gats. Il reste %d points de vie a %c",2+joueur.force,iaS->pv,iaS->nom);
     }
     if(joueur.element == 'Eau' || ia.element == 'Feu')
     {
         iaS->pv = ia.pv - (2 + joueur.force);
         printf("C'est tr�s efficaces");
         printf("L'attaque inflige %d points de d�gats. Il reste %d points de vie a %c",2+joueur.force,iaS->pv,iaS->nom);
     }
     if(joueur.element == 'Feu' || ia.element == 'Air')
     {
         iaS->pv = ia.pv - (2 + joueur.force);
         printf("C'est tr�s efficaces");
         printf("L'attaque inflige %d points de d�gats. Il reste %d points de vie a %c",2+joueur.force,iaS->pv,iaS->nom);
     }
     if(joueur.element == 'Air' || ia.element == 'Terre')
     {
         iaS->pv = ia.pv - (2 + joueur.force);
         printf("C'est tr�s efficaces");
         printf("L'attaque inflige %d points de d�gats. Il reste %d points de vie a %c",2+joueur.force,iaS->pv,iaS->nom);
     }
     if(joueur.element == 'Terre' || ia.element == 'electricite')
     {
         iaS->pv = ia.pv - (2 + joueur.force);
         printf("C'est tr�s efficaces");
         printf("L'attaque inflige %d points de d�gats. Il reste %d points de vie a %c",2+joueur.force,iaS->pv,iaS->nom);
     }
     else
     {
         iaS->pv = ia.pv -joueur.force;
         printf("C'est peu efficace, un joueur plus strat�gique aurait chang� de pok�mon.");
         printf("L'attaque inflige %d points de d�gats. Il reste %d points de vie a %c",joueur.force,iaS->pv,iaS->nom);
     }
     return;

 }




 echec()
 {
     printf("Il ne vous reste aucun Pokemon. Vous avez ECHOU�. Retenttez votre chance pour vous am�liorer.");
     Sleep(1000);
     printf("GAME OVER!");
     printf("You better improve yourself!");
     Sleep(1000);
     exit(0);
 }
