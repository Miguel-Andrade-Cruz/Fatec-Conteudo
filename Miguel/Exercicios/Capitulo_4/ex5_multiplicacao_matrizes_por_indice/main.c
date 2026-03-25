// 5 - Defina 2 vetores bidimensionais do tipo inteiro de 2x3. Escreva um programa
//    que recebe os dados via teclado para esses 2 vetores. Usando o operador
//    multiplicacao '*', multiplique os elementos de mesmo indice dos 2 vetores e guarde
//    o resultado em um 3. vetor. Imprima na tela os indices, os valores e o resultado
//    dos 6 elementos dos vetores.

#include "middleware.h"


int main() {
    
    char again = 'n';
    do {
        
        
        
        
        // +-+-+-+-+-+-+-+-+-+-+-+-+
        printf("Desja executar novamente? ( s / n )  ");
        scanf("%c", &again);
        clear_buffer();
    } while (again == 's');
    return 0;
}
