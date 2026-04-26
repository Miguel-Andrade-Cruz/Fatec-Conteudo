#include "middleware.h"


void clear_buffer() {
    
    while (getchar() != '\n');
    return;
}

int ask_for_value() {
    
    int value;
    
    printf("Digite um valor:  ");
    scanf("%d", &value);
    return value;
}


float add(float accumulator, float new_number) {
    
    return accumulator + new_number;
}


float subtract(float accumulator, float new_number) {
    
    return accumulator - new_number;
}


float multiply(float accumulator, float new_number) {
    
    return accumulator * new_number;;
}


float divide(float accumulator, float new_number) {
    
    return accumulator / new_number;
}


void show_aritmetics(float acc_sum, float acc_subtraction, float acc_multiplication, float acc_division) {
    
    printf("Resultado das operações consecutivas:\n");
    printf("Adição: %.3f\n", acc_sum);
    printf("Subtração: %.3f\n", acc_subtraction);
    printf("Multiplicação: %.3f\n", acc_multiplication);
    printf("Divisão: %.3f\n", acc_division);
    return;
}
