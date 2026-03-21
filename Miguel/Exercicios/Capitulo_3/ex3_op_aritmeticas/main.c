// 3 - Escreva um programa que receba na funcao main() 2 valores inteiro. Escreva
//     uma funcao para cada operacoes aritmeticas e passe como parametro os 2
//     valores recebidos na funcao main(). Retorne os resultados usando o comando
//     return e imprima os 4 resultados no video na funcao main().

#include "middleware.h"


int main() {
    
    char again = 'n';
    do {
        
        float sum_of, substraction_of, multiplication_of, division_of;
        
        int num_1 = ask_first_number();
        int num_2 = ask_second_number();
        
        sum_of = add(num_1, num_2);
        substraction_of = subtract(num_1, num_2);
        multiplication_of = multiply(num_1, num_2);
        division_of = divide(num_1, num_2);
        
        show_aritmetics(sum_of, substraction_of, multiplication_of, division_of);
        
        // +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
        printf("Deseja executar novamente? ( s / n )  ");
        scanf("%c", &again);
        clear_buffer();
    } while (again == 's');
    
    return 0;
}