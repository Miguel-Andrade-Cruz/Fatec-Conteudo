// 1 - Receba 2 string de ate 10 caracteres via teclado na funcao main(). Faça uma
//     funcao para compara-las e retorne como resultado se são IGUAIS 1 ou se
//     DIFERENTES 0 para a funcao main(). Imprima o resultado na funcao main().
//     (Declare os vetores como variavel global) (nao pode usar funcao de biblioteca)

#include "middleware.h"
// #define DEBUG
// #define INNER_MODE
#define OUTER_MODE

char string_one[STRING_SIZE + 1];
char string_two[STRING_SIZE + 1];

#ifdef OUTER_MODE
int main() {
    
    char again = 'n';
    do {
        
        ask_for_two_strings(string_one, string_two);
        int is_equal = string_comparator(string_one, string_two);
        
        show_comparison_result(is_equal);
        
        // +-+-+-+-+-+-+-+-+-+-+-+-+-+
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
        
        // 'ask_for_two_strings' function
        printf("Insira a primeira string (máximo 10 carcteres):  ");
        scanf("%s", string_one);
        clear_buffer();
        
        printf("Insira a segunda string (máximo 10 carcteres):  ");
        scanf("%s", string_two);
        clear_buffer();
        
        #ifdef DEBUG
        printf("[DEBUG] FIRST STRING: %s\n", string_one);
        printf("[DEBUG] SECOND STRING: %s\n", string_two);
        #endif
        // -----------------------------------------
        
        
        // 'string_comparator' function
        int equal_chars_qtd = 0;
        for (int i_char = 0; i_char < STRING_SIZE; i_char++) {
            
            if (string_one[i_char] == string_two[i_char]) {
                equal_chars_qtd++;
            }
        }
        int is_equal = equal_chars_qtd == STRING_SIZE;
        printf("[DEBUG] IS_EQUAL: %d\n", is_equal);
        // -----------------------------------------
        
        
        // 'show_comparison_result' function
        if (is_equal == 1) {
        printf("As duas strings são iguais\n");
        } else {
            printf("Há diferenças entre as strings\n");
        }
        // -----------------------------------------
        
        // +-+-+-+-+-+-+-+-+-+-+-+-+-+
        printf("Deseja executar novamente? ( s / n )  ");
        scanf("%c", &again);
        clear_buffer();
    } while (again == 's');
    return 0;
}
#endif