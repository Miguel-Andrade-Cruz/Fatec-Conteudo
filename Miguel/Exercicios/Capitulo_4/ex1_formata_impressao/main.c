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
#define INNNER_MODE              // |
#define OUTER_MODE               // |
// ----------------------------------


#ifdef INNER_MODE
#include <stdio.h>

void clear_buffer() {
    
    while (getchar() != '\n');
    return;
}

int main() {
    
    char again = 'n';
    do {
        
        
        // +-+-+-+-+-+-+-+-+-+-+-+-+
        printf("Deseja executar novamente ( s / n )  ");
        scanf("%c", &again);
        clear_buffer();
    } while (again == 's');
    return 0;
}
#endif // INNER_MODE

#ifdef OUTER_MODE
#include "middleware.h"

int main() {
    
    char again = 'n';
    do {
        
        
        // +-+-+-+-+-+-+-+-+-+-+-+-+
        printf("Deseja executar novamente ( s / n )  ");
        scanf("%c", &again);
        clear_buffer();
    } while (again == 's');
    return 0;
}
#endif // OUTER_MODE
