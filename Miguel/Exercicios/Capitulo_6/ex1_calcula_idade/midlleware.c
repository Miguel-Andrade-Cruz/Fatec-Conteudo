#include "middleware.h"


void clear_buffer() {
    
    while (getchar() == '\n');
    return;
}

int ask_birth_date(); // TODO: Desenvolver função

int ask_now_date(); // TODO: Desenvolver função

void convert_to_date_format(int total_days, int *day, int *month, int *year); // TODO: Desenvolver função

void show_person_age(int age_day, int age_month, int age_year); // TODO: Desenvolver função