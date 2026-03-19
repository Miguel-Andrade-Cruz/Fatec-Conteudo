// 5 - As ligacoes telefonicas sao cobradas pela sua duracao. O sistema registra os
//    instantes em que a ligacao foi iniciada e concluida.
//    Escreva um programa que recebe via teclado dois instantes dados em
//    horas, minutos e segundo e determina o intervalo de tempo
//    (em horas, minutos e segundos) decorrido entre eles.


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

        d_time_seconds = s_time_seconds - e_time_seconds;

        d_hour = convert_hours(d_time_seconds);
        d_minute = convert_minutes(d_time_seconds);
        d_second = convert_seconds(d_time_seconds);

        show_call_duration(d_hour, d_minute, d_second);


        // +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
        printf("Deseja executar novamente? ");
        scanf("%c", &again);
        clear_buffer();
    } while (again == 's');



    return 0;
}