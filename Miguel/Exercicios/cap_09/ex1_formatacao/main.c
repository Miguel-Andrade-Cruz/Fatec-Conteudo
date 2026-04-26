
// 1 - Escreva um programa que tem uma estrutura da dados com os membros abaixo.
//     A estrutura e' uma variavel LOCAL na funcao main(). Receba via teclado o
//     conteudo de cada um dos membros numa funcao e imprima-os no video no
//     seguinte formato, tambem numa funcao.

//     estrutura: char, int, long, float, double, unsigned char, unsigned int,
//     unsigned long

//             10        20        30        40        50        60        70
//     1234567890123456789012345678901234567890123456789012345678901234567890
//       char      int                 long                float     double
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