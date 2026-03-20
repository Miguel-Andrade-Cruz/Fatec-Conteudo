// 1 - Escreva um programa que receba dois numeros inteiros e execute as seguintes
//    funcoes:
//    - Verificar se o numero digitado e' positivo ou negativo. Sendo que o valor de
//      retorno sera' 1 se positivo, 0 se negativo e -1 se for igual a 0.
//    - Se os 2 numeros sao positivos, retorne a soma dos N numeros existentes entre
//      eles, excluindo eles.
//    - Se os 2 numeros sao negativos, retorne a multiplicacao dos N numeros existente
//      entre eles, excluindo eles.
//    - Se 1. numero for positivo e o 2. negativo faca a divisao entre eles.

#include "middleware.h"


int main() {
    
    char again = 'n';
    do {
        // signal combination table:
        // "P" --> The two numbers are positive
        // "N" --> The two numbers are negative
        // "F" --> First number is positive an second is negative
        
        char signal_combination;
        float combination_result;
        
        int num_1 = ask_first_number();
        int num_2 = ask_second_number();
        
        int signal_1 = show_signal(num_1);
        int signal_2 = show_signal(num_2);
        
        signal_combination = realize_signal_combination(signal_1, signal_2);
        combination_result = execute_combination_operation(signal_combination, num_1, num_2);
        
        show_result(combination_result);
        
        // +-+-+-+-+-+-+-+-+-+-+-+-+-+-
        printf("Deseja executar novamente? ( s / n )  ");
        scanf("%c", &again);
        clear_buffer();
    } while (again == 's');
    return 0;
}