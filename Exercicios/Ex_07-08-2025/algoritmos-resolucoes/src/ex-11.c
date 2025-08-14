#include <stdio.h>


int main() {
    int is_multiples;
    int number_one, number_two;
    
    printf("digite o primeiro número: \n");
    scanf("%d", &number_one);
    
    printf("digite o segundo número: \n");
    scanf("%d", &number_two);
    
    if (number_one >= number_two) {
        is_multiples = number_one % number_two == 0;
    } else {
        is_multiples = number_two % number_one == 0;
    }
    
    if (is_multiples == 1) {
        printf("são múltiplos");
    } else {
        printf("não são múltiplos");
    }
    
    return 0;
}