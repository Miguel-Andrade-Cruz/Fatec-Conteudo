#include "middleware.h"


void clear_buffer() {

    while(getchar() != '\n');
    return;
}


int convert_timestamp_in_seconds(int hour, int minute, int second) {
    
    int instant_in_seconds = 0;
    
    instant_in_seconds += second;
    instant_in_seconds += minute * TIME_FACTOR;
    instant_in_seconds += hour * 60 * 60;
    return instant_in_seconds;
}


int ask_call_start() {
    
    int hour, minute, second;
    
    printf("Insira o horário que a chamada começou (use o formato HH:MM:SS):  ");
    scanf("%d:%d:%d", &hour, &minute, &second);
    clear_buffer();
    
    return convert_timestamp_in_seconds(hour, minute, second);
}


int ask_call_end() {
    
    int hour, minute, second;
    
    printf("Agora insira o horário que a chamada terminou (use o formato HH:MM:SS):  ");
    scanf("%d:%d:%d", &hour, &minute, &second);
    clear_buffer();
    
    return convert_timestamp_in_seconds(hour, minute, second);
}


int convert_hours(int d_time_seconds); {
    
    return d_time_seconds / (TIME_FACTOR * TIME_FACTOR);
}


int convert_minutes(int d_time_seconds) {
    
    return d_time_seconds / TIME_FACTOR;
}


int convert_seconds(int d_time_seconds) {
    
    int time_seconds;
    // get the remaining minutes
    time_seconds = d_time_seconds % (TIME_FACTOR * TIME_FACTOR);
    // get the remaining seconds
    time_seconds = time_seconds % TIME_FACTOR;
    return time_seconds;
}

void show_call_duration(int d_hour, int d_minute, int d_second) {
    
    printf("A sua chamada teve %d:%d:%d de duração", d_hour, d_minute, d_second);
    return;
}