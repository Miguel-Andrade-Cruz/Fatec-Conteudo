#include "middleware.h"



void clean_buffer() {

    while(getchar() != '\n');
    return;
}

int ask_call_start(); // TODO: Declarar função
int ask_call_end(); // TODO: Declarar função

int convert_hours(int d_time_seconds); // TODO: Declarar função
int convert_minutes(int d_time_seconds); // TODO: Declarar função
int convert_seconds(int d_time_seconds); // TODO: Declarar função

void show_call_duration(int d_hour, int d_mimute, int d_second); // TODO: Declarar função