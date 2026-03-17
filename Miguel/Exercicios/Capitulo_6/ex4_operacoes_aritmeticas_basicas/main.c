// 4 - Escreva um programa que receba via teclado 2 numeros inteiros e
//     imprima-os no video com o resultado das 4 operacoes aritmeticas.


#include "middleware.h"

int main() {
    
    char again = 'n';
    do {
        int num_1, num_2;
        ask_for_two_numbers(&num_1, &num_2);
        
        print_add_operation(num_1, num_2);
        print_sub_operation(num_1, num_2);
        print_mult_operation(num_1, num_2);
        print_div_operation(num_1, num_2);
        
        // +-+-+-+-+-+-+-+-+
        printf("Deseja executar novamente? ( s / n )  ");
        scanf("%c", &again);
        clear_buffer();
    } while (again == 's');
    return 0;
}
