#include "middleware.h"
#include <stdio.h>


void clean_buffer() {

    while (getchar() != '\n');
    return;
}

float add(int accumulator, int new_number); // TODO: Desenvolver função
float subtract(int accumulator, int new_number); // TODO: Desenvolver função
float multiply(int accumulator, int new_number); // TODO: Desenvolver função
float divide(int accumulator, int new_number); // TODO: Desenvolver função

void show_aritmetics(float acc_sum, float acc_subtraction, float acc_multiplication, float acc_division); // TODO: Desenvolver função