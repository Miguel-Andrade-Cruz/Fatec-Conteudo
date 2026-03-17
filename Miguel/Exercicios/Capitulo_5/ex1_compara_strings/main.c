// 1 - Receba 2 string de ate 10 caracteres via teclado na funcao main(). Faça uma
//     funcao para compara-las e retorne como resultado se são IGUAIS 1 ou se
//     DIFERENTES 0 para a funcao main(). Imprima o resultado na funcao main().
//     (Declare os vetores como variavel global) (nao pode usar funcao de biblioteca)

#include "middleware.h"


char string_one[10], string_two[10];

int main() {

    char again = 'n';
    do {
        
        // +-+-+-+-+-+-+-+-+-+-+-+-+-+
        printf("Deseja executar novamente? ( s / n )  ");
        scanf("%c", &again);
        clear_buffer();
    } while (again == 's');
    return 0;
}