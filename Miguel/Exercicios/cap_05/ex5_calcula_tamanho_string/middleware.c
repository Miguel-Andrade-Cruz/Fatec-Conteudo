#include "middleware.h"
#include <stdio.h>


void clear_buffer() {
    
    while (getchar() != '\n');
    return;
}


void ask_for_string(char *str) {
    
    printf("Digite um texto (tamanho máx. 40 caracteres):  ");
    scanf("%s", str);
    clear_buffer();
    return;
}


int size(char *str) {
    
    int i = 0;
    while (str[i] != '\0') i++;
    return i;
}


void show_string_and_size(char *str, int size) {
    
    printf("String: %s\ntamanho: %d\n", str, size);
    return;
}