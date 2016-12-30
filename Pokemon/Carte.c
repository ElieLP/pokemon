#include <stdio.h>
#include <stdlib.h>
#include "Carte.h"
#include <time.h>
#include <windows.h>


char** maping(DIM *dim)
{
    int i,j;
    FILE *F = NULL;
    F = fopen("Map.txt.txt","r");
    if(F==NULL){
        printf("La carte ne s'est pas ouverte."); // Verifie que F pointe sur quelque chose
        exit(1);
    }
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
    int a,b=0;
    srand(time(NULL));
    for(i=0;i<3;i++)
    {
        a=b=0;
        while((M[b][a] == '#') || (M[b][a] == 'X'))
        {
            a=rand()%dim->lignes;
            b=rand()%dim->colonnes;
        }
        M[b][a] = '*';
        Sleep(1000);
    }
    fclose(F);
    return M;
}
