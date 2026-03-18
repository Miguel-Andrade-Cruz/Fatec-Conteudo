// 3 - Escreva um programa que receba via teclado numeros inteiros positivos.
//    Quando o numero digitado for negativo o programa deve parar e calcula a
//    media dos valores positivos digitados.

#include "middleware.h"

int main() {
    
    char again = 'n';
    do {
        
        int average = acummulator();
        show_average(average);
        
        printf("Deseja executar novamente? ( s / n ) ");
        scanf("%c", &again);
        clear_buffer();
    } while (again == 's');
    return 0;
}