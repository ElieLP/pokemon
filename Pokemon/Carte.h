#ifndef CARTE_H_INCLUDED
#define CARTE_H_INCLUDED

char* maping();

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

coordonnes genPokemon(char** CARTE);


#endif // CARTE_H_INCLUDED
