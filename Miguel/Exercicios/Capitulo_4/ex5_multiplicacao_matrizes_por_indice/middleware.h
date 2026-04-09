#include <stdio.h>


#define ROWS 2
#define COLS 3

void clear_buffer();

void ask_matrix(int vec[ROWS][COLS]);

void matrix_multiplicator(int vec_1[ROWS][COLS], int vec_2[ROWS][COLS], int result_vec[ROWS][COLS]);

void show_vecs(int vec_1[ROWS][COLS], int vec_2[ROWS][COLS], int result_vec[ROWS][COLS]);
