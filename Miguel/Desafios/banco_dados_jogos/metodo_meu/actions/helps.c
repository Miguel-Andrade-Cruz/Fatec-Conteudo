#include "../bootstrap.c"

void ask_for(char *msg, char *ipt) {
    
    printf("%s", msg);
    scanf("%[^\n]s", ipt);
    clear_buffer();
    return;
}


void ask_continue(char *is_filling) {
    
    printf("Continuar preenchimento?  ( s / n )  ");
    scanf("%c", is_filling);
    clear_buffer();
    return;
}


void write_record(char *game, char *studio, FILE *fptr) {
    
    fwrite(game, sizeof(game), 1, fptr);
    fwrite("  |  ", sizeof(char) * 5, 1, fptr);
    fwrite(studio, sizeof(studio), 1, fptr);
    return;
}



void read_record(char *game, char *studio, FILE *fptr) {
    
    fread(game, sizeof(game), 1, fptr);
    fseek(fptr, 5, SEEK_CUR);
    fread(studio, sizeof(studio), 1, fptr);
    return;
}


void display_not_found(char *ipt) {
    
    printf("jogo '%s' não encontrado.\n", ipt);
    return;
}



void display_record(char *game, char *studio) {
    
    printf("--------------------------------------------------------\n");
    printf("JOGO:  %s -- PRODUTORA: %s\n", game, studio);
    printf("--------------------------------------------------------\n");
    return;
}