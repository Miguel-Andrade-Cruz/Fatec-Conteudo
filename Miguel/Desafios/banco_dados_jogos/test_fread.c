#include <stdio.h>


char jogo[20];


void clear_string(char *string, char *ret) {
    
    int char_i;
    while ( !(string[char_i] == '\0' || string[char_i + 1] == '\0') ) {
        ret[char_i] = string[char_i];
        char_i++;
    }
    return;
}


void search_game(char *search) {
    
    return;
}



int main() {
    
    FILE *fptr;
    
    fptr = fopen("banco_dados.txt", "r");
    
    if (fptr == NULL) {
        printf("Deu merda parça");
        return 0;
    }
    int n = fread(jogo, sizeof(char), 19, fptr);
    fclose(fptr);
    jogo[n] = '\n';
    if (n == 0) {
        printf("fread com problema...");
        return 0;
    }
    
    printf("Jogo: %s", jogo);
    return 0;
}