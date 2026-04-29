
// 6 - Acrescente ao menu do exercicio anterior as funcoes de procura, altera e
//     exclui um registro sempre usando ponteiros.

#define INNER_MODE
// #define OUTER_MODE

#ifdef INNER_MODE

#include <stdio.h>


void clear_buffer() {
    
    while ( getchar() != '\n' );
    return;
}

typedef struct {
    
    char name[25];
    char end[5];
    char city[20];
    char state[3];
    char cep[9];
} Userdata;

char DONE = 'n';

void ask_handler(char *msg, char *ptr) {
    
    printf("%s", msg);
    scanf("%s", ptr);
    clear_buffer();
    return;
}



int strequal(char *str1, char *str2) {
    
    int i = 0;
    while ( 
        str1[i] == str2[i] &&
        str1[i] != '\0' &&
        str2[i] != '\0'
    ) {
        i++;
    }
    if ( str1[i] == '\0' && str2[i] == '\0' ) {
        return 1;
    } else {
        return 0;
    }
}



void display_user(Userdata *cur_user) {
    
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    
    printf("Nome: %s\n", cur_user->name);
    printf("Cidade: %s\n", cur_user->city);
    printf("Estado: %s\n", cur_user->state);
    printf("CEP: %s\n", cur_user->cep);
    printf("Endereço: %s\n", cur_user->end);
    
    printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    return;
}



void __1_insert(Userdata *users) {
    
    for (int i = 0; i < 4; i++) {
        
        Userdata *cur_user = (users + i);
        
        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        ask_handler("Nome:  ", cur_user->name);
        ask_handler("CEP:  ", cur_user->cep);
        ask_handler("Cidade:  ", cur_user->city);
        ask_handler("Estado:  ", cur_user->state);
        ask_handler("Endereço:  ", cur_user->end);
        printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    }
    return;
}



void __2_show(Userdata *users) {
    
    for (int i = 0; i < 4; i++) {
        
        Userdata *cur_user = users + i;
        if ( cur_user->name[0] != '~' ) {
            display_user(cur_user);
        }
    }
    return;
}



void __3_edit(Userdata *users) {
    
    char *ipt;
    ask_handler("Pesquise pelo nome do usuário:  ", ipt);
    
    int i = 0;
    while ( i < 4 ) {
        
        Userdata *cur_user = users + i;
        int is_equal = strequal(ipt, cur_user->name);
        if (is_equal) {
            
            ask_handler("Nome:  ", cur_user->name);
            ask_handler("CEP:  ", cur_user->cep);
            ask_handler("Cidade:  ", cur_user->city);
            ask_handler("Estado:  ", cur_user->state);
            ask_handler("Endereço:  ", cur_user->end);
            return;
        }
        i++;
    }
    
    printf("Esse usuário não existe\n");
    return;
}



void __4_search(Userdata *users) {
    
    char ipt[25];
    ask_handler("Pesquise pelo nome do usuário:  ", ipt);
    
    int i = 0;
    while ( i < 4 ) {
        
        Userdata *cur_user = users + i;
        int is_equal = strequal(ipt, cur_user->name);
        
        if ( is_equal ) {
            display_user(cur_user);
            return;
        }
        i++;
    }
    
    printf("Esse usuário não existe\n");
    return; //
}



void __5_exclude(Userdata *users) {
    
    char *ipt;
    ask_handler("Pesquise pelo nome do usuário:  ", ipt);
    
    int i = 0;
    while ( i < 4 ) {
        
        Userdata *cur_user = users + i;
        int is_equal = strequal(ipt, cur_user->name);
        if (is_equal) {
            
            cur_user->name[0] = '~';
            return;
        }
        i++;
    }
    
    printf("Esse usuário não existe\n");
    return; //
}



void __6_exit() {
    
    DONE = 's';
}



int ask_action() {
    
    int action;
    
    printf("--------------- Ações disponíveis: ------------\n");
    printf("[ 1 ] Inserir dados\n");
    printf("[ 2 ] Ver dados\n");
    printf("[ 3 ] Editar\n");
    printf("[ 4 ] Procurar\n");
    printf("[ 5 ] Excluir\n");
    printf("[ 6 ] Sair\n");
    
    printf("---->>  ");
    scanf("%d", &action);
    clear_buffer();
    return action;
}


int main() {
    
    char again = 'n';
    do {
        
        Userdata users[4];
        
        while (DONE == 'n') {
                
            int action = ask_action();
            switch (action) {
                
                case 1:
                __1_insert(&users[0]);
                break;
                
                case 2:
                __2_show(&users[0]);
                break;
                
                case 3:
                __3_edit(&users[0]);
                break;
                
                case 4:
                __4_search(&users[0]);
                break;
                
                case 5:
                __5_exclude(&users[0]);
                break;
                
                case 6:
                __6_exit();
                break;
                
                default:
                continue;
            }
        }
        // +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
        printf("Deseja executar novamente ( s / n )  ");
        scanf("%c", &again);
        clear_buffer();
    } while (again == 's');
    return 0;
}
#endif // INNER_MODE


#ifdef OUTER_MODE
int main() {
    
    char again = 'n';
    do {
        
        
        // +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
        printf("Deseja executar novamente ( s / n )  ");
        scanf("%c", &again);
        clear_buffer();
    } while (again == 's');
    return 0;
}
#endif // OUTER_MODE