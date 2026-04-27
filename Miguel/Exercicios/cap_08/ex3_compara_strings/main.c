
// 3 - Receba 2 string de ate 10 caracteres via teclado na funcao main(). Faca uma
//     funcao para compara-las usando ponteiros e retorne como resultado se 
//     sao IGUAIS 1 ou se sao DIFERENTES 0 para a funcao main(). 
//     Imprima o resultado na funcao main(). Declare os vetores como variavel global


#define INNER_MODE
// #define OUTER_MODE


#ifdef INNER_MODE

#include <stdio.h>

void clear_buffer() {
    
    while (getchar() != '\n');
    return;
}

int strequal(char *str1, char *str2) {
    
    int is_equal = 0;
    int i = 0;
    while (
        str1[i] == str2[i] &&
        str1[i] != '\0' &&
        str2[i] != '\0'
    ) {
        i++;
    }
    if ( str1[i] == '\0' && str2[i] == '\0' ) {
        is_equal = 1;
    }
    return is_equal;
}


char str1[10], str2[10];

int main() {
    
    char again = 'n';
    do {
        
        printf("Insira a primeira string:  ");
        scanf("%s", str1);
        clear_buffer();
        
        printf("Insira a segunda string:  ");
        scanf("%s", str2);
        clear_buffer();
        
        int is_equal = strequal(str1, str2);
        
        if (is_equal) {
            printf("As duas strings são iguais\n");
        } else {
            printf("As duas strings são diferentes\n");
        }
        
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