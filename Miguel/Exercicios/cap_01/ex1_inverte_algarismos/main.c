// 1 - Faça um programa para ler um numero inteiro, positivo de tres digitos, e gerar
//      outro número formado pelos dígitos invertidos do número lido.
//      Ex:   NúmeroLido = 123
//               NúmeroGerado = 321

// 2490 --> 0942



#define INNER_MODE
// #define OUTER_MODE


#ifdef OUTER_MODE
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
#endif // OUTER_MODE



#ifdef INNER_MODE
#include <stdio.h>

#define BASE_TEN 10

void clear_buffer() {
	
	while ( getchar() != '\n');
	return;
}

int valid_input() {

    int input;
    
    do {

        printf("Insira um número: \n");
        scanf("%d", &input);
        clear_buffer();
        
    } while (input <= 99 || input > 999);
    
    return input;
}

int reflect_number(int input) {
    
    int hundreds, tens, units;
    int mirror_input = 0;
    
    // get the hundreds
    hundreds = input / (BASE_TEN * BASE_TEN);
    mirror_input += hundreds;
    
    input -= hundreds * (BASE_TEN * BASE_TEN);
    
    // get the tens
    tens = input / BASE_TEN;
    mirror_input += tens * BASE_TEN;
    
    input -= tens * BASE_TEN;
    
    // get the units
    units = input;
    mirror_input += units * (BASE_TEN * BASE_TEN);
    return mirror_input;
}


int main() {
    
    char again = 'n';
    
    do {
        
        int clean_input = valid_input();
        int refelected_input = reflect_number(clean_input);
        
        printf("O número espelhado de %d é %d \n\n", clean_input, refelected_input);
        
        // +-+-+-+-+-+-+-+-+-+-+-+-+-+-+
        printf("Deseja executar novamente? ( s / n )  ");
        scanf("%c", &again);
        clear_buffer();
    } while (again == 's');
    return 0;
}
#endif // INNER_MODE
