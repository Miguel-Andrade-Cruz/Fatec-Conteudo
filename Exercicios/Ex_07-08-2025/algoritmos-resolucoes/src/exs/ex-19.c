#include <stdio.h>

int square(int num) {
    
    return num * num;
}

int main() {
    
    int num1, num2, num3, num4, result;
    do {
        
        do {
            printf("Número 1:\n");
            scanf("%d", &num1);
        
        } while (num1 <= 10 && num1 >= 25);
        
        do {
            printf("Número 2:\n");
            scanf("%d", &num2);
        } while (num2 < 0);
        
        num3 = num1 + num2;
        num4 = num1 * num2 * num3;
        
        result = square(num1) + square(num2) + square(num3) + square(num4);
        
        printf("O resultado final da conta maluca é %d", result);
    } while (result < 5000);
        
    return 0;
}