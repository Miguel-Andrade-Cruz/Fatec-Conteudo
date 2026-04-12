// 5 - Escreva um programa que receba via teclado um tempo em segundos e converta
//      para horas, minutos e segundos.
//      Ex.: recebe 3850 segundos que converte para 1h 4min 10s.

// #define OUTER_MODE
#define INNER_MODE


#ifdef OUTER_MODE
#include "middleware.h"

int main() {
    
    char again = 'n';
    do {
        ReadableTime readable_time;
        
        int time_in_seconds = recieve_time();
        readable_time_conversion(time_in_seconds, &readable_time);
        
        printf("O tempo inserido equivale a %dh %dmin %ds\n",
            readable_time.hour,
            readable_time.minute,
            readable_time.second
        );
        
        // +-+-+-+-+-+-+-+-+-+-+-+-+-+-+
        printf("Deseja executar novamente? ( s / n )  ");
        scanf("%c", &again);
        clear_buffer();
    } while (again == 's');
}
#endif // OUTER_MODE


#ifdef INNER_MODE
#include <stdio.h>

void clear_buffer() {
    
    while (getchar() != '\n');
    return;
}

int recieve_time() {
    
    int time_in_seconds;
    
    do {
        printf("Insira um tempo em segundos:\n");
        scanf("%d", &time_in_seconds);
        clear_buffer();
    } while (time_in_seconds < 0 || time_in_seconds > 5999940);
    return time_in_seconds;
}

const int BASE_60 = 60;

int main() {
    
    char again = 'n';
    do {
        int time = recieve_time();
        
        int seconds = time % BASE_60;
        time /= 60;
        
        int minutes = time % BASE_60;
        time /= BASE_60;
        
        int hours = time;
        
        printf("O tempo inserido equivale a %dh %dmin %ds\n",
            hours,
            minutes,
            seconds
        );
        
        // +-+-+-+-+-+-+-+-+-+-+-+-+-+-+
        printf("Deseja executar novamente? ( s / n )  ");
        scanf("%c", &again);
        clear_buffer();
    } while (again == 's');
}
#endif // INNER_MODE
