
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

#include <stddef.h>
#define INNER_MODE


#ifdef INNER_MODE

#include <stdio.h>
#include <stdlib.h>

void clear_buffer() {
    
    while (getchar() != '\n');
    return;
}

// --------------------|
#define DATA_FILE "../txts/agenda.txt"
int DONE = 0;
// --------------------|


typedef struct {
    
    char name[26];
    char phone[11];
    int day;
    int month;
} Client;


int ask_action() {
    
    int ipt;
    printf("Escolha sua ação:  ");
    scanf("%d", &ipt);
    clear_buffer();
    return ipt;
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

int strequal(char *ipt, char *compare) {
    
    int i = 0;
    while (
        ipt[i] == compare[i] &&
        ipt[i] != '\0'       &&
        compare[i] != '\0'
    ) {
        i++;
    }
    
    return ( ipt[i] == '\0' && compare[i] == '\0' );
}


void load_clients(Client *clients) {
    
    FILE *fptr;
    fptr = fopen(DATA_FILE, "r");
    if (fptr == NULL) {
        printf("Erro ao abrir o arquivo.");
        exit(0);
    }
    for (int i = 0; i < 4; i++) {
        size_t sucess = fread(&clients[i], sizeof(Client), 1, fptr);
        if (sucess == 0)
            clients[i].name[0] = '^';
    }
    fclose(fptr);
    return;
}


void store_clients(Client *clients) {
    
    FILE *fptr;
    fptr = fopen(DATA_FILE, "w");
    if (fptr == NULL) {
        printf("Erro ao abrir o arquivo.");
        exit(0);
    }
    
    fwrite(clients, sizeof(Client), 4, fptr);
    fclose(fptr);
    return;
}

void client_form(Client *client) {
    
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("Nome:  ");
    scanf("%s", client->name);
    clear_buffer();
    
    printf("Telefone:  ");
    scanf("%s", client->phone);
    clear_buffer();
    
    printf("Dia:  ");
    scanf("%d", &client->day);
    clear_buffer();
    
    printf("Mês:  ");
    scanf("%d", &client->month);
    clear_buffer();
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    return;
}

int display_client(Client *client) {
    
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("Nome: %s\n", client->name);
    printf("Telefone: %s\n", client->phone);
    printf("Nascimento: %d/%d\n", client->day, client->month);
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    return 1;
}




void __1_insert(Client *clients) {
    
    int i = 0;
    while (i < 4) {
        if ( clients[i].name[0] == '^' ) {
            client_form(&clients[i]);
            return;
        }
        i++;
    }
    printf("Arquivo cheio: sem espaço para novos clientes.\n");
    return;
}

void __2_list(Client *clients) {
    
    int has_records = 0;
    for (int i = 0; i < 4; i++) {
        if (clients[i].name[0] == '^') continue;
        
        has_records = display_client(&clients[i]);
    }
    if (!has_records) printf("Não há registros no banco.\n");
    return;
}

void __3_search(Client *clients) {
    
    char ipt[25];
    printf("Pesquisar: --->>  ");
    scanf("%s", ipt);
    clear_buffer();
    
    int i = 0;
    while (i < 4) {
        
        int is_equal = strequal(ipt, clients[i].name);
        if (is_equal) {
            display_client(&clients[i]);
            clear_buffer();
            return;
        }
        i++;
    }
    printf("'%s' não está cadastrado.\n", ipt);
    return;
}


void __4_list(Client *clients) {
    
    char ipt;
    printf("Insira a primeira letra do nome do cliente:  ");
    ipt = getchar();

    int has_matches = 0;
    for (int i = 0; i < 4; i++) {
        
        if ( ipt == clients[i].name[0] ) {
            has_matches = display_client(&clients[i]);
        }
    }
    if (!has_matches)
        printf("!-!-!-!-!\nNão há clientes com inicial '%c'\n!-!-!-!-!\n", ipt);
    return;
}


void __5_display_month(Client *clients) {
    
    int current_month;
    printf("Qual é o mês da data de hoje? --->>  ");
    scanf("%d", &current_month);

    int has_matches = 0;
    for (int i = 0; i < 4; i++) {
        
        if ( current_month == clients[i].month ) {
            has_matches = display_client(&clients[i]);
        }
    }
    if (!has_matches)
        printf("!-!-!-!-!\nNão há clientes que naceram no mês %d\n!-!-!-!-!\n", current_month);
    return;
}


void __6_edit(Client *clients) {
    
    char ipt[25];
    printf("Pesquise pelo nome completo do cliente:  ");
    scanf("%s", ipt);
    clear_buffer();
    
    int i = 0;
    while (i < 4) {
        
        int is_equal = strequal(ipt, clients[i].name);
        if ( is_equal ) {
            client_form(&clients[i]);
            return;
        }
        i++;
    }
    printf("!-!-!-!-!\nNão há registros com o nome '%s'.\n!-!-!-!-!\n", ipt);
    return;
}


void __7_delete(Client *clients) {
    
    char ipt[25];
    printf("Pesquise pelo nome completo do cliente:  ");
    scanf("%s", ipt);
    clear_buffer();
    
    int i = 0;
    while (i < 4) {
        
        int is_equal = strequal(ipt, clients[i].name);
        if ( is_equal ) {
            clients[i].name[0] = '^';
            break;
        }
        i++;
    }
    printf("!-!-!-!-!\nNão há registros com o nome '%s'.\n!-!-!-!-!\n", ipt);
    return;
}


void __8_exit() {

    DONE = 1;
    return;
}

int main() {
    
    char again = 'n';
    
    do {
        DONE = 0;
        
        Client clients[4];
        load_clients(clients);
        do {
            
            display_menu();
            int action = ask_action();
            
            switch (action) {
                
                case 1:
                    __1_insert(clients);
                break;
                
                case 2:
                    __2_list(clients);
                break;
                
                case 3:
                    __3_search(clients);
                break;
                
                case 4:
                    __4_list(clients);
                break;
                
                case 5:
                    __5_display_month(clients);
                break;
                
                case 6:
                    __6_edit(clients);
                break;
                
                case 7:
                    __7_delete(clients);
                break;
                
                case 8:
                    __8_exit();
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