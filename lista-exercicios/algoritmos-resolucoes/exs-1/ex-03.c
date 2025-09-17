#include <stdio.h>


int main() {
    
    // Solicite ao usuário o preço de um produto e calcular novo preço com desconto de 9%
    
    const float discount = 0.9; 
    float price;
    float discounted_price;
    
    printf("Digite um preço: \n");
    scanf("%f", &price);
    
    discounted_price = price * (1 - discount);
    
    printf("Sua compra custará %f com o nosso disconto", discounted_price);
    
    return 0;
}