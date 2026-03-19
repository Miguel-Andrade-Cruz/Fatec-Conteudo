// 5 - Escreva um programa que receba via teclado um tempo em segundos e converta
//      para horas, minutos e segundos.
//      Ex.: recebe 3850 segundos que converte para 1h 4min 10s.

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
