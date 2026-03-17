#include "middleware.h"


void clear_buffer() {
    
    while (getchar() != '\n');
    return;
}

void ask_for_two_numbers(int *num_1, int *num_2) {
    
    printf("Insira o primeiro número:  ");
    scanf("%d", num_1);
    
    printf("Insira o segundo número:  ");
    scanf("%d", num_1);
    return;
}

void print_add_operation(int num_1, int num_2) {
    
    int add_result = num_1 + num_2;
    printf("Adição entre %d e %d = %d", num_1, num_2, add_result);
    return;
}

void print_sub_operation(int num_1, int num_2) {
    
    int sub_result = num_1 - num_2;
    printf("Subtração entre %d e %d = %d", num_1, num_2, sub_result);
    return;
}

void print_mult_operation(int num_1, int num_2) {
    
    int mult_result = num_1 * num_2;
    printf("Multiplicação entre %d e %d = %d", num_1, num_2, mult_result);
    return;
}

void print_div_operation(int num_1, int num_2) {
    
    float div_result = num_1 / num_2;
    printf("Divisão entre %d e %d = %.2f", num_1, num_2, div_result);
    return;
}