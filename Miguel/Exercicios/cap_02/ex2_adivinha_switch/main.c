// 2 - Reescreva o programa do exercicio anterior agora utilizando o comando switch.
//     Conte o n. de tentativas e imprima o resultado no video.

#define INNER_MODE
// #define OUTER_MODE

#ifdef OUTER_MODE
#include "middleware.h"

int main() {
    
    char again = 'n';
    do {
        int tries;
        
        display_message();
        tries = number_guesser();
        
        printf("Levaram %d tentativas para adivinhar\n\n", tries);
        
        // +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
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

int number_guesser() {
    int guess;
    int tries = 0;
    int LOWER_BOUND = 1;
    int UPPER_BOUND = 99;
    
    int half_cut = (UPPER_BOUND - LOWER_BOUND) / 2;
    
    char relation;
    while (UPPER_BOUND - LOWER_BOUND != 1) {
        
        printf("Seu número é %d?  ", half_cut);
        scanf("%c", &relation);
        clear_buffer();
        printf("\n\n");
        
        switch (relation) {
            case '>':
                tries++;
                LOWER_BOUND = half_cut + 1;
                half_cut = LOWER_BOUND + (UPPER_BOUND - LOWER_BOUND) / 2;
                break;
            case '<':
                tries++;
                UPPER_BOUND = half_cut - 1;
                half_cut = LOWER_BOUND + (UPPER_BOUND - LOWER_BOUND) / 2;
                break;
            case '=':
                tries++;
                guess = half_cut;
                printf("O número escolhido é %d\n\n", guess);
                return tries;
                break;
        }
    }
    
    printf("Seu número é %d?  ", UPPER_BOUND);
    scanf("%c", &relation);
    clear_buffer();
    printf("\n\n");
    
    if (relation == '=') {
        guess = UPPER_BOUND;
        printf("O número escolhido é %d\n\n", guess);
        
    } else {
        
        tries++;
        printf("O número escolhido é %d\n\n", guess);
    }
    return tries;
}

void display_message() {
    
    printf("Bem vindo ao adivinhador!\n");
    printf("Adivinharei seu número na menor quantidade de tentativas possível\n");
    printf("Ao aparecer o número, digite:");
    printf("\n   ' < ' --> se for menor\n   ' > ' --> se for maior\n   ' = ' --> se for igual\n\n");
    return;
}

int main() {
    
    char again = 'n';
    do {
        int tries;
        
        display_message();
        tries = number_guesser();
        
        printf("Levaram %d tentativas para adivinhar\n\n", tries);
        
        // +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
        printf("Deseja executar novamente? ( s / n )  ");
        scanf("%c", &again);
        clear_buffer();
    } while (again == 's');
    return 0;
}
#endif // INNER_MODE
