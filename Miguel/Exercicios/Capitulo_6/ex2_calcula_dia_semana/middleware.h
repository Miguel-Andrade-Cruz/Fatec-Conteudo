#include <stdio.h>
#include <string.h>

void clear_buffer();


typedef struct {
    
    int day;
    int month;
    int year;
} Date;



void ask_date(Date *date);

void resolve_weekday(Date date, char *weekday);

void show_weekday_date(Date date, char *weekday);
