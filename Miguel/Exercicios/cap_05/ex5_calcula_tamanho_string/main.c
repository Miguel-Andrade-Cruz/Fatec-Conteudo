// 5 - Escreva um programa que receba uma string de comprimento até 40 na funcao
//     main(). Faca uma funcao que calcula o comprimento da string recebida via teclado.
//     Mostre o valor do comprimento na funcao main().
//     (Declare o vetor como variavel global) (nao pode usar funcao de biblioteca)


#define INNER_MODE
// #define OUTER_MODE


#ifdef OUTER_MODE
#include "middleware.h"
int main() {
    
    char again = 'n';
    do {
        
        char str[STR_SIZE + 1];
        
        ask_for_string(str);
        
        int str_size = size(str);
        
        show_string_and_size(str, str_size);
        // +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
        printf("Deseja executar novamente? ( s / n )  ");
        scanf("%c", &again);
        clear_buffer();
    } while (again == 's');
    return 0;
}
#endif // OUTER_MODE



#ifdef INNER_MODE
#include <stdio.h>

const int STR_SIZE = 40;

void clear_buffer() {
    
    while (getchar() != '\n');
    return;
}

int main() {
    
    int size;
    char str[STR_SIZE + 1];
    
    char again = 'n';
    do {
        
        // 'ask_for_string' function
        printf("Digite um texto (tamanho máx. 40 caracteres):  ");
        scanf("%s", str);
        clear_buffer();
        // ------------------------------
        
        // 'size' function
        int i = 0;
        while (str[i] != '\0') i++;
        size = i;
        // ------------------------------
        
        // 'show_string_and_size' function
        printf("String: %s\ntamanho: %d\n", str, size);
        // ------------------------------
        
        // +-+-+-+-+-+-+-+-+-+
        printf("Deseja executar novamente? ( s / n )  ");
        scanf("%c", &again);
        clear_buffer();
    } while (again == 's');
    return 0;
}
#endif // INNER_MODE
