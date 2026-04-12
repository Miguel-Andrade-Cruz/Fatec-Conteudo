#include "middleware.h"
#include <stdio.h>


void clear_buffer() {
    
    while (getchar() != '\n');
    return;
}


void show_average(float average) {
    
    printf("O valor médio dos números digitados é %.2f\n\n", average);
    return;
}


int acummulator() {
    
    int sum = 0, numbers_passed = 0, average;
    int inputed;
    do {
        
        printf("Digite um número: ");
        scanf("%d", &inputed);
        
        sum += inputed;
        numbers_passed++;
    } while (inputed >= 0);
    numbers_passed--;      // Revert negative count
    sum += inputed * (-1); // Revert negative acummulation
    
    average = sum / numbers_passed;
    return average;
}
