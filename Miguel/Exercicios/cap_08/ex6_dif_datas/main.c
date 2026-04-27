
// 6 - Escreva um programa com a estrutura abaixo. Receba 2 datas via teclado 
//     usando ponteiros. Calcule e exiba o numero de dias entre as duas datas
//     usando ponteiros. Utilize um vetor de estruturas declarado como variavel 
//     global.
//     	estrutura: dia, mes e ano


#include <stdio.h>
#define INNER_MODE
// #define OUTER_MODE


#ifdef INNER_MODE

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
#endif // INNER_MODE



#ifdef OUTER_MODE
#endif // OUTER_MODE