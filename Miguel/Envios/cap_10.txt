
#define EX_0

// EX_1 -- OK
// EX_2 -- OK
// EX_3 -- OK
// EX_4 -- OK

#ifdef EX_1

#include <stdlib.h>
#include <stdio.h>

void clear_buffer() {
    
    while (getchar() != '\n');
    return;
}


int main() {
    
    char again = 'n';
    do {
        
        FILE *fptr;
        fptr = fopen("../txts/ex1.txt", "w+");
        
        if (fptr == NULL) {
            printf("Erro ao abrir o arquivo\n");
            exit(0);
        }
        
        
        // write chars to file ------ <
        char ipt;
        printf("--->>  ");
        ipt = getchar();
        while (ipt != '0') {
            
            fputc(ipt, fptr);
            ipt = getchar();
        }
        fputc('\0', fptr);
        fseek(fptr, 0, SEEK_SET);
        // ------------ >
        
        // read chars from file ------ <
        char buff;
        buff = fgetc(fptr);
        while ( buff != '\0' ) {
            putchar(' ');
            putchar(buff);
            buff = fgetc(fptr);
        }
        // ------------ >
        fclose(fptr);
        
        // +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
        printf("Deseja executar novamente ( s / n )  ");
        scanf("%c", &again);
        clear_buffer();
    } while (again == 's');
    return 0;
}
#endif // EX_1
// ------------------------------------------------


// ------------------------------------------------
#ifdef EX_2
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
#endif // EX_2
// ------------------------------------------------


// ------------------------------------------------
#ifdef EX_3
#include <stdio.h>


void clear_buffer() {
    
    while (getchar() != '\n');
    return;
}

// ----------------------------------------------
#define DATA_FILE "../txts/cadastro.txt"
int DONE = 0;
// ----------------------------------------------

typedef struct {
    
    char name[26];
    char email[30];
    char phone[12];
} Client;




void display_menu() {
    
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("[ 1 ] - incluir registros\n");
    printf("[ 2 ] - listar todos os registros\n");
    printf("[ 3 ] - pesquisar registro pelo nome\n");
    printf("[ 4 ] - alterar registro\n");
    printf("[ 5 ] - excluir registro\n");
    printf("[ 6 ] - sair\n");
    
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    return;
}

