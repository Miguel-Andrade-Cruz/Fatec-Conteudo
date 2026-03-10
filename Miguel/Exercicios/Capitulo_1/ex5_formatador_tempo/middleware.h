#ifndef MIDDLEWARE_H
#define MIDDLEWARE_H


typedef struct {
    int hour;
    int minute;
    int second;
} ReadableTime;

int recieve_time();

void readable_time_conversion(int time_in_seconds, ReadableTime *readable_time);


#endif