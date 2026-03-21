// 2 - Escreva um programa que receba um numero inteiro N via teclado. Escreva uma 
//     funcao que retorne a soma dos algarismos do numero N recebido. O resultado 
//     deve ser mostrado na funcao main(). 
//     Ex: se N = 1234. Logo, a soma de seus algarismos e' 1 + 2 + 3 + 4 = 10.

#include "middleware.h"


int main() {
    
    char again = 'n';
    do {
        
        int sum_of_alg;
        int num = ask_for_number();
        
        sum_of_alg = sum_number_algarisms(num);
        
        show_sum_of_algarisms(num, sum_of_alg);
        
        // +-+-+-+-+-+-+-+-+-+-+-+-
        printf("Deseja executar novamente? ( s / n )  ");
        scanf("%c", &again);
        clear_buffer();
    } while (again == 's');
    
    return 0;
}