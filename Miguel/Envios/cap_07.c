
// EX 1 -- NO
// EX 2 -- OK
// EX 3 -- OK
// EX 4 -- OK

#define EX_0

#ifdef EX_1
#endif // EX_1
// ----------------------------------------



// ----------------------------------------
#ifdef EX_2
#include <stdio.h>

typedef struct {
    
    char nome[20];
    char end[6];
    char cidade[30];
    char estado[3];
    char cep[9];
} Cadastro;

Cadastro cadastros[4];

void clear_buffer() {
    
    while (getchar() != '\n');
    return;
}

void fill_form() {
    
    for (int i = 0; i < 4; i++) {
        
        printf("-------- Cadastro: Dados pessoais ---------\n");
        
        printf("Nome: ");
        scanf("%s", cadastros[i].nome);
        clear_buffer();
        
        printf("Número: ");
        scanf("%s", cadastros[i].end);
        clear_buffer();
        
        printf("Estado (sigla de duas letras): ");
        scanf("%s", cadastros[i].estado);
        clear_buffer();
        
        printf("Cidade: ");
        scanf("%s", cadastros[i].cidade);
        clear_buffer();
        
        printf("CEP (apenas números): ");
        scanf("%s", cadastros[i].cep);
        clear_buffer();
    }
    return;
}

void show_form() {
    
    for (int i = 0; i < 4; i++) {
        
        printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        printf("Nome: %s\n", cadastros[i].nome);
        printf("CEP: %s\n", cadastros[i].cep);
        printf("Estado: %s\n", cadastros[i].estado);
        printf("Cidade: %s\n", cadastros[i].cidade);
        printf("Número: %s\n", cadastros[i].end);
        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    }
}


int main() {
    
    char again = 'n';
    do {
        
        fill_form();
        show_form();
        
        // +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
        printf("Deseja executar novamente ( s / n )  ");
        scanf("%c", &again);
        clear_buffer();
    } while (again == 's');
    return 0;
}
#endif // EX_2
// ----------------------------------------



// ----------------------------------------
#ifdef EX_3
#include <stdio.h>

void clear_buffer() {
    
    while (getchar() != '\n');
    return;
}


typedef struct {
    
    int day;
    int month;
    int year;
} Date;


Date begin;
Date end;

int calculate_days_diff() {
    
    const int MONTH_DAYS[12] = {
        31, 28, 31,
        30, 31, 30,
        31, 31, 30,
        31, 30, 31
    };
    
    int delta_years = end.year - begin.year;
    int delta_months = end.month - begin.month;
    int delta_days = end.day  - begin.day;
    
    int total_days = delta_days;
    int leap_years = (delta_years / 4) - (delta_years / 100) + (delta_years / 400);
    
    for (int i = begin.month; i <= delta_months; i = (i + 1) % 12) {
        total_days += MONTH_DAYS[i];
    }
    
    total_days += (delta_years * 365);
    total_days += leap_years;
    return total_days;
}


int main() {
    
    char again = 'n';
    do {
        
        printf("Digite a data de início (exemplo: 23/09/2012):");
        scanf("%d/%d/%d", &begin.day, &begin.month, &begin.year);
        clear_buffer();
        
        printf("Digite a data de término (exemplo: 23/09/2012): ");
        scanf("%d/%d/%d", &end.day, &end.month, &end.year);
        clear_buffer();
        
        int total_days = calculate_days_diff();
        printf("A diferença entre as datas é de %d dias\n", total_days);
        // +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
        printf("Deseja executar novamente? ( s / n )  ");
        scanf("%c", &again);
        clear_buffer();
    } while (again == 's');
    return 0;
}
#endif // EX_3
// ----------------------------------------



// ----------------------------------------
#ifdef EX_4
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
#endif // EX_4