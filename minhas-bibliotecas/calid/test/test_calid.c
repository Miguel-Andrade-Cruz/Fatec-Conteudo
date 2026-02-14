#include <stdio.h>
#include "../src/calid.c"

int main() {
    
    int qtd;
    
    Rule requirements[2] = {more_than(50), less_than(500)};
    Guard qtd_guard = {
        .value = {
            .value = {.V_INT = &qtd},
            .type = T_INT
        },
        .requires = requirements,
        .value_size = 2,
        .requires_size = 2
    };
    
    run_guard(&qtd_guard);
    
    printf("Valor ai que foi definid memo: %d", qtd);
    return 0;
}