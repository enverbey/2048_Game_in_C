#ifndef GAME_2048_H
# define GAME_2048_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

int how_to_play(void);
void add_number_to_matrix(int str_add[4][4]);
int swipe_left(int str_swp[4][4], int skor);
void play();
void turn_ccw(int str_turn[4][4]);
void game_scene(int str[4][4], int skor);
int is_equal_matrix(int matrix1[4][4], int matrix2[4][4]);
int how_many_digit_number(int number);
int control(int str_cnt[4][4]);




#endif