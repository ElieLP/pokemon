#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Carte.h"
#include <time.h>
#include <assert.h>

coordonnes genPokemon(char** CARTE, DIM dim)
{
    coordonnes coord;
    srand(time(NULL));
    coord.x = rand()%dim.colonnes;
    coord.y = rand()%dim.lignes;
    if((CARTE[coord.x][coord.y] == "#") || (CARTE[coord.x][coord.y] == "X")){
        return;// genPokemon(CARTE,dim);
    }
    else return coord;
}

struct pokemon* typing()
{
    pokemon *liste;
    int i=0,j;
    char* tab[256];
    char* pokemon[50][5];
    char line[256];
    FILE *F = NULL;
    F = fopen("pokemon.txt","r");
    if(F==NULL){
        printf("pokemon.txt ne s'est pas ouvert.");
        exit(2);
    }
    while (fgets(line, sizeof(line), F))
    {
        printf("%s", line);
        tab[i]=strdup(line);
        i++;
    }
    printf("%d",i);
    fclose(F);
    printf("\n");
    /* Sépare chacune des entrées du tableau */
    for (j=0;j<i;j++) {
        char** tokens;
        tab[j][ strlen(tab[j]) - 1 ] = '\0'; // supprime le \n
        printf("[%s]\n\n", tab[j]);

        tokens = str_split(tab[j], ' ');

        if (tokens)
        {
            int k;
            for (k = 0; *(tokens + k); k++)
            {
                pokemon[j][k]=*(tokens + k);
                printf("[%s]\n", *(tokens + k));
            }
            printf("\n");
            free(tokens);
        }
    }
    liste=malloc(256*sizeof(pokemon));
    for (j=0;j<i;j++){
        liste[j].id = atoi(pokemon[j][0]);
        liste[j].nom = pokemon[j][1];
        liste[j].element = pokemon[j][2];
        liste[j].force = atoi(pokemon[j][3]);
        liste[j].pv = atoi(pokemon[j][4]);
        printf("%d %s %s %d %d ",liste[j].id,liste[j].nom,liste[j].element,liste[j].force,liste[j].pv);
        printf("\n");
    }
    return liste;
}





