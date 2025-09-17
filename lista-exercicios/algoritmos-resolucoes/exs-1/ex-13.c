#include <stdio.h>


int main() {
    int number_one, number_two, bigger;
    
    printf("Escolha um número: \n");
    scanf("%d", &number_one);
    
    printf("Escolha um outro número: \n");
    scanf("%d", &number_two);
    
    if (number_one == number_two) {
        printf("Os números são iguais");
    } else {
        bigger = (number_one > number_two) ? number_one : number_two;
        printf("O maior número é %d", bigger);
    }
    
    return 0;
}