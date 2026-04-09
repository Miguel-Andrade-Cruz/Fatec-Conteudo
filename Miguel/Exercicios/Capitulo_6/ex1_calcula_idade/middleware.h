#include <stdio.h>
#include <string.h>


typedef struct {
    
    int day;
    int month;
    int year;
} Date;

void clear_buffer();

Date ask_date(char *msg);

Date convert_to_date_format(int date_on_days_format);

Date calculate_age(Date now, Date birth);

void show_person_age(Date age);
