// 2 - Escreva um programa que receba via teclado uma data (dia, mes, e ano).
//     Determine o dia da semana desta data.


#include "middleware.h"


int main() {

    char again = 'n';
    do {
        char weekday[8];
        int day, month, year;
        ask_date(&day, &month, &year);
        
        int is_leap_year = leap_year_check(year);
        int total_leap_years = calculate_total_leap_years(year);
        int total_days = get_days_since_start_point(day, month, year, is_leap_year, total_leap_years);
        
        resolve_weekday(total_days, weekday);
        show_weekday_date(day, month, year, weekday);
        // +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
        printf("Deseja executar novamente? (s / n)");
        scanf("%c", &again);
        clear_buffer();
    } while (again == 's');
    return 0;
}