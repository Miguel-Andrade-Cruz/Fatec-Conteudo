// 5 - Escreva um programa que receba uma string de comprimento até 40 na funcao
//     main(). Faca uma funcao que calcula o comprimento da string recebida via teclado.                
//     Mostre o valor do comprimento na funcao main().
//     (Declare o vetor como variavel global) (nao pode usar funcao de biblioteca)

#include "middleware.h"

#define INNER_MODE
// #define OUTER_MODE


#ifdef OUTER_MODE
int main() {
    
    char again = 'n';
    do {
        
        
        // +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
        printf("Deseja executar novamente? ( s / n )  ");
        scanf("%c", &again);
        clear_buffer();
    } while (again == 's');
    return 0;
}
#endif



#ifdef INNER_MODE
int main() {
    
    char again = 'n';
    do {
        
        
        
        // +-+-+-+-+-+-+-+-+-+
        printf("Deseja executar novamente? ( s / n )  ");
        scanf("%c", &again);
        clear_buffer();
    } while (again == 's');
    return 0;
}
#endif