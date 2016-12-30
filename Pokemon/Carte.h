#ifndef CARTE_H_INCLUDED
#define CARTE_H_INCLUDED

typedef struct
{
    int lignes;
    int colonnes;
}DIM;

typedef struct
{
    int x;
    int y;
}coordonnes;

typedef struct
{
    int id;
    char* nom;
    char* element;
    int force;
    int pv;
}pokemon;


void genPokemon();

pokemon* typing();


char** maping(DIM *);

void attaque(pokemon joueur,pokemon ia,pokemon* joueurS,pokemon* iaS);

void echec();

#endif // CARTE_H_INCLUDED
