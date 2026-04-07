#include <stdio.h>

char again = 's';

char
    nome_jogo_1[21] ,
    nome_jogo_2[21] ,
    nome_jogo_3[21]
;

char
    produtora_1[21] ,
    produtora_2[21] ,
    produtora_3[21]
;

char search[21];

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
    
    // load data to memory ----- [
    read_data_handler();
    // ----- ]
    // insert data ----- [
    int
        equal_to_game_1 ,
        equal_to_game_2 ,
        equal_to_game_3
    ;
    
    int
        chars_matched_1 ,
        chars_matched_2 ,
        chars_matched_3
    ;
    

    
    // Check if the inputed already exists on databse ----- [
    printf("=====================================================\n");
    printf("Importante: Não é possível inserir\n");
    printf("o mesmo jogo duas vezes. Caso a tentativa ocorra,\n");
    printf("será pedido par inerir novamente.\n");
    printf(" =====================================================\n");
    do {
        
        // Reset matched chars ----- [
        chars_matched_1 =
        chars_matched_2 =
        chars_matched_3 = 0;
        // ----- ]
        
        printf("JOGO:  ");
        scanf("%[^\n]s", search);
        clear_buffer();
        
        // evaluate search match ----- [
        int i = 0, search_size = 0;
        while (search[search_size] != '\0') {
            
            // Condition returns an integer, wich will be summed
            chars_matched_1 += (search[i] == nome_jogo_1[i]);
            chars_matched_2 += (search[i] == nome_jogo_2[i]);
            chars_matched_3 += (search[i] == nome_jogo_3[i]);
            
            search_size++, i++;
        }
        
        equal_to_game_1 = (chars_matched_1 == search_size);
        equal_to_game_2 = (chars_matched_2 == search_size);
        equal_to_game_3 = (chars_matched_3 == search_size);
        //  ----- ]
        
    } while (
        equal_to_game_1 || equal_to_game_2 || equal_to_game_3
    );
    //  ----- ]
    
    
    for (int i = 0; i < 21; i++) {
        nome_jogo_1[i] = search[i];
    }
    printf("PRODUTORA:  ");
    scanf("%[^\n]s", produtora_1);
    clear_buffer();
    
    
    
    // Check if the inputed already exists on databse ----- [
    do {
        
        // Reset matched chars ----- [
        chars_matched_1 =
        chars_matched_2 =
        chars_matched_3 = 0;
        // ----- ]
        
        printf("JOGO:  ");
        scanf("%[^\n]s", search);
        clear_buffer();
        
        // evaluate search match ----- [
        
        int i = 0, search_size = 0;
        while (search[search_size] != '\0') {
            
            // Condition returns an integer, wich will be summed
            chars_matched_1 += (search[i] == nome_jogo_1[i]);
            chars_matched_2 += (search[i] == nome_jogo_2[i]);
            chars_matched_3 += (search[i] == nome_jogo_3[i]);
            
            search_size++, i++;
        }
        
        equal_to_game_1 = (chars_matched_1 == search_size);
        equal_to_game_2 = (chars_matched_2 == search_size);
        equal_to_game_3 = (chars_matched_3 == search_size);
        //  ----- ]
        
    } while (
        equal_to_game_1 || equal_to_game_2 || equal_to_game_3
    );
    //  ----- ]
    
    
    for (int i = 0; i < 21; i++) {
        nome_jogo_2[i] = search[i];
    }
    printf("PRODUTORA:  ");
    scanf("%[^\n]s", produtora_2);
    clear_buffer();
    
    
    
    // Check if the inputed already exists on databse ----- [
    do {
        
        // Reset matched chars ----- [
        chars_matched_1 =
        chars_matched_2 =
        chars_matched_3 = 0;
        // ----- ]
        
        printf("JOGO:  ");
        scanf("%[^\n]s", search);
        clear_buffer();
        
        // evaluate search match ----- [
        
        int i = 0, search_size = 0;
        while (search[search_size] != '\0') {
            
            // Condition returns an integer, wich will be summed
            chars_matched_1 += (search[i] == nome_jogo_1[i]);
            chars_matched_2 += (search[i] == nome_jogo_2[i]);
            chars_matched_3 += (search[i] == nome_jogo_3[i]);
            
            search_size++, i++;
        }
        
        equal_to_game_1 = (chars_matched_1 == search_size);
        equal_to_game_2 = (chars_matched_2 == search_size);
        equal_to_game_3 = (chars_matched_3 == search_size);
        //  ----- ]
        
    } while (
        equal_to_game_1 || equal_to_game_2 || equal_to_game_3
    );
    //  ----- ]
    
    
    for (int i = 0; i < 21; i++) {
        nome_jogo_3[i] = search[i];
    }
    printf("PRODUTORA:  ");
    scanf("%[^\n]s", produtora_3);
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
    printf("         JOGO            |            PRODUTORA            \n");
    printf("-----------------------------------------------------------\n");
    printf("  %-26s      %-26s\n", nome_jogo_1, produtora_1);
    printf("  %-26s      %-26s\n", nome_jogo_2, produtora_2);
    printf("  %-26s      %-26s\n", nome_jogo_3, produtora_3);
    // ----- ]
    return;
}


