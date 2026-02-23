#include <stdio.h>


void input_all_types(
    short short_number,
    long long_number,
    int default_number,
    float float_number,
    double double_number,
    char character
) {

    printf("Insira aqui um short: :\n");
    scanf("%hd", &short_number);
    printf("Insira aqui um long: ");
    scanf("%ld", &long_number);
    printf("Insira aqui um inteiro: ");
    scanf("%d", &default_number);
    printf("Insira aqui um float: ");
    scanf("%f", &float_number);
    printf("Insira aqui um double: ");
    scanf("%lf", &double_number);
    printf("Insira aqui um char: ");
    scanf("%c", &character);
    
    return;
}


int main() {

    short short_number;
    long long_number;
    int default_number;
    float float_number;
    double double_number;
    char character;

    input_all_types(
        short_number,
        long_number,
        default_number,
        float_number,
        double_number,
        character
    );

    printf("\n");
    for (int i = 0, step_10 = 10; i < 6; i++, step_10 += 10) {

        printf("%8d", step_10);
    }

    printf("\n");

    for (int i = 0; i < 5; i++) {

        int one_to_zero = 1234567890;
        printf("%3d", one_to_zero);
        
    }
    printf("%d", 12345);
    
    printf("\n");


    printf("%10hd", short_number);
    printf("%16ld", long_number);
    printf("%16d", default_number);

    printf("\n");

    printf("%20f", float_number);
    printf("%15lf", double_number);
    printf("%14c", character);

    printf("\n");

    return 0;
}




// 3 - Escreva um programa que receba dados via teclado para variaveis do tipo short,
//      long, int, float, double e um char e imprima-os no video no seguinte
//      formato:

//              10        20        30        40        50        60
//      12345678901234567890123456789012345678901234567890123456789012345
//          short               long                int
//                    float               double              char
