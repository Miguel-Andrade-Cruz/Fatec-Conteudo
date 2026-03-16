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
        int num_1, num_2;
        ask_for_two_numbers(&num_1, &num_2);
        
        print_bitwise_and(num_1, num_2);
        print_bitwise_or(num_1, num_2);
        print_bitwise_xor(num_1, num_2);
        
        printf("Deseja executar novamente? ( s / n )  ");
        scanf("%c", &again);
        clear_buffer();
    } while (again == 's');
    return 0;
}