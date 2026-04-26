// 1 - Escreva um programa que receba dois numeros inteiros e execute as seguintes
//    funcoes:
//    - Verificar se o numero digitado e' positivo ou negativo. Sendo que o valor de
//      retorno sera' 1 se positivo, 0 se negativo e -1 se for igual a 0.
//    - Se os 2 numeros sao positivos, retorne a soma dos N numeros existentes entre
//      eles, excluindo eles.
//    - Se os 2 numeros sao negativos, retorne a multiplicacao dos N numeros existente
//      entre eles, excluindo eles.
//    - Se 1. numero for positivo e o 2. negativo faca a divisao entre eles.

#define INNER_MODE
// #define OUTER_MODE


#ifdef OUTER_MODE
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
        
        int num_1 = ask_number();
        int num_2 = ask_number();
        
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
#endif // OUTER_MODE



#ifdef INNER_MODE
#include <stdio.h>

void clear_buffer() {
    
    while(getchar() != '\n');
    return;
}

int ask_number() {
    
    int num;
    
    scanf("%d", &num);
    clear_buffer();
    return num;
}

int show_signal(int num) {
    
    int signal_enum;
    if (num > 0) {
        signal_enum = 1;
        
    } else if (num < 0) {
        signal_enum = 0;
        
    } else {
        
        signal_enum = -1;
    }
    return signal_enum;
}

char get_signal_combination(int signal_1, int signal_2) {
    
    char signal_combination;
    // random number to make different answer combinations
    signal_1 *= 3;
    int combination = signal_1 - signal_2;
    if (combination == 2) {
        signal_combination = 'P';
        
    } else if (combination == 0) {
        signal_combination = 'N';
    
    } else if (combination == 3) {
        signal_combination = 'F';
    }
    
    return signal_combination;
}

float combination_operation(char combination_operation, int num_1, int num_2) {
    
    float start, end, result;
    if (num_1 < num_2) {
        start = num_1; end = num_2;
    } else {
        start = num_2; end = num_1;
    }
    result = start + 1;
    
    if ( combination_operation == 'P') {
        
        printf("Cálculo: Soma acumulada\n");
        for (int i = start + 2; i < end; i++) {
            result += i;
        }
    } else if ( combination_operation == 'N') {
        
        printf("Cálculo: Multiplicação acumulada\n");
        for (int i = start + 2; i < end; i++) {
            result *= i;
        }
    } else if (combination_operation == 'F') {
        
        result = start / end;
    }
    return result;
}

void show_result(float result) {
    
    printf("O resultado final é %0.f", result);
    return;
}

int main() {
    
    char again = 'n';
    do {
        
        printf("Insira o primeiro número:  ");
        int num_1 = ask_number();
        
        printf("Insira o primeiro número:  ");
        int num_2 = ask_number();
        
        int signal_1 = show_signal(num_1);
        int signal_2 = show_signal(num_2);
        
        char signal_combination = get_signal_combination(signal_1, signal_2);
        
        float result = combination_operation(signal_combination, num_1, num_2);
        
        show_result(result);
        // +-+-+-+-+-+-+-+-+-+-+-+-+-+-
        printf("Deseja executar novamente? ( s / n )  ");
        scanf("%c", &again);
        clear_buffer();
    } while (again == 's');
    return 0;
}
#endif // INNER_MODE
