#include <stdio.h>


void clear_buffer();

int ask_for_value();

float add(float accumulator, float new_number);
float subtract(float accumulator, float new_number);
float multiply(float accumulator, float new_number);
float divide(float accumulator, float new_number);

void show_aritmetics(float acc_sum, float acc_subtraction, float acc_multiplication, float acc_division);