#include "middleware.h"


void clear_buffer() {
    
    while (getchar() != '\n');
    return;
}

void ask_for_two_numbers(float *num_1, float *num_2) {
    
    printf("Insira o primeiro número:  ");
    scanf("%f", num_1);
    clear_buffer();
    
    printf("Insira o segundo número:  ");
    scanf("%f", num_2);
    clear_buffer();
    return;
}

void print_add_operation(float num_1, float num_2) {
    
    float add_result = num_1 + num_2;
    printf("Adição entre %.2f e %.2f = %.2f", num_1, num_2, add_result);
    return;
}

void print_sub_operation(float num_1, float num_2) {
    
    float sub_result = num_1 - num_2;
    printf("Subtração entre %.2f e %.2f = %.2f", num_1, num_2, sub_result);
    return;
}

void print_mult_operation(float num_1, float num_2) {
    
    float mult_result = num_1 * num_2;
    printf("Multiplicação entre %.2f e %.2f = %.2f", num_1, num_2, mult_result);
    return;
}

void print_div_operation(float num_1, float num_2) {
    
    float div_result = num_1 / num_2;
    printf("Divisão entre %.2f e %.2f = %.2f", num_1, num_2, div_result);
    return;
}
