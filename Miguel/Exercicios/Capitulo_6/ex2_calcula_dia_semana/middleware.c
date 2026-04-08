#include "middleware.h"
#include <stdio.h>
#include <string.h>


const char DAYS_OF_THE_WEEK[7][8] = {
    "Domingo",
    "Segunda",
    "Terça",
    "Quarta",
    "Quinta",
    "Sexta",
    "Sábado"
};


void clear_buffer() {
    
    while (getchar() != '\n');
    return;
}


void ask_date(Date *date) {
    
    printf("Insira a data que deseja no formato 00/00/0000  :");
    scanf("%d/%d/%d", &date->day, &date->month, &date->year);
    clear_buffer();
    return;
}


void resolve_weekday(Date date, char *weekday){
    
    int month_offset[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    if ( date.month < 3 ) {
        date.year -= 1;
    }
    int y = date.year;
    int m = date.month;
    int d = date.day;
    
    int leap_years = y/4 - y/100 + y/400;
    
    // 'dow' means 'day of week'
    int dow_index = (y + leap_years + month_offset[m-1] + d) % 7;
    
    strcpy(weekday, DAYS_OF_THE_WEEK[dow_index]);
}


void show_weekday_date(Date date, char *weekday) {
    
    char article[4] = "uma";
    if ( strcmp(weekday, "Sábado") == 0 || strcmp(weekday, "Domingo") == 0 ) {
        strcpy(article, "um");
    }
    printf(
        "O dia %d/%d/%d foi %s %s\n",
        date.day, date.month, date.year, article, weekday
    );
    return;
}
