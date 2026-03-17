// 5 - Reescreva o exercicio anterior utilizando operadores de atribuicao
//    composta.

#include "middleware.h"


int main() {

    char again = 'n';
    do {
        
        // +-+-+-+-+-+-+-+-+-+-
        printf("Deseja executar novamente? ( s / n )  ");
        scanf("%c", &again);
        clear_buffer();
    } while (again == 's');
    return 0;
}