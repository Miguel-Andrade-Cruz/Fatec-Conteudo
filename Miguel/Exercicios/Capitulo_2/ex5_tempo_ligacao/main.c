// 5 - As ligacoes telefonicas sao cobradas pela sua duracao. O sistema registra os
//    instantes em que a ligacao foi iniciada e concluida.
//    Escreva um programa que recebe via teclado dois instantes dados em
//    horas, minutos e segundo e determina o intervalo de tempo
//    (em horas, minutos e segundos) decorrido entre eles.


#define INNER_MODE
// #define OUTER_MODE



#ifdef OUTER_MODE
#include "middleware.h"

int main() {
    
    char again = 'n';
    do {
        // <s> means start
        // <e> means end
        // <d> means delta
        
        int d_hour, d_minute, d_second;
        
        int d_time_seconds;
        int s_time_seconds = ask_call_start();
        int e_time_seconds = ask_call_end();
        
        d_time_seconds = e_time_seconds - s_time_seconds;
        
        d_hour = convert_hours(d_time_seconds);
        d_minute = convert_minutes(d_time_seconds);
        d_second = convert_seconds(d_time_seconds);
        
        show_call_duration(d_hour, d_minute, d_second);
        
        
        // +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
        printf("Deseja executar novamente? ( s / n )  ");
        scanf("%c", &again);
        clear_buffer();
    } while (again == 's');
    return 0;
}
#endif // OUTER_MODE



#ifdef INNER_MODE
#include <stdio.h>
#define TIME_FACTOR 60

void clear_buffer() {

    while(getchar() != '\n');
    return;
}

int convert_in_seconds(int hour, int minute, int second) {
    
    int in_seconds = 0;
    
    in_seconds += second;
    in_seconds += minute * TIME_FACTOR;
    in_seconds += hour * (TIME_FACTOR * TIME_FACTOR);
    
    return in_seconds;
}

int ask_call_start() {
    
    int hour, minute, second;
    
    printf("Insira o horário que a chamada começou (use o formato HH:MM:SS):  ");
    scanf("%d:%d:%d", &hour, &minute, &second);
    clear_buffer();
    
    return convert_in_seconds(hour, minute, second);
}

int ask_call_end() {
    
    int hour, minute, second;
    
    printf("Agora insira o horário que a chamada terminou (use o formato HH:MM:SS):  ");
    scanf("%d:%d:%d", &hour, &minute, &second);
    clear_buffer();
    
    return convert_in_seconds(hour, minute, second);
}

int convert_hours(int in_seconds) {
    
    int extracted_hours = in_seconds / (TIME_FACTOR * TIME_FACTOR);
    
    return extracted_hours;
}

int convert_minutes(int in_seconds) {
    
    // discard the hours already counted;
    int seconds_without_hours = in_seconds % (TIME_FACTOR * TIME_FACTOR);
    
    int extracted_minutes = seconds_without_hours / TIME_FACTOR;
    
    return extracted_minutes;
}

int convert_seconds(int in_seconds) {
    
    int extracted_seconds = in_seconds % (TIME_FACTOR * TIME_FACTOR) % TIME_FACTOR;
    
    return extracted_seconds;
}



void show_call_duration(int d_hour, int d_minute, int d_second) {
    
    printf("A sua chamada teve %0.2d:%0.2d:%0.2d de duração", d_hour, d_minute, d_second);
    return;
}

int main() {
    
    char again = 'n';
    do {
        
        // <s> means start
        // <e> means end
        // <d> means delta
        
        int d_hour, d_minute, d_second;
        
        int d_time_seconds;
        int s_time_seconds = ask_call_start();
        int e_time_seconds = ask_call_end();
        
        d_time_seconds = e_time_seconds - s_time_seconds;
        
        d_hour = convert_hours(d_time_seconds);
        d_minute = convert_minutes(d_time_seconds);
        d_second = convert_seconds(d_time_seconds);
        
        show_call_duration(d_hour, d_minute, d_second);
        
        // +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
        printf("Deseja executar novamente? ( s / n )  ");
        scanf("%c", &again);
        clear_buffer();
    } while (again == 's');
    return 0;
}
#endif // INNER_MODE
