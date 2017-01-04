#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "Carte.h"
#include <strings.h>
#include <stdbool.h>

pokemon *pokemons;
pokemon pokemonsJoueur[256];
int tailleListe;
int tailleMenu;
int idPokJoueur;

void attaque(pokemon* joueurS,pokemon* iaS)
 {
     if((strcmp(joueurS->element,"Elec") == 0) && (strcmp(iaS->element,"Eau")==0))
     {
         iaS->pv = iaS->pv - (2 + joueurS->force);
         printf("C'est tres efficace\n");
         printf("L'attaque inflige %d points de degats. Il reste %d points de vie a %s\n",2+joueurS->force,iaS->pv,iaS->nom);
     }
    if((strcmp(joueurS->element,"Tenebre") == 0) && (strcmp(iaS->element,"Psy")==0))
     {
         iaS->pv = iaS->pv - (2 + joueurS->force);
         printf("C'est tres efficace\n");
         printf("L'attaque inflige %d points de degats. Il reste %d points de vie a %s\n",2+joueurS->force,iaS->pv,iaS->nom);
     }
     else if((strcmp(joueurS->element,"Eau") == 0) && (strcmp(iaS->element,"Feu")==0))
     {
         iaS->pv = iaS->pv - (2 + joueurS->force);
         printf("C'est tres efficace\n");
         printf("L'attaque inflige %d points de degats. Il reste %d points de vie a %s\n",2+joueurS->force,iaS->pv,iaS->nom);
     }
     else if((strcmp(joueurS->element,"Feu") == 0) && (strcmp(iaS->element,"Air")==0))
     {
         iaS->pv = iaS->pv - (2 + joueurS->force);
         printf("C'est tres efficace\n");
         printf("L'attaque inflige %d points de degats. Il reste %d points de vie a %s\n",2+joueurS->force,iaS->pv,iaS->nom);
     }
     else if((strcmp(joueurS->element,"Air") == 0) && (strcmp(iaS->element,"Terre")==0))
     {
         iaS->pv = iaS->pv - (2 + joueurS->force);
         printf("C'est tres efficace\n");
         printf("L'attaque inflige %d points de degats. Il reste %d points de vie à %s\n",2+joueurS->force,iaS->pv,iaS->nom);
     }
     else if((strcmp(joueurS->element,"Terre") == 0) && (strcmp(iaS->element,"Elec")==0))
     {
         iaS->pv = iaS->pv - (2 + joueurS->force);
         printf("C'est tres efficace\n");
         printf("L'attaque inflige %d points de degats. Il reste %d points de vie a %s\n",2+joueurS->force,iaS->pv,iaS->nom);
     }
     else
     {
         iaS->pv = iaS->pv - joueurS->force;
         printf("C'est peu efficace\n");
         printf("L'attaque inflige %d points de degats. Il reste %d points de vie a %s\n",joueurS->force,iaS->pv,iaS->nom);
     }

 }
 void echec()
 {
     system("cls");
     printf("Il ne vous reste aucun Pokemon. Vous avez ECHOUE. Retentez votre chance pour vous ameliorer.\n");
     Sleep(1000);
     printf("GAME OVER!\n");
     printf("You better improve yourself!");
     Sleep(1000);
     exit(0);
 }

void initPokemons(){
    int i;
    pokemons = typing(&tailleListe);
    for (i=0;i<256;i++){
            pokemonsJoueur[i].pv=-1;
    }
    pokemonsJoueur[0].id=7;
    pokemonsJoueur[0].nom="Pikachu";
    pokemonsJoueur[0].element="Elec";
    pokemonsJoueur[0].force=1;
    pokemonsJoueur[0].pv=5;
    tailleMenu=1;
}

pokemon menuPokemon(){
    int i,choix,count;
    count=0;
    system("cls");
    printf("Numero\tNom\tElement\tForce\tPV\n");
    for(i=0;i<tailleMenu;i++){
        if (pokemonsJoueur[i].pv<=0){count++;}
        else {printf("%d\t%s\t%s\t%d\t%d\n",i+1,pokemonsJoueur[i].nom,pokemonsJoueur[i].element,pokemonsJoueur[i].force,pokemonsJoueur[i].pv);}
    }
    if(count >= tailleMenu){echec();}
    printf("Choisissez le pokemon qui doit combattre (Numero) (quitter:0) : ");
    scanf("%d",&choix);
    choix--;
    if (choix >=0) {
        system("cls");
        idPokJoueur = choix;
        return pokemonsJoueur[choix];
    } else if (choix <= 0) {
        system("cls");return pokemonsJoueur[idPokJoueur];
    } else if (pokemonsJoueur[choix].pv<=0){ printf("Vous ne pouvez pas choisir ce Pokemon\n");Sleep(1500);system("cls");menuPokemon();
    } else {system("cls");return pokemonsJoueur[idPokJoueur];}
}

void demarrerCombat(){
    srand(time(NULL));
    int flag = 1;
    int idattaquant=rand()%tailleListe;
    pokemon attaquant, joueur;
    joueur = pokemonsJoueur[idPokJoueur];
    attaquant = pokemons[idattaquant];
    int touche=0;
    system("cls");
    printf("Un %s vous attaque\n",attaquant.nom);
    while((touche!='f') && (flag == 1))
    {
        printf("a : attaquer, f : fuir, c : changer\n");
        touche = getch();
        switch(touche)
        {
        case 'a':
            printf("Votre %s attaque\n",joueur.nom);
            Sleep(500);
            attaque(&joueur,&attaquant);
            if (attaquant.pv <= 0){tailleMenu++; pokemonsJoueur[tailleMenu-1]=pokemons[idattaquant]; flag=0; break;}
            Sleep(1500);
            printf("%s ennemi attaque\n",attaquant.nom);
            Sleep(500);
            attaque(&attaquant,&joueur);
            Sleep(1500);
            pokemonsJoueur[idPokJoueur].pv=joueur.pv;
            if (joueur.pv <= 0) {joueur=menuPokemon(); break;}
            break;
        case 'c':
            joueur=menuPokemon();
            break;
        }
    }
    if (flag == 0) {printf("Vous avez gagne le combat");}
    else {printf("\nVous prenez la fuite...");}

    Sleep(1000);
}
