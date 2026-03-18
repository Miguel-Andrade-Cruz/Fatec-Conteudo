// 2 - Reescreva o programa do exercicio anterior agora utilizando o comando switch.
//     Conte o n. de tentativas e imprima o resultado no video.

#include "middleware.h"


int main() {

    char again = 'n';
    do {
        int tries;
        
        display_message();
        tries = number_guesser();
        
        printf("Levaram %d tentativas para adivinhar", tries);

        // +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
        printf("Deseja executar novamente? ");
        scanf("%c", &again);
        clear_buffer();
    } while (again == 's');
    return 0;

}