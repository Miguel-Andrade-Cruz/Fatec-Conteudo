#include <stdio.h>
#include <math.h>

#include "../../lib/calid/calid.c"

int main() {
    
    double step_height, wanted_height;
    double steps;
    
    Inputer inputs[] = {
        {.msg = "Qual é o tamanho do degrau?\n", .type = T_FLOAT},
        {.msg = "Quanto você quer subir?\n", .type = T_FLOAT}
    };
    InputerSet *heights = group_inputs(inputs, 2);
    
    Validator *check[] = {greater_than(0)};
    Needs *checker = group_needs(check, 1);
    
    pull(heights, checker);
    steps = takefloat(heights->arr[1]) / takefloat(heights->arr[0]);
    double w = ceil(steps);
    
    printf("Você precisa subir %lf degraus", w);
    
    return 0;
}