#include <stdio.h>
#include <stdlib.h>
#include "Carte.h"

char* maping()
{
    int i;
    char* F = NULL;
    int D[2];
    F = fopen("Map.txt.txt","r");
    if(F==NULL){
        printf("La carte ne s'est pas ouverte.");
        exit(1);

    };
    fscanf(F,"%d %d %d",&D[0],&D[1]);
    printf("Il y a %d lignes et %d colones",D[0],D[1]);
    /*for(i=0;i<100;i++)
    {
        printf("%c",F[i]);
    }*/
    fclose(F);
}


//affichercarte()
