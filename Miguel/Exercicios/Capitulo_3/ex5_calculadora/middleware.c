#include "middleware.h"


void clear_buffer() {

    while (getchar() != '\n');
    return;
}

void display_explaining_message() {
    
    printf("\n\nBem vindo á calculadora\n");
    printf("Digite uma expressão (exemplo: '23 + 45) para calcular o resultado\n'");
    printf("Caso queira terminar de calcular digite '=='\n");
    printf("Após a primeira expressão, o primeiro operando será sempre preenchido com o resultado da operação anterior\n\n");
    return;
}


void display_ans(float accumulator) {
    
    printf("%f ", accumulator);
    return;
}


float addition(float accumulator, float operand) {
    
    return accumulator + operand;
}


float subtraction(float accumulator, float operand) {
    
    return accumulator - operand;

}


float multiplication(float accumulator, float operand) {
    
    return accumulator * operand;

}


float division(float accumulator, float operand) {
    
    return accumulator / operand;

}


float resolve_expression(float operand_1, char _operator, float operand_2) {
    
    switch (_operator) {
       
        case ADD:
            
            operand_1 = addition(operand_1, operand_2);
            break;
        case SUB:
            
            operand_1 = subtraction(operand_1, operand_2);
            break;
        case MULT:
            
            operand_1 = multiplication(operand_1, operand_2);
            break;
        case DIV:
            
            operand_1 = division(operand_1, operand_2);
            break;
    }
    return operand_1;
}
