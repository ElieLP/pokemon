#ifndef CARTE_H_INCLUDED
#define CARTE_H_INCLUDED

char* maping();

void affichercarte();

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
    char* espece;
    char* element;
    int force;
    int pv;
}pokemon;

#endif // CARTE_H_INCLUDED
