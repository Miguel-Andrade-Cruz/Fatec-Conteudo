
// 5 - Com a estrutura abaixo, defina um vetor de estruturas de 4 elementos.
//     Receba os dados via teclado numa funcao usando ponteiros. Imprima os dados
//     recebidos no video numa funcao usando ponteiros. Utilize um comando de loop. 
//     O vetor de estruturas deve ser declarado como variavel global.
//        estrutura: nome, end, cidade, estado, cep

#define INNER_MODE
// #define OUTER_MODE


#ifdef INNER_MODE

#include <stdio.h>

typedef struct {
    
    char nome[20];
    char end[6];
    char cidade[30];
    char estado[3];
    char cep[9];
} Form;

Form forms[4];

void clear_buffer() {
    
    while (getchar() != '\n');
    return;
}

void fill_form() {
    
    for (int i = 0; i < 4; i++) {
        
        Form *cur_form = &forms[i];
        
        printf("-------- Cadastro: Dados pessoais ---------\n");
        
        printf("Nome: ");
        scanf("%s", cur_form->nome);
        clear_buffer();
        
        printf("Número: ");
        scanf("%s", cur_form->end);
        clear_buffer();
        
        printf("Estado (sigla de duas letras): ");
        scanf("%s", cur_form->estado);
        clear_buffer();
        
        printf("Cidade: ");
        scanf("%s", cur_form->cidade);
        clear_buffer();
        
        printf("CEP (apenas números): ");
        scanf("%s", cur_form->cep);
        clear_buffer();
    }
    return;
}

void show_form() {
    
    for (int i = 0; i < 4; i++) {
        
        Form *cur_form = &forms[i];
        
        printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        printf("Nome: %s\n", cur_form->nome);
        printf("CEP: %s\n", cur_form->cep);
        printf("Estado: %s\n", cur_form->estado);
        printf("Cidade: %s\n", cur_form->cidade);
        printf("Número: %s\n", cur_form->end);
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