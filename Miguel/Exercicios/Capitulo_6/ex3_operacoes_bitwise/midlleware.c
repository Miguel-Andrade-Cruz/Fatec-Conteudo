#include "middleware.h"


void clear_buffer() {
    
    while(getchar() != '\n');
    return;
}


void ask_for_two_numbers(int *num_1, int *num_2) {
    
    printf("Insira o primeiro número:  ");
    scanf("%d", num_1);
    
    printf("Insira o segundo número:  ");
    scanf("%d", num_2);
    
    return;
}

void print_bitwise_and(int num_1, int num_2) {
    
    int bitwise_answer = num_1 & num_2;
    
    printf("Expressão: %d AND %d = %d(10) ou %x(16)", num_1, num_2, bitwise_answer, bitwise_answer);
    return;
}


void print_bitwise_or(int num_1, int num_2) {
    
    int bitwise_answer = num_1 | num_2;
    
    printf("Expressão: %d OR %d = %d(10) ou %x(16)", num_1, num_2, bitwise_answer, bitwise_answer);
    return;
}


void print_bitwise_xor(int num_1, int num_2) {
    
    int bitwise_answer = num_1 ^ num_2;
    
    printf("Expressão: %d XOR %d = %d(10) ou %x(16)", num_1, num_2, bitwise_answer, bitwise_answer);
    return;
}
