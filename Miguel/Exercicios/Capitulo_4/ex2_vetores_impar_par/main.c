// 2 - Escreva um programa que receba um vetor de inteiros com tamanho 10 e o 
//    decomponha em dois outros vetores. Um tera“ as componentes de ordem impar 
//    e o outro tera“ as componentes de ordem par.
//    Por exemplo, se o vetor dado for v = {3, 5, 6, 8, 1, 4, 2, 3, 7, 9}, o programa
//    deve gerar os vetores u = {3, 6, 1, 2, 7} e w = {5, 8, 4, 3, 9}.

#include "middleware.h"


int main() {

    char again = 'n';
    do {
        int input_vec[VEC_SIZE], even_vec[VEC_SIZE / 2], odd_vec[VEC_SIZE / 2];
        ask_for_10_numbers(input_vec);
        
        extract_even_nums(input_vec, even_vec);
        extract_odd_nums(input_vec, odd_vec);
        
        show_vecs(even_vec, odd_vec);
        
        // +-+-+-+-+-+-+-+-+-+-+-+-+-+
        printf("Deseja executar novamente? ( s / n )  ");
        scanf("%c", &again);
        clear_buffer();
    } while (again == 's');
    return 0;
}