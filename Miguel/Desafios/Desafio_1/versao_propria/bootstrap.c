#include "includes.c"


void insert_all();

void list_all();

void search_game();

void search_studio();

void edit_record();

void delete_record();

void finish();


typedef void ( *Action )();

Action menu[7] = {
    *insert_all,
    *list_all,
    *search_game,
    *search_studio,
    *edit_record,
    *delete_record,
    *finish
};



int ask_action() {
    
    int ipt;
    printf("---->>  ");
    scanf("%d", &ipt);
    clear_buffer();
    return ipt;
}


void call_action(int option) {
    
    // Sub 1 for vec index
    Action requested = menu[option - 1];
    requested();
    return;
}