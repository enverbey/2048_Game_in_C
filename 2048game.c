#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

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

int control(int str_cnt[4][4])
{
    for (int i = 0; i < 4; i++) 
    {
        for (int j = 0; j < 4; j++) 
        {
            if(str_cnt[i][j] == 0)
                return(1);
            if(str_cnt[i][j] == 2048)
                return(3);
        }
    }
    //Yukarıda kod sayesinde matrixde 0 varsa boş alan var ve oyun bitmiyor olduğundan 1 döndürür ve oyun devam eder.
    //step1 : Matrixin kopyasını oluştur.
    //Step2 : Kopya matrixte w,a,s,d işlemlerini dene eğer hiçbir işlemde değişiklik olmamışsa sistemi bitir(her işlemden sonra kontrol sağla).
    int control_matrix[4][4], copy_matrix[4][4];
    for (int i = 0; i < 4; i++) 
    {
        for (int j = 0; j < 4; j++) 
        {
            control_matrix[i][j] = str_cnt[i][j];
            copy_matrix[i][j] = str_cnt[i][j];
        }
    }

    swipe_left(copy_matrix, 0); //A ya tıkladığımızda değişiklik olup olmadığını kontrol eder.
    if(is_equal_matrix(copy_matrix, control_matrix) == 0)
        return(1);
    turn_ccw(copy_matrix);  //W ya tıkladığımızda değişiklik olup olmadığını kontrol eder.
    swipe_left(copy_matrix, 0);
    turn_ccw(copy_matrix);
    turn_ccw(copy_matrix);
    turn_ccw(copy_matrix);
    if(is_equal_matrix(copy_matrix, control_matrix) == 0)
        return(1);
    turn_ccw(copy_matrix);  //D ya tıkladığımızda değişiklik olup olmadığını kontrol eder.
    turn_ccw(copy_matrix);
    swipe_left(copy_matrix, 0);
    turn_ccw(copy_matrix);
    turn_ccw(copy_matrix);
    if(is_equal_matrix(copy_matrix, control_matrix) == 0)
        return(1);
    turn_ccw(copy_matrix);  //S ya tıkladığımızda değişiklik olup olmadığını kontrol eder.
    turn_ccw(copy_matrix);
    turn_ccw(copy_matrix);
    swipe_left(copy_matrix, 0);
    turn_ccw(copy_matrix);
    if(is_equal_matrix(copy_matrix, control_matrix) == 0)
        return(1);
    return(0);



}

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