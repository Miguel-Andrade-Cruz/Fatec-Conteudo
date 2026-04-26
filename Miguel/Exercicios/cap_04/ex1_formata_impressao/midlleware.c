#include "middleware.h"

void clear_buffer() {
    
    while (getchar() != '\n');
    return;
}

void ask_for_ints(int *vec, char *msg) {
    
    printf("Números %s:\n", msg);
    for (int i = 0; i < 3; i++) {
        
        printf("-->>  ");
        scanf("%d", &vec[i]);
        clear_buffer();
    }
    return;
}

void ask_for_floats(float *vec, char *msg) {
    
    printf("Número %s:\n", msg);
    for (int i = 0; i < 3; i++) {
        printf("-->>  ");
        scanf("%f", &vec[i]);
        clear_buffer();
    }
    return;
}

void ask_for_unsigneds(unsigned *vec, char *msg) {
    
    printf("Número %s:\n", msg);
    for (int i = 0; i < 3; i++) {
        printf("-->>  ");
        scanf("%u", &vec[i]);
        clear_buffer();
    }
    return;
}

void ask_for_longs(long *vec, char *msg) {
    
    printf("Número %s:\n", msg);
    for (int i = 0; i < 3; i++) {
        printf("-->>  ");
        scanf("%li", &vec[i]);
        clear_buffer();
    }
    return;
}

void ask_for_doubles(double *vec, char *msg) {
    
    printf("Número %s:\n", msg);
    for (int i = 0; i < 3; i++) {
        printf("-->>  ");
        scanf("%lf", &vec[i]);
        clear_buffer();
    }
    return;
}


void print_formatted(
    int *vec_int,
    float *vec_float,
    unsigned *vec_unsigned,
    long *vec_long,
    double *vec_double
) {
    
    printf("%10d%8d%8d%8d%8d\n",
        TEN, TWENY, THIRTY, FORTY, FIFTY
    );
    printf("%4d%d%d%d%d\n",
        one_to_zero, one_to_zero,
        one_to_zero, one_to_zero,
        one_to_zero
    );
    
    for (int i = 0; i < 3; i++) {
        
        printf("%6d%17li%16u\n",
            vec_int[i], vec_long[i], vec_unsigned[i]
        );
        printf("%16f%15lf\n",
            vec_float[i], vec_double[i]
        );
    }

}
