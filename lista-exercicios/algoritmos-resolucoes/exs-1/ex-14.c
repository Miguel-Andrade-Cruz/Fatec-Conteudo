#include <math.h>
#include <stdio.h>

struct eq_roots {
    int have_real_roots;
    float root_negative;
    float root_positive;
};

int calc_delta(int a, int b, int c) {
    float delta;
    delta = sqrtf(b) - (4  * a * c);
    return delta;
}


struct eq_roots calc_eq_roots(int a, int b, int c) {
    struct eq_roots roots_result;
    float root_negative;
    float root_positive;
    float delta = calc_delta(a, b, c);
    
    if (delta < 0) {
        roots_result.have_real_roots = 0;
        return roots_result;
    }
    
    root_negative = (-b - sqrt(delta)) / 2 * a;
    root_positive = (-b + sqrt(delta)) / 2 * a;

    roots_result.have_real_roots = 1;
    roots_result.root_negative = root_negative;
    roots_result.root_positive = root_positive;
    
    return roots_result;
}

int main() {
    
    struct eq_roots final_roots;
    int a, b, c;
    
    printf("Escolha um número: \n");
    scanf("%d", &a);
    
    printf("Escolha um número: \n");
    scanf("%d", &b);    
    
    printf("Escolha um número: \n");
    scanf("%d", &c);
    
    if (a == 0 || b == 0 || c == 0) {
        printf("Equação de segundo grau incompleta");
        return 0;
    }
    
    final_roots = calc_eq_roots(a, b, c);
    if (final_roots.have_real_roots == 0) {
        return 0;
    }
    
    if (final_roots.root_negative == final_roots.root_positive) {
        printf("A raíz da equação é %f", final_roots.root_negative);
    } else {
        printf(
            "As raízes da equação são %f e %f",
            final_roots.root_negative,
            final_roots.root_positive
        );
    }
    
    return 0;
}