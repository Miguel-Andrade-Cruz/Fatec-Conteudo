#include <stdio.h>


int gt_three_nums(int num1, int num2, int num3) {
    
    if (num2 > num1) {
        if (num3 > num2) {
            return num3;
        } else {
            return num2;
        }
    } else if (num1 > num3) {
        return num1;
    } else {
        return num3;
    }
}



int main() {
    int num1, num2, num3;
    
    printf("Número um: \n");
    scanf("%d", &num1);
    printf("Número dois: \n");
    scanf("%d", &num2);
    printf("Número três: \n");
    scanf("%d", &num3);

    if ( num1 == num2 && num2 == num3 ) {
        printf("Os números são iguais, digite outros novos:\n");
    }
    while ( num1 == num2 && num2 == num3 ) {
        printf("Número um: \n");
        scanf("%d", &num1);
        printf("Número dois: \n");
        scanf("%d", &num2);
        printf("Número três: \n");
        scanf("%d", &num3);
    }
    
    int greater_number = gt_three_nums(num1, num2, num3);
    printf("O maior número é: %d", greater_number);
    
    return 0;
}