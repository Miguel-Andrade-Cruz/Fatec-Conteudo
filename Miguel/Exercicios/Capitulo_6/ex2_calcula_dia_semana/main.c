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


int main() {
    
    
    char again = 'n';
    do {
        
        // +-+-+-+-+-+-+-+-+-+-+
        printf("Deseja executar novamente ( s / n )  ");
        scanf("%c", &again);
        clear_buffer();
    } while (getchar() != '\n');
    return 0;
}
#endif // INNER_MODE
