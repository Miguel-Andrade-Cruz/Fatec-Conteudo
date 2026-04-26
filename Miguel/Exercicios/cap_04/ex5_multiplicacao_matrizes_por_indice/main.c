// 5 - Defina 2 vetores bidimensionais do tipo inteiro de 2x3. Escreva um programa
//    que recebe os dados via teclado para esses 2 vetores. Usando o operador
//    multiplicacao '*', multiplique os elementos de mesmo indice dos 2 vetores e guarde
//    o resultado em um 3. vetor. Imprima na tela os indices, os valores e o resultado
//    dos 6 elementos dos vetores.


// #define OUTER_MODE
#define INNER_MODE


#ifdef OUTER_MODE
#include "middleware.h"

int main() {
    
    char again = 'n';
    do {
        
        int vec_1[2][3];
        int vec_2[2][3];
        int mult_vec[2][3];
        
        printf("Insira os números para a primeira matriz:\n");
        
        ask_matrix(vec_1);
        ask_matrix(vec_2);
        
        matrix_multiplicator(vec_1, vec_2, mult_vec);
        show_vecs(vec_1, vec_2, mult_vec);
        
        // +-+-+-+-+-+-+-+-+-+-+-+-+
        printf("Desja executar novamente? ( s / n )  ");
        scanf("%c", &again);
        clear_buffer();
    } while (again == 's');
    return 0;
}
#endif // OUTER_MODE



#ifdef INNER_MODE

#include <stdio.h>

#define ROWS 2
#define COLS 3

int vec_1[ROWS][COLS];
int vec_2[ROWS][COLS];
int vec_mult[ROWS][COLS];

void clear_buffer() {
    
    while (getchar() != '\n');
    return;
}

int main() {
    
    
    char again = 'n';
    do {
        
        printf("Insira os números para a primeira matriz:\n\n");
        
        // 'ask_matrix' matrix 1
        printf("Matriz 1:\n");
        for (int i_row = 0; i_row < ROWS; i_row++) {
            
            for (int i_col = 0; i_col < COLS; i_col++) {
                
                printf("[%d][%d] ->> ", i_row, i_col);
                scanf("%d", &vec_1[i_row][i_col]);
                clear_buffer();
            }
        }
        
        // --------------------------------------
        printf("\n-----------------------------\n");
        // --------------------------------------
        
        // 'ask_matrix' for matrix 2
        printf("Matriz 2:\n");
        for (int i_row = 0; i_row < ROWS; i_row++) {
            
            for (int i_col = 0; i_col < COLS; i_col++) {
                
                printf("[%d][%d] ->> ", i_row, i_col);
                scanf("%d", &vec_2[i_row][i_col]);
                clear_buffer();
            }
        }        
        
        
        // 'matrix_multiplicator'
        for (int i_row = 0; i_row < ROWS; i_row++) {
            
            for (int i_col = 0; i_col < COLS; i_col++) {
                
                vec_mult[i_row][i_col] = vec_1[i_row][i_col] * vec_2[i_row][i_col];
            }
        }
        
        
        // 'show_vecs'
        printf("Resultados:\n");
        printf("    Vetor 1    \n");
        for (int i_row = 0; i_row < ROWS; i_row++) {
            
            printf("[  ");
            printf(
                "%d  %d  %d",
                vec_1[i_row][0],
                vec_1[i_row][1],
                vec_1[i_row][2]
            );
            printf("  ]\n");
        }
        
        
        printf("    Vetor 2    \n");
        for (int i_row = 0; i_row < ROWS; i_row++) {
            
            printf("[  ");
                
            printf(
                "%d  %d  %d",
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
                vec_mult[i_row][0],
                vec_mult[i_row][1],
                vec_mult[i_row][2]
            );
            printf("  ]\n");
        }
        
        // +-+-+-+-+-+-+-+-+-+-+-+-+
        printf("Desja executar novamente? ( s / n )  ");
        scanf("%c", &again);
        clear_buffer();
    } while (again == 's');
    return 0;
}
#endif
