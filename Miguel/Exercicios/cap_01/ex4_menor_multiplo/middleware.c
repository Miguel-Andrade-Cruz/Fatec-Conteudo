#include "middleware.h"


void clear_buffer() {
    
    while (getchar() != '\n');
    return;
}


int input_reference_number() {
    
    int number;
    printf("Digite seu número de referência (número positivo): ");
    do {
        scanf("%d", &number);
        clear_buffer();
    } while (number <= 0);
    
    return number;
}


int input_minimal_limit() {
    
    int number;
    printf("Digite o limite (número positivo): ");
    do {
        scanf("%d", &number);
        clear_buffer();
    } while (number <= 0);
    
    return number;
}



int get_minimal_factor(int reference_number, int minimal_limit) {
    
    int minimal_factor;
    
    if (minimal_limit <= reference_number) {
        minimal_factor = reference_number;
    } else {
        
        int aprox_minimal_factor = minimal_factor / reference_number - 1;
        
        int next_factor = reference_number * aprox_minimal_factor;
        while ( next_factor < minimal_limit ) {
            next_factor += reference_number;
        }
        minimal_factor = next_factor;
    }

    return minimal_factor;
}
