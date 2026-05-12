#include <stdio.h>
#include "helps.c"



void insert_all() {
    
    // printf("[ insert_all ] was executed");
    char game[FIELD_SIZE + 1], studio[FIELD_SIZE + 1];
    
    FILE *fptr;
    fptr = fopen(DB_FILE, "a");
    
    char is_filling = 's';
    while ( is_filling == 's' ) {
        
        ask_for("Nome do jogo --->>  ", game);
        ask_for("Nome da produtora --->>  ", studio);
        
       
        printf("- - - - - - - - - - - - - - - -\n");
        
        write_record(game, studio, fptr);
        ask_continue(&is_filling);
    }
    
    fclose(fptr);
    return;
}



void list_all() {
    
    // printf("[ list_all ] was executed\n");
    char game[FIELD_SIZE + 1], studio[FIELD_SIZE + 1];
    
    FILE *fptr;
    fptr = fopen(DB_FILE, "r");
    
    printf("       JOGO          |           PRODUTORA\n");
    while (1) {
        
        read_record(game, studio, fptr);
        if (check_table_end(fptr)) {
            break;
        }
        
        printf("%10s%30s\n", game, studio);
    }
    
    fclose(fptr);
    return;
}



void search_game() {
    
    // printf("[ search_game ] was executed\n");
    char ipt[FIELD_SIZE + 1];
    ask_for("Nome do jogo --->>  ", ipt);
    
    FILE *fptr;
    fptr = fopen(DB_FILE, "r");
    
    char game[FIELD_SIZE + 1], studio[FIELD_SIZE + 1];
    while (1) {
        
        read_record(game, studio, fptr);
        if ( check_table_end(fptr) ) {
            
            display_not_found(ipt);
            return;
        }
        
        int matched = (hashed(ipt) == hashed(game));
        if ( matched ) {
            display_record(game, studio);
            return;
        }
    }
    
    fclose(fptr);
    return;
}


void search_studio() {
    
    char ipt;
    ask_for("Digite a primeira letra do estúdio:  ", &ipt);
    
    FILE *fptr;
    fptr = fopen(DB_FILE, "r");
    
    char game[FIELD_SIZE + 1], studio[FIELD_SIZE + 1];
    int exists = 0;
    while (1) {
        
        read_record(game, studio, fptr);
        if ( check_table_end(fptr) ) {
            
            if (!exists) {
                 display_not_found(&ipt);
            }
            fclose(fptr);
            return;
        }
        
        int matched = ( ipt == studio[0] );
        if ( matched ) {
            
            exists = 1;
            display_record(game, studio);
        }
        
    }
    fclose(fptr);
    return;
}


void edit_record() {
    
    return;
}


void delete_record() {
    
    return;
}


void finish() {
    
    AGAIN = 'n';
    return;
}
