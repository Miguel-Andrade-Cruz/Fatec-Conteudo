// 2 - Escreva um programa para receber 5 nomes, com até 7 caracteres, via teclado
//     e imprima-os no video no seguinte formato:
//     (Declare os 5 vetores como variaveis globais)
//
//              10        20        30        40        50
//    12345678901234567890123456789012345678901234567890
//      nome1                                   nome5
//                nome2               nome4
//                          nome3

#include "middleware.h"


int main() {

    char again = 'n';
    do {
        
        // +-+-+-+-+-+-+-+-+-+-+-+-+-+
        printf("Deseja executar novamente? ( s / n )  ");
        scanf("%c", &again);
        clear_buffer();
    } while (again == 's');
    return 0;
}