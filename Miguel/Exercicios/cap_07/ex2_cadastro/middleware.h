#include <stdio.h>

typedef struct {
    
    char nome[20];
    char end[6];
    char cidade[30];
    char estado[3];
    char cep[9];
} Cadastro;

void clear_buffer();

void fill_form(Cadastro *cadastros);

void show_form(Cadastro *cadastro);