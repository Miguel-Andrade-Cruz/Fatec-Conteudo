#include <stdio.h>
#include <math.h>

#define DB_FILE "banco_dados.txt"
const int END_FILE_OFFSET = 5;

#define FIELD_SIZE 25
char AGAIN = 's';


void clear_buffer() {
    
    while (getchar() != '\n');
    return;
}

int check_table_end(FILE *fptr) {
    
    return feof(fptr);
}


long hashed(char *str) {
    
    const long MULT_PRIME = 179;
    const int MOD_PRIME = pow(10, 9) + 7;
    
    long hash = str[0] * ( long ) pow(MULT_PRIME, 0);
    for (int i = 1; str[i] != '\0'; i++) {
        
        hash += str[i] * ( long ) pow(MULT_PRIME, i);
    }
    
    hash %= MOD_PRIME;
    
    printf("HASH: %li\n", hash);
    return hash;
}



void display_greetings() {
    
    printf("Bem vindo ao banco de dados de jogos!\n\n");
    printf("Escolha uma ação pelo seu número\n");
    return;
}

void display_menu() {
    
    printf("==============================================\n");
    printf("[ 1 ] - Preencher banco de dados\n");
    printf("[ 2 ] - Visualizar banco de dados\n");
    printf("[ 3 ] - Pesquisar por jogo\n");
    printf("[ 4 ] - Pesquisar por estúdio (primeira letra)\n");
    printf("[ 5 ] - Editar dados de um jogo\n");
    printf("[ 6 ] - Excluir dados de um jogo\n");
    printf("[ 7 ] - Sair\n");
    printf("==============================================\n");
   return; 
}