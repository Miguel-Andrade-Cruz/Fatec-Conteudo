#include <stdio.h>



int main() {
    
    int number_one, number_two;
    
    printf("digite o primeiro número: \n");
    scanf("%d", &number_one);
    
    printf("digite o segundo número: \n");
    scanf("%d", &number_two);
    
    if (number_one >= number_two) {
        printf("O maior número entre os dois é %d", number_one);
    } else {
        printf("O maior número entre os dois é %d", number_two);
    }
    
    return 0;
}