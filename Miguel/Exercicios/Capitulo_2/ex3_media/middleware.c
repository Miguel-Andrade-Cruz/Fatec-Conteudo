#include "middleware.h"

void show_average(int average) {

    printf("O valor médio dos números digitados é %d", average);
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
    sum += inputed * (-1); // Revert the negative acummulation

    average = sum / numbers_passed;
    return average;
}