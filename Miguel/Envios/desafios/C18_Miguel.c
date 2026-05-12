
#include <stdio.h>

// Variáveis de controle global ------ <
char again = 's';
int DONE = 0;
#define DATA_FILE "jogos.txt"
// ------------ >

void clear_buffer() {
    
    while (getchar() !=   '\n');
    return;
}

// Estrutura ------ <
typedef struct {
    
    char name[30];
    char studio[30];
    float price;
    int stock;
} GameRecord;
// ------------ >


void file_handler_open(FILE **fptr, char *mode) {
    
    *fptr = fopen(DATA_FILE, mode);
    return;
}

void file_handler_close(FILE **fptr) {
    
    fclose(*fptr);
    return;
}

void ask_game(GameRecord *game) {
    
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("Nome:  ");
    scanf("%s", game->name);
    clear_buffer();
    
    printf("Produtora:  ");
    scanf("%s", game->studio);
    clear_buffer();
    
    printf("Preço:  ");
    scanf("%f", &game->price);
    clear_buffer();
    
    printf("Quantidade:  ");
    scanf("%d", &game->stock);
    clear_buffer();
    
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
}

void display_menu() {
    
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("[ 1  ] - Inserir\n");
    printf("[ 2  ] - Listar\n");
    printf("[ 3  ] - Pesquisar pelo jogo\n");
    printf("[ 4  ] - Pesquisar por letra da produtora\n");
    printf("[ 5  ] - Pesquisar por faixa de preço\n");
    printf("[ 6  ] - Atualizar estoque\n");
    printf("[ 7  ] - Atualizar preço\n");
    printf("[ 8  ] - Alterar dados do jogo\n");
    printf("[ 9  ] - Excluir jogo\n");
    printf("[ 10 ]- Sair\n");
    printf("=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    return;
}


void display_game(GameRecord *game) {
    
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("Nome: %s\n", game->name);
    printf("Produtora: %s\n", game->studio);
    printf("Preço: %f\n", game->price);
    printf("Quantidade: %d\n", game->stock);
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    return;
}

int ask_action() {
    
    int action;
    printf("----->>  ");
    scanf("%d", &action);
    clear_buffer();
    return action;
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

void __1_insert(GameRecord *game, FILE *fptr) {
    
    char again = 's';
    while (again == 's') {
        
        fread(game, sizeof(GameRecord), 1, fptr);
        if (!feof(fptr)) {
            if (game->name[0] == '\0') {
                fseek(fptr, (long) -sizeof(GameRecord), SEEK_CUR);
            } else {
                continue;
            }
        }
        ask_game(game);
        fwrite(game, sizeof(GameRecord), 1, fptr);
        printf("Continuar inserindo? [ s/n ]  ");
        again = getchar();
    }
    return;
}

void __2_list(GameRecord *game, FILE *fptr) {
    
    while (1) {
        fread(game, sizeof(GameRecord), 1, fptr);
        if (feof(fptr)) break;
        if (game->name[0] == '\0') continue;
        display_game(game);
    }
    return;
}

void __3_search(GameRecord *game, FILE *fptr) {
    
    char ipt[30];
    printf("Pesquisar por:  ");
    scanf("%s", ipt);
    clear_buffer();
    
    while (1) {
        
        fread(game, sizeof(GameRecord), 1, fptr);
        if (feof(fptr)) break;
        
        int matched = strequal(ipt, game->name);
        if (matched) {
            display_game(game);
            break;
        }
    }
    return;
}

void __4_search_letter(GameRecord *game, FILE *fptr) {
    
    char ipt;
    printf("Pesquisar por:  ");
    ipt = getchar();
    
    while (1) {
        
        fread(game, sizeof(GameRecord), 1, fptr);
        if (feof(fptr)) break;
        if (game->name[0] == '\0') continue;
        
        if (ipt == game->studio[0]) {
            display_game(game);
        }
    }
    return;
}

void __5_search_price(GameRecord *game, FILE *fptr) {
    
    int lower, higher;
    printf("Pesquisar por valor [Exemplo: 40 120]  ");
    scanf("%d %d", &lower, &higher);
    clear_buffer();
    
    while (1) {
        
        fread(game, sizeof(GameRecord), 1, fptr);
        if (feof(fptr)) break;
        if (game->name[0] == '\0') continue;
        
        float price = game->price;
        if (lower <= price && higher >= price) {
            display_game(game);
        }
    }
    return;
}

void __6_change_stock(GameRecord *game, FILE *fptr) {
    
    char ipt[30];
    printf("Pesquisar por:  ");
    scanf("%s", ipt);
    clear_buffer();
    
    while (1) {
        
        fread(game, sizeof(GameRecord), 1, fptr);
        if (feof(fptr)) break;
        
        int matched = strequal(ipt, game->name);
        if (matched) {
            char change;
            int qtd;
            printf("Insira a alteração [ Exemplo: + 250 ]  ");
            scanf("%c %d", &change, &qtd);
            clear_buffer();

            // change value and save ------ <
            if (change == '+') {
                game->stock += qtd;
            } else if (change == '-') {
                game->stock -= qtd;
            }
            
            fseek(fptr, (long) -sizeof(GameRecord), SEEK_CUR);
            fwrite(game, sizeof(GameRecord), 1, fptr);
            // ------------ >
            break;
        }
    }
    return;
}

void __7_change_price(GameRecord *game, FILE *fptr) {
    
    char ipt[30];
    printf("Pesquisar por:  ");
    scanf("%s", ipt);
    clear_buffer();
    
    while (1) {
        
        fread(game, sizeof(GameRecord), 1, fptr);
        if (feof(fptr)) break;
        
        int matched = strequal(ipt, game->name);
        if (matched) {
            
            printf("Novo preço:  ");
            scanf("%f", &game->price);
            clear_buffer();
            
            fseek(fptr, (long) -sizeof(GameRecord), SEEK_CUR);
            fwrite(game, sizeof(GameRecord), 1, fptr);
        }
    }
        return;
}

void __8_change_all(GameRecord *game, FILE *fptr) {
    
    char ipt[30];
    printf("Pesquisar por:  ");
    scanf("%s", ipt);
    clear_buffer();
    
    while (1) {
        
        fread(game, sizeof(GameRecord), 1, fptr);
        if (feof(fptr)) break;
        
        int matched = strequal(ipt, game->name);
        if (matched) {
            ask_game(game);
            fseek(fptr, (long) -sizeof(GameRecord), SEEK_CUR);
            fwrite(game, sizeof(GameRecord), 1, fptr);
        }
    }
            return;
}

void __9_delete(GameRecord *game, FILE *fptr) {
    
    char ipt[30];
    printf("Pesquisar por:  ");
    scanf("%s", ipt);
    clear_buffer();
    
    while (1) {
        
        fread(game, sizeof(GameRecord), 1, fptr);
        if (feof(fptr)) break;
        
        int matched = strequal(ipt, game->name);
        if (matched) {
            game->name[0] = '\0';
            fseek(fptr, (long) -sizeof(GameRecord), SEEK_CUR);
            fwrite(game, sizeof(GameRecord), 1, fptr);
        }
    }
    return;
}

void __10_exit() {
    
    DONE = 1;
    return;
}
int main() {
    
    do {
        DONE = 0;
        GameRecord game;
        do {
            display_menu();
            int action = ask_action();
            
            FILE *fptr;
            switch (action) {
                
                case 1:
                file_handler_open(&fptr, "r+");
                __1_insert(&game, fptr);
                file_handler_close(&fptr);
                break;
                
                case 2:
                file_handler_open(&fptr, "r");
                __2_list(&game, fptr);
                file_handler_close(&fptr);
                break;
                
                case 3:
                file_handler_open(&fptr, "r");
                __3_search(&game, fptr);
                file_handler_close(&fptr);
                break;
                
                case 4:
                file_handler_open(&fptr, "r");
                __4_search_letter(&game, fptr);
                file_handler_close(&fptr);
                break;
                
                case 5:
                file_handler_open(&fptr, "r");
                __5_search_price(&game, fptr);
                file_handler_close(&fptr);
                break;
                
                case 6:
                file_handler_open(&fptr, "r+");
                __6_change_stock(&game, fptr);
                file_handler_close(&fptr);
                break;
                
                case 7:
                file_handler_open(&fptr, "r+");
                __7_change_price(&game, fptr);
                file_handler_close(&fptr);
                break;
                
                case 8:
                file_handler_open(&fptr, "r+");
                __8_change_all(&game, fptr);
                file_handler_close(&fptr);
                break;
                
                case 9:
                file_handler_open(&fptr, "r+");
                __9_delete(&game, fptr);
                file_handler_close(&fptr);
                break;
                
                case 10:
                __10_exit();
                break;
                
            }
        } while (!DONE);
        printf("+-+-+-+-+-+-+-+-+-+-+-+-");
        printf("Deseja executar novamente? [ s / n ]  ");
        again = getchar();
    } while (again == 's');
    return 0;
}