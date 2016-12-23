#include <stdio.h>
#include <stdlib.h>
#include "Carte.h"



int main()
{
    int i,j;
    DIM dim;
    char ** carte= NULL;
    carte = maping(&dim);
    /*for(i=0;i<dim.lignes;i++){
        for(j=0;j<dim.colonnes;j++){
            printf("%c",carte[i][j]);
        }
        printf("\n");
    }*/
//    affichercarte();
    return 0;
}
