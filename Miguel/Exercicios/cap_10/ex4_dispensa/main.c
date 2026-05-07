
// 4 - Escreva um programa para o controle de mercadorias em uma dispensa
//     domestica. Para cada produto sera' armazenado um codigo numerico, nome
//     do produto e quantidade atual numa estrutura de dados. A unica estrutura
//     de dados deve ser declarada como variavel LOCAL na funcao main(). Escreva
//     os registros das mercadorias direto no arquivo. (utilize a funcao fseek quando
//     necessario). NAO pode usar vetor de estruturas. Utilize ponteiros.
//     O programa deve ter as seguintes opcoes: (cada opcao do menu e' um funcao)
//     1 - inclui produtos
//     2 - listar todos os produtos
//     3 - pesquisar uma mercadoria pela descricao
//     4 - listar os produtos nao disponiveis.
//     5 - alterar a quantidade atual
//     6 - altera produtos
//     7 - exclui produtos
//     8 - saida


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
    fptr = fopen(DATA_FILE, "a");
    if (fptr == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(0);
    }
    char again = 's';
    while ( again == 's' ) {
        
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
        
        size_t sucess = fread(product, sizeof(Product), 1, fptr);
        if (product->sku[0] == '\0') {
            has_records = 1;
            continue;
        }
        if (feof(fptr)) break;
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
        
        fpos_t current;
        fgetpos(fptr, &current);
        
        fread(product, sizeof(Product), 1, fptr);
        if (feof(fptr)) break;
        
        int matched = strequal(ipt, product->description);
        if (matched) {
            
            found = 1;
            printf("Nova quantidade:  ");
            scanf("%d", &product->stock);
            clear_buffer();
            
            fsetpos(fptr, &current);
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
        fpos_t current;
        fgetpos(fptr, &current);

        fread(product, sizeof(Product), 1, fptr);
        if (feof(fptr)) break;
        
        int matched = strequal(ipt, product->description);
        if (matched) {
            
            found = 1;
            ask_product(product);
            
            fsetpos(fptr, &current);
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

        fpos_t current;
        fgetpos(fptr, &current);

        fread(product, sizeof(Product), 1, fptr);
        if (feof(fptr)) break;
        
        int matched = strequal(ipt, product->description);
        if (matched) {
            
            found = 1;
            product->sku[0] = '\0';
            fsetpos(fptr, &current);
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
}