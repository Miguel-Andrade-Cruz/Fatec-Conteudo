// 1 - Escreva um programa para receber via teclado em vetores 3 int, 3 long,
//    3 unsigned, 3 float e 3 double e imprima-os no video no seguinte formato:
//
//          10        20        30        40        50
//    12345678901234567890123456789012345678901234567890
//      int                 long                unsigned
//                float               double
//      int                 long                unsigned
//                float               double
//      int                 long                unsigned
//                float               double


// ----------------------------------
#define INNER_MODE              // |
// #define OUTER_MODE               // |
// ----------------------------------


#ifdef OUTER_MODE
#include "middleware.h"

int main() {
    
    char again = 'n';
    do {
        
        int vec_int[3];
        float vec_float[3];
        unsigned vec_unsigned[3];
        long vec_long[3];
        double vec_double[3];
        
        ask_for_ints(vec_int, "inteiro");
        ask_for_floats(vec_float, "decimal");
        ask_for_unsigneds(vec_unsigned, "inteiro positivo");
        ask_for_longs(vec_long, "inteiro grande");
        ask_for_doubles(vec_double, "com muitas casas decimais");
        
        print_formatted(
            vec_int,
            vec_float,
            vec_unsigned,
            vec_long,
            vec_double
        );
        
        // +-+-+-+-+-+-+-+-+-+-+-+-+
        printf("Deseja executar novamente ( s / n )  ");
        scanf("%c", &again);
        clear_buffer();
    } while (again == 's');
    return 0;
}
#endif // OUTER_MODE



#ifdef INNER_MODE
#include <stdio.h>

void clear_buffer() {
    
    while (getchar() != '\n');
    return;
}

const int one_to_zero = 1234567890;

const int TEN = 10;
const int TWENY = 20;
const int THIRTY = 30;
const int FORTY = 40;
const int FIFTY = 50;


int vec_int[3];
float vec_float[3];
unsigned vec_unsigned[3];
long vec_long[3];
double vec_double[3];


int main() {
    
    char again = 'n';
    do {
        
        // Request user input ------ <
        printf("Insira quatro tipos de número:\n");
        for (int i = 0; i < 3; i++) {
            
            printf("Rodada %d\n\n", i + 1);
            
            printf("Número inteiro -->> ");
            scanf("%d", &vec_int[i]);
            clear_buffer();
            
            printf("Número decimal -->> ");
            scanf("%f", &vec_float[i]);
            clear_buffer();
            
            printf("Número inteiro positivo -->> ");
            scanf("%ui", &vec_unsigned[i]);
            clear_buffer();
            
            printf("Número inteiro muito grande -->> ");
            scanf("%li", &vec_long[i]);
            clear_buffer();
            
            printf("Número com muitas casas decimais -->> ");
            scanf("%lf", &vec_double[i]);
            clear_buffer();
        }
        // ------------ >
        
        // print formatting ------ <
        printf("%10d%8d%8d%8d%8d\n",
            TEN, TWENY, THIRTY, FORTY, FIFTY
        );
        printf("%4d%d%d%d%d\n",
            one_to_zero, one_to_zero,
            one_to_zero, one_to_zero,
            one_to_zero
        );
        
        for (int i = 0; i < 3; i++) {
            
            printf("%6d%17li%16u\n",
                vec_int[i], vec_long[i], vec_unsigned[i]
            );
            printf("%16f%15lf\n",
                vec_float[i], vec_double[i]
            );
        }
        // ------------ >
        
        // +-+-+-+-+-+-+-+-+-+-+-+-+
        printf("Deseja executar novamente ( s / n )  ");
        scanf("%c", &again);
        clear_buffer();
    } while (again == 's');
    return 0;
}
#endif // INNER_MODE
