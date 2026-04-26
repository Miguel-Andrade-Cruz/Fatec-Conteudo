// 3 - Escreva um programa que receba na funcao main() 2 valores inteiro. Escreva
//     uma funcao para cada operacoes aritmeticas e passe como parametro os 2
//     valores recebidos na funcao main(). Retorne os resultados usando o comando
//     return e imprima os 4 resultados no video na funcao main().


#define INNER_MODE
// #define OUTER_MODE




#ifdef OUTER_MODE
#include "middleware.h"

int main() {
    
    char again = 'n';
    do {
        
        // +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
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

float ask_number() {
    
    float num;
    
    scanf("%f", &num);
    clear_buffer();
    return num;
}

float add(float num_1, float num_2) {
    
    return num_1 + num_2;
}

float subtract(float num_1, float num_2) {
    
    return num_1 - num_2;
}

float multiply(float num_1, float num_2) {
    
    return num_1 * num_2;
}

float divide(float num_1, float num_2) {
    
    return num_1 / num_2;
}

void show_aritmetics(float sum, float subtraction, float multiplication, float division) {
    
    printf("Resultado das opreações:\n");
    
    printf("Adição: %.3f\n", sum);
    printf("Subtração: %.3f\n", subtraction);
    printf("Multiplicação: %.3f\n", multiplication);
    printf("Divisão: %.3f\n", division);
    
    return;
}

int main() {
    
    char again = 'n';
    do {
        
        float sum_of, sub_of, mult_of, div_of;
        
        printf("Insira o primeiro número:  ");
        float num_1 = ask_number();
        
        printf("Insira o segundo número:  ");
        float num_2 = ask_number();
        
        sum_of = add(num_1, num_2);
        sub_of = subtract(num_1, num_2);
        mult_of = multiply(num_1, num_2);
        div_of = divide(num_1, num_2);
        
        show_aritmetics(sum_of, sub_of, mult_of, div_of);
        
        // +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
        printf("Deseja executar novamente? ( s / n )  ");
        scanf("%c", &again);
        clear_buffer();
    } while (again == 's');
    
    return 0;
}
#endif // INNER_MODE
