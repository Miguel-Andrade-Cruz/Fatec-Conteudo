// 4 - Reescreva o programa do exercicio anterior para receber via teclado n
//     valores. Mostre os 4 resultados na funcao main().
//     Os n valores nao sao pedidos ao usuario. Lembre-se da calculadora.

#include "middleware.h"


int main() {

    char again = 'n';
    do {
        float acc_sum, acc_subtraction, acc_multiplication, acc_division;
        float start_value = ask_for_value();
        
        
        // first attribution
        // 'acc' means 'accumulated'
        acc_sum = start_value; acc_subtraction = start_value;
        acc_multiplication = start_value; acc_division = start_value;
        
        while (1) {
            
            int next_value = ask_for_value();
            if ( next_value == 0 ) {
                break;
            }
            
            acc_sum = add(acc_sum, next_value);
            acc_subtraction = subtract(acc_subtraction, next_value);
            acc_multiplication = multiply(acc_multiplication, next_value);
            acc_division = divide(acc_division, next_value);
        }
        
        show_aritmetics(acc_sum, acc_subtraction, acc_multiplication, acc_division);
        
        // +-+-+-+-+-+-+-+-+-+-+-+-+-
        printf("Deseja executar novamente? ( s / n )  ");
        scanf("%c", &again);
        clear_buffer();
    } while (again == 's');
    return 0;
}

