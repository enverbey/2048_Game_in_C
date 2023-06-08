#include "Game_2048.h"

void Tablo_yazdir()
{
    printf("  ==============2048===============\n");
    printf("  ---------------------------------\n");
    printf("  |   0   |   0   |   0   |   0   |\n");
    printf("  ---------------------------------\n");
    printf("  |   0   |   0   |   0   |   0   |\n");
    printf("  ---------------------------------\n");
    printf("  |   0   |   0   |   0   |   0   |\n");
    printf("  ---------------------------------\n");
    printf("  |   0   |   0   |   0   |   0   |\n");
    printf("  ---------------------------------\n");
    while(1)
    {
        printf("Play (1).\n");
        printf("How to play (2)\n");
        printf("Exit (3)\n");
        int control;
        scanf("%d", &control);
        if(control == 1)
        {
            play();
        }
        else if(control == 2)
        {
            int x;
            x = how_to_play();
            if(x == 3)
            {
                system("cls");
                break;
            }
            if(x == 1)
            {
                system("cls");
                //kendini tekrarlayan fonksiyon
                Tablo_yazdir();
                break;
            }
        }
        else if(control == 3)
        {
            system("cls");
            break;
        }
        else 
        {
            system("cls");
            printf("You should enter only between 1-3! Try again\n");
        }
    }
}

int main() 
{
    srand(time(NULL));
    Tablo_yazdir();
    return 0;
}