#include <stdio.h>
#include <stdlib.h>
#include "Carte.h"


char** maping(DIM *dim)
{
    int i,j;
    char a;
    char* F = NULL;
    F = fopen("Map.txt.txt","r");
    if(F==NULL){
        printf("La carte ne s'est pas ouverte.");
        exit(1);
    };
    fscanf(F,"%d %d ",&dim->lignes,&dim->colonnes);
    printf("Il y a %d lignes et %d colonnes \n",dim->lignes,dim->colonnes);
    char **M = malloc(dim->lignes*sizeof(char *));
    for(i=0;i<dim->lignes;i++)
    {
        M[i]=malloc(dim->colonnes*sizeof(char));
        for(j=0;j<dim->colonnes;j++)
        {
            M[i][j] = fgetc(F);
            printf(" ");
        }
        fgetc(F);
    }
    fclose(F);
    return M;
}
