
// 3 - Escreva um programa para controlar de um cadastro de clientes. Para cada
//     registro sera' armazenado nome, email e celular numa estrutura de dados. 
//     A unica estrutura de dados e' uma variavel LOCAL na funcao main().
//     Escreva os registros direto no arquivo. (utilize a funcao fseek quando
//     necessario). NAO pode usar vetor de estruturas. Utilize ponteiros para
//     passar parametros para as funcoes.
//     O programa deve ter as seguintes opcoes: (cada opcao do menu e' um funcao)
//     1 - inclui registros
//     2 - listar todos os registros
//     3 - pesquisar registro pelo nome
//     4 - altera registro
//     5 - exclui registro
//     6 - saida

#include <complex.h>
#define INNNER_MODE

#ifdef INNNER_MODE

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
#endif // INNNER_MODE