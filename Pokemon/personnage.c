#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "Carte.h"

char ** CARTE = NULL;
DIM DIMENSIONS;

void initMap(){
    CARTE = maping(&DIMENSIONS);
}

void Afficher(int x,int y)
{
    system("cls");
    int i,j;

    for(i=0;i<DIMENSIONS.lignes;i++)
    {
        for(j=0;j<DIMENSIONS.colonnes;j++)
        {
            printf(" ");
            if (i==x && j==y)
                printf("X");
            else
                printf("%c",CARTE[i][j]);
        }
        printf("\n");
    }
    printf("\nq : quitter \no,k,l,m : se deplacer");
}

void deplacer(int* x,int* y,int vx,int vy)
{
    if (CARTE[*x+vx][*y+vy]=='#')
    {
        return;
    } else {
        (*x)+=vx;
        (*y)+=vy;
    }
}
