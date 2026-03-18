// 1 - Escreva um programa para adivinhar um numero entre 1 e 99 que o usuario
//    pensou. Digite via teclado os simbolos =, > ou < a cada pergunta. Utilize o
//    comando if-else.

#include "middleware.h"


int main() {

    char again = 'n';
    do {
        int guess;
        
        display_message();
        guess = number_guesser();
        
        printf("O número escolhido foi %d", guess);
        
        // +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
        printf("Deseja executar novamente? ");
        scanf("%c", &again);
        clear_buffer();
    } while (again == 's');
    return 0;
}