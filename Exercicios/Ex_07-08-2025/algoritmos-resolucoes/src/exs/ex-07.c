#include <stdio.h>

int main() {
    
    // Receba via teclado um número qualquer e
    // exiba se ele é positivo ou negativo ou zero
    
    int number;
    
    printf("Digite um número:");
    scanf("%d", &number);
    
    if (number < 0) {
        printf("Esse número é negativo");
        return 0;
    } else if (number > 0) {
        printf("Esse número é positivo");
        return 0;
    } else {
        printf("Esse número é zero");
        return 0;
    }    
}