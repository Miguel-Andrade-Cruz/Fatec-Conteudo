// 2 - Escreva um programa que receba um numero inteiro N via teclado. Escreva uma 
//     funcao que retorne a soma dos algarismos do numero N recebido. O resultado 
//     deve ser mostrado na funcao main(). 
//     Ex: se N = 1234. Logo, a soma de seus algarismos e' 1 + 2 + 3 + 4 = 10.

#define INNER_MODE
// #define OUTER_MODE


#ifdef OUTER_MODE
#include "middleware.h"

int main() {
    
    char again = 'n';
    do {
        
        int sum_of_alg;
        int num = ask_for_number();
        
        sum_of_alg = sum_number_algs(num);
        
        show_alg_sum(num, sum_of_alg);
        
        // +-+-+-+-+-+-+-+-+-+-+-+-
        printf("Deseja executar novamente? ( s / n )  ");
        scanf("%c", &again);
        clear_buffer();
    } while (again == 's');
    
    return 0;
}
#endif // OUTER_MODE


#ifdef INNER_MODE
#include <stdio.h>
#include <math.h>

void clear_buffer() {
    
    while (getchar() != '\n');
    return;
}

int ask_for_number() {
    
    int num;
    
    printf("Insira um número positivo:  ");
    scanf("%d", &num);
    clear_buffer();
    return num;
}

int sum_number_algs(int num) {
    
    const int BASE_TEN = 10;
    // 'alg' means 'algarism'
    int alg_sum = 0;
    
    int max_exponent = 0;
    int is_just_decimal_part =
        ( num / pow(BASE_TEN, max_exponent) ) < 1
    ;
    
    while ( is_just_decimal_part == 0 ) {
        is_just_decimal_part = (num / pow(BASE_TEN, ++max_exponent) < 1);
    }
    
    for (int exponent = max_exponent; exponent >= 0; exponent--) {
        
        int pow_of_ten = pow(BASE_TEN, exponent);
        int alg_value = num / pow_of_ten;
        
        alg_sum += alg_value;
        num -= alg_value * pow_of_ten;
    }
    
    return alg_sum;
}

void show_alg_sum(int num, int sum_of_alg) {
    
    printf("A soma dos algarismos de %d é igual a %d\n", num, sum_of_alg);
    return;
}

int main() {
    
    char again = 'n';
    do {
        
        int num = ask_for_number();
        int alg_sum = sum_number_algs(num);
        
        show_alg_sum(num, alg_sum);
        // +-+-+-+-+-+-+-+-+-+-+-+-
        printf("Deseja executar novamente? ( s / n )  ");
        scanf("%c", &again);
        clear_buffer();
    } while (again == 's');
    
    return 0;
}
#endif // INNER_MODE
