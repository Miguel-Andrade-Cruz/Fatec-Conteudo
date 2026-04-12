// 1 - Escreva um programa para adivinhar um numero entre 1 e 99 que o usuario
//    pensou. Digite via teclado os simbolos =, > ou < a cada pergunta. Utilize o
//    comando if-else.

#define INNER_MODE
// #define OUTER_MODE

#ifdef OUTER_MODE

#include "middleware.h"
int main() {

    char again = 'n';
    do {
        int guess;
        
        display_message();
        guess = number_guesser();
        
        printf("O número escolhido foi %d\n\n", guess);
        
        // +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
        printf("Deseja executar novamente? ( s / n )  ");
        scanf("%c", &again);
        clear_buffer();
    } while (again == 's');
    return 0;
}
#endif // OUTER_MODE


#ifdef INNER_MODE
#include <stdio.h>

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
    while (UPPER_BOUND - LOWER_BOUND != 1) {
        printf("Seu número é %d?  ", half_cut);
        scanf("%c", &relation);
        clear_buffer();
        printf("\n");
        
        if ( relation == '>' ) {
            
            LOWER_BOUND = half_cut + 1;
            half_cut = LOWER_BOUND + (UPPER_BOUND - LOWER_BOUND) / 2;
        } else if ( relation == '<' ) {
            
            UPPER_BOUND = half_cut - 1;
            half_cut = LOWER_BOUND + (UPPER_BOUND - LOWER_BOUND) / 2;
        } else {
            guess = half_cut;
            return guess;
        }
    }
    
    printf("Seu número é %d?  ", LOWER_BOUND);
    scanf("%c", &relation);
    clear_buffer();
    if ( relation == '=' ) {
        guess = LOWER_BOUND;
    } else {
        guess = UPPER_BOUND;
    }
    return guess;
}

int main() {

    char again = 'n';
    do {
        int guess;
        
        display_message();
        guess = number_guesser();
        
        printf("O número escolhido foi %d\n\n", guess);
        
        // +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
        printf("Deseja executar novamente? ( s / n )  ");
        scanf("%c", &again);
        clear_buffer();
    } while (again == 's');
    return 0;
}
#endif // INNER_MODE
