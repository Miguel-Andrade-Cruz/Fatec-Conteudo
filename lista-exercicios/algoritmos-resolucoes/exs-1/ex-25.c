#include <stdio.h>


int main() {
    
    int num1, num2;
    
    printf("Põe um número aí fio:\n");
    scanf("%d", &num1);
    
    printf("Agora outro, vamo:\n");
    scanf("%d", &num2);
    
    if (num1 % 2 == 0 && num2 % 2 == 0) {
        printf("Esses dois aí são pares, não sei se tá sabendo");
    } else if (num1 % 2 != 0 && num2 % 2 != 0) {
        printf("Mano, se liga: Os dois são ímpares, tu acredita?");
    }
    return 0;
}