// 4 - Escreva um programa que receba via teclado 2 numeros inteiros e
//     imprima-os no video com o resultado das 4 operacoes aritmeticas.


#include "middleware.h"

int main() {
    
    char again = 'n';
    do {

        // +-+-+-+-+-+-+-+-+
        printf("Deseja executar novamente? ( s / n )  ");
        scanf("%c", &again);
        clear_buffer();
    } while (again == 's');
    return 0;
}
