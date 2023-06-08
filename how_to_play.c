#include "Game_2048.h"

int how_to_play()
{
    system("cls");
    int x;
    printf("A veya a sola kaydirir.\n");
    printf("W veya w yukari kaydirir.\n");
    printf("D veya d saga kaydirir.\n");
    printf("S veya s assagi kaydirir.\n");
    printf("Oyun sirasinda 'q' veya 'Q' oyunu bitirir.\n");
    printf("Back (1)\n");
    printf("Exit (3)\n");
    scanf("%d", &x);
    return(x);
}