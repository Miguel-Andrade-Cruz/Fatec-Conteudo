#include "middleware.h"
#include <stdio.h>


void clear_buffer() {
    
    while (getchar() != '\n');
    return;
}


void display_message() {
    
    printf("Bem vindo ao adivinhador!\n");
    printf("Adivinharei seu número na menor quantidade de tentativas possível\n");
    
    return; //
}


int number_guesser() {
    int guess;
    int tries = 0;
    int LOWER_BOUND = 1;
    int UPPER_BOUND = 99;
    
    int half_cut = UPPER_BOUND - LOWER_BOUND / 2;
    
    char relation;
    while (UPPER_BOUND - LOWER_BOUND == 2) {
        printf("Seu número é maior que %d?  ", half_cut);
        scanf("%c", &relation);
        
        switch (relation) {
            case '>':
                tries++;
                LOWER_BOUND = half_cut;
                half_cut = (UPPER_BOUND - LOWER_BOUND / 2) + LOWER_BOUND;
            case '<':
                tries++;
                UPPER_BOUND = half_cut;
                half_cut = (UPPER_BOUND - LOWER_BOUND / 2);
            case '=':
                guess = half_cut;
                printf("O número escolhido é %d", guess);
                return tries;
        }
    }
    
    printf("Seu número é %d?  ", LOWER_BOUND + 1);
    scanf("%c", &relation);
    switch (relation) {
        case '=':
            guess = LOWER_BOUND + 1;
            printf("O número escolhido é %d", guess);
        case '>':
            tries++;
            guess = UPPER_BOUND;
            printf("O número escolhido é %d", guess);
    }
    return tries; //
}