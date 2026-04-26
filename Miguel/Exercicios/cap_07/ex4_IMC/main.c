
// 4 - Escreva um programa com a estrutura de dados abaixo. Defina um vetor de
//     estrutura de 4 elementos. Receba dados via teclado e imprima-os no video.
//     A estrutura e' uma variavel global.
//     Faca um menu com as seguintes opcoes:
//     1 - receber todos os dados
//     2 - imprime todos os dados 
//     3 - calcula o IMC de todas as pessoas. 
//     4 - sair
//         Calculo do IMC = peso/(altura*altura).
//         estrutura: nome, peso, altura


#define INNER_MODE
// #define OUTER_MODE

#ifdef INNER_MODE
#include <stdio.h>
#include <locale.h>


typedef struct {
    
    char name[25];
    int weight;
    float height;
} Metrics;

int _CONTINUE = 1;
Metrics pacients_metrics[4];

void clear_buffer() {
    
    while( getchar() != '\n');
    return;
}


void display_menu() {
    
    printf("------------- Ações disponíveis: ------------------\n");
    printf("[ 1 ] Inserir dados\n");
    printf("[ 2 ] Mostrar dados\n");
    printf("[ 3 ] Calcular IMCs\n");
    printf("[ 4 ] Sair\n");
}


void __1_insert() {
    
    for (int i = 0; i < 4; i++) {
        
        printf("\n------------------------------------------------------\n");
        
        printf("Nome: ");
        scanf("%s", pacients_metrics[i].name);
        clear_buffer();
        
        printf("Peso: ");
        scanf("%d", &pacients_metrics[i].weight);
        clear_buffer();
        
        printf("Altura: ");
        scanf("%f", &pacients_metrics[i].height);
        clear_buffer();
        
        printf("----------------------------------------------------------\n");
    }
    return;
}

void __2_display() {
    
    for (int i = 0; i < 4; i++) {
        
        printf("\n----------------------------------------------------------\n");
        
        printf("Nome: %s\n", pacients_metrics[i].name);
        printf("Peso: %d\n", pacients_metrics[i].weight);
        printf("Altura: %f\n", pacients_metrics[i].height);
        
        printf("----------------------------------------------------------\n");
    }
    return;
}



void __3_calculate() {
    
    for (int i = 0; i < 4; i++) {
        
        int weight = pacients_metrics[i].weight;
        float height = pacients_metrics[i].height;
        
        float imc = weight / ( height * height );
        
        printf("IMC pessoa %d: %.2f", i + 1, imc);
    }
    return;
}



void __4_exit() {
    _CONTINUE = 0;
}


int main() {
    setlocale(LC_ALL, "Portuguese");
    
    char again = 'n';
    do {
        
        do {
            
            display_menu();
            
            int action;
            printf("--->> ");
            scanf("%d", &action);
            clear_buffer();
            
            switch (action) {
                
                case 1:
                    __1_insert();
                    break;
                case 2:
                    __2_display();
                    break;
                case 3:
                    __3_calculate();
                    break;
                case 4:
                    __4_exit();
                    break;
                default:
                    continue;
            }
        } while (_CONTINUE == 1);
        
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