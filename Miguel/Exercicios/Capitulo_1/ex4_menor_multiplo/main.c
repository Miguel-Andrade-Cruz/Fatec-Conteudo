// 4 - Escreva um programa que determine o menor multiplo de um numero inteiro. Este
//      multiplo deve ser maior que o limite minimo recebido. Recebe os 2 numeros via
//      teclado.
//     Ex: menor multiplo de 13 maior que 100. Resultado: 104.

#include <stdio.h>
#include "middleware.h"


int main() {

    char again = 'n';
    do {
        int reference_number = input_reference_number();
        int minimal_limit = input_minimal_limit();
        int minimal_factor = get_minimal_factor(reference_number, minimal_limit);

        printf("O menor múltiplo de %d maior que %d é %d\n", reference_number, minimal_limit, minimal_factor);

        printf("Deseja inserir um novo número? ");
        scanf("%c", &again);
    } while (again == 's');
    return 0;
}