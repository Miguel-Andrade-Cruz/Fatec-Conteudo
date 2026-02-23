#include <stdio.h>


int main() {

    int a, b;
    
    printf("Insira um número (será denominado como A): \n");
    scanf("%d", &a);
    
    printf("Insira um outro número (dessa vez denominado como B): \n");
    scanf("%d", &b);

    printf("No momento, A tem valor %d e B tem valor %d\n", a, b);
    
    a ^= b;
    b ^= a;
    a ^= b;

    printf("Troca efetuada\n");
    printf("Agora, A vale %d e B vale %d\n", a, b);
    
    return 0;
}
