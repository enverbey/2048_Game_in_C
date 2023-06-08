#include "Game_2048.h"

int is_equal_matrix(int matrix1[4][4], int matrix2[4][4])
{
    for (int i = 0; i < 4; i++) 
    {
        for (int j = 0; j < 4; j++) 
        {
            if(matrix1[i][j] != matrix2[i][j])
                return(0);
        }
    }
    return(1);
}