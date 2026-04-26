#include "middleware.h"


// #define DEBUG

void clear_buffer() {

    while(getchar() != '\n');
    return;
}


int convert_timestamp_in_seconds(int hour, int minute, int second) {
    
    int instant_in_seconds = 0;
    
    instant_in_seconds += second;
    instant_in_seconds += minute * TIME_FACTOR;
    instant_in_seconds += hour * (TIME_FACTOR * TIME_FACTOR);
    
    #ifdef DEBUG
    printf("INSTANT EXPRESSED IN SECONDS: %d\n\n", instant_in_seconds);
    #endif
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


int convert_hours(int d_time_seconds) {
    
    int extracted_hours = d_time_seconds / (TIME_FACTOR * TIME_FACTOR);
    
    #ifdef DEBUG
    printf("EXTRACTED HOURS FROM SECONDS INSTANT: %d\n", extracted_hours);
    #endif
    return extracted_hours;
}


int convert_minutes(int d_time_seconds) {
    
    // disard the hours already counted;
    int d_time_seconds_without_hours = d_time_seconds % (TIME_FACTOR * TIME_FACTOR);
    
    int extracted_minutes = d_time_seconds_without_hours / TIME_FACTOR;
    
    #ifdef DEBUG
    printf("EXTRACTED MINUTES FROM SECONDS INSTANT: %d\n", extracted_minutes);
    #endif
    return extracted_minutes;
}


int convert_seconds(int d_time_seconds) {
    
    int extracted_seconds = d_time_seconds % (TIME_FACTOR * TIME_FACTOR) % TIME_FACTOR;
    
    #ifdef DEBUG
    printf("SECONDS EXTRACTED FROM CALL TIME: %d\n", extracted_seconds);
    #endif
    return extracted_seconds;
}

void show_call_duration(int d_hour, int d_minute, int d_second) {
    
    printf("A sua chamada teve %0.2d:%0.2d:%0.2d de duração", d_hour, d_minute, d_second);
    return;
}
