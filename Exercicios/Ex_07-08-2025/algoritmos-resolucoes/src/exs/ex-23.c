#include <stdio.h>

int main() {
    
    float n1, n2, n3, n4;
    
    printf("Nota 1:\n");
    scanf("%f", &n1);
    
    printf("Nota 2:\n");
    scanf("%f", &n2);
    
    printf("Nota 3:\n");
    scanf("%f", &n3);
    
    printf("Nota 4:\n");
    scanf("%f", &n4);
    
    float median = (n1 + n2 + n3 + n4) / 4;
    
    if (median >= 6.0) {
        printf("Aprovado");
    } else {
        printf("reprovado");
    }
    
    return 0;
}