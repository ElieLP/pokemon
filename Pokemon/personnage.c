#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#define MAX 10

char laby[MAX][MAX] = {
"**********",
"* *      *",
"* ****** *",
"*        *",
"* **** ***",
"*    *   *",
"* ** *** *",
"* ********",
"*        *",
"**********"
};

void Afficher(int x,int y)
{
    system("cls");
    int i,j;
    for(i=0;i<MAX;i++)
    {
        for(j=0;j<MAX;j++)
        {
            printf(" ");
            if (i==x && j==y)
                printf("X");
            else
                printf("%c",laby[i][j]);
        }
        printf("\n");
    }
}

void deplacer(int* x,int* y,int vx,int vy)
{
    if (laby[*x+vx][*y+vy]=='*')
    {
        return;
    } else {
        (*x)+=vx;
        (*y)+=vy;
    }
}
