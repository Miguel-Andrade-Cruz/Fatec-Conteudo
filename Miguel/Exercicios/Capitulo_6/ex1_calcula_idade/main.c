// 1 - Escreva um programa para determinar a idade de uma pessoa, em anos, meses e
//    dias, recebendo via teclado a data (dia, mes e ano) do seu nascimento e a
//    data (dia, mes e ano) atual.

#include "middleware.h"
// #define INNER_MODE
#define OUTER_MODE


#ifdef OUTER_MODE
int main() {

    char again = 'n';
    do {
        
        Date birth = ask_birth_date();
        Date now = ask_now_date();
        
        Date age = calculate_age(now, birth);
        
        show_person_age(age);
        
        // +-+-+-+-+-+-+-+-+-+-+-
        printf("Deseja executar nomvaente? ( s / n )  ");
        scanf("%c", &again);
        clear_buffer();
    } while (again == 's');
    return 0;
}
#endif

#ifdef INNER_MODE
int main() {

    char again = 'n';
    do {
        int age_day, age_month, age_year;
        
        
        
        // +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
        printf("Deseja executar novamente? ( s / n )  ");
        scanf("%c", &again);
        clear_buffer();
    } while (again == 's');
    return 0;
}
#endif