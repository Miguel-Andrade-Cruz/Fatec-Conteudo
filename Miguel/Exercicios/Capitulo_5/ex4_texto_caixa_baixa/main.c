// 4 - Receba via teclado uma string de comprimento 10 em letras maiusculas  e converta 
//     todos os caracteres para letras minusculas. (nao pode usar funcao de biblioteca)

#include "middleware.h"


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