#include "Game_2048.h"

void add_number_to_matrix(int str_add[4][4])
{
    int number = 0;
    int list[16];
    while(number <= 15)
    {
        list[number] = 1;
        number++;
    }
    number = 0;
    int control_zero = 0;
    while(number <= 15)
    {
        if(str_add[number/4][number%4] == 0)
        {
            control_zero++;
            list[number] = 0;
        }
        number++;
    }
    if(control_zero > 0)
    {
        int random_number = rand() % 16;
        while(list[random_number] != 0)
        {
            random_number = rand() % 16;
        }
        str_add[random_number/4][random_number%4] = 2;
    }
}