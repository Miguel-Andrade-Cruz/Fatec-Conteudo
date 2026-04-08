// 3 - Escreva um programa que receba via teclado 2 numeros inteiros e execute
//    as operacoes logicas bit a bit AND, OU, OU EXCLUSIVO e imprima-os no
//    video no formato decimal e hexadecimal.
// 3 - Escreva um programa que receba via teclado 2 numeros inteiros e execute
//    as operacoes logicas bit a bit AND, OU, OU EXCLUSIVO e imprima-os no
//    video no formato decimal e hexadecimal.

// #define OUTER_MODE
#define INNER_MODE

#ifdef OUTER_MODE
#include "middleware.h"
int main() {

    char again = 'n';
    do {
        int num_1, num_2;
        ask_for_two_numbers(&num_1, &num_2);
        
        print_bitwise_and(num_1, num_2);
        print_bitwise_or(num_1, num_2);
        print_bitwise_xor(num_1, num_2);
        
        // +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
        printf("Deseja executar novamente? ( s / n )  ");
        scanf("%c", &again);
        clear_buffer();
    } while (again == 's');
    return 0;
}
#endif // OUTER_MODE



#ifdef INNER_MODE
#include <stdio.h>
void clear_buffer() {
    
    while(getchar() != '\n');
    return;
}

int main() {
    
    char again = 's';
    do {
        
        // user input ------ <
        int num1, num2;
        printf("Insira o primeiro número:  ");
        scanf("%d", &num1);
        clear_buffer();
        
        printf("Insira o segundo número:  ");
        scanf("%d", &num2);
        clear_buffer();
        // ------------ >
        
        // bitwise operations ------ <
        int bitwise_and = num1 & num2;
        printf("Expressão: %d AND %d = %d(10) ou %x(16)\n\n",
            num1, num2, bitwise_and, bitwise_and
        );
        
        int bitwise_or = num1 | num2;
        printf("Expressão: %d OR %d = %d(10) ou %x(16)\n\n",
            num1, num2, bitwise_or, bitwise_or
        );
        
        int bitwise_xor = num1 ^ num2;
        printf("Expressão: %d XOR %d = %d(10) ou %x(16)\n\n",
            num1, num2, bitwise_xor, bitwise_xor
        );
        // ------------ >
        
        // +-+-+-+-+-+-+-+-+-+-+-+-+-+
        printf("Deseja executar novamente ( s / n )  ");
        scanf("%c", &again);
        clear_buffer();
    } while (again == 's');
    return 0;
}
#endif // INNER_MODE
