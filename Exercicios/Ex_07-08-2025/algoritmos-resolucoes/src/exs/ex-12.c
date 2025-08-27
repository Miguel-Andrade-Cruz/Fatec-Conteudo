#include <stdio.h>


int is_even(int number){
    
    return number % 2 == 0;
}

int main() {
    
    int number_one, number_two;
    
    printf("Escolha um número: \n");
    scanf("%d", &number_one);
    
    printf("Escolha um outro número: \n");
    scanf("%d", &number_two);
    
    if (is_even(number_one) && is_even(number_two)) {
        printf("São pares");
    } else {
        printf("São ímpares");
    }
    
    return 0;
}