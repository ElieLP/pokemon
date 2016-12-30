#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "Carte.h"
#include <time.h>

coordonnes collection[256] = {7};

int main()
{
    initMap();
    initPokemons();
    int x,y;  // position joueur
    int touche;
    x = y = 1;
    touche = 0;
    while(touche!='q')
    {
        Afficher(x,y);
        srand(time(NULL));
        if(rand()%3==1){genPokemon();}
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
