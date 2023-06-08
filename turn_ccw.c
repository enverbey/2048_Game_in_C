#include "Game_2048.h"

void turn_ccw(int str_turn[4][4])
{
    char copy_matrix[4][4];
    for (int i = 0; i < 4; i++) 
    {
        for (int j = 0; j < 4; j++) 
        {
            copy_matrix[i][j] = str_turn[i][j];
        }
    }
    int number = 0;
    for(int j = 0; j < 4; j++)
    {
        for(int i=3; i >= 0; i--)
        {
            str_turn[i][j] = copy_matrix[number/4][number%4];
            number++;
        }
    }
}