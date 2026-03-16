#include "middleware.h"
#include <stdio.h>


void clean_buffer() {

    while(getchar() != '\n');
    return;
}

int ask_first_number(); // TODO: Desenvolver função
int ask_second_number(); // TODO: Desenvolver função

char realize_numbers_signal(int num_1, int num_2); // TODO: Desenvolver função

int execute_combination_operation(char combination_operation, int num_1, int num_2); // TODO: Desenvolver função