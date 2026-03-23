// 2 - Escreva um programa que receba um vetor de inteiros com tamanho 10 e o 
//    decomponha em dois outros vetores. Um tera“ as componentes de ordem impar 
//    e o outro tera“ as componentes de ordem par.
//    Por exemplo, se o vetor dado for v = {3, 5, 6, 8, 1, 4, 2, 3, 7, 9}, o programa
//    deve gerar os vetores u = {3, 6, 1, 2, 7} e w = {5, 8, 4, 3, 9}.

#include "middleware.h"


int input_vec[VEC_SIZE], even_vec[VEC_SIZE / 2], odd_vec[VEC_SIZE / 2];

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