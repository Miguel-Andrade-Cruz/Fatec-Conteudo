// 5 - Escreva um programa que receba n valores inteiros via teclado na funcao main().
//     Faca uma calculadora com as 4 operacoes aritmeticas.(utilize o comando switch).
//     As operacoes aritmeticas devem ser funcoes. O resultado acumulado deve ser 
//     mostrado na funcao main().

#include "middleware.h"


int main() {
    
    char again = 'n';
    do {
        
        int running = 1;
        float accumulator, second_operand;
        char _operator;
        
        display_explaining_message();
        
        // first expression
        scanf("%f %c %f", &accumulator, &_operator, &second_operand);
        clear_buffer();
        accumulator = resolve_expression(accumulator, _operator, second_operand);
        display_ans(accumulator);
        
        while (running == 1 && second_operand != 0) {
            
            scanf("%c %f", &_operator, &second_operand);
            clear_buffer();
            
            if ( _operator == EQUALS) {
                printf("Operação inválida: divisão por 0\n");
                break;
            }
            
            accumulator = resolve_expression(accumulator, _operator, second_operand);
            display_ans(accumulator);
        }
        
        // +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
        printf("Deseja execurar novamente? ( s / n )  ");
        scanf("%c", &again);
        clear_buffer();
    } while (again == 's');
    return 0;
}