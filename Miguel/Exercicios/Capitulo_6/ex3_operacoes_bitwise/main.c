// 3 - Escreva um programa que receba via teclado 2 numeros inteiros e execute
//    as operacoes logicas bit a bit AND, OU, OU EXCLUSIVO e imprima-os no
//    video no formato decimal e hexadecimal.
// 3 - Escreva um programa que receba via teclado 2 numeros inteiros e execute
//    as operacoes logicas bit a bit AND, OU, OU EXCLUSIVO e imprima-os no
//    video no formato decimal e hexadecimal.


#include "middleware.h"

int main() {

    char again = 'n';
    do {
        
        
        printf("Deseja executar novamente? ( s / n )  ");
        scanf("%c", &again);
        clear_buffer();
    } while (again == 's');
    return 0;
}