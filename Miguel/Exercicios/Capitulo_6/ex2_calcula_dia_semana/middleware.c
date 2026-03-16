#include "middleware.h"
#include <stdio.h>
#include <string.h>

#define DEBUG


void clear_buffer() {

    while (getchar() != '\n');
    return;
}

void ask_date(int *day, int *month, int *year) {
    
    printf("Insira a data que deseja no formato 00/00/0000  :");
    scanf("%d/%d/%d", day, month, year);
    clear_buffer();
    
    #ifdef DEBUG
    printf("DIA: %d | MÊS: %d | ANO: %d\n\n", *day, *month, *year);
    #endif
    return;
}

int leap_year_check(int year) {
    
    int is_leap_year = 0;
    if ( ( year % 4 == 0 && year % 100 != 0 ) || year % 400 == 0 ) {
        is_leap_year = 1;
    }
    
    return is_leap_year;
}

int calculate_total_leap_years(int year) {
    
    const int YEAR_STARTING_POINT = 1583;
    int total_leap_years = 0;
    
    for (int i_year = YEAR_STARTING_POINT; i_year < year - 1; i_year++) {
        
        if (leap_year_check(i_year) == 1) {
            total_leap_years++;
        }
    }
    
    #ifdef DEBUG
    printf("TOTAL ANOS BISSEXTOS: %d\n\n", total_leap_years);
    #endif
    return total_leap_years;
}

int get_days_since_start_point(int day, int month, int year, int is_leap_year, int total_leap_years) {
    
    const int YEAR_STARTING_POINT = 1583;
    int DAYS_ON_A_YEAR = 365;
    int DAYS_ON_MONTHS[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    
    int total_days = 0;
    
    // get the days for passed years
    total_days = (year - YEAR_STARTING_POINT) * DAYS_ON_A_YEAR;
    
    #ifdef DEBUG
    printf("TOTAL DE DIAS (SEM CONTAR BISSEXTOS): %d\n\n", total_days);
    #endif
    
    // get the days for remaining months
    for (int i_month = 0; i_month < month - 1; i_month++) {
        total_days += DAYS_ON_MONTHS[i_month];
    }
    
    #ifdef DEBUG
    printf("TOTAL DE DIAS (SEM CONTAR BISSEXTOS) (CONTANDO COM OS MESES): %d\n\n", total_days);
    #endif
    
    // add the remaining days
    total_days += day;
    
    #ifdef DEBUG
    printf("TOTAL DE DIAS (SEM CONTAR BISSEXTOS) (CONTANDO COM OS MESES) (CONTANDO COM DIAS): %d\n\n", total_days);
    #endif
    
    // account for leap_years
    total_days += total_leap_years;
    total_days += (is_leap_year == 1) ? 1 : 0;
    
    #ifdef DEBUG
    printf("TOTAL DE DIAS (CONTANDO BISSEXTOS) (CONTANDO COM OS MESES) (CONTANDO COM DIAS): %d\n\n", total_days);
    #endif
    
    return total_days;
}

void resolve_weekday(int days_since_start_point, char *weekday){
    
    const int DAYS_ON_A_WEEK = 7;
    const char DAYS_OF_THE_WEEK[7][8] = {
        "Sábado",
        "Domingo",
        "Segunda",
        "Terça",
        "Quarta",
        "Quinta",
        "Sexta"
    };
    int remainder = days_since_start_point % DAYS_ON_A_WEEK;
    
    strcpy(weekday, DAYS_OF_THE_WEEK[remainder]);
}

void show_weekday_date(int day, int month, int year, char *weekday) {
    
    char article[4] = "uma";
    if ( strcmp(weekday, "Sábado") == 0 || strcmp(weekday, "Domingo") == 0 ) {
        strcpy(article, "um");
    }
    printf("O dia %d/%d/%d foi %s %s.\n", day, month, year, article, weekday);
    
    return;
}