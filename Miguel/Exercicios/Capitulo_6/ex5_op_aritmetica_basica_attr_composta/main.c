// 5 - Reescreva o exercicio anterior utilizando operadores de atribuicao
//    composta.

#include "middleware.h"
// #define INNER_MODE
#define OUTER_MODE

#ifdef INNER_MODE
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
#endif // INNER_MODE




#ifdef OUTER_MODE
int main() {
    
    char again = 'n';
    do {
        
        
        
        
        // +-+-+-+-+-+-+-+-+-+-+-+
        printf("Deseja executar novamente ( s / n )  ");
        scanf("%c", &again);
        clear_buffer();
    } while (again == 's');
    
    
    return 0;
}

#endif // OUTER_MODE