// 4 - Escreva um programa que determine o menor multiplo de um numero inteiro. Este
//      multiplo deve ser maior que o limite minimo recebido. Recebe os 2 numeros via
//      teclado.
//     Ex: menor multiplo de 13 maior que 100. Resultado: 104.

#define INNER_MODE
// #define OUTER_MODE






#ifdef OUTER_MODE
#include "middleware.h"

int main() {
    
    char again = 'n';
    do {
        int reference_number = input_reference_number();
        int minimal_limit = input_minimal_limit();
        int minimal_factor = get_minimal_factor(reference_number, minimal_limit);
        
        printf("O menor múltiplo de %d maior que %d é %d\n", reference_number, minimal_limit, minimal_factor);
        
        // +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
        printf("Deseja executar novamente? ( s / n)  ");
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

int input_reference_number() {
    
    int number;
    printf("Digite seu número de referência (número positivo): ");
    do {
        scanf("%d", &number);
        clear_buffer();
    } while (number <= 0);
    
    return number;
}

int input_minimal_limit() {
    
    int number;
    printf("Digite o limite (número positivo): ");
    do {
        scanf("%d", &number);
        clear_buffer();
    } while (number <= 0);
    
    return number;
}

int get_minimal_factor(int reference_number, int minimal_limit) {
    
    int minimal_factor;
    
    if (minimal_limit <= reference_number) {
        minimal_factor = reference_number;
    } else {
        
        int aprox_minimal_factor = minimal_factor / reference_number - 1;
        
        int next_factor = reference_number * aprox_minimal_factor;
        while ( next_factor < minimal_limit ) {
            next_factor += reference_number;
        }
        minimal_factor = next_factor;
    }

    return minimal_factor;
}

int main() {
    
    char again = 'n';
    do {
        int reference_number = input_reference_number();
        int minimal_limit = input_minimal_limit();
        int minimal_factor = get_minimal_factor(reference_number, minimal_limit);
        
        printf("O menor múltiplo de %d maior que %d é %d\n", reference_number, minimal_limit, minimal_factor);
        
        // +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
        printf("Deseja executar novamente? ( s / n)  ");
        scanf("%c", &again);
        clear_buffer();
    } while (again == 's');
    return 0;
}
#endif // INNER_MODE