void ask_client(Client *client) {
    
    printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("Nome:  ");
    scanf("%s", client->name);
    clear_buffer();
    
    printf("Email:  ");
    scanf("%s", client->email);
    clear_buffer();
    
    printf("Celular:  ");
    scanf("%s", client->phone);
    clear_buffer();
    
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
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

void display_client(Client *client) {
    
    printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("Nome: %s\n", client->name);
    printf("Email: %s\n", client->email);
    printf("Celular: %s\n", client->phone);
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    return;
}

void __1_insert(Client *client) {
    
    FILE *fptr;
    fptr = fopen(DATA_FILE, "r+");
    
    char again = 's';
    while (again == 's') {
        
        fread(client, sizeof(Client), 1, fptr);
        if (!feof(fptr)) {
            if (client->name[0] == '\0') {
                continue;
            }
            fseek(fptr, (long) -sizeof(Client), SEEK_CUR);
        }
        
        ask_client(client);
        fwrite(client, sizeof(Client), 1, fptr);
        printf("Continuar inserindo? [s/ n]  ");
        again = getchar();
    }
    fclose(fptr);
    return;
}

void __2_list(Client *client) {
    
    FILE *fptr;
    fptr = fopen(DATA_FILE, "r");
    while (1) {
        
        fread(client, sizeof(Client), 1, fptr);
        if (feof(fptr)) break;
        if (client->name[0] == '\0') continue;
        display_client(client);
    }
    fclose(fptr);
    return;
}

void __3_search(Client *client) {
    
    char ipt[26];
    printf("Pesquisar por:");
    scanf("%s", ipt);
    clear_buffer();
    FILE *fptr;
    fptr = fopen(DATA_FILE, "r");
    while (1) {
        
        fread(client, sizeof(Client), 1, fptr);
        if (feof(fptr)) break;
        int matched = strequal(ipt, client->name);
        if (matched) {
            display_client(client);
            break;
        }
    }
    fclose(fptr);
    return;
}

void __4_edit(Client *client) {
    
    char ipt[26];
    printf("Pesquisar por:");
    scanf("%s", ipt);
    clear_buffer();
    FILE *fptr;
    fptr = fopen(DATA_FILE, "r+");
    while (1) {
        
        fread(client, sizeof(Client), 1, fptr);
        if (feof(fptr)) break;
        int matched = strequal(ipt, client->name);
        if (matched) {
            fseek(fptr, (long) -sizeof(Client), SEEK_CUR);
            ask_client(client);
            fwrite(client, sizeof(Client), 1, fptr);
            break;
        }
    }
    fclose(fptr);
    return;
}



void __5_delete(Client *client) {
    
    char ipt[26];
    printf("Pesquisar por:");
    scanf("%s", ipt);
    FILE *fptr;
    fptr = fopen(DATA_FILE, "r+");
    while (1) {
        
        fread(client, sizeof(Client), 1, fptr);
        if (feof(fptr)) break;
        int matched = strequal(ipt, client->name);
        if (matched) {
            fseek(fptr, (long) -sizeof(Client), SEEK_CUR);
            client->name[0] = '\0';
            fwrite(client, sizeof(Client), 1, fptr);
            printf("Cliente deletado\n");
            break;
        }
    }
    fclose(fptr);
    return;
}


void __6_exit() {
    
    DONE = 1;
    return;
}

int ask_action() {
    
    int action;
    printf("---->>  ");
    scanf("%d", &action);
    clear_buffer();
    return action;
}


int main() {
    
    char again = 'n';
    do {
        Client client;
        do {
            
            display_menu();
            int action = ask_action();
            
            switch (action) {
                
                case 1:
                __1_insert(&client);
                break;
                
                case 2:
                __2_list(&client);
                break;
                
                case 3:
                __3_search(&client);
                break;
                
                case 4:
                __4_edit(&client);
                break;
                
                case 5:
                __5_delete(&client);
                break;
                
                case 6:
                __6_exit();
                break;
                
            }
            
        } while (!DONE);
        // +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
        printf("Deseja executar novamente ( s / n )  ");
        scanf("%c", &again);
        clear_buffer();
    } while (again == 's');
    return 0;
}
#endif // EX_3
// ------------------------------------------------


// ------------------------------------------------
#ifdef EX_4

#include <stdio.h>
#include <stdlib.h>

// -----------------------|
#define DATA_FILE "../txts/dispensa.txt"
int DONE = 0;
// -----------------------|

void clear_buffer() {
    
    while (getchar() != '\n');
    return;
}

typedef struct {
    
    char sku[26];
    char description[31];
    int stock;
} Product;

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


void display_menu() {
    
    printf("[ 1 ] - incluir produtos\n");
    printf("[ 2 ] - listar todos os produtos\n");
    printf("[ 3 ] - pesquisar uma mercadoria pela descricao\n");
    printf("[ 4 ] - listar os produtos nao disponiveis.\n");
    printf("[ 5 ] - alterar a quantidade atual\n");
    printf("[ 6 ] - alterar produto\n");
    printf("[ 7 ] - excluir produto\n");
    printf("[ 8 ] - sair\n");
    return;
}

int ask_action() {
    
    int action;
    printf("--->>  ");
    scanf("%d", &action);
    clear_buffer();
    return action;
}

void ask_product(Product *product) {
    
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    
    printf("Descrição:  ");
    scanf("%s", product->description);
    clear_buffer();
    
    printf("Código (SKU):  ");
    scanf("%s", product->sku);
    clear_buffer();
    
    printf("Estoque:  ");
    scanf("%d", &product->stock);
    clear_buffer();
    
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    return;
}

void display_product(Product *product) {

    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("Descrição: %s\n", product->description);
    printf("Estoque: %d\n", product->stock);
    printf("Código (SKU): %s\n", product->sku);
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");    
    return;
}

void __1_insert(Product *product) {
    
    FILE *fptr;
    fptr = fopen(DATA_FILE, "r+");
    if (fptr == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(0);
    }
    char again = 's';
    while ( again == 's' ) {
        
        fread(product, sizeof(Product), 1, fptr);
        
        if (!feof(fptr)) {
            if (product->description[0] != '\0') {
                continue;
            } else {
                fseek(fptr, (long) -sizeof(Product), SEEK_CUR);
            }
        }
        ask_product(product);
        fwrite(product, sizeof(Product), 1, fptr);
        printf("Continuar? [ s / n ] --->>  ");
        again = getchar();
    }
    fclose(fptr);
    return;
}

void __2_list(Product *product) {
    
    FILE *fptr;
    fptr = fopen(DATA_FILE, "r");
    if (fptr == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(0);
    }
    
    int has_records = 0;
    while (1) {
        
        fread(product, sizeof(Product), 1, fptr);
        if (feof(fptr)) break;
        if (product->description[0] == '\0') {
            continue;
        }
        display_product(product);
    }
    if (!has_records) printf("Não existem produtos na dispensa.\n");
    fclose(fptr);
    return;
}

void __3_search(Product *product) {
    
    char ipt[26];
    printf("Pesquise pelo nome do produto:  ");
    scanf("%s", ipt);
    clear_buffer();
    
    FILE *fptr;
    fptr = fopen(DATA_FILE, "r");
    int found = 0;
    while (1) {
        
        fread(product, sizeof(Product), 1, fptr);
        int matched = strequal(ipt, product->description);
        if (matched) {
            found = 1;
            display_product(product);
            break;
        } else if (feof(fptr)) {
            break;
        }
    }
    if (!found) printf("'%s' não existe na dispensa.\n", ipt);
    fclose(fptr);
    return;
}

void __4_not_available(Product *product) {
    
    FILE *fptr;
    fptr = fopen(DATA_FILE, "r");
    int found = 0;
    while (1) {
        
        fread(product, sizeof(Product), 1, fptr);
        if (feof(fptr)) break;
        if (product->stock == 0) {
            found = 1;
            display_product(product);
        }
    }
    if (!found) printf("Não há estoque vazio.\n");
    fclose(fptr);
    return;
}

void __5_change_qtd(Product *product) {
    
    char ipt[26];
    printf("Pesquise pelo nome do produto:  ");
    scanf("%s", ipt);
    clear_buffer();
    
    FILE *fptr;
    fptr = fopen(DATA_FILE, "r+");
    
    int found = 0;
    while (1) {
        
        fread(product, sizeof(Product), 1, fptr);
        if (feof(fptr)) break;
        
        int matched = strequal(ipt, product->description);
        if (matched) {
            
            found = 1;
            printf("Nova quantidade:  ");
            scanf("%d", &product->stock);
            clear_buffer();
            
            fseek(fptr, (long) -sizeof(Product), SEEK_CUR);
            fwrite(product, sizeof(Product), 1, fptr);
            break;
        }
    }
    if (!found) printf("Produto '%s' não encontrado.\n", ipt);
    fclose(fptr);
    
    return;
}

void __6_edit(Product *product) {
    
    char ipt[26];
    printf("Pesquise pelo nome do produto:  ");
    scanf("%s", ipt);
    clear_buffer();
    
    FILE *fptr;
    fptr = fopen(DATA_FILE, "r+");
    
    int found = 0;
    while (1) {
        
        fread(product, sizeof(Product), 1, fptr);
        if (feof(fptr)) break;
        
        int matched = strequal(ipt, product->description);
        if (matched) {
            
            found = 1;
            ask_product(product);
            
            fseek(fptr, (long) -sizeof(Product), SEEK_CUR);
            fwrite(product, sizeof(Product), 1, fptr);
            break;
        }
    }
    if (!found) printf("Produto '%s' não encontrado.\n", ipt);
    fclose(fptr);
    return;
}

void __7_delete(Product *product) {
    
    char ipt[26];
    printf("Pesquise pelo nome do produto:  ");
    scanf("%s", ipt);
    clear_buffer();
    
    FILE *fptr;
    fptr = fopen(DATA_FILE, "r+");
    
    int found = 0;
    while (1) {
        
        fread(product, sizeof(Product), 1, fptr);
        if (feof(fptr)) break;
        
        int matched = strequal(ipt, product->description);
        if (matched) {
            
            found = 1;
            product->description[0] = '\0';
            
            fseek(fptr, (long) -sizeof(Product), SEEK_CUR);
            fwrite(product, sizeof(Product), 1, fptr);
            break;
        }
    }
    if (!found) printf("Produto '%s' não encontrado.\n", ipt);
    fclose(fptr);
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
        
        Product prod_buff;
        
        do {
            display_menu();
            
            int action = ask_action();
            switch (action) {
                
                case 1:
                __1_insert(&prod_buff);
                break;
                
                case 2:
                __2_list(&prod_buff);
                break;
                
                case 3:
                __3_search(&prod_buff);
                break;
                
                case 4:
                __4_not_available(&prod_buff);
                break;
                
                case 5:
                __5_change_qtd(&prod_buff);
                break;
                
                case 6:
                __6_edit(&prod_buff);
                break;
                
                case 7:
                __7_delete(&prod_buff);
                break;
                
                case 8:
                __8_exit();
                break;
            }
        } while (!DONE);

        // +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
        printf("Deseja executar novamente ( s / n )  ");
        scanf("%c", &again);
        clear_buffer();
    } while (again == 's');
    return 0;
#endif // EX_4
// ------------------------------------------------