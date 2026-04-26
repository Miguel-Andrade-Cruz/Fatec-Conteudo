
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