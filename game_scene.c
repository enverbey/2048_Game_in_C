#include "Game_2048.h"

void game_scene(int str[4][4], int skor)
{
    int i = 0, j;
    printf("  ==============2048===============              SKOR : %d\n",skor);
    while(i <= 3)
    {
        printf("  ---------------------------------\n");
        j = 0;
        while(j <= 3)
        {
            int bosluk_sayisi = (6 - how_many_digit_number(str[i][j]));
            if(bosluk_sayisi == 6)
                printf("|   %d   ",str[i][j] );
            else if(bosluk_sayisi == 5)
                printf("|   %d  ",str[i][j] );
            else if(bosluk_sayisi == 4)
                printf("|  %d  ",str[i][j] );
            else if(bosluk_sayisi == 3)
                printf("|  %d ",str[i][j] );
            j++;
        }
        printf("|\n");
        i++;
    }
    printf("  ---------------------------------\n");

}