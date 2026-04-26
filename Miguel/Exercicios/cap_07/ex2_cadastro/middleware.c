#include "middleware.h"

void clear_buffer() {
    
    while (getchar() != '\n');
    return;
}


void ask_for(char *msg, char *field) {
    
    printf("%s", msg);
    scanf("%s", field);
    clear_buffer();
    return;
}


void fill_form(Cadastro *cadastro) {
    
    printf("-------- Cadastro: Dados pessoais ---------\n");
    ask_for("Nome: ", cadastro->nome);
    ask_for("Endereço (número da rua): ", cadastro->end);
    ask_for("Cidade: ", cadastro->cidade);
    ask_for("Estado (sigla de duas letras): ", cadastro->estado);
    ask_for("CEP (apenas números): ", cadastro->cep);
    return;
}


void show_form(Cadastro *cadastro) {
    
    printf("\n-------- Confirme os dados inseridos ---------\n");
    printf("Nome: %s", cadastro->nome);
    printf("Endereço (número da rua): %s", cadastro->end);
    printf("Cidade: %s", cadastro->cidade);
    printf("Estado (sigla de duas letras): %s", cadastro->estado);
    printf("CEP (apenas números): %s", cadastro->cep);
    printf("----------------------------------------------------\n");
}