// 4 - Receba via teclado uma string de comprimento 10 em letras maiusculas  e converta 
//     todos os caracteres para letras minusculas. (nao pode usar funcao de biblioteca)


#define INNER_MODE
// #define OUTER_MODE


#ifdef OUTER_MODE
#include "middleware.h"
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
        scanf("%s", string);
        clear_buffer();
        // ---------------------------------
        
        printf("A string digitada foi: %s\n", string);
        
        // 'to_lowercase_conversion' function
        for (int i_char = 0; i_char < STRING_SIZE; i_char++) {
            
            int is_space = string[i_char] == 0x20;
            int is_lower = string[i_char] >= 0x61 & string[i_char] <= 0x7a;
            
            if (is_space || is_lower) {
                continue;
                
            } else if (string[i_char] == '\0') {
                i_char = STRING_SIZE;
                
            } else {
                
                string[i_char] += 0x20;
            }
        }
        // ---------------------------------
        
        // 'show_string' function
        printf("Assim ficou a string em caixa baixa: %s\n", string);
        // ---------------------------------
        
        // +-+-+-+-+-+-+-+-+-+-+-+-+-+
        printf("Deseja executar novamente? ( s / n )  ");
        scanf("%c", &again);
        clear_buffer();
    } while (again == 's');
    return 0;
}
#endif // INNER_MODE
