#include <stdio.h>
#include "middleware.h"



// 1 - Faça um programa para ler um numero inteiro, positivo de tres digitos, e gerar
//      outro número formado pelos dígitos invertidos do número lido.
//      Ex:   NúmeroLido = 123
//               NúmeroGerado = 321

// 2490 --> 0942


int main() {

    char again = 's';

    while (again == 's') {

        int clean_input = valid_input();
        int inverted_algarisms = mirror_number(clean_input);

        printf("Generated the inverse of %d: --> %d \n\n", clean_input, inverted_algarisms);

        printf("Do you want to run again? (s/n): ");
        scanf("%c", &again);
        
        // clear buffer
        while(getchar() != '\n');
    }

    return 0;
}