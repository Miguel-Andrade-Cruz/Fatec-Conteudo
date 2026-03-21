#include "middleware.h"


void clear_buffer() {

    while (getchar() != '\n');
    return;
}

int ask_first_number() {
    
    int num;
    
    printf("Insira o primeiro número:  ");
    scanf("%d", &num);
    clear_buffer();
    return num;
}


int ask_second_number() {
    
    int num;
    
    printf("Agora insira segundo número:  ");
    scanf("%d", &num);
    clear_buffer();
    return num;
}


float add(int num_1, int num_2) {
    
    return num_1 + num_2;
}


float subtract(int num_1, int num_2) {
    
    return num_1 - num_2;
}


float multiply(int num_1, int num_2) {
    
    return num_1 * num_2;
}


float divide(int num_1, int num_2) {
    
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