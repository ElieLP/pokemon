#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "Carte.h"

int main()
{
    int i,j;
    printf("\a");
    DIM dim;
    char ** map = maping(&dim);
    initMap();
    int x,y;  // position joueur
    int touche;
    x = y = 2;
    touche = 0;
    while(touche!='q')
    {
        Afficher(x,y);
        touche = getch();
        switch(touche)
        {
        case 'k':
            deplacer(&x,&y,0,-1);
            break;
        case 'm':
            deplacer(&x,&y,0,1);
            break;
        case 'o':
            deplacer(&x,&y,-1,0);
            break;
        case 'l':
            deplacer(&x,&y,1,0);
        default:
            break;
        }
    }
    return 0;

}
