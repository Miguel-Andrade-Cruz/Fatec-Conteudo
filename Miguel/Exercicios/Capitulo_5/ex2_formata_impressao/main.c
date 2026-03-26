// 2 - Escreva um programa para receber 5 nomes, com até 7 caracteres, via teclado
//     e imprima-os no video no seguinte formato:
//     (Declare os 5 vetores como variaveis globais)
//
//              10        20        30        40        50
//    12345678901234567890123456789012345678901234567890
//      nome1                                   nome5
//                nome2               nome4
//                          nome3

#include "middleware.h"
#define INNER_MODE
// #define OUTER_MODE

char str_1[STR_SIZE + 1];
char str_2[STR_SIZE + 1];
char str_3[STR_SIZE + 1];
char str_4[STR_SIZE + 1];
char str_5[STR_SIZE + 1];


#ifdef INNER_MODE
int main() {

    char again = 'n';
    do {
        
        int one_through_zero = 1234567890;
        int TEN = 10, TWENTY = 20, THIRTY = 30, FORTY = 40, FIFTY = 50;
        
        // 'ask_strings' function
        printf("Insira cinco strings, de até 7 caracteres:\n");
        
        printf("[ 1 ] ->> ");
        scanf("%s", str_1);
        clear_buffer();
        
        printf("[ 2 ] ->> ");
        scanf("%s", str_2);
        clear_buffer();
        
        printf("[ 3 ] ->> ");
        scanf("%s", str_3);
        clear_buffer();
        
        printf("[ 4 ] ->> ");
        scanf("%s", str_4);
        clear_buffer();
        
        printf("[ 5 ] ->> ");
        scanf("%s", str_5);
        clear_buffer();
        // --------------------------------------
        
        // 'show_formatting' function
        printf("%14d%8d%8d%8d%8d\n", TEN, TWENTY, THIRTY, FORTY, FIFTY);
        printf("%12d%d%d%d%d\n",
            one_through_zero,
            one_through_zero,
            one_through_zero,
            one_through_zero,
            one_through_zero
        );
        
        printf("%6s%34s\n", str_1, str_5);
        printf("%16s%15s\n", str_2, str_4);
        printf("%22s\n", str_3);
        // --------------------------------------
        
        // +-+-+-+-+-+-+-+-+-+-+-+-+-+
        printf("\n\nDeseja executar novamente? ( s / n )  ");
        scanf("%c", &again);
        clear_buffer();
    } while (again == 's');
    return 0;
}
#endif


#ifdef OUTER_MODE
int main() {

    char again = 'n';
    do {
    
        int one_through_zero = 1234567890;
        int TEN = 10, TWENTY = 20, THIRTY = 30, FORTY = 40, FIFTY = 50;

        printf("Insira cinco strings, de até 7 caracteres:\n");
        ask_for_strings(str_1, str_2, str_3, str_4, str_5);
        
        show_formatting(
            str_1, str_2, str_3, str_4, str_5,
            TEN, TWENTY, THIRTY, FORTY, FIFTY,
            one_through_zero
        );
        
        // +-+-+-+-+-+-+-+-+-+-+-+-+-+-+
        printf("Deseja executar novamente? ( s / n )  ");
        scanf("%c", &again);
        clear_buffer();
    } while (again == 's');
    return 0;
}
#endif