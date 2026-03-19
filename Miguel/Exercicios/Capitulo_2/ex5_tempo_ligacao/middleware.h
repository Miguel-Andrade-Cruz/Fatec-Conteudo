#include <stdio.h>


#define TIME_FACTOR 60

void clear_buffer();

int ask_call_start();
int ask_call_end();

int convert_hours(int d_time_seconds);
int convert_minutes(int d_time_seconds);
int convert_seconds(int d_time_seconds);

void show_call_duration(int d_hour, int d_mimute, int d_second);