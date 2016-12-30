#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Carte.h"
#include <time.h>
#include <assert.h>

pokemon* typing(int *taille)
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

        tokens = str_split(tab[j], ' ');

        if (tokens)
        {
            int k;
            for (k = 0; *(tokens + k); k++)
            {
                pokemon[j][k]=*(tokens + k);
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
        printf("\n");
    }
    *taille = j;
    return liste;
}
