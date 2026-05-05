
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

// --------------------|
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
    fptr = fopen("C:/Users/lab52/Desktop/Repos/fatec-conteudo/txts/agenda.txt", "w");
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




void __1_insert(Client *clients) {
    
    int i = 0;
    while (i < 4) {
        if ( clients->name[0] == '^' ) {
            client_form(&clients[0]);
        }
        i++;
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
        
        int is_equal = strequal(ipt, clients[i].name);
        if (is_equal) {
            display_client(&clients[i]);
        }
    }
    return;
}


void __4_list(Client *clients) {
    
    char ipt;
    printf("Insira a primeira letra do nome do cliente:  ");
    ipt = getchar();
    
    for (int i = 0; i < 4; i++) {
        
        if ( ipt == clients[i].name[0] ) {
            display_client(&clients[i]);
        }
    }
    return;
}


void __5_display_month(Client *clients) {
    
    int current_month;
    printf("Qual é o mês da data de hoje? --->>  ");
    scanf("%d", &current_month);
    
    for (int i = 0; i < 4; i++) {
        
        if ( current_month == clients[i].month ) {
            display_client(&clients[i]);
        }
    }
    
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
            break;
        }
    }
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
            clients[i].name[0] == '^';
            break;
        }
    }    
    return;
}


void __8_exit() {

    DONE = 1;
    return;
}

int main() {
    
    char again = 'n';
    
    do {
        
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