#include <stdio.h>


int main() {
    int num1, num2, num3;
    do {
        
        printf("N1:\n");
        scanf("%d", &num1);
        
        printf("N2:\n");
        scanf("%d", &num2);    
        
        printf("N3:\n");
        scanf("%d", &num3);
        
        if (num1 > num2) {
            if (num1 > num3) {
                printf("O número %d é o maior", num1);
            } else {
                printf("O número %d é maior", num3);
            }
        } else {
            if (num2 > num3) {
                printf("O número %d é maior", num2);
            } else {
                printf("O número %d é maior", num3);
            }
        }
    } while (num1 == num2 && num2 == num3);
    
    
    return 0;
}