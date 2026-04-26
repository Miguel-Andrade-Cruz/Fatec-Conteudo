
// 1 - Escreva um programa que receba via teclado usando ponteiros um char,
//     int, long, unsigned, float, double, unsigned long e unsigned char,
//     e imprima-os no video utilizando ponteiros no seguinte formato:
// OBS.: As variaveis sao locais na funcao main().
    

//             10        20        30        40        50        60
//     123456789012345678901234567890123456789012345678901234567890
//         int                 long                unsigned
//                   float               double              char
//              unsigned long       unsigned char

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