// 5 - Reescreva o exercicio anterior utilizando operadores de atribuicao
//    composta.

#define INNER_MODE
// #define OUTER_MODE

#ifdef OUTER_MODE
#include "middleware.h"
int main() {
    
    char again = 'n';
    do {
        // 'acc' stands for 'accumulate'
        float acc_num, num;
        ask_for_two_numbers(&acc_num, &num);
        
        add_acc(acc_num, num);
        sub_acc(acc_num, num);
        mult_acc(acc_num, num);
        div_acc(acc_num, num);
        
        // +-+-+-+-+-+-+-+-+-+-
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


int main() {
    
    char again = 'n';
    do {
        
        float num1, num2;
        printf("Digite o primeiro número:  ");
        scanf("%f", &num1);
        
        printf("Digite o segundo número:  ");
        scanf("%f", &num2);
        
        float
            acc_sum = num1 ,
            acc_sub = num1 ,
            acc_mult = num1 ,
            acc_div = num1
        ;
        
        acc_sum += num2;
        printf("A soma entre %.2f e %.2f é igual a %.2f\n\n", num1, num2, acc_sum);
        
        acc_sub -= num2;
        printf("A subtração entre %.2f e %.2f é igual a %.2f\n\n", num1, num2, acc_sub);
        
        acc_mult *= num2;
        printf("A multiplicação entre %.2f e %.2f é igual a %.2f\n\n", num1, num2, acc_mult);
        
        acc_div /= num2;
        printf("A divisão entre %.2f e %.2f é igual a %.2f\n\n", num1, num2, acc_div);
        
        
        // +-+-+-+-+-+-+-+-+-+-+-+
        printf("Deseja executar novamente ( s / n )  ");
        scanf("%c", &again);
        clear_buffer();
    } while (again == 's');
    
    
    return 0;
}
#endif // INNER_MODE
