#include <stdio.h>
#include <math.h>

int main() {
    
    int a, b, c;
    
    printf("a: \n");
    scanf("%d", &a);

    printf("a: \n");
    scanf("%d", &b);

    printf("a: \n");
    scanf("%d", &c);
    
    int delta = (b * b) - 4 * a * c;
    
    float root_one, root_two;
    if (delta < 0) {
        
        printf("Sem raízes reais");
    } else if (delta == 0) {
        
        root_one = (-b + sqrt(delta)) / 2 * a;
        printf("Raíz da equação: %f", root_one);
    } else {
        
        float root_one = (-b + sqrt(delta) / 2 * a);
        float root_two = (-b - sqrt(delta) / 2 * a);
        printf("Raízes da equação: %f e %f", root_one, root_two);
    }
    
    return 0;
}