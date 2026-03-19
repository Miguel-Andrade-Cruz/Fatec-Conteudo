#include "middleware.h"

#define DEBUG

const int BASE_DEC = 10;
const int ALGS_QTD = 3;

void clear_buffer() {
    
    while (getchar() != '\n');
    return;
}


int valid_input() {
    int input;
    
    do {
        printf("Insira um número: \n");
        scanf("%d", &input);
        
    } while (input <= 99 || input > 999);
    clear_buffer();
    
    return input;
}


void decompose(int origin_input, int *decomposed) {
    
    int quocient = origin_input;
    for (int i = 0; i < ALGS_QTD; i++) {
        decomposed[i] = quocient % BASE_DEC;
        quocient /= BASE_DEC;
    }
    
    return;
}


int recompose(int *decomposed) {
    
    int recomposed;
    for (int i = ALGS_QTD -1, exp = 0; i >= 0; i--, exp++) {
        recomposed += (int) (pow(BASE_DEC, exp) * decomposed[i]);
    }
    
    return recomposed;
}


int mirror_number(int origin_input) {
    
    int decomposed[3];
    
    decompose(origin_input, decomposed);
    int mirrored = recompose(decomposed);
    
    return mirrored;
}
