// 4 - Receba via teclado 10 valores inteiros e ordene por ordem crescente assim
//    que sao digitados. Guarde-os em um vetor. Mostre ao final os valores 
//    ordenados.

#include "middleware.h"
// #define DEBUG


int input_vec[VEC_SIZE] = {0, 0, 0, 0, 0, 0, 0, 0, 0};


int main() {
    
    char again = 'n';
    do {
        
        int right_i = VEC_SIZE - 1;
        
        printf("Insira 10 números inteiros, separados por espaço:\n");
        for (int count = 0; count < VEC_SIZE; count++) {
            
            int ipt;
            printf("[%d]-> ", count + 1);
            scanf("%d", &ipt);
            clear_buffer();
            
            while (ipt < input_vec[right_i]) right_i--;
            
            int next_left_most = (VEC_SIZE - count) - 1;
            
            int times_to_switch = right_i - next_left_most;
            for (
                int i_left_most = next_left_most, switches = 0;
                switches < times_to_switch;
                switches++, i_left_most++
            ) {
                
                input_vec[i_left_most] = input_vec[i_left_most + 1];
            }
            
            input_vec[right_i] = ipt;
            
            #ifdef DEBUG
            debug_show_vector(input_vec);
            #endif
        }
        
        // 'show_vector' function
        printf("{");
        for (int i = 0; i < VEC_SIZE; i++) {
            printf(" %d", input_vec[i]);
        }
        printf(" }\n");
        
        for (int i = 0; i < VEC_SIZE; i++) {
            input_vec[i] = 0;
        }
        // --------------------
        
        // +-+-+-+-+-+-+-+-+-+-+-+-+-+
        printf("Deseja executar novamente? ( s / n )  ");
        scanf("%c", &again);
        clear_buffer();
    } while (again == 's');
    return 0;
}