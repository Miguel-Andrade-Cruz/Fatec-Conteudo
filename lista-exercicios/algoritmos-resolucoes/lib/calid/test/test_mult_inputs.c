#include "../src/lib/calid/calid.c"



int main() {
    
    Inputer student_grades[] = {
        {.msg = "Nota do primeiro semestre: \n", .type = T_FLOAT},
        {.msg = "Nota do segundo semestre: \n", .type = T_FLOAT},
        {.msg = "Nota do terceiro semestre: \n", .type = T_FLOAT},
        {.msg = "Nota do quarto semestre: \n", .type = T_FLOAT}
    };
    InputerSet *input_group = group_inputs(student_grades, 4);

    
    Validator *validate_grades[2] = {
      greater_than(0),
      less_than(10)
    };
    Needs *validate_group = group_needs(validate_grades, 2);    
    
    pull(input_group, validate_group);
    
    float sum = 0;
    for (int i = 0; i < input_group->qtd; i++) {
        sum += takefloat(input_group->arr[i]);
    } float median = sum / input_group->qtd;
    
    
    printf("Sua média final é: %f \n", median);
    clean_all(input_group, validate_group);
    
    return 0;
}