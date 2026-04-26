#include "middleware.h"


void clear_buffer() {
    
    while (getchar() != '\n');
    return;
}


void display_message() {
    
    printf("Bem vindo ao adivinhador!\n");
    printf("Adivinharei seu número na menor quantidade de tentativas possível\n");
    printf("Para cada número que aparecer, digite:\n");
    printf("   ' < ' --> Se for menor\n\n   ' > ' --> Se for maior\n\n   ' = ' --> Se for igual\n\n");
    return; //
}


int number_guesser() {
    int guess;
    int LOWER_BOUND = 1;
    int UPPER_BOUND = 99;
    
    int half_cut = (UPPER_BOUND - LOWER_BOUND) / 2;
    
    char relation;
    while (UPPER_BOUND - LOWER_BOUND != 2) {
        printf("Seu número é %d?  ", half_cut);
        scanf("%c", &relation);
        clear_buffer();
        printf("\n");
        
        if ( relation == '>' ) {
            
            LOWER_BOUND = half_cut;
            half_cut = LOWER_BOUND + (UPPER_BOUND - LOWER_BOUND) / 2;
        } else if ( relation == '<' ) {
            
            UPPER_BOUND = half_cut;
            half_cut = LOWER_BOUND + (UPPER_BOUND - LOWER_BOUND) / 2;
        } else {
            guess = half_cut;
            return guess;
        }
    }
    
    printf("Seu número é %d?  ", LOWER_BOUND + 1);
    scanf("%c", &relation);
    clear_buffer();
    if ( relation == '=' ) {
        guess = LOWER_BOUND + 1;
    } else {
        guess = UPPER_BOUND;
    }
    return guess; //
}