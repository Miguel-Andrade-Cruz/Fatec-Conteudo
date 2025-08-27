#include <stdio.h>


int main() {
     
    // Leia o preço de um produto e inflaciona
    // esse preço em 10% se ele for menor que 100 e
    // em 20% se ele for maior ou igual a 100
     
    float price;
    float new_price;
    
    printf("Digite um preço: \n");
    scanf("%f", &price);
    
    if (price < 100) {
        new_price = price * (1 * 0.1);
        printf("O novo preço é de %f", new_price);
        
        return 0;
    }
    new_price = price * (1 * 0.2);
    printf("O novo preço é de %f", new_price);
    
    return 0;
}