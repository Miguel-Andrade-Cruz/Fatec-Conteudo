#include "middleware.h"
#include <stdio.h>


void clear_buffer() {
    
    while (getchar() != '\n');
    return;
}


void display_message() {
    
    printf("Bem vindo ao adivinhador!\n");
    printf("Adivinharei seu número na menor quantidade de tentativas possível\n");
    printf("Ao aparecer o número, digite:\n\n   ' < ' --> se for menor\n\n   ' > ' --> se for maior\n\n   ' = ' --> se for igual\n\n");
    return;
}


int number_guesser() {
    int guess;
    int tries = 0;
    int LOWER_BOUND = 1;
    int UPPER_BOUND = 99;
    
    int half_cut = UPPER_BOUND - LOWER_BOUND / 2;
    
    char relation;
    while (UPPER_BOUND - LOWER_BOUND != 2) {
        
        printf("Seu número é %d?  ", half_cut);
        scanf("%c", &relation);
        clear_buffer();
        printf("\n\n");
        
        switch (relation) {
            case '>':
                tries++;
                LOWER_BOUND = half_cut;
                half_cut = LOWER_BOUND + (UPPER_BOUND - LOWER_BOUND) / 2;
                break;
            case '<':
                tries++;
                UPPER_BOUND = half_cut;
                half_cut = LOWER_BOUND + (UPPER_BOUND - LOWER_BOUND) / 2;
                break;
            case '=':
                tries++;
                guess = half_cut;
                printf("O número escolhido é %d\n\n", guess);
                return tries;
        }
    }
    
    printf("Seu número é %d?  ", LOWER_BOUND + 1);
    scanf("%c", &relation);
    clear_buffer();
    printf("\n\n");
    
    switch (relation) {
        case '=':
            guess = LOWER_BOUND + 1;
            printf("O número escolhido é %d\n\n", guess);
        case '>':
            tries++;
            guess = UPPER_BOUND;
            printf("O número escolhido é %d\n\n", guess);
    }
    return tries; //
}