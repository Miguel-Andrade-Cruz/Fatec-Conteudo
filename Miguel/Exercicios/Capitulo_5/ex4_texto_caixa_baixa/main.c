// 4 - Receba via teclado uma string de comprimento 10 em letras maiusculas  e converta 
//     todos os caracteres para letras minusculas. (nao pode usar funcao de biblioteca)

#include "middleware.h"

#define INNER_MODE
// #define OUTER_MODE


#ifdef OUTER_MODE
int main() {
    
    char again = 'n';
    do {
        
        char string[STRING_SIZE + 1];
        
        ask_for_string(string);
        show_string(string);
        
        to_lowercase_conversion(string);
        show_string(string);
        
        // +-+-+-+-+-+-+-+-+-+-+-+-+-+
        printf("Deseja executar novamente? ( s / n )  ");
        scanf("%c", &again);
        clear_buffer();
    } while (again == 's');
    return 0;
}
#endif


#ifdef INNER_MODE
char string[STRING_SIZE + 1];

int main() {
    
    char again = 'n';
    do {
        
        // 'ask_for_string' function
        printf("Insira uma string (máximo 10 caracteres):  ");
        scanf("%s", string);
        clear_buffer();
        // ---------------------------------
        
        printf("A string digitada foi: %s", string);
        
        // 'to_lowercase_conversion' function
        for (int i_char = 0; i_char < STRING_SIZE; i_char++) {
            if (string[i_char] == 0x20) {
                continue;
            } else if (string[i_char] == '\0') {
                i_char = STRING_SIZE;
                
            } else {
                string[i_char] -= 0x20;
            }
        }
        // ---------------------------------
        
        // 'show_string' function
        printf("Assim ficou a string em caixa baixa: %s", string);
        // ---------------------------------
        
        // +-+-+-+-+-+-+-+-+-+-+-+-+-+
        printf("Deseja executar novamente? ( s / n )  ");
        scanf("%c", &again);
        clear_buffer();
    } while (again == 's');
    return 0;
}
#endif