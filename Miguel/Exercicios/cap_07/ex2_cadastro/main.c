
// 2 - Escreva um programa com a estrutura de dados abaixo. Defina um vetor de
//    estruturas de 4 elementos. Receba os dados pelo teclado em uma funcao 
//    e imprima-os no video em uma funcao. Utilize vetor de estruturas.
//    A estrutura e' uma variavel global.
//    Faca um menu com uma opcao para saida do programa. 
//    estrutura: nome, end, cidade, estado, cep

#define INNER_MODE
// #define OUTER_MODE

#ifdef OUTER_MODE

#include "middleware.h"


int main() {
    
    char again = 'n';
    do {
        
        Cadastro cadastros[4];
        for (int i = 0; i < 4; i++) {
            
            fill_form(&cadastros[i]);
            show_form(&cadastros[i]);
        }
        
        // +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
        printf("Deseja executar novamente ( s / n )  ");
        scanf("%c", &again);
        clear_buffer();
    } while (again == 's');
    return 0;
}
#endif // OUTER_MODE


#ifdef INNER_MODE
#include <stdio.h>

typedef struct {
    
    char nome[20];
    char end[6];
    char cidade[30];
    char estado[3];
    char cep[9];
} Cadastro;

Cadastro cadastros[4];

void clear_buffer() {
    
    while (getchar() != '\n');
    return;
}

void fill_form() {
    
    for (int i = 0; i < 4; i++) {
        
        printf("-------- Cadastro: Dados pessoais ---------\n");
        
        printf("Nome: ");
        scanf("%s", cadastros[i].nome);
        clear_buffer();
        
        printf("Número: ");
        scanf("%s", cadastros[i].end);
        clear_buffer();
        
        printf("Estado (sigla de duas letras): ");
        scanf("%s", cadastros[i].estado);
        clear_buffer();
        
        printf("Cidade: ");
        scanf("%s", cadastros[i].cidade);
        clear_buffer();
        
        printf("CEP (apenas números): ");
        scanf("%s", cadastros[i].cep);
        clear_buffer();
    }
    return;
}

void show_form() {
    
    for (int i = 0; i < 4; i++) {
        
        printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        printf("Nome: %s\n", cadastros[i].nome);
        printf("CEP: %s\n", cadastros[i].cep);
        printf("Estado: %s\n", cadastros[i].estado);
        printf("Cidade: %s\n", cadastros[i].cidade);
        printf("Número: %s\n", cadastros[i].end);
        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    }
}


int main() {
    
    char again = 'n';
    do {
        
        fill_form();
        show_form();
        
        // +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
        printf("Deseja executar novamente ( s / n )  ");
        scanf("%c", &again);
        clear_buffer();
    } while (again == 's');
    return 0;
}
#endif // INNER_MODE