#include <stdio.h>
#include "middleware.h"

#define DEBUG


void clear_buffer() {
    
    while (getchar() != '\n');
    return;
}


char select_var_type() {
    
    char var_type;
    do {
        printf("Insira < i > para trocar números ou < c > para trocar caracteres:\n");
        scanf("%c", &var_type);
        clear_buffer();
    } while ( var_type != 'c' && var_type != 'i');
    
    return var_type;
};



void char_switcher() {
    
    char a, b;
    
    printf("Insira um caractere (será denominado como A): \n");
    scanf("%c", &a);
    clear_buffer();
    
    printf("Insira um outro caractere (dessa vez denominado como B): \n");
    scanf("%c", &b);
    clear_buffer();
    
    printf("No momento, A tem valor %c e B tem valor %c\n", a, b);
    
    a ^= b;
    b ^= a;
    a ^= b;
    
    printf("Agora, A vale %c e B vale %c\n", a, b);
    
    return;
};



void int_switcher() {
    
    int a, b;
    
    printf("Insira um número (será denominado como A): \n");
    scanf("%d", &a);
    clear_buffer();
    
    printf("Insira um outro número (dessa vez denominado como B): \n");
    scanf("%d", &b);
    clear_buffer();
    
    printf("No momento, A tem valor %d e B tem valor %d\n", a, b);
    
    a ^= b;
    b ^= a;
    a ^= b;
    
    printf("Agora, A vale %d e B vale %d\n", a, b);
    
    return;
};