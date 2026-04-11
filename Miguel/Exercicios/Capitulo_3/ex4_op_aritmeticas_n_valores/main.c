// 4 - Reescreva o programa do exercicio anterior para receber via teclado n
//     valores. Mostre os 4 resultados na funcao main().
//     Os n valores nao sao pedidos ao usuario. Lembre-se da calculadora.

#define INNER_MODE
// #define OUTER_MODE


#ifdef OUTER_MODE
#include "middleware.h"

int main() {

    char again = 'n';
    do {
        
        printf("Insira valores consecutivamente até que não se possa calcular\n");
        printf("O resultado acumulado será exibido ao final do cálulo\n");
        
        float acc_sum, acc_sub, acc_mult, acc_div;
        float start_value = ask_for_value();
                
        // 'acc' means 'accumulated'
        acc_sum =
            acc_sub =
            acc_mult =
            acc_div =
        start_value;
        
        float next_value = ask_for_value();
        
        
        int running = 1;
        while (running) {
            
            acc_sum = add(acc_sum, next_value);
            acc_sub = subtract(acc_sub, next_value);
            acc_mult = multiply(acc_mult, next_value);
            acc_div = divide(acc_div, next_value);
            
            next_value = ask_for_value();
            if ( next_value == 0 ) {
                running = 0;
            }
        }
        
        show_aritmetics(acc_sum, acc_sub, acc_mult, acc_div);
        
        // +-+-+-+-+-+-+-+-+-+-+-+-+-
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

int ask_for_value() {
    
    int value;
    
    printf("--->>  ");
    scanf("%d", &value);
    return value;
}

float add(float accumulator, float new_number) {
    
    return accumulator + new_number;
}


float subtract(float accumulator, float new_number) {
    
    return accumulator - new_number;
}


float multiply(float accumulator, float new_number) {
    
    return accumulator * new_number;;
}


float divide(float accumulator, float new_number) {
    
    return accumulator / new_number;
}

void show_aritmetics(float acc_sum, float acc_subtraction, float acc_multiplication, float acc_division) {
    
    printf("Resultado das operações consecutivas:\n");
    printf("Adição: %.3f\n", acc_sum);
    printf("Subtração: %.3f\n", acc_subtraction);
    printf("Multiplicação: %.3f\n", acc_multiplication);
    printf("Divisão: %.3f\n", acc_division);
    return;
}

int main() {
    
    char again = 'n';
    do {
        printf("Insira valores consecutivamente até que não se possa calcular\n");
        printf("O resultado acumulado será exibido ao final do cálulo\n");
        
        float acc_sum, acc_sub, acc_mult, acc_div;
        float start_value = ask_for_value();
                
        // 'acc' means 'accumulated'
        acc_sum =
            acc_sub =
            acc_mult =
            acc_div =
        start_value;
        
        float next_value = ask_for_value();
        
        int running = 1;
        while (running) {
            
            acc_sum = add(acc_sum, next_value);
            acc_sub = subtract(acc_sub, next_value);
            acc_mult = multiply(acc_mult, next_value);
            acc_div = divide(acc_div, next_value);
            
            next_value = ask_for_value();
            if ( next_value == 0 ) {
                running = 0;
            }
        }
        
        show_aritmetics(acc_sum, acc_sub, acc_mult, acc_div);
        
        // +-+-+-+-+-+-+-+-+-+-+-+-+-
        printf("Deseja executar novamente? ( s / n )  ");
        scanf("%c", &again);
        clear_buffer();
    } while (again == 's');
    return 0;
}
#endif // INNER_MODE
