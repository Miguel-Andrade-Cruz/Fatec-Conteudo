// 1 - Escreva um programa para determinar a idade de uma pessoa, em anos, meses e
//    dias, recebendo via teclado a data (dia, mes e ano) do seu nascimento e a
//    data (dia, mes e ano) atual.

#define INNER_MODE
// #define OUTER_MODE


#ifdef OUTER_MODE
#include "middleware.h"
int main() {

    char again = 'n';
    do {
        
        Date birth = ask_date("Digite a data de nascimento no formato 00/00/0000");
        Date now = ask_date("Digite a data de hoje no formato 00/00/0000");
        
        Date age = calculate_age(now, birth);
        
        show_person_age(age);
        
        // +-+-+-+-+-+-+-+-+-+-+-
        printf("Deseja executar nomvaente? ( s / n )  ");
        scanf("%c", &again);
        clear_buffer();
    } while (again == 's');
    return 0;
}
#endif

#ifdef INNER_MODE
#include <stdio.h>

const char year_str[5] = "anos";
const char month_str[6] = "meses";
const char days_str[5] = "dias";

const int YEAR_DAYS = 365;
const int MONTH_DAYS[12] = {
    31, 28, 31,
    30, 31, 30,
    31, 31, 30,
    31, 30, 31
};


void clear_buffer() {
    
    while (getchar() != '\n');
    return;
}


int is_leap_year(int year) {
    
    return ( (year % 4 == 0 && year % 100 != 0) || year % 400 == 0 );
}


int get_leap_years_from_date(int day, int month, int year) {
    
    int leap_years;
    if (month <= 2) {
        year -= 1;
    }
    
    leap_years = year / 4;
    leap_years -= leap_years / 100;
    leap_years += leap_years / 400;
    return leap_years;
}


int get_leap_years_from_days(int days) {
    
    int leap_years = (days / 365);
    
    leap_years = leap_years / 4;
    leap_years += leap_years/ 400;
    leap_years -= leap_years / 100;
    return leap_years;
}


int calculate_total_days(int day, int month, int year) {
    
    int total_days = (year * YEAR_DAYS) + day;
    
    for (int i = 0; i < month -1; i++) {
        total_days += MONTH_DAYS[i];
    }
    
    total_days += get_leap_years_from_date(day, month, year);
    return total_days;
}

void show_person_age(int day, int month, int year) {
    
    int year_str_bound = 5;
    if (year == 1) {
        year_str_bound--;
    }
    
    int month_str_bound = 6;
    if (month == 1) {
        month_str_bound -= 2;
    }
    
    int day_str_bound = 5;
    if (day == 1) {
        day_str_bound--;
    }
    
    printf("A pessoa tem %d %.*s, %d %.*s e %d %.*s\n", 
         year, year_str_bound, year_str,
        month, month_str_bound, month_str,
        day, day_str_bound, days_str
    );
    return;
}


int main() {

    char again = 'n';
    do {
        // request user input ------ <
        int birth_day, birth_month, birth_year;
        int age_day, age_month, age_year;
        int now_day, now_month, now_year;
        
        printf("Digite a data de nascimento no formato 00/00/0000\n");
        printf("-->>  ");
        scanf("%d/%d/%d", &birth_day, &birth_month, &birth_year);
        clear_buffer();
        
        printf("Digite a data de hoje no formato 00/00/0000\n");
        printf("-->>  ");
        scanf("%d/%d/%d", &now_day, &now_month, &now_year);
        clear_buffer();
        // ------------ >
        
        // get differnce in days ------ <
        int birth_on_days_format = calculate_total_days( birth_day, birth_month, birth_year);
        int now_on_days_format = calculate_total_days( now_day, now_month, now_year);
        int age_on_days_format = now_on_days_format - birth_on_days_format;
        // ------------ >
        
        // convert difference to date format ------ <
        int total_leap_years = get_leap_years_from_days(age_on_days_format);
        
        age_on_days_format -= total_leap_years;
        
        int year = age_on_days_format / YEAR_DAYS;
        int remaining_days = age_on_days_format % YEAR_DAYS;
        
        int i = 0, month = 0;
        while (remaining_days > MONTH_DAYS[i]) {
            remaining_days -= MONTH_DAYS[i];
            month++; i++;
        }
        int day = remaining_days;
        
        age_year = year;
        age_month = month;
        age_day = ( is_leap_year(year) ) ? day + 1 : day;
        // ------------ >
        
        show_person_age(day, month, year);
        
        // +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
        printf("Deseja executar novamente? ( s / n )  ");
        scanf("%c", &again);
        clear_buffer();
    } while (again == 's');
    return 0;
}
#endif // INNER_MODE
