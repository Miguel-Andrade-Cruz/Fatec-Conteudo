
// 3 - Escreva um programa que receba n valores via teclado e receba tambem a
//     operacao a ser executada. Quando for digitado "=" o programa deve mostrar
//     o resultado acumulado dos n valores. As operacoes aritmeticas e a entrada
//     de dados devem ser funcoes que recebe os valores usando ponteiros.  
//     As variaveis sao LOCAIS na funcao main().

// #define OUTER_MODE
#define INNER_MODE

#ifdef INNER_MODE

#include <stdio.h>

void clear_buffer() {
    
    while ( getchar() != '\n' );
    return;
}


void ask_operation(int *ipt, char *operator) {
    
    scanf("%c %d", operator, ipt);
    clear_buffer();
}

void exec_operation(int *ipt, char *operator, float *acc) {
    
    switch ( *operator ) {
        
        case '+':
        *acc += *ipt;
        break;
        
        case '-':
        *acc -= *ipt;
        break;
        
        case '*':
        *acc *= *ipt;
        break;
        
        case '/':
        *acc /= *ipt;
        break;
    }
    return;
}



void show_cur_acc(float *acc) {
    
    printf("%.2f ", *acc);
    return;
}



int main() {
    
    char again = 'n';
    do {
        
        char operator, *pOperator = &operator;
        float accumulator, *pAcc = &accumulator;
        int ipt, *pIpt = &ipt;
        
        printf(
"Digite a primeira expressão completa [ 4 + 5 ].\n \
Depois, o primeiro operando será o valor acumulado, \n \
então digite apenas o restante [ / 3 ]."
        );
        
        scanf("%f %c %d", pAcc, pOperator, pIpt);
        clear_buffer();
        do {
            
            ask_operation(pIpt, pOperator);
            exec_operation(pIpt, pOperator, pAcc);
            show_cur_acc(pAcc);
        } while (*pOperator != '=');
        
        // +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
        printf("Deseja executar novamente ( s / n )  ");
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
        
        
        
        // +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
        printf("Deseja executar novamente ( s / n )  ");
        scanf("%c", &again);
        clear_buffer();
    } while (again == 's');
    return 0;
}
#endif // OUTER_MODE