// 3 - Escreva um programa que receba um vetor de inteiros com tamanho 10 e o 
//     decomponha em dois outros vetores. Um tera“ as componentes de valor impar 
//     e o outro tera“ as componentes de valor par. 
//     Por exemplo, se o vetor dado for v = {3, 5, 6, 8, 1, 4, 2, 3, 7, 4} o
//     programa deve gerar os vetores u = {3, 5, 1, 3, 7} e w = {6, 8, 4, 2, 4}. 

#include "middleware.h"


int input_vec[VEC_SIZE], vec_1[VEC_SIZE / 2], vec_2[VEC_SIZE / 2];

int main() {

    char again = 'n';
    do {
        
        printf("Insira 10 números:  \n");
        for (int i_num = 0; i_num < VEC_SIZE; i_num++) {
            
            printf("%d -> ", i_num + 1);
            scanf("%d", &input_vec[i_num]);
            clear_buffer();
            printf("VETOR INPUT INDICE %d : %d\n", i_num, input_vec[i_num]);//
        }
        
        // To split the vector into evens and odds
        for (int i_even = 0, i_odd = 0, i_ipt = 0; i_ipt < VEC_SIZE; i_ipt++) {
            
            if (input_vec[i_ipt] % 2 == 0) {
                
                vec_1[i_even] = input_vec[i_ipt];
                i_even++;
            } else {
                
                vec_2[i_odd] = input_vec[i_ipt];
                i_odd++;
            }
        }
        
        // Showing the numbers
        // Odds
        printf("Números pares passados: ");
        printf("{  ");
        for (int i_num = 0; i_num < VEC_SIZE / 2; i_num++) {
            
            printf("%d  ", vec_1[i_num]);
        }
        printf("}");
        
        
        printf("\n\n");
        
        
        // Evens
        printf("Números ímpares passados: ");
        printf("{  ");
        for (int i_num = 0; i_num < VEC_SIZE / 2; i_num++) {
            
            printf("%d  ", vec_2[i_num]);
        }
        printf("}");
        
        // +-+-+-+-+-+-+-+-+-+-+-+-+-+
        printf("\nDeseja executar novamente? ( s / n )  ");
        scanf("%c", &again);
        clear_buffer();
    } while (again == 's');
    return 0;
}