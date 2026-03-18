// 4 - Receba via teclado uma string de comprimento 10 em letras maiusculas  e converta 
//     todos os caracteres para letras minusculas. (nao pode usar funcao de biblioteca)

#include "middleware.h"


int main() {

    char again = 'n';
    do {
        
        char string[STRING_SIZE + 1];
        ask_for_string(string);
        printf("A string digitada foi: %s", string);
        
        to_lowercase_conversion(string);
        show_string_change(string);
        
        // +-+-+-+-+-+-+-+-+-+-+-+-+-+
        printf("Deseja executar novamente? ( s / n )  ");
        scanf("%c", &again);
        clear_buffer();
    } while (again == 's');
    return 0;
}