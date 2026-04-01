#include <stdio.h>

char again = 'n';

char nome_jogo_1[20], nome_jogo_2[20], nome_jogo_3[20];
char produtora_1[20], produtora_2[20], produtora_3[20];

void clear_buffer() {
    
    while (getchar() != '\n');
    return;
}


void cpy_strs_suffix(char *src_1, char *dest_1, char *src_2, char *dest_2) {
    
    int char_i;
    // Size with suffix
    const int FIXED_SIZE = 23;
    
    // Copy content without spaces
    char_i = 0;
    while (src_1[char_i] != '\0') {
        
        dest_1[char_i] = src_1[char_i];
        char_i++;
    }
    // Add suffix
    for ( int i = char_i; i < FIXED_SIZE - 1; i++) dest_1[i] = '\0';
    dest_1[FIXED_SIZE] = '|';
    
    
    char_i = 0;
    while (src_2[char_i] != '\0') {
        
        dest_2[char_i] = src_2[char_i];
        char_i++;
    }
    // Add suffix
    for ( int i = char_i; i < FIXED_SIZE - 1; i++) dest_2[i] = '\0';
    dest_2[FIXED_SIZE] = '|';
    return;
}


void write_data_handler(char *data_1, char *data_2) {
    
    FILE *db;
    db = fopen("banco_dados.txt", "a");
    
    fwrite(data_1, sizeof(char), 23, db);
    fwrite(data_2, sizeof(char), 23, db);
    fwrite("\n", sizeof(char), 1, db);
    
    fclose(db);
    return;
}


void read_data_handler() {
    
    const int i_lmt_1 = 0;
    const int i_lmt_2 = 44;
    const int i_lmt_3 = 67;
    const int i_lmt_4 = 92;
    const inr i_lmt_5 = 115;
    const int i_lmt_6 = 137;
    FILE *db;
    db = fopen("banco_dados.txt", "r");
    
    char fileline[137];
    fread(fileline, sizeof(char), 137, db);
    return;
}

void __1_entrada_dados() {
    
    const int STR_SIZE_WITH_SUFFIX = 22;
    char temp_buffer_1[23], temp_buffer_2[23];
    
    printf("   JOGO                    PRODUTORA    ");
    scanf("%s      %s", nome_jogo_1, produtora_1);
    clear_buffer();
    cpy_strs_suffix(nome_jogo_1, temp_buffer_1, produtora_1, temp_buffer_1);
    write_data_handler(temp_buffer_1, temp_buffer_2);
    printf("\n");
    
    printf("   JOGO                    PRODUTORA    ");
    scanf("%s      %s", nome_jogo_2, produtora_2);
    clear_buffer();
    cpy_strs_suffix(nome_jogo_2, temp_buffer_1, produtora_2, temp_buffer_1);
    write_data_handler(temp_buffer_1, temp_buffer_2);
    printf("\n");
    
    printf("   JOGO                    PRODUTORA    ");
    scanf("%s      %s", nome_jogo_3, produtora_3);
    clear_buffer();
    cpy_strs_suffix(nome_jogo_3, temp_buffer_1, produtora_3, temp_buffer_1);
    write_data_handler(temp_buffer_1, temp_buffer_2);
    printf("\n");
    return;
}


void __2_lista_dados() {
    
    
    return;
}


void __3_pesquisar_jogo() {
    
    return;
}

void __4_pesquisar_produtora() {
    
    return;
}

void __5_alterar_dados() {
    
    return;
}


void __6_exculir_dados() {
    
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
        
        printf("-->>  ");
        scanf("%c", &choice);
        clear_buffer();
        
        switch (choice) {
            case 1:
                __1_entrada_dados();
                break;
            case 2:
                __2_lista_dados();
                break;
            case 3:
                 __3_pesquisar_jogo();
                 break;
            case 4:
                __4_pesquisar_produtora();
                break;
            case 5:
                __5_alterar_dados();
                break;
            case 6:
                __6_exculir_dados();
                break;
            case 7:
                __7_sair();
        }
        
    } while (again == 's');
    return 0;
}