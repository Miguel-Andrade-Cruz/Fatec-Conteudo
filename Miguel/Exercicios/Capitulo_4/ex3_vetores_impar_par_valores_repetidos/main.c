// 3 - Escreva um programa que receba um vetor de inteiros com tamanho 10 e o 
//     decomponha em dois outros vetores. Um tera“ as componentes de valor impar 
//     e o outro tera“ as componentes de valor par. 
//     Por exemplo, se o vetor dado for v = {3, 5, 6, 8, 1, 4, 2, 3, 7, 4} o
//     programa deve gerar os vetores u = {3, 5, 1, 3, 7} e w = {6, 8, 4, 2, 4}. 

#define INNER_MODE
// #define OUTER_MODE



#ifdef INNER_MODE
#include <stdio.h>
#define VEC_SIZE 10

void clear_buffer() {
    
    while (getchar() != '\n');
    return;
}

int input_vec[VEC_SIZE], even_vec[VEC_SIZE / 2], odd_vec[VEC_SIZE / 2];

int main() {

    char again = 'n';
    do {
        
        printf("Insira 10 números:  \n");
        for (int i_num = 0; i_num < VEC_SIZE; i_num++) {
            
            printf("%d -> ", i_num + 1);
            scanf("%d", &input_vec[i_num]);
            clear_buffer();
        }
        
        // To split the vector into evens and odds
        for (int i_even = 0, i_odd = 0, i_ipt = 0; i_ipt < VEC_SIZE; i_ipt++) {
            
            if (input_vec[i_ipt] % 2 == 0) {
                
                even_vec[i_even] = input_vec[i_ipt];
                i_even++;
            } else {
                
                odd_vec[i_odd] = input_vec[i_ipt];
                i_odd++;
            }
        }
        
        // Showing the numbers
        // Odds
        printf("Números pares passados: ");
        printf("{  ");
        for (int i_num = 0; i_num < VEC_SIZE / 2; i_num++) {
            
            printf("%d  ", even_vec[i_num]);
        }
        printf("}");
        
        
        printf("\n\n");
        
        
        // Evens
        printf("Números ímpares passados: ");
        printf("{  ");
        for (int i_num = 0; i_num < VEC_SIZE / 2; i_num++) {
            
            printf("%d  ", odd_vec[i_num]);
        }
        printf("}");
        
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
        
        int
            input_vec[VEC_SIZE],
            even_vec[VEC_SIZE / 2],
            odd_vec[VEC_SIZE / 2]
        ;
        ask_for_10_numbers(input_vec);
        
        extract_evens(input_vec, even_vec);
        extract_odds(input_vec, odd_vec);
        
        show_vecs(even_vec, odd_vec);
        
        // +-+-+-+-+-+-+-+-+-+-+-+-+-+
        printf("\nDeseja executar novamente? ( s / n )  ");
        scanf("%c", &again);
        clear_buffer();
    } while (again == 's');
    return 0;
}

#endif // OUTER_MODE
