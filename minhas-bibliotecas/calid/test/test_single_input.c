#include "../src/lib/calid/calid.c"

int main() {
    // Test full utility in a simulated program

    
    Inputer price_of_pizza[] = {{.msg = "Qual é o preço da pizza? \n", .type = T_FLOAT}};
    InputerSet *input_set = group_inputs(price_of_pizza, 1);
    
    Validator *price_validation[] = {less_than(100), greater_than(50)};
    Needs *checks = group_needs(price_validation, 2);
    
    pull(input_set, checks);
    
    printf("Your pizza will cost %f \n", takefloat(input_set->arr[0]) * (1 + 0.05));
    printf("Have a great dinner! \n");
    
    clean_all(input_set, checks);
    return 0;
}
