
// EX 1 -- NO
// EX 2 -- OK
// EX 3 -- NO
// EX 4 -- OK
// EX 5 -- OK
// EX 6 -- OK

#define EX_0

#ifdef EX_1
#endif // EX_1
// -----------------------------------------------


// -----------------------------------------------
#ifdef EX_2
void clear_buffer() {
    
    while (getchar() != '\n');
    return;
}

void ask_for_strs(char *str1, char *str2) {
    
    printf("Digite a primeira string (máx. 10 caract) -->>  ");
    scanf("%s", str1);
    clear_buffer();
    
    printf("Digite a segunda string (máx. 10 caract) -->>  ");
    scanf("%s", str2);
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
    
    if ( (str1[i] == '\0') && (str2[i] == '\0') ) {
        return 1;
    }
    return 0;
}

int main() {
    
    char again = 'n';
    do {
        
        char str1[10];
        char str2[10];
        
        ask_for_strs(str1, str2);
        int is_equal = strequal(str1, str2);
        
        if ( is_equal ) {
            printf("As duas strings são iguais\n");
        } else {
            printf("As duas strings são diferentes\n");
        }
        
        // +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
        printf("Deseja executar novamente ( s / n )  ");
        scanf("%c", &again);
        clear_buffer();
    } while (again == 's');
    return 0;
}
#endif // EX_2
// -----------------------------------------------


// -----------------------------------------------
#ifdef EX_3
#endif // EX_3
// -----------------------------------------------



// -----------------------------------------------
#ifdef EX_4
#include <stdio.h>

void clear_buffer() {
    
    while ( getchar() != '\n' );
    return;
}



int search_for_char(char *ipt, char *list) {
    
    int i = 0;
    while ( i <= 10 ) {
        
        if ( *ipt == list[i] ) {
            return 1;
        }
        i++;
    }
    return 0;
}



int main() {
    
    char again = 'n';
    do {
        
        char list[] = {
            'b','d','f',
            'h','j','k',
            'm','o','q',
            's','u','w','y'
        };
        char ipt, *pIpt;
        
        printf("Insira um caractere: ");
        scanf("%c", pIpt);
        clear_buffer();
        
        int found = search_for_char(pIpt, list);
        
        if (found) {
            printf("Essa letra existe na lista\n");
        } else {
            printf("Essa letra não está na lista\n");
        }
        
        
        // +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
        printf("Deseja executar novamente ( s / n )  ");
        scanf("%c", &again);
        clear_buffer();
    } while (again == 's');
    return 0;
}
#endif // EX_4
// -----------------------------------------------




// -----------------------------------------------
#ifdef EX_5
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

void __1_insert(Userdata *users) {
    
    for (int i = 0; i < 4; i++) {
        
        Userdata *cur_user = (users + i);
        
        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
        
        ask_handler("Digite seu nome:  ", cur_user->name);
        ask_handler("Digite o estado:  ", cur_user->state);
        ask_handler("Digite a cidade:  ", cur_user->city);
        ask_handler("Digite o CEP:  ", cur_user->cep);
        ask_handler("Digite o endereço:  ", cur_user->end);
        
        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    }
    return;
}

void __2_show(Userdata *users) {
    
    for (int i = 0; i < 4; i++) {
        
        Userdata cur_user = *(users + i);
        
        printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        
        printf("Nome: %s\n", cur_user.name);
        printf("Cidade: %s\n", cur_user.city);
        printf("Estado: %s\n", cur_user.state);
        printf("CEP: %s\n", cur_user.cep);
        printf("Endereço: %s\n", cur_user.end);
        
        printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    }
    return;
}

void __3_exit() {
    
    DONE = 's';
}

int ask_action() {
    
    int action;
    
    printf("--------------- Ações disponíveis: ------------\n");
    printf("[ 1 ] Inserir dados\n");
    printf("[ 2 ] Ver dados\n");
    printf("[ 3 ] Sair\n");
    
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
                __3_exit();
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
#endif // EX_5




#ifdef EX_6
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
#endif // EX_6



