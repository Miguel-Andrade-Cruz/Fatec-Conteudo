// 5 - Escreva um programa que receba n valores inteiros via teclado na funcao main().
//     Faca uma calculadora com as 4 operacoes aritmeticas.(utilize o comando switch).
//     As operacoes aritmeticas devem ser funcoes. O resultado acumulado deve ser 
//     mostrado na funcao main().

#define INNER_MODE
// #define OUTER_MODE

#ifdef OUTER_MODE
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
#endif // OUTER_MODE


#ifdef INNER_MODE
#include <stdio.h>

#define EQUALS '='
#define ADD '+'
#define SUB '-'
#define MULT '*'
#define DIV '/'

void clear_buffer() {
    
    while (getchar() != '\n');
    return;
}

int main() {
    
    char again = 'n';
    do {
        
        int running = 1;
        
        printf("\n\nBem vindo á calculadora\n");
        printf("| Digite uma expressão ( exemplo: '23 + 45' ) para calcular o resultado\n");
        printf("| Caso queira terminar de calcular, digite '= 0'\n");
        printf("| Após a primeira expressão, o primeiro operando será sempre preenchido com o resultado da operação anterior\n\n");
        
        char _operator;
        float accumulator, operand;
        
        printf("--->>  ");
        scanf("%f %c %f", &accumulator, &_operator, &operand);
        clear_buffer();
        
        while (running) {
            
            switch (_operator) {
               
                case ADD:
                    
                    accumulator += operand;
                    break;
                case SUB:
                    
                    accumulator -= operand;
                    break;
                case MULT:
                    
                    accumulator *= operand;
                    break;
                case DIV:
                    
                    accumulator /= operand;
                    break;
            }
            
            printf("--->>  %.3f", accumulator);
            scanf(" %c %f", &_operator, &operand);
            clear_buffer();
            
            if (_operator == EQUALS) {
                
                printf("R: --->>  %.3f\n", accumulator);
                running = 0;
            }
            if (_operator == DIV && operand == 0) {
                
                printf("Operação inválida: divisão por 0\n\n");
                running = 0;
            }
        }
        // +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
        printf("Deseja execurar novamente? ( s / n )  ");
        scanf("%c", &again);
        clear_buffer();
    } while (again == 's');
return 0;
}
#endif // INNER_MODE
