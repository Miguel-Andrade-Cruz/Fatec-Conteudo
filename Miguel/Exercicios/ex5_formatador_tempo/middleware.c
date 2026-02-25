#include <stdio.h>
#include "middleware.h"

#define DEBUG


int recieve_time() {

    int time_in_seconds;

    do {
        printf("Insira um tempo em segundos:\n");
        scanf("%d", &time_in_seconds);
    } while (time_in_seconds < 0 || time_in_seconds > 5999940);
    return time_in_seconds;
}



void readable_time_conversion(int time_in_seconds, ReadableTime *readable_time) {

    const int BASE_60 = 60;
    const int TIMESTAMP_LENGHT = 3;

    int timestamp[3];
    int seconds_index = 0;
    int minutes_index = 1;
    int hours_index = 2;
    
    // splitting into minutes
    timestamp[seconds_index] = time_in_seconds % BASE_60;
    timestamp[minutes_index] = time_in_seconds / BASE_60;

    #ifdef DEBUG
    printf("DEBUG: %d seconds passed, formatted to %d minutes and %d seconds\n",
        time_in_seconds,
        timestamp[minutes_index],
        timestamp[seconds_index]
    );
    #endif


    // splitting into hours
    int reserved_minutes = timestamp[minutes_index];
    timestamp[minutes_index] = reserved_minutes % BASE_60;
    timestamp[hours_index] = reserved_minutes / BASE_60;

    #ifdef DEBUG
    printf("DEBUG: %d seconds passed, formatted to %d hours, %d minutes and %d seconds\n",
        time_in_seconds,
        timestamp[hours_index],
        timestamp[minutes_index],
        timestamp[seconds_index]
    );
    #endif


    readable_time->hour = timestamp[hours_index];
    readable_time->minute = timestamp[minutes_index];
    readable_time->second = timestamp[seconds_index];
    
    return;
}
