#include <stdio.h>


#define one_to_zero 1234567890
#define TEN 10
#define TWENY 20
#define THIRTY 30
#define FORTY 40
#define FIFTY 50

void clear_buffer();

void ask_for_ints(int *vec, char *msg);
void ask_for_floats(float *vec, char *msg);
void ask_for_unsigneds(unsigned *vec, char *msg);
void ask_for_longs(long *vec, char *msg);
void ask_for_doubles(double *vec, char *msg);

void print_formatted(
    int *vec_int,
    float *vec_float,
    unsigned *vec_unsigned,
    long *vec_long,
    double *vec_double
);
