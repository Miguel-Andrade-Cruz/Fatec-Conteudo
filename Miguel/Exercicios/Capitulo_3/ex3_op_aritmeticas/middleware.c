#include "middleware.h"


void clear_buffer() {

    while (getchar() != '\n');
    return;
}

float ask_number() {
    
    float num;
    
    printf("Insira o primeiro número:  ");
    scanf("%f", &num);
    clear_buffer();
    return num;
}


float add(float num_1, float num_2) {
    
    return num_1 + num_2;
}


float subtract(float num_1, float num_2) {
    
    return num_1 - num_2;
}


float multiply(float num_1, float num_2) {
    
    return num_1 * num_2;
}


float divide(float num_1, float num_2) {
    
    return num_1 / num_2;
}


void show_aritmetics(float sum, float subtraction, float multiplication, float division) {
    
    printf("Resultado das opreações:\n");
    
    printf("Adição: %.5f\n", sum);
    printf("Subtração: %.5f\n", subtraction);
    printf("Multiplicação: %.5f\n", multiplication);
    printf("Divisão: %.5f\n", division);
    
    return;
}
