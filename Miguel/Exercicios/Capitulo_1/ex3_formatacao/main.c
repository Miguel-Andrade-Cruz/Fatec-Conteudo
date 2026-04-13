// 3 - Escreva um programa que receba dados via teclado para variaveis do tipo short,
//      long, int, float, double e um char e imprima-os no video no seguinte
//      formato:

//              10        20        30        40        50        60
//      12345678901234567890123456789012345678901234567890123456789012345
//          short               long                int
//                    float               double              char

#define INNER_MODE

#ifdef INNER_MODE
#include <stdio.h>


void clear_buffer() {
    
    while (getchar() != '\n');
    return;
}

short ask_short() {
    
    short num_short;
    printf("Número tipo short:  ");
    scanf("%hd", &num_short);
    clear_buffer();
    return num_short;
}

float ask_float() {
    
    float num_float;
    printf("Número float:   ");
    scanf("%f", &num_float);
    clear_buffer();
    return num_float;
}

long ask_long() {
    long num_long;
    printf("Número long:   ");
    scanf("%ld", &num_long);
    clear_buffer();
    return num_long;
}

double ask_double() {
    double num_double;
    printf("Número double:   ");
    scanf("%lf", &num_double);
    clear_buffer();
    return num_double;
}

int ask_int() {
    int num_int;
    printf("Número int:   ");
    scanf("%d", &num_int);
    clear_buffer();
    return num_int;
}

char ask_char() {
    char value_char;
    printf("Valor char:   ");
    scanf("%c", &value_char);
    clear_buffer();
    return value_char;
}




int main() {
    
    char again = 'n';
    do {
        
        int one_to_five = 12345;
        int six_to_zero = 67890;
        
        short short_number = ask_short();
        long long_number = ask_long();
        int int_number = ask_int();
        float float_number = ask_float();
        double double_number = ask_double();
        char character = ask_char();
        
        printf("%14d%8d%8d%8d%8d%8d\n",
            10, 20, 30, 40, 50, 60
        );
        printf("%8d%d%d%d%d%d%d%d%d%d%d%d%d\n",
            one_to_five, six_to_zero, one_to_five,
            six_to_zero, one_to_five, six_to_zero,
            one_to_five, six_to_zero, one_to_five,
            six_to_zero, one_to_five, six_to_zero,
            one_to_five
        );
        
        printf("%10hi%15li%16d",
            short_number, long_number, int_number
        );
        printf("%15f%20lf%14c",
            float_number, double_number, character
        );
        
        // +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
        printf("\nDeseja executar novamente ( s / n )  ");
        scanf("%c", &again);
        clear_buffer();
    } while (again == 's');
    return 0;
}
#endif // INNER_MODE
