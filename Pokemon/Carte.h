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

coordonnes genPokemon(char**,DIM);
char** maping(DIM *);
#endif // CARTE_H_INCLUDED
