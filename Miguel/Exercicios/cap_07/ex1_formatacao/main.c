
// 1 - Escreva um programa que tem uma estrutura da dados com os membros abaixo.
//     Receba dados via teclado em uma funcao e imprima estes conteudos no video,
//     em outra funcao, no seguinte formato. A estrutura e' uma variavel global.
// 
//      estrutura: char, int, long, float, double, unsigned char, unsigned int, 
//                 unsigned long
// 
//             10        20        30        40        50        60        70
//     1234567890123456789012345678901234567890123456789012345678901234567890
//         char      int       long                float               double
//               unsigned char       unsigned int        unsigned long


#define INNER_MODE
// #define OUTER_MODE


#ifdef INNER_MODE

#include <stdio.h>

void clear_buffer() {
    
    while (getchar() != '\n');
    return;
}


typedef struct {
    
    char v_char;   int v_int;
    long v_long;   float v_float;
    double v_double;   unsigned char v_Uchar;
    unsigned int v_Uint;   unsigned long v_Ulong;
} Values;


Values values;

//             10        20        30        40        50        60        70
//     1234567890123456789012345678901234567890123456789012345678901234567890
//         char      int       long                float               double
//               unsigned char       unsigned int        unsigned long

void display_nums() {
    
    const int one_to_zero = 1234567890;
    printf("%13d%8d%8d%8d%8d%8d%8d\n",
        10, 20, 30, 40, 50, 60, 70
    );
    printf("%5d%d%d%d%d%d%d\n",
        1234567890, 1234567890,
        1234567890, 1234567890,
        1234567890, 1234567890,
        1234567890
    );
    printf("%9c%6d%7li%16f%15lf\n",
        values.v_char, values.v_int,
        values.v_long, values.v_float,
        values.v_double
    );
    printf("%15c%7u%8lu\n",
        values.v_Uchar,
        values.v_Uint,
        values.v_Ulong
    );
    return;
}


int main() {
    
    char again = 'n';
    do {
        
        
        printf("Insira todos os números:\n");
        
        
        printf("char:  ");
        scanf("%c", &values.v_char);
        clear_buffer();
        
        printf("int:  ");
        scanf("%d", &values.v_int);
        clear_buffer();
        
        printf("long:  ");
        scanf("%li", &values.v_long);
        clear_buffer();
        
        printf("float:  ");
        scanf("%f", &values.v_float);
        clear_buffer();
        
        printf("double:  ");
        scanf("%lf", &values.v_double);
        clear_buffer();
        
        printf("unsigned int:  ");
        scanf("%ud", &values.v_Uint);
        clear_buffer();
        
        printf("unsigned char:  ");
        scanf("%c", &values.v_Uchar);
        clear_buffer();
        
        printf("unsigned long:  ");
        scanf("%li", &values.v_Ulong);
        clear_buffer();
        
        display_nums();
        
        // +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
        printf("Deseja executar novamente ( s / n )  ");
        scanf("%c", &again);
        clear_buffer();
    } while (again == 's');
    return 0;
}
#endif // INNER_MODE




#ifdef OUTER_MODE
int main() {
    
    char again = 'n';
    do {
        
        
        // +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
        printf("Deseja executar novamente ( s / n )  ");
        scanf("%c", &again);
        clear_buffer();
    } while (again == 's');
    return 0;
}
#endif // OUTER_MODE