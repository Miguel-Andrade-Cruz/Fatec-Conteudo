// 1 - Faça um programa para ler um numero inteiro, positivo de tres digitos, e gerar
//      outro número formado pelos dígitos invertidos do número lido.
//      Ex:   NúmeroLido = 123
//               NúmeroGerado = 321

// 2490 --> 0942

#include "middleware.h"


int main() {
    
    char again = 'n';
    
    do {
        
        int clean_input = valid_input();
        int refelected_input = reflect_number(clean_input);
        
        printf("Generated the inverse of %d: --> %d \n\n", clean_input, refelected_input);
        
        // +-+-+-+-+-+-+-+-+-+-+-+-+-+-+
        printf("Deseja executar novamente? ( s / n )  ");
        scanf("%c", &again);
        clear_buffer();
    } while (again == 's');
    return 0;
}