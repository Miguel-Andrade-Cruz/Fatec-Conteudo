#include "middleware.h"


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


char realize_signal_combination(int signal_1, int signal_2) {
    
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
