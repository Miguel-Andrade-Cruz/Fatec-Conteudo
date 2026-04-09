// 3 - Receba via teclado uma string de comprimento 10 em letras minusculas e
// converta
//     todos os caracteres para letras maiusculas. (nao pode usar funcao de
//     biblioteca)

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
        
        to_uppercase_conversion(string);
        show_string(string);
        
        // +-+-+-+-+-+-+-+-+-+-+-+-+-+
        printf("Deseja executar novamente? ( s / n )  ");
        scanf("%c", &again);
        clear_buffer();
    } while (again == 's');
    return 0;
}
#endif // OUTER_MODE


#ifdef INNER_MODE
#include <stdio.h>

#define STRING_SIZE 10
char string[STRING_SIZE + 1];

void clear_buffer() {
    
    while (getchar() != '\n');
    return;
}

int main() {
    
    char again = 'n';
    do {
        
        // 'ask_for_string' function
        printf("Insira uma string (máximo 10 caracteres):  ");
        scanf("%[^\n]s", string);
        clear_buffer();
        // ------------------------------
        
        printf("A string digitada foi: %s\n", string);
        
        // 'to_uppercase_conversion' function
        for (int i_char = 0; i_char < STRING_SIZE; i_char++) {
            
            int is_space = string[i_char] == 0x20;
            int is_upper = string[i_char] >= 0x41 && string[i_char] <= 0x5a;
            
            if (is_space || is_upper) {
                continue;
                
            } else if (string[i_char] == '\0') {
                i_char = STRING_SIZE;
                
            } else {
                
                string[i_char] -= 0x20;
            }
        }
        // ------------------------------
        
        // 'show_string' function
        printf("Assim ficou a string em caixa alta: %s\n", string);
        // ------------------------------
        
        // +-+-+-+-+-+-+-+-+-+-+-+-+-+
        printf("\n\nDeseja executar novamente? ( s / n )  ");
        scanf("%c", &again);
        clear_buffer();
    } while (again == 's');
    return 0;
}
#endif // INNER_MODE
