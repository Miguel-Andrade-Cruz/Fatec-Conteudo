#include <stdio.h>


int main() {
    
    // Receba via teclado um número positivo e exiba esse valor com acréscimo de 10%
    
    const float percentage = 1;
    float number;
    float number_with_percentage;
    
    printf("Escolha um número: \n");
    scanf("%f", &number);
    
    number_with_percentage = number * ( 1 + percentage);
    printf("Seu número acrescido de 10 porcento é igual á %f", number_with_percentage);
    
    return 0;
}