#include "Game_2048.h"

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