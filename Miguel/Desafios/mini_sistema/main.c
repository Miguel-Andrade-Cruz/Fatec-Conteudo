#include <stdio.h>

char again = 's';

char nome_jogo_1[21], nome_jogo_2[21], nome_jogo_3[21];
char produtora_1[21], produtora_2[21], produtora_3[21];

void clear_buffer() {
    
    while (getchar() != '\n');
    return;
}


void write_data_handler() {
    
    FILE *fptr;
    fptr = fopen("banco_dados.txt", "w");
    
    char splitter[2] = "|\n";
    
    fwrite(nome_jogo_1, sizeof(nome_jogo_1), 1, fptr);
    fwrite(splitter, sizeof(splitter), 1, fptr);
    
    fwrite(produtora_1, sizeof(produtora_1), 1, fptr);
    fwrite(splitter, sizeof(splitter), 1, fptr);
    
    fwrite(nome_jogo_2, sizeof(nome_jogo_2), 1, fptr);
    fwrite(splitter, sizeof(splitter), 1, fptr);
    
    fwrite(produtora_2, sizeof(produtora_2), 1, fptr);
    fwrite(splitter, sizeof(splitter), 1, fptr);
    
    fwrite(nome_jogo_3, sizeof(nome_jogo_3), 1, fptr);
    fwrite(splitter, sizeof(splitter), 1, fptr);
    
    fwrite(produtora_3, sizeof(produtora_3), 1, fptr);
    fwrite(splitter, sizeof(splitter), 1, fptr);
    
    fclose(fptr);
    return;
}


void read_data_handler() {
    
    FILE *fptr;
    fptr = fopen("banco_dados.txt", "r");
    
    char splitter[2];
    
    fread(nome_jogo_1, sizeof(nome_jogo_1), 1, fptr);
    fread(splitter, sizeof(splitter), 1, fptr);
    
    fread(produtora_1, sizeof(produtora_1), 1, fptr);
    fread(splitter, sizeof(splitter), 1, fptr);
    
    fread(nome_jogo_2, sizeof(nome_jogo_2), 1, fptr);
    fread(splitter, sizeof(splitter), 1, fptr);
    
    fread(produtora_2, sizeof(produtora_2), 1, fptr);
    fread(splitter, sizeof(splitter), 1, fptr);
    
    fread(nome_jogo_3, sizeof(nome_jogo_3), 1, fptr);
    fread(splitter, sizeof(splitter), 1, fptr);
    
    fread(produtora_3, sizeof(produtora_3), 1, fptr);
    fread(splitter, sizeof(splitter), 1, fptr);
    
    fclose(fptr);
    return;
}


void __1_entrada_dados() {
    
    // insert data ----- [
    printf("JOGO:  ");
    scanf("%s", nome_jogo_1);
    clear_buffer();
    
    printf("PRODUTORA:  ");
    scanf("%s", produtora_1);
    clear_buffer();
    
    printf("JOGO:  ");
    scanf("%s", nome_jogo_2);
    clear_buffer();
    
    printf("PRODUTORA:  ");
    scanf("%s", produtora_2);
    clear_buffer();
    
    printf("JOGO:  ");
    scanf("%s", nome_jogo_3);
    clear_buffer();
    
    printf("PRODUTORA:  ");
    scanf("%s", produtora_3);
    clear_buffer();
    
    write_data_handler();
    // ----- ]
    return;
}


void __2_lista_dados() {
    
    // load data to memory ----- [
    read_data_handler();
    // ----- ]
    
    // list all the data ----- [
    printf("   JOGO           PRODUTORA\n");
    printf("---------------------\n");
    printf("  %s      %s\n", nome_jogo_1, produtora_1);
    printf("  %s      %s\n", nome_jogo_2, produtora_2);
    printf("  %s      %s\n", nome_jogo_3, produtora_3);
    // ----- ]
    return;
}


