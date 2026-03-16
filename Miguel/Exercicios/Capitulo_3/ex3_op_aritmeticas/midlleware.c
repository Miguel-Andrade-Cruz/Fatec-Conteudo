#include "middleware.h"
#include <stdio.h>


void clean_buffer() {

    while (getchar() != '\n');
    return;
}

int ask_first_number(); // TODO: Desenvolver função
int ask_second_number(); // TODO: Desenvolver função

float add(int num_1, int num_2); // TODO: Desenvolver função
float subtract(int num_1, int num_2); // TODO: Desenvolver função
float multiply(int num_1, int num_2); // TODO: Desenvolver função
float divide(int num_1, int num_2); // TODO: Desenvolver função

void show_aritmetics(float sum, float subtraction, float multiplication, float division); // TODO: Desenvolver função