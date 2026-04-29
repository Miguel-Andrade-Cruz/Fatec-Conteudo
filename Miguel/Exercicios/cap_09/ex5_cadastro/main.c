
// 5 - Escreva um programa com a estrutura abaixo. Defina um vetor de estruturas
//     de 4 elementos como variavel LOCAL na funcao main(). Receba os 4 registros
//     sequencialmente pelo teclado numa funcao e imprima todos os registros no
//     video em outra funcao. Faca um menu. Utilize ponteiros nas funcoes.
//     Coloque no menu a opcao de sair tambem. Utilize o comando switch.
//     (vetor de estruturas)
//      estutura: nome, end, cidade, estado, cep

#define INNER_MODE

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
#endif // INNER_MODE