// 4 - Reescreva o programa do exercicio anterior para receber via teclado n
//     valores. Mostre os 4 resultados na funcao main().
//     Os n valores nao sao pedidos ao usuario. Lembre-se da calculadora.

#include "middleware.h"


int main() {

    char again = 'n';
    do {
        int input = 0;
        
        // < acc > means "accumulated"
        float acc_sum, acc_subtraction, acc_multiplication, acc_division;
        
        printf("Insira um número: ");
        scanf("%d", &input);
        clean_buffer();
        
        acc_sum = input; acc_subtraction = input;
        acc_multiplication = input; acc_division = input;
        
        while (1) {
            
            printf("Insira um número: ");
            scanf("%d", &input);
            clean_buffer();

            if ( input == 0 ) {
                break;
            }
            
            acc_sum = add(acc_sum, input);
            acc_subtraction = subtract(acc_subtraction, input);
            acc_multiplication = multiply(acc_multiplication, input);
            acc_division = divide(acc_division, input);
        }
        
        show_aritmetics(acc_sum, acc_subtraction, acc_multiplication, acc_division);
        
        // +-+-+-+-+-+-+-+-+-+-+-+-+-
        printf("Deseja executar novamente? ( s / n)");
        scanf("%c", &again);
        clean_buffer();
    } while (again == 's');
    return 0;
}

