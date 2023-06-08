#include "Game_2048.h"

int how_many_digit_number(int number)
{
    int i = 0;
    while(number >= 10)
    {
        i++;
        number = number / 10;
    }
    return(i);
}