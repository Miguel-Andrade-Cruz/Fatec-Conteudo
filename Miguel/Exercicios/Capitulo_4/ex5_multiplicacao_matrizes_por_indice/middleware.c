#include "middleware.h"

#define DEBUG


void clear_buffer() {
    
    while (getchar() != '\n');
    return;
}


void ask_matrix(int vec[2][3]) {
    
    for (int i_row = 0; i_row < ROWS; i_row++) {
        
        for (int i_col = 0; i_col < COLS; i_col++) {
            
            printf("[%d][%d] ->>", i_row, i_col);
            scanf("%d", &vec[i_row][i_col]);
            clear_buffer();
        }
    }
    return;
}


void matrix_multiplicator(int vec_1[2][3], int vec_2[2][3], int vec_result[2][3]) {
    
    for (int i_row = 0; i_row < ROWS; i_row++) {
        
        for (int i_col = 0; i_col < COLS; i_col++) {
            
            vec_result[i_row][i_col] = vec_1[i_row][i_col] * vec_2[i_row][i_col];
            #ifdef DEBUG
            printf("[DEBUG] VEC_1: %d | VEC_2: %d | RESULT_VEC: %d\n",
                vec_1[i_row][i_col],
                vec_2[i_row][i_col],
                vec_result[i_row][i_col]
            );
            #endif
        }
    }
    return;
}


void show_vecs(int vec_1[2][3], int vec_2[2][3], int result_vec[2][3]) {
    
    printf("Resultados:\n");
    printf("    Vetor 1    \n");
    for (int i_row = 0; i_row < ROWS; i_row++) {
        
        printf("[  ");
        for (int i_col = 0; i_col < COLS; i_col++) {
            
            printf("%d  ", vec_1[i_row][i_col]);
        }
        printf("]\n");
    }
    
    
    printf("    Vetor 2    \n");
    for (int i_row = 0; i_row < ROWS; i_row++) {
        
        printf("[  ");
        for (int i_col = 0; i_col < COLS; i_col++) {
            
            printf("%d  ", vec_2[i_row][i_col]);
        }
        printf("]\n");
    }
    
    
    printf("    Vetor multiplicado    \n");
    for (int i_row = 0; i_row < ROWS; i_row++) {
        
        printf("[  ");
        for (int i_col = 0; i_col < COLS; i_col++) {
            
            printf("%d  ", mult_vec[i_row][i_col]);
        }
        printf("]\n");
    }

    return;
}