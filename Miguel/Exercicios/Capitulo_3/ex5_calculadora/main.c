// 5 - Escreva um programa que receba n valores inteiros via teclado na funcao main().
//     Faca uma calculadora com as 4 operacoes aritmeticas.(utilize o comando switch).
//     As operacoes aritmeticas devem ser funcoes. O resultado acumulado deve ser 
//     mostrado na funcao main().

#include "middleware.h"


int main() {

    const char ADD = '+';
    const char SUB = '-';
    const char MULT = '*';
    const char DIV = '/';
    
    const char CONTINUE = '>';
    const char EQUALS = '=';
    
    char again = 'n';
    do {
        
        // +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
        printf("Deseja execurar novamente? ( s / n) ");
        scanf("%c", &again);
        clean_buffer();
    } while (again == 's');
    return 0;
}