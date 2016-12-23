#include <stdio.h>
#include <stdlib.h>
#include "Carte.h"


char* maping(DIM *dim)
{
    int i,j;
    char a;
    char* F = NULL;
    int D[2];
    F = fopen("Map.txt.txt","r");
    if(F==NULL){
        printf("La carte ne s'est pas ouverte.");
        exit(1);

    };
    fscanf(F,"%d %d ",&D[0],&D[1]);
    printf("Il y a %d lignes et %d colones \n",D[0],D[1]);
   // char M[D[0]][D[1]];
    char ** M = malloc(D[0]*sizeof(char));
    for(i=0;i<D[0];i++)
    {
        M[i]=malloc(D[1]*sizeof(char));
        for(j=0;j<D[1];j++)
        {
            M[i][j] = fgetc(F);
            //printf("%c",M[i][j]);
        }
        fgetc(F);

    }
/*    for(i=0;i<D[0];i++)
    {
        for(j=0;j<D[1];j++)
        {
            printf("%c",M[i][j]);
        }
        printf("\n");
    }
    /*for(i=0;i<100;i++)
    {
        printf("%c",F[i]);
    }*/
    fclose(F);
    dim->lignes = D[0];
    dim->colonnes = D[1];
    return M;
}


//void affichercarte()
