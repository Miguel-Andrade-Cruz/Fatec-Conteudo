// 2 - Escreva um programa que receba via teclado uma data (dia, mes, e ano).
//     Determine o dia da semana desta data.

// #define OUTER_MODE
#define INNER_MODE

#ifdef OUTER_MODE
#include "middleware.h"
int main() {

    char again = 'n';
    do {
        
        Date date_input;
        ask_date(&date_input);
        
        char weekday[8];
        resolve_weekday(date_input, weekday);
        
        show_weekday_date(date_input, weekday);
        
        // +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
        printf("Deseja executar novamente? (s / n)");
        scanf("%c", &again);
        clear_buffer();
    } while (again == 's');
    return 0;
}
#endif // OUTER_MODE



#ifdef INNER_MODE
#include <stdio.h>

void clear_buffer() {
    
    while (getchar() != '\n');
    return;
}

const char DAYS_OF_THE_WEEK[7][8] = {
    "Domingo",
    "Segunda",
    "Terça",
    "Quarta",
    "Quinta",
    "Sexta",
    "Sábado"
};

const int month_offset[] = {
    0, 3, 2, 
    5, 0, 3, 
    5, 1, 4, 
    6, 2, 4
};

const char article[4] = "uma";

int main() {
    
    
    char again = 'n';
    do {
        
        int day, month, year;
        printf("Insira a data que deseja no formato 00/00/0000  :");
        scanf("%d/%d/%d", &day, &month, &year);
        clear_buffer();
        
        int v_year = year;
        
        char weekday[8];
        if ( month < 3) {
            v_year = year - 1;
        }
        int leap_years = (v_year / 4) - (v_year / 100) + (v_year / 400);
        
        // 'dow' means 'day of week'
        int dow_index = (year + leap_years + month_offset[month - 1] + day) % 7;
        
        
        for (int i = 0; i < 8; i++) {
            weekday[i] = DAYS_OF_THE_WEEK[dow_index][i];
        }
        
        int article_limit = 2;
        if (!(dow_index == 0) && !(dow_index == 6)) {
            article_limit++;
        }
        
        printf(
            "O dia %.2d/%.2d/%.4d foi %.*s %s\n",
            day, month, year, article_limit, article, weekday
        );
        
        // +-+-+-+-+-+-+-+-+-+-+
        printf("Deseja executar novamente ( s / n )  ");
        scanf("%c", &again);
        clear_buffer();
    } while (getchar() != 's');
    return 0;
}
#endif // INNER_MODE
