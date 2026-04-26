// 3 - Escreva um programa que receba via teclado numeros inteiros positivos.
//    Quando o numero digitado for negativo o programa deve parar e calcula a
//    media dos valores positivos digitados.

#define INNER_MODE
// #define OUTER_MODE

#ifdef OUTER_MODE
#include "middleware.h"

int main() {
    
    char again = 'n';
    do {
        
        int average = acummulator();
        show_average(average);
        
        printf("Deseja executar novamente? ( s / n )  ");
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

int ask_number() {
    
    int num;
    
    printf("--->>  ");
    scanf("%d", &num);
    clear_buffer();
    return num;
}

void show_average(float average) {
    
    printf("O valor médio dos números digitados é %.2f\n\n", average);
    return;
}

int main() {
    
    char again = 'n';
    do {
        
        float total = 0;
        int acummulator = ask_number();
        
        int counter = 0;
        int is_negative = 0;
        do {
            
            counter++;
            total += acummulator;
            
            acummulator = ask_number();
            
            is_negative = ( acummulator < 0 );
        } while (!is_negative);
        
        float average = total / counter;
        show_average(average);
        
        printf("Deseja executar novamente? ( s / n )  ");
        scanf("%c", &again);
        clear_buffer();
    } while (again == 's');
    return 0;
}
#endif // INNER_MODE
