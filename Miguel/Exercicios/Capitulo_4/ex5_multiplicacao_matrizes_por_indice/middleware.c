#include "middleware.h"

#define DEBUG


void clear_buffer() {
    
    while (getchar() != '\n');
    return;
}


void ask_matrix(int vec[ROWS][COLS]) {
    
    for (int i_row = 0; i_row < ROWS; i_row++) {
        
        for (int i_col = 0; i_col < COLS; i_col++) {
            
            printf("[%d][%d] ->>", i_row, i_col);
            scanf("%d", &vec[i_row][i_col]);
            clear_buffer();
        }
    }
    return;
}


void matrix_multiplicator(
    
    int vec_1[ROWS][COLS],
    int vec_2[ROWS][COLS],
    int vec_result[ROWS][COLS]
) {
    
    for (int i_row = 0; i_row < ROWS; i_row++) {
        
        for (int i_col = 0; i_col < COLS; i_col++) {
            
            vec_result[i_row][i_col] = vec_1[i_row][i_col] * vec_2[i_row][i_col];
        }
    }
    return;
}


void show_vecs(int vec_1[ROWS][COLS], int vec_2[ROWS][COLS], int result_vec[ROWS][COLS]) {
    
    printf("Resultados:\n");
    printf("    Vetor 1    \n");
    for (int i_row = 0; i_row < ROWS; i_row++) {
        
        printf("[  ");
        printf("%d  %d  %d",
            vec_1[i_row][0],
            vec_1[i_row][1],
            vec_1[i_row][2]
        );
        printf("  ]\n");
    }
    
    
    printf("    Vetor 2    \n");
    for (int i_row = 0; i_row < ROWS; i_row++) {
        
        printf("[  ");
        printf("%d  %d  %d",
            vec_2[i_row][0],
            vec_2[i_row][1],
            vec_2[i_row][2]
        );
        printf("  ]\n");
    }
    
    
    printf("    Vetor multiplicado    \n");
    for (int i_row = 0; i_row < ROWS; i_row++) {
        
        printf("[  ");
        printf(
            "%d  %d  %d",
            result_vec[i_row][0],
            result_vec[i_row][1],
            result_vec[i_row][2]
        );
        printf("  ]\n");
    }

    return;
}
