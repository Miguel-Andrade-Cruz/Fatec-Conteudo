#define EX_0


#ifdef EX_1
#endif // EX_1
// --------------------------------



// --------------------------------
#ifdef EX_2
#endif // EX_2
// --------------------------------



// --------------------------------
#ifdef EX_3
#include <stdio.h>

void clear_buffer() {
    
    while (getchar() != '\n');
    return;
}

int strequal(char *str1, char *str2) {
    
    int is_equal = 0;
    int i = 0;
    while (
        str1[i] == str2[i] &&
        str1[i] != '\0' &&
        str2[i] != '\0'
    ) {
        i++;
    }
    if ( str1[i] == '\0' && str2[i] == '\0' ) {
        is_equal = 1;
    }
    return is_equal;
}


char str1[10], str2[10];

int main() {
    
    char again = 'n';
    do {
        
        printf("Insira a primeira string:  ");
        scanf("%s", str1);
        clear_buffer();
        
        printf("Insira a segunda string:  ");
        scanf("%s", str2);
        clear_buffer();
        
        int is_equal = strequal(str1, str2);
        
        if (is_equal) {
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
#endif // EX_3
// --------------------------------



// --------------------------------
#ifdef EX_4
#endif // EX_4
// --------------------------------



// --------------------------------
#ifdef EX_5
#include <stdio.h>

typedef struct {
    
    char nome[20];
    char end[6];
    char cidade[30];
    char estado[3];
    char cep[9];
} Form;

Form forms[4];

void clear_buffer() {
    
    while (getchar() != '\n');
    return;
}

void fill_form() {
    
    for (int i = 0; i < 4; i++) {
        
        Form *cur_form = &forms[i];
        
        printf("-------- Cadastro: Dados pessoais ---------\n");
        
        printf("Nome: ");
        scanf("%s", cur_form->nome);
        clear_buffer();
        
        printf("Número: ");
        scanf("%s", cur_form->end);
        clear_buffer();
        
        printf("Estado (sigla de duas letras): ");
        scanf("%s", cur_form->estado);
        clear_buffer();
        
        printf("Cidade: ");
        scanf("%s", cur_form->cidade);
        clear_buffer();
        
        printf("CEP (apenas números): ");
        scanf("%s", cur_form->cep);
        clear_buffer();
    }
    return;
}

void show_form() {
    
    for (int i = 0; i < 4; i++) {
        
        Form *cur_form = &forms[i];
        
        printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        printf("Nome: %s\n", cur_form->nome);
        printf("CEP: %s\n", cur_form->cep);
        printf("Estado: %s\n", cur_form->estado);
        printf("Cidade: %s\n", cur_form->cidade);
        printf("Número: %s\n", cur_form->end);
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
#endif // EX_5
// --------------------------------


// --------------------------------
#ifdef EX_6
void clear_buffer() {
    
    while (getchar() != '\n');
    return;
}

typedef struct {
    
    int day;
    int month;
    int year;
} Date;

Date dates[2];

int calculate_days_diff() {
    
    Date *begin = &dates[0];
    Date *end = &dates[1];
    
    const int MONTH_DAYS[12] = {
        31, 28, 31,
        30, 31, 30,
        31, 31, 30,
        31, 30, 31
    };
    
    int delta_years = end->year - begin->year;
    int delta_months = end->month - begin->month;
    int delta_days = end->day  - begin->day;
    
    int total_days = delta_days;
    int leap_years = (delta_years / 4) - (delta_years / 100) + (delta_years / 400);
    
    for (int i = begin->month; i <= delta_months; i = (i + 1) % 12) {
        total_days += MONTH_DAYS[i];
    }
    
    total_days += (delta_years * 365);
    total_days += leap_years;
    return total_days;
}

int main() {
    
    char again = 'n';
    do {
        
        Date *begin = &dates[0];
        Date *end = &dates[1];
        printf("Digite a data de início (exemplo: 23/09/2012):");
        scanf("%d/%d/%d", &begin->day, &begin->month, &begin->year);
        clear_buffer();
        
        printf("Digite a data de término (exemplo: 23/09/2012): ");
        scanf("%d/%d/%d", &end->day, &end->month, &end->year);
        clear_buffer();
        
        int total_days = calculate_days_diff();
        printf("A diferença entre as datas é de %d dias\n", total_days);
        
        // +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
        printf("Deseja executar novamente ( s / n )  ");
        scanf("%c", &again);
        clear_buffer();
    } while (again == 's');
    return 0;
}
#endif // EX_6