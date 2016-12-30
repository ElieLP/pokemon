#include <stdio.h>
#include <stdlib.h>
#include <time.h>
<<<<<<< HEAD
#include "Carte.h"
=======
>>>>>>> f1944428086b17f1ac4971c9b5340f1be146be12
#include <windows.h>
#include "Carte.h"


pokemon *pokemons;
pokemon pokemonsJoueur[256];
int tailleListe;
int tailleMenu;
int idPokJoueur;

void attaque(pokemon* joueurS,pokemon* iaS)
 {
     if((joueurS->element == "electricite") && (iaS->element == "Eau"))
     {
         iaS->pv = iaS->pv - (2 + joueurS->force);
         printf("C'est très efficace\n");
         printf("L'attaque inflige %d points de dégats. Il reste %d points de vie a %s\n",2+joueurS->force,iaS->pv,iaS->nom);
     }
     else if((joueurS->element == "Eau") && (iaS->element == "Feu"))
     {
         iaS->pv = iaS->pv - (2 + joueurS->force);
         printf("C'est très efficace\n");
         printf("L'attaque inflige %d points de dégats. Il reste %d points de vie a %s\n",2+joueurS->force,iaS->pv,iaS->nom);
     }
     else if((joueurS->element) == "Feu" && (iaS->element == "Air"))
     {
         iaS->pv = iaS->pv - (2 + joueurS->force);
         printf("C'est très efficace\n");
         printf("L'attaque inflige %d points de dégats. Il reste %d points de vie a %s\n",2+joueurS->force,iaS->pv,iaS->nom);
     }
     else if((joueurS->element == "Air") && (iaS->element == "Terre"))
     {
         iaS->pv = iaS->pv - (2 + joueurS->force);
         printf("C'est très efficace\n");
         printf("L'attaque inflige %d points de dégats. Il reste %d points de vie à %s\n",2+joueurS->force,iaS->pv,iaS->nom);
     }
     else if((joueurS->element == "Terre") && (iaS->element == "Electricite"))
     {
         iaS->pv = iaS->pv - (2 + joueurS->force);
         printf("C'est très efficace\n");
         printf("L'attaque inflige %d points de dégats. Il reste %d points de vie a %s\n",2+joueurS->force,iaS->pv,iaS->nom);
     }
     else
     {
         iaS->pv = iaS->pv -joueurS->force;
         printf("C'est peu efficace\n");
         printf("L'attaque inflige %d points de dégats. Il reste %d points de vie a %s\n",joueurS->force,iaS->pv,iaS->nom);
     }

 }
 void echec()
 {
     printf("Il ne vous reste aucun Pokemon. Vous avez ECHOUÉ. Retentez votre chance pour vous améliorer.\n");
     Sleep(1000);
     printf("GAME OVER!\n");
     printf("You better improve yourself!");
     Sleep(1000);
     exit(0);
 }
<<<<<<< HEAD
=======



pokemon *pokemons;
pokemon pokemonsJoueur[256];
int tailleListe;
int tailleMenu;
>>>>>>> f1944428086b17f1ac4971c9b5340f1be146be12

void initPokemons(){
    pokemons = typing(&tailleListe);
    pokemonsJoueur[0].id=7;
    pokemonsJoueur[0].nom="Pikachu";
    pokemonsJoueur[0].element="Electricite";
    pokemonsJoueur[0].force=1;
    pokemonsJoueur[0].pv=5;
    tailleMenu=1;
}

pokemon menuPokemon(){
    int i,choix;
    system("cls");
    printf("Numero\tNom\tElement\t\tForce\tPV\n");
    for(i=0;i<tailleMenu;i++){
        printf("%d\t%s\t%s\t%d\t%d\n",i+1,pokemonsJoueur[idPokJoueur].nom,pokemonsJoueur[i].element,pokemonsJoueur[i].force,pokemonsJoueur[i].pv);
    }
    printf("Choisissez le pokemon qui doit combattre (Numéro) : ");
    scanf(&choix);
    choix--;
    idPokJoueur = choix;
    return pokemonsJoueur[choix];
}

void demarrerCombat(){
    srand(time(NULL));
    int idattaquant=rand()%tailleListe;
    pokemon attaquant, joueur;
    joueur = pokemonsJoueur[0];
    attaquant = pokemons[idattaquant];
    int touche=0;
    system("cls");
    printf("Un %s vous attaque\n",attaquant.nom);
    while(touche!='f')
    {
        printf("a : attaquer, f : fuir, c : changer\n");
        touche = getch();
        switch(touche)
        {
        case 'a':
            printf("Votre %s attaque\n",joueur.nom);
            Sleep(500);
            attaque(&joueur,&attaquant);
            if (attaquant.pv <= 0){tailleMenu++; pokemonsJoueur[tailleMenu-1]=pokemons[attaquant.id-1]; break;}
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
        default:
            break;
        }
    }
    printf("\nVous prenez la fuite...");
    Sleep(1000);
}
