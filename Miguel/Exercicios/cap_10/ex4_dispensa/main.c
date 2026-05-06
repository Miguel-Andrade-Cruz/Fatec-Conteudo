
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
#define DATA_FILE "dispensa.txt"
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

void load_product(Product *prodct) {

    FILE *fptr;
    fptr = fopen(DATA_FILE, "r");
    if (fptr == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(0);
    }
    
    size_t sucess = fread(product, sizeof(Product), 1, fptr);
    if (!sucess) product->sku = 0000;
    fclose(fptr);
    return;
}


void store_product(Product *product) {

    FILE *fptr;
    fopen(DATA_FILE, "w");
    if (fptr == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(0);
    }
    
    fwrite(product, sizeof(Product), 1, fptr);
    fclose(fptr);
    return;
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
    
    return;
}

void __2_list(Product *product) {
    
    return;
}

void __3_search(Product *product) {
    
    return;
}

void __4_available(Product *product) {
    
    return;
}

void __5_change_qtd(Product *product) {
    
    return;
}

void __6_edit(Product *product) {
    
    return;
}

void __7_delete(Product *product) {
    
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
                __1_();
                break;

                case 2:
                __2_();
                break;
        
                case 3:
                __3_();
                break;

                case 4:
                __4_();
                break;

                case 5:
                __5_();
                break;

                case 6:
                __6_();
                break;

                case 7:
                __7_();
                break;

                case 8:
                __8_();
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