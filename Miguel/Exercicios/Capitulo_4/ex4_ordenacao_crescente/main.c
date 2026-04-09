// 4 - Receba via teclado 10 valores inteiros e ordene por ordem crescente assim
//    que sao digitados. Guarde-os em um vetor. Mostre ao final os valores 
//    ordenados.

// -----------------
#define INNER_MODE
// #define OUTER_MODE
// -----------------


#ifdef OUTER_MODE
#include "middleware.h"

int main() {
    char again = 'n';
    do {
        
        int input_vec[VEC_SIZE] = {
            0, 0, 0, 0, 0,
            0, 0, 0, 0, 0
        };
        
        recieve_and_sort(input_vec);
        
        // +-+-+-+-+-+-+-+-+-+-+-+-+-+
        printf("Deseja executar novamente? ( s / n )  ");
        scanf("%c", &again);
        clear_buffer();
    } while (getchar() != '\n');
    return 0;
}
#endif // OUTER_MODE


#ifdef INNER_MODE

#include <stdio.h>
#define VEC_SIZE 10

void clear_buffer() {
    
    while (getchar() != '\n');
    return;
}

int main() {

    int input_vec[VEC_SIZE] = {
        0, 0, 0, 0, 0,
        0, 0, 0, 0, 0
    };
    
    char again = 'n';
    do {
        // recieve and sort algorithn ------ <
        const int right_bound = VEC_SIZE - 1;
        int right_i;
        printf("Insira 10 números inteiros, separados por espaço:\n");
        for (int count = 0; count < VEC_SIZE; count++) {
            
            right_i = right_bound;
            int ipt;
            printf("[%d]-> ", count + 1);
            scanf("%d", &ipt);
            clear_buffer();
            
            while (ipt < input_vec[right_i]) right_i--;
            
            int left_most = (VEC_SIZE - count) - 1;
            
            int times_to_switch = right_i - left_most;
            for (
                int i_left_most = left_most, switches = 0;
                switches < times_to_switch;
                switches++, i_left_most++
            ) {
                
                input_vec[i_left_most] = input_vec[i_left_most + 1];
            }
            
            input_vec[right_i] = ipt;
        }
        // ------------ >
        
        // 'show_vector' function
        printf("{ ");
        for (int i = 0; i < VEC_SIZE; i++) {
            printf(" %d ", input_vec[i]);
        }
        printf(" }\n");
        
        // reset vector ------ <
        for (int i = 0; i < VEC_SIZE; i++) {
            input_vec[i] = 0;
        }
        // ------------ >
        
        // +-+-+-+-+-+-+-+-+-+-+-+-+-+
        printf("Deseja executar novamente? ( s / n )  ");
        scanf("%c", &again);
        clear_buffer();
    } while (again == 's');
    return 0;
}
#endif // INNER_MODE
