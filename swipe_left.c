#include "Game_2048.h"

int swipe_left(int str_swp[4][4], int skor)
{
    int i = 0, j1, j2, control;
    while (i < 4)
    {
        j1 = 0;
        while(j1 < 4)
        {
            j2 = j1 + 1;
            while(j2 < 4)
            {
                control = j2 - j1;
                switch(control)
                {
                    case 1:
                        if(str_swp[i][j1] == str_swp[i][j2])
                        {
                            str_swp[i][j1] = str_swp[i][j1] + str_swp[i][j2];
                            skor += str_swp[i][j1];
                            str_swp[i][j2] = 0;
                        }
                    case 2:
                        if(str_swp[i][j1] == str_swp[i][j2] && str_swp[i][j2-1] == 0)
                        {
                            str_swp[i][j1] = str_swp[i][j1] + str_swp[i][j2];
                            skor += str_swp[i][j1];
                            str_swp[i][j2] = 0;
                        }
                    case 3:
                        if(str_swp[i][j1] == str_swp[i][j2] && str_swp[i][j2-1] == 0 && str_swp[i][j2-2] == 0)
                        {
                            str_swp[i][j1] = str_swp[i][j1] + str_swp[i][j2];
                            skor += str_swp[i][j1];
                            str_swp[i][j2] = 0;
                        }
                }
                j2++;
            }
            j1++;
        }
        i++;
    }
    //Yukaridaki işlemler satırdaki ayni elemanları toplar.
    i = 0;
    j1 = 0;
    j2 = 0;
    while(i < 4)
    {
        j1 = 0;
        while(j1 < 4)
        {
            j2 = j1+1;
            while(str_swp[i][j1] == 0 && j2 < 4)
            {
                if(str_swp[i][j2] != 0)
                {
                    str_swp[i][j1] = str_swp[i][j2];
                    str_swp[i][j2] = 0;
                }
                j2++;
            }
            j1++;
        }
        i++;
    }
    return (skor);
}