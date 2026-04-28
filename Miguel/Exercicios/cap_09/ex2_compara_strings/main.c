
// 2 - Escreva um programa que receba em uma funcao 2 strings de ate' 10 caracteres
//     passando como parametro ponteiros.
//     Os vetores devem ser declarados como variaveis LOCAIS na funcao main().
//     Escreva uma funcao para comparar as 2 strings. Passe como parametros para 
//     a funcao as 2 strings usando ponteiros e retorne como resultado se IGUAIS 1 
//     ou se DIFERENTES 0. Mostre o resultado no video na funcao main().


#define INNER_MODE
// #define OUTER_MODE

#ifdef INNER_MODE

#include <stdio.h>

void clear_buffer() {
    
    while (getchar() != '\n');
    return;
}

void ask_for_strs(char *str1, char *str2) {
    
    printf("Digite a primeira string (máx. 10 caract) -->>  ");
    scanf("%s", str1);
    clear_buffer();
    
    printf("Digite a segunda string (máx. 10 caract) -->>  ");
    scanf("%s", str2);
    clear_buffer();
    return;
}

int strequal(char *str1, char *str2) {
    
    int i = 0;
    while ( 
        str1[i] == str2[i] &&
        str1[i] != '\0' &&
        str2[i] != '\0'
    ) {
        i++;
    }
    
    if ( (str1[i] == '\0') && (str2[i] == '\0') ) {
        return 1;
    }
    return 0;
}

int main() {
    
    char again = 'n';
    do {
        
        char str1[10];
        char str2[10];
        
        ask_for_strs(str1, str2);
        int is_equal = strequal(str1, str2);
        
        if ( is_equal ) {
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