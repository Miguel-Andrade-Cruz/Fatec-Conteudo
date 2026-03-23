// 4 - Receba via teclado 10 valores inteiros e ordene por ordem crescente assim
//    que sao digitados. Guarde-os em um vetor. Mostre ao final os valores 
//    ordenados.

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