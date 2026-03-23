// 3 - Escreva um programa que receba um vetor de inteiros com tamanho 10 e o 
//     decomponha em dois outros vetores. Um tera“ as componentes de valor impar 
//     e o outro tera“ as componentes de valor par. 
//     Por exemplo, se o vetor dado for v = {3, 5, 6, 8, 1, 4, 2, 3, 7, 4} o
//     programa deve gerar os vetores u = {3, 5, 1, 3, 7} e w = {6, 8, 4, 2, 4}. 

#include "middleware.h"


int main() {

    char again = 'n';
    do {
        
        
        
        
        // +-+-+-+-+-+-+-+-+-+-+-+-+-+
        printf("Deseja executar novamente? ( s / n )  ");
        scanf("%c", &again);
        clear_buffer();
    } while (again == 's');
    return 0;
}