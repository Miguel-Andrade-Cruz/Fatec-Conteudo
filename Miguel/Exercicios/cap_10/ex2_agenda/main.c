
// 2 - Escreva um programa para gerenciar uma agenda de contatos. Para cada contato
//     armazene o nome, o telefone e o aniversario (dia e mes) em uma estrutura de
//     dados. Utilize um vetor de estrutura de 4 elementos como variavel LOCAL na
//     funcao main(). Utilize ponteiros para passar o vetor de estrutura para
//     as funcoes. Sempre que o programa for encerrado, os contatos devem ser
//     escritos no arquivo e quando o programa iniciar os contatos devem ser lidos
//     do arquivo.
//     O programa deve ter as seguintes opcoes:(cada opcao do menu e' um funcao)
//     1 - inserir contato
//     2 - listar todos os contatos
//     3 - pesquisar um contato pelo nome completo
//     4 - listar os contatos cujo nome inicia com uma letra digitada
//     5 - imprimir os aniversariantes do m s.
//     6 - altera contato pesquisando pelo nome completo
//     7 - exclui contato pesquisando pelo nome completo
//     8 - saida

#define INNER_MODE


#ifdef INNER_MODE

#include <stdio.h>
#include <stdlib.h>

void clear_buffer() {
    
    while (getchar() != '\n');
    return;
}

void display_menu() {
    
    printf("[1] - inserir contato\n");
    printf("[2] - listar todos os contatos\n");
    printf("[3] - pesquisar um contato pelo nome completo\n");
    printf("[4] - listar os contatos cujo nome inicia com uma letra digitada\n");
    printf("[5] - imprimir os aniversariantes do mês\n");
    printf("[6] - altera contato pesquisando pelo nome completo\n");
    printf("[7] - exclui contato pesquisando pelo nome completo\n");
    printf("[8] - sair\n");
    return;
}


typedef struct {
    
    char *name;
    char *phone;
    int day;
    int month;
} Client;


void load_clients(Client *clients) {
    
    FILE *fptr;
    fptr = fopen("../txts/agenda.txt", "w");
    if (fptr == NULL) {
        printf("Erro ao abrir o arquivo.");
        exit(0);
    }
    
    int reads = fread(clients, sizeof(Client), 4, fptr);
    if ( reads == 0 ) {
        for (int i = 0; i < 4; i++) {
            clients->name[0] = '^';
        }
    }
    fclose(fptr);
    return;
}


void store_clients(Client *clients) {
    
    FILE *fptr;
    fptr = fopen("../txts/agendas.txt", "r");
    if (fptr == NULL) {
        printf("Erro ao abrir o arquivo.");
        exit(0);
    }
    
    fwrite(clients, sizeof(Client), 4, fptr);
    fclose(fptr);
    return;
}

void client_form(Client *client) {
    
    printf("Nome:  ");
    scanf("%s", client->name);
    clear_buffer();
    
    printf("Telefone:  ");
    scanf("%s", client->phone);
    clear_buffer();
    
    printf("Dia:  ");
    scanf("%d", &client->day);
    clear_buffer();
    
    printf("Month:  ");
    scanf("%d", &client->month);
    clear_buffer();
    return;
}

void display_client(Client *client) {
    
    printf("Nome: %s\n", client->name);
    printf("Telefone: %s\n", client->phone);
    printf("Nascimento: %d/%d\n", client->day, client->month);
    return;
}


int DONE = 0;

void __1_insert(Client *clients) {
    
    int i = 0;
    while (i < 4) {
        if ( clients->name[0] == '^' ) {
            client_form(&clients[0]);
        }
    }
    printf("Arquivo cheio: sem espaço para novos clientes.\n");
    return;
}

void __2_list(Client *clients) {
    
    for (int i = 0; i < 4; i++) {
        if (clients->name[0] == '^') continue;
        
        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
        printf("Nome: %s", clients->name);
        printf("Telefone: %s", clients->phone);
        printf("Nascimento: %d/%d", clients->day, clients->month);
        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    }
    return;
}

void __3_search(Client *clients) {
    
    char ipt[25];
    printf("Pesquisar: --->>  ");
    scanf("%s", ipt);
    clear_buffer();
    
    int i = 0;
    while (i < 4) {
        
        int is_equal = strequal(ipt, clients->name);
        if (is_equal) {
            display_client(&clients[i]);
        }
    }
    return;
}


void __4_(Client *clients) {
    
    
    return;
}

int main() {
    
    char again = 'n';
    
    Client clients[4];
    load_clients(clients);
    do {
        
        display_menu();
        int action = ask_action();
        
        switch (action) {
            
            case 1:
                __1_();
            break;
            
            case 2:
                __1_();
            break;
            
            case 3:
                __1_();
            break;
            
            case 4:
                __1_();
            break;
            
            case 5:
                __1_();
            break;
            
            case 6:
                __1_();
            break;
            
            case 7:
                __1_();
            break;
            
            case 8:
                __1_();
            break;
        }
    } while (!DONE);
    store_clients(clients);
        // +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
        printf("Deseja executar novamente ( s / n )  ");
        scanf("%c", &again);
        clear_buffer();
    } while (again == 's');
    return 0;
}
#endif // INNER_MODE