void __3_pesquisar_jogo() {
    
    // load data to memory ----- [
    read_data_handler();
    // ----- ]
    
    // request search string ----- [
    char search[21];
    printf("Digite o nome do jogo:  ");
    
    // gets(search);
    // scanf("%s", search);
    clear_buffer();
    // ----- ]
    
    // evaluate search match ----- [
    int chars_matched_1 = 0;
    int chars_matched_2 = 0;
    int chars_matched_3 = 0;
    
    for (int i = 0; i < 21; i++) {
        
        int is_equal_1 = search[i] == nome_jogo_1[i];
        int is_equal_2 = search[i] == nome_jogo_2[i];
        int is_equal_3 = search[i] == nome_jogo_3[i];
        
        chars_matched_1 += (is_equal_1 == 1) ? 1 : 0;
        chars_matched_2 += (is_equal_2 == 1) ? 1 : 0;
        chars_matched_3 += (is_equal_3 == 1) ? 1 : 0;
    }
    
    if (chars_matched_1 == 20) {
        printf("Jogo: %s  |  Produtora: %s\n", nome_jogo_1, produtora_1);
    } else if (chars_matched_2 == 20) {
        printf("Jogo: %s  |  Produtora: %s\n", nome_jogo_2, produtora_2);
    } else if (chars_matched_3 == 20) {
        printf("Jogo: %s  |  Produtora: %s\n", nome_jogo_3, produtora_3);
    } else {
        printf("Nenehum jogo foi encontrado.\n");
    }
    // ----- ]
    return;
}


void __4_pesquisar_produtora() {
    
    // pull data to memory --- [
    read_data_handler();
    // --- ]
    
    // request search string --- [
    char ft_letter_search;
    printf("Digite o nome da produtora (primeira letra):  ");
    scanf("%c", &ft_letter_search);
    clear_buffer();
    // --- ]
    
    // evaluate search match ---- [
    if (ft_letter_search == produtora_1[0]) {
        printf("Jogo: %s  |  Produtora: %s\n", nome_jogo_1, produtora_1);
        
    } else if (ft_letter_search == produtora_2[0]) {
        printf("Jogo: %s  |  Produtora: %s\n", nome_jogo_2, produtora_2);
        
    } else if (ft_letter_search == produtora_3[0]) {
        printf("Jogo: %s  |  Produtora: %s\n", nome_jogo_3, produtora_3);
        
    } else {
        
        printf("Nenhuma produtora encontrada.\n");
    }
    // --- ]
    return;
}


void __5_alterar_dados() {
    
    // pull data to memory --- [
    read_data_handler();
    // --- ]
    
    // request search string --- [
    char search[21];
    printf("Digite o nome do jogo:  ");
    scanf("%s", search);
    clear_buffer();
    // --- ]
    
    // evaluate search match ---- [
    int chars_matched_1 = 0;
    int chars_matched_2 = 0;
    int chars_matched_3 = 0;
    for (int i = 0; i < 20; i++) {
        
        int is_equal_1 = search[i] == nome_jogo_1[i];
        int is_equal_2 = search[i] == nome_jogo_2[i];
        int is_equal_3 = search[i] == nome_jogo_3[i];
        
        chars_matched_1 += (is_equal_1 == 1) ? 1 : 0;
        chars_matched_2 += (is_equal_2 == 1) ? 1 : 0;
        chars_matched_3 += (is_equal_3 == 1) ? 1 : 0;
    }
    // -------------- ]
    
    // mark field to edit ----- [
    char to_alter;
    if (chars_matched_1 == 20) {
        to_alter = '1';
    } else if (chars_matched_2 == 20) {
        to_alter = '2';
        
    } else if (chars_matched_3 == 20) {
        to_alter = '3';
        
    } else {
        
        printf("Nenehum jogo encontrado.\n");
        return;
    }
    // ---------- ]
    
    // request new input ------------- [
    char new_game[21];
    printf("Insira o novo nome do jogo:  ");
    scanf("%s", new_game);
    clear_buffer();
    
    char new_studio[21];
    printf("Insira a nova produtora:  ");
    scanf("%s", new_studio);
    clear_buffer();
    // ------------- ]
    
    // make edit ------------- [
    switch (to_alter) {
        
        case '1':
            for (int char_i = 0; char_i < 21; char_i++) {
                nome_jogo_1[char_i] = new_game[char_i];
                produtora_1[char_i] = new_studio[char_i];
            }
            break;
        
        case '2':
            for (int char_i = 0; char_i < 21; char_i++) {
                nome_jogo_2[char_i] = new_game[char_i];
                produtora_2[char_i] = new_studio[char_i];
            }
            break;
        
        case '3':
            for (int char_i = 0; char_i < 21; char_i++) {
                nome_jogo_3[char_i] = new_game[char_i];
                produtora_3[char_i] = new_studio[char_i];
            }
            break;
    }
     // ------------- ]

    // write back to db --- [
    write_data_handler();
    // ----- ]
    return;
}