void __3_pesquisar_jogo() {
    
    // load data to memory ----- [
    read_data_handler();
    // ----- ]
    
    // request search string ----- [
    
    printf("Digite o nome do jogo:  ");
    scanf("%[^\n]s", search);
    clear_buffer();
    // ----- ]
    
    // evaluate search match ----- [
    int chars_matched_1 = 0;
    int chars_matched_2 = 0;
    int chars_matched_3 = 0;
    
    int i = 0, search_size = 0;
    while (search[search_size] != '\0') {
        
        int is_equal_1 = search[i] == nome_jogo_1[i];
        int is_equal_2 = search[i] == nome_jogo_2[i];
        int is_equal_3 = search[i] == nome_jogo_3[i];
        
        chars_matched_1 += (is_equal_1 == 1) ? 1 : 0;
        chars_matched_2 += (is_equal_2 == 1) ? 1 : 0;
        chars_matched_3 += (is_equal_3 == 1) ? 1 : 0;
        
        search_size++, i++;
    }
    
    if (chars_matched_1 == search_size) {
        printf("Jogo: %s  |  Produtora: %s\n", nome_jogo_1, produtora_1);
    } else if (chars_matched_2 == search_size) {
        printf("Jogo: %s  |  Produtora: %s\n", nome_jogo_2, produtora_2);
    } else if (chars_matched_3 == search_size) {
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
    
    // search loop for data ----- [
    int
        equal_to_game_1 = 0,
        equal_to_game_2 = 0,
        equal_to_game_3 = 0
    ;
    
    int
        chars_matched_1 ,
        chars_matched_2 ,
        chars_matched_3
    ;
    
    printf("=====================================================\n");
    printf("Importante: Caso insira um jogo\n");
    printf("inexistente, será pedido para\n");
    printf("inerir novamente.\n");
    printf(" =====================================================\n");
    
    do {
        // request search string --- [
        printf("Digite o nome do jogo:  ");
        scanf("%[^\n]s", search);
        clear_buffer();
        // --- ]
        
        
        // evaluate search match ---- [
        chars_matched_1 = 
        chars_matched_2 = 
        chars_matched_3 = 0;
        
        int i = 0, search_size = 0;
        while (search[search_size] != '\0') {
            
            int is_equal_1 = search[i] == nome_jogo_1[i];
            int is_equal_2 = search[i] == nome_jogo_2[i];
            int is_equal_3 = search[i] == nome_jogo_3[i];
            
            chars_matched_1 += is_equal_1;
            chars_matched_2 += is_equal_2;
            chars_matched_3 += is_equal_3;
            
            search_size++, i++;
        }
        
        equal_to_game_1 = (chars_matched_1 == search_size);
        equal_to_game_2 = (chars_matched_2 == search_size);
        equal_to_game_3 = (chars_matched_3 == search_size);
        // -------------- ]
    } while (!equal_to_game_1 && !equal_to_game_2 && !equal_to_game_3);
    // ----- ]
    
    // mark field to edit ----- [
    char to_alter;
    if (equal_to_game_1) {
        to_alter = '1';
    } else if (equal_to_game_2) {
        to_alter = '2';
        
    } else if (equal_to_game_3) {
        to_alter = '3';
        
    } else {
        
        printf("Nenehum jogo encontrado.\n");
    }
    // ---------- ]

    
    
    // request new input ------------- [
    printf("=====================================================\n");
    printf("Importante: Não é possível inserir\n");
    printf("o mesmo jogo duas vezes. Caso a tentativa ocorra,\n");
    printf("será pedido par inerir novamente.\n");
    printf(" =====================================================\n");
    
    printf("Insira o novo nome do jogo:  ");
    scanf("%[^\n]s", search);
    clear_buffer();
    
    // Check if the inputed already exists on databse ----- [
    do {
        
        // Reset matched chars ----- [
        chars_matched_1 =
        chars_matched_2 =
        chars_matched_3 = 0;
        // ----- ]
        
        printf("JOGO:  ");
        scanf("%[^\n]s", search);
        clear_buffer();
        
        // evaluate search match ----- [
        int i = 0, search_size = 0;
        while (search[search_size] != '\0') {
            
            // Condition returns an integer, wich will be summed
            chars_matched_1 += (search[i] == nome_jogo_1[i]);
            chars_matched_2 += (search[i] == nome_jogo_2[i]);
            chars_matched_3 += (search[i] == nome_jogo_3[i]);
            
            search_size++, i++;
        }
        
        equal_to_game_1 = (chars_matched_1 == search_size);
        equal_to_game_2 = (chars_matched_2 == search_size);
        equal_to_game_3 = (chars_matched_3 == search_size);
        //  ----- ]
        
    } while (
        equal_to_game_1 || equal_to_game_2 || equal_to_game_3
    );
    //  ----- ]
    
    
    
    // make edit ------------- [
    switch (to_alter) {
        
        case '1':
            for (int char_i = 0; char_i < 21; char_i++) {
                nome_jogo_1[char_i] = search[char_i];
            }
            break;
        
        case '2':
            for (int char_i = 0; char_i < 21; char_i++) {
                nome_jogo_2[char_i] = search[char_i];
            }
            break;
        
        case '3':
            for (int char_i = 0; char_i < 21; char_i++) {
                nome_jogo_3[char_i] = search[char_i];
            }
            break;
    }
    // ------------- ]
    
    // request user input ----- [
    printf("Insira a nova produtora:  ");
    scanf("%[^\n]s", search);
    clear_buffer();
    // ----- ]
    
    // make edit ------------- [
    switch (to_alter) {
        
        case '1':
            for (int char_i = 0; char_i < 21; char_i++) {
                produtora_1[char_i] = search[char_i];
            }
            break;
        
        case '2':
            for (int char_i = 0; char_i < 21; char_i++) {
                produtora_2[char_i] = search[char_i];
            }
            break;
        
        case '3':
            for (int char_i = 0; char_i < 21; char_i++) {
                produtora_3[char_i] = search[char_i];
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
    
    printf("Digite o nome do jogo:  ");
    scanf("%[^\n]s", search);
    clear_buffer();
    // ----- ]
    
    // search loop for data ----- [
    int
        equal_to_game_1 = 0,
        equal_to_game_2 = 0,
        equal_to_game_3 = 0
    ;
    
    int
        chars_matched_1 ,
        chars_matched_2 ,
        chars_matched_3
    ;
    
    printf("=====================================================\n");
    printf("Importante: Caso insira um jogo\n");
    printf("inexistente, será pedido para\n");
    printf("inerir novamente.\n");
    printf(" =====================================================\n");
    
    do {
        // request search string --- [
        printf("Digite o nome do jogo:  ");
        scanf("%[^\n]s", search);
        clear_buffer();
        // --- ]
        
        
        // evaluate search match ---- [
        chars_matched_1 = 
        chars_matched_2 = 
        chars_matched_3 = 0;
        
        int i = 0, search_size = 0;
        while (search[search_size] != '\0') {
            
            int is_equal_1 = search[i] == nome_jogo_1[i];
            int is_equal_2 = search[i] == nome_jogo_2[i];
            int is_equal_3 = search[i] == nome_jogo_3[i];
            
            chars_matched_1 += is_equal_1;
            chars_matched_2 += is_equal_2;
            chars_matched_3 += is_equal_3;
            
            search_size++, i++;
        }
        
        equal_to_game_1 = (chars_matched_1 == search_size);
        equal_to_game_2 = (chars_matched_2 == search_size);
        equal_to_game_3 = (chars_matched_3 == search_size);
        // -------------- ]
    } while (!equal_to_game_1 && !equal_to_game_2 && !equal_to_game_3);
    // ----- ]
    
    
    // mark field to delete --- [
    char to_delete;
    if (equal_to_game_1) {
        to_delete = '1';
    } else if (equal_to_game_2) {
        to_delete = '2';
        
    } else if (equal_to_game_3) {
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
        printf("\n\n");
        printf("=======================================\n");
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
        printf("====================================\n");
        
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
