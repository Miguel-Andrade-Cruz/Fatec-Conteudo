// 4 - Escreva um programa que determine o menor multiplo de um numero inteiro. Este
//      multiplo deve ser maior que o limite minimo recebido. Recebe os 2 numeros via
//      teclado.
//     Ex: menor multiplo de 13 maior que 100. Resultado: 104.

#include <stdio.h>



int input_positive_number() {

    int number;

    do {
        printf("Insira um número positivo");
        scanf("%d", &number);
    } while (number <= 0);
    
    return number;
}


int get_minimal_factor(int refernce_number, int minimal_limit) {

    int minimal_factor;
    
    if (minimal_limit <= refernce_number) {
        minimal_factor = refernce_number;
    } else {
    
        int aprox_minimal_factor = minimal_factor / refernce_number - 1;
        
        int next_factor = refernce_number * aprox_minimal_factor;
        while ( next_factor < minimal_limit ) {
            next_factor += refernce_number;
        }
        minimal_factor = next_factor;
    }

    return minimal_factor;
}


int main() {

    int reference_number = input_positive_number();
    int minimal_limit = input_positive_number();

    int minimal_factor = get_minimal_factor(reference_number, minimal_limit);

    printf("O menor múltiplo de %d maior que %d é %d", reference_number, minimal_limit, minimal_factor);

    return 0;
}