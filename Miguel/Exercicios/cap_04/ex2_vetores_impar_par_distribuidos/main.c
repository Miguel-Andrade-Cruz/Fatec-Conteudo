// 2 - Escreva um programa que receba um vetor de inteiros com tamanho 10 e o 
//    decomponha em dois outros vetores. Um tera“ as componentes de ordem impar 
//    e o outro tera“ as componentes de ordem par.
//    Por exemplo, se o vetor dado for v = {3, 5, 6, 8, 1, 4, 2, 3, 7, 9}, o programa
//    deve gerar os vetores u = {3, 6, 1, 2, 7} e w = {5, 8, 4, 3, 9}.

// #define INNER_MODE
#define OUTER_MODE


#ifdef INNER_MODE
#include <stdio.h>
#define VEC_SIZE 10

void clear_buffer() {
    
    while (getchar() != '\n');
    return;
}

int input_vec[VEC_SIZE],
    vec_1[VEC_SIZE / 2],
    vec_2[VEC_SIZE / 2]
;

int main() {

    char again = 'n';
    do {
        
        printf("Insira 10 números:  \n");
        for (int i_num = 0; i_num < VEC_SIZE; i_num++) {
            
            printf("%d -> ", i_num + 1);
            scanf("%d", &input_vec[i_num]);
            clear_buffer();
        }
        
        // To split the vectors into evens and odds, evenly
        char turn = 'o';
        for (int i_ipt = 0, i_vec_1 = 0, i_vec_2 = 0; i_ipt < VEC_SIZE; i_ipt++) {
            
            int current_num = input_vec[i_ipt];
            
            if (turn == 'o' && current_num % 2 != 0) {
                vec_1[i_vec_1] = current_num;
                i_vec_1++;
                turn = 'e';
                
            } else if (turn == 'e' && current_num % 2 == 0) {
                vec_1[i_vec_1] = current_num;
                i_vec_1++;
                turn = 'o';
                
            } else {
                vec_2[i_vec_2] = current_num;
                i_vec_2++;
            }
        }
        
        // Showing the numbers
        // Odds
        printf("Números pares passados: ");
        printf("{ ");
        for (int i_num = 0; i_num < VEC_SIZE / 2; i_num++) {
            
            printf(" %d ", vec_1[i_num]);
        }
        printf(" }");
        
        
        printf("\n\n");
        
        
        // Evens
        printf("Números ímpares passados: ");
        printf("{ ");
        for (int i_num = 0; i_num < VEC_SIZE / 2; i_num++) {
            
            printf(" %d ", vec_2[i_num]);
        }
        printf(" }");
        
        // +-+-+-+-+-+-+-+-+-+-+-+-+-+
        printf("\nDeseja executar novamente? ( s / n )  ");
        scanf("%c", &again);
        clear_buffer();
    } while (again == 's');
    return 0;
}
#endif // INNER_MODE




#ifdef OUTER_MODE
#include "middleware.h"

int main() {
    
    char again = 'n';
    do {
        
        int ipt_vec[VEC_SIZE],
            vec_1[VEC_SIZE / 2],
            vec_2[VEC_SIZE / 2]
        ;
        ask_for_10_numbers(ipt_vec);
        
        split_even_odd_evenly(ipt_vec, vec_1, vec_2);
        
        show_vecs(vec_1, vec_2);
        // +-+-+-+-+-+-+-+-+-+-+-+-+-+
        printf("\nDeseja executar novamente? ( s / n )  ");
        scanf("%c", &again);
        clear_buffer();
    } while (again == 's');
    return 0;
}
#endif // OUTER_MODE
