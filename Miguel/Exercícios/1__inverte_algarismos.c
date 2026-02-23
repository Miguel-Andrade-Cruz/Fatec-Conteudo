#include <stdio.h>
#include <math.h>

const int BASE_DEC = 10;
const int ALGS_QTD = 3;



// 1 - Faça um programa para ler um numero inteiro, positivo de tres digitos, e gerar
//      outro número formado pelos dígitos invertidos do número lido.
//      Ex:   NúmeroLido = 123
//               NúmeroGerado = 321

// 2490 --> 0942

int valid_input() {
    int input;
    
    do {
        printf("Insira um número: \n");
        scanf("%d", &input);
        
    } while (input <= 99 || input > 999);
    
    return input;
}



void decompose(int origin_input, int *decomposed) {
    
    int quocient = origin_input;
    for (int i = 0; i < ALGS_QTD; i++) {
        if (origin_input == 0) {
            decomposed[i] = 0;
        } else {
            decomposed[i] = quocient % BASE_DEC;
            quocient /= BASE_DEC;
        }
    }

    return;
}

int recompose(int *decomposed) {
    
    int recomposed;
    for (int i = ALGS_QTD -1, exp = 0; i >= 0; i--, exp++) {
        recomposed += (int) (pow(BASE_DEC, exp) * decomposed[i]);
    }
    
    return 0;
}



int mirror_number(int origin_input) {
    
    
    int decomposed[3];
    
    decompose(origin_input, decomposed);
    int mirrored = recompose(decomposed);
    
    return mirrored;
}



int main() {
    
    char again = 's';
    
    while (again == 's') {
        
        int clean_input = valid_input();
        int inverted_algarisms = mirror_number(clean_input);
        
        printf("Generated the inverse of %d: --> %d \n\n", clean_input, inverted_algarisms);
        
        printf("Do you want to run again? (s/n): \n");
        while(getchar() != 0);
        scanf("%c", &again);
    }
    
    return 0;
}