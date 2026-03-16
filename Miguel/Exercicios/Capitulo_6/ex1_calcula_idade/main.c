// 1 - Escreva um programa para determinar a idade de uma pessoa, em anos, meses e
//    dias, recebendo via teclado a data (dia, mes e ano) do seu nascimento e a
//    data (dia, mes e ano) atual.

#include "middleware.h"


int main() {

    char again = 'n';
    do {
        int age_day, age_month, age_year;
    
        int birth_date_in_days = ask_birth_date();
        int now_date_in_days = ask_now_date();
        
        int person_age_in_days = birth_date_in_days - now_date_in_days;
        convert_to_date_format(person_age_in_days, &age_day, &age_month, &age_year);
        
        show_person_age(age_day, age_month, age_year);
        
        // +-+-+-+-+-+-+-+-+-+-+-
        printf("Deseja executar nomvaente? ( s / n)  ");
        scanf("%c", &again);
        clear_buffer();
    } while (again == 's');
    return 0;
}