void __6_exculir_dados() {
    
    // pull data to memory ----- [
    read_data_handler();
    // ----- ]
    
    // request serach string ----- [
    char search[21];
    printf("Digite o nome do jogo:  ");
    scanf("%s", search);
    clear_buffer();
    // ----- ]
    
    // evaluate search match ----- [
    int chars_matched_1 = 0;
    int chars_matched_2 = 0;
    int chars_matched_3 = 0;
    for (int i = 0; i < 20; i++) {
        
        int is_equal_1 = search[i] == nome_jogo_1[i];
        int is_equal_2 = search[i] == nome_jogo_2[i];
        int is_equal_3 = search[i] == nome_jogo_3[i];
        
        chars_matched_1 += (is_equal_1 == 1) ? 1 : 0;
        chars_matched_2 += (is_equal_2 == 1) ? 1 : 0;
        chars_matched_3 += (is_equal_3 == 1) ? 1 : 0;
    }
    // ----- ]
    
    // mark field to delete --- [
    char to_delete;
    if (chars_matched_1 == 20) {
        to_delete = '1';
    } else if (chars_matched_2 == 20) {
        to_delete = '2';
        
    } else if (chars_matched_3 == 20) {
        to_delete = '3';
        
    } else {
        
        printf("Nenehum jogo encontrado.\n");
        return;
    }
    // ----- ]
    
    // exclude selected data --- [
    switch (to_delete) {
        
        case '1':
            nome_jogo_1[0] = '^';
            produtora_1[0] = '^';
            break;
        
        case '2':
            nome_jogo_2[0] = '^';
            produtora_2[0] = '^';
            break;
        
        case '3':
            nome_jogo_3[0] = '^';
            produtora_3[0] = '^';
            break;
    }
    // ----- ]

    // write back to db --- [
    write_data_handler();
    // ----- ]
    return;
}


void __7_sair() {
    
    again = 'n';
    return;
}


int main() {
    
    printf("Bem vindo ao banco de dados dos jogos!\n");
    do {
        
        char choice;
        
        printf("Escolha uma opoção:  \n");
        printf("[ 1 ]  Insira todos os dados\n");
        printf("[ 2 ]  Liste todos os dados\n");
        printf("[ 3 ]  Pesquise por um jogo\n");
        printf("[ 4 ]  Pesquise a produtora\n");
        printf("[ 5 ]  Altere todos os dados\n");
        printf("[ 6 ]  Exclua o jogo e a produtora\n");
        printf("[ 7 ]  Sair\n");
        
        printf("-->>  ");
        scanf("%c", &choice);
        clear_buffer();
        
        switch (choice) {
            case '1':
                __1_entrada_dados();
                break;
            case '2':
                __2_lista_dados();
                break;
            case '3':
                 __3_pesquisar_jogo();
                 break;
            case '4':
                __4_pesquisar_produtora();
                break;
            case '5':
                __5_alterar_dados();
                break;
            case '6':
                __6_exculir_dados();
                break;
            case '7':
                __7_sair();
        }
    
    } while (again == 's');
    return 0;
}
