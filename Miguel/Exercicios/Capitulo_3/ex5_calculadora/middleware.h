#include <stdio.h>

#define EQUALS '='
#define ADD '+'
#define SUB '-'
#define MULT '*'
#define DIV '/'


void clear_buffer();

void display_explaining_message();

void display_ans(float accumulator);

float addition(float accumulator, float operand);
float subtraction(float accumulator, float operand);
float multiplication(float accumulator, float operand);
float division(float accumulator, float operand);

float resolve_expression(float operand_1, char _operator, float operand_2);