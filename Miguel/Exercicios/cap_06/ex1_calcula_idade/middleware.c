#include "middleware.h"
#include <string.h>

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


Date ask_date(char *msg) {
    
    Date birth;
    
    printf("%s\n", msg);
    printf("-->>  ");
    scanf("%d/%d/%d", &birth.day, &birth.month, &birth.year);
    clear_buffer();
    return birth;
}


Date ask_now_date(char *msg) {
    
    Date now;
    
    printf("%s\n", msg);
    printf("-->>  ");
    scanf("%d/%d/%d", &now.day, &now.month, &now.year);
    clear_buffer();
    return now;
}


int is_leap_year(int year) {
    
    return ( (year % 4 == 0 && year % 100 != 0) || year % 400 == 0 );
}

int get_leap_years_from_date(Date date) {
    
    int leap_years;
    if (date.month <= 2) {
        date.year -= 1;
    }
    
    leap_years = date.year / 4;
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


int calculate_total_days(Date date) {
    
    int total_days = (date.year * YEAR_DAYS) + date.day;
    
    for (int i = 0; i < date.month -1; i++) {
        total_days += MONTH_DAYS[i];
    }
    
    total_days += get_leap_years_from_date(date);
    return total_days;
}


Date convert_to_date_format(int date_on_days_format) {
    
    Date date;
    
    int total_leap_years = get_leap_years_from_days(date_on_days_format);
    
    date_on_days_format -= total_leap_years;
    
    int year = date_on_days_format / YEAR_DAYS;
    int remaining_days = date_on_days_format % YEAR_DAYS;
    
    int i = 0, month = 0;
    while (remaining_days > MONTH_DAYS[i]) {
        remaining_days -= MONTH_DAYS[i];
        month++; i++;
    }
    int day = remaining_days;
    
    date.year = year;
    date.month = month;
    date.day = ( is_leap_year(year) ) ? day + 1 : day;
    return date;
}


Date calculate_age(Date now, Date birth) {
    
    int now_on_days_format = calculate_total_days(now);
    int birth_on_days_format = calculate_total_days(birth);
    int age_on_days_format = now_on_days_format - birth_on_days_format;

    Date age = convert_to_date_format(age_on_days_format);
    return age;
}


void show_person_age(Date age) {
    
    char year_correct_numeral[5];
    (age.year > 1) ?
        strcpy(year_correct_numeral, "anos")
        :
        strcpy(year_correct_numeral, "ano");
        
    char month_correct_numeral[6];
    (age.month > 1) ?
        strcpy(month_correct_numeral, "meses")
        :
        strcpy(month_correct_numeral, "mês");

    char day_correct_numeral[5];
    (age.day > 1) ?
        strcpy(day_correct_numeral, "dias")
        :
        strcpy(day_correct_numeral, "dia");
    
    printf("A pessoa tem %d %s, %d %s e %d %s\n", 
        age.year, year_correct_numeral,
        age.month, month_correct_numeral,
        age.day, day_correct_numeral
    );
    return;
}
