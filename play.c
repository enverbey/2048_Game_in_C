#include "Game_2048.h"

void play()
{
    int skor = 0;
    int i = 0;
    system("cls");
    int matrix[4][4] = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };
    while(i < 2)
    {
        int random1 = rand() % 4;
        int random2 = rand() % 4;
        matrix[random1][random2] = 2;
        i++;
    }
    char option = 'I';
    while(option != 'Q' && option != 'q')
    {
        game_scene(matrix, skor);
        printf("EXIS -> Q\n");
        printf("Enter your choise -> W,S,A,D\n");
        getchar();
        scanf("%c",&option);
        system("cls");
        if(option == 'A' || option == 'a')
        {
            skor = swipe_left(matrix,skor);
        }
        else if (option == 'W' || option == 'w')
        {
            turn_ccw(matrix);
            skor = swipe_left(matrix,skor);
            turn_ccw(matrix);
            turn_ccw(matrix);
            turn_ccw(matrix);
        }
        else if (option == 'D' || option == 'd')
        {
            turn_ccw(matrix);
            turn_ccw(matrix);
            skor = swipe_left(matrix,skor);
            turn_ccw(matrix);
            turn_ccw(matrix);
        }
        else if (option == 'S' || option == 's')
        {
            turn_ccw(matrix);
            turn_ccw(matrix);
            turn_ccw(matrix);
            skor = swipe_left(matrix,skor);
            turn_ccw(matrix);
        }
        add_number_to_matrix(matrix);
        if(control(matrix) == 0)
        {
            system("cls");
            printf("Malesef kaybettiniz, skorunuz : %d\n\n",skor);
            getchar();
            break;
        }
        else if(control(matrix) == 3)
        {
            system("cls");
            printf("!! Tebrikler kazandiniz !!\n\n\n Skorunuz : %d\n\n",skor);
            break;
        }
            
    }

}