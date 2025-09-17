#include "../lib/calid/calid.c"
int main() {
    
    Inputer inputs[] = {{.msg = "Números da sequência para exibir: \n", .type = T_INT}};
    InputerSet *k_elements = group_inputs(inputs, 1);
    
    Validator *checking[] = {greater_than(0)};
    Needs *checkers = group_needs(checking, 1);
    
    pull(k_elements, checkers);
    
    int item_a_numerator_ratio = 2;
    int item_a_denominator_ratio = 5;
    int item_a_next_numerator, item_a_next_denominator;
    
    int item_b_ratio = 4;
    int item_b_numerator_next, item_b_denominator_next;
    
    
    
    printf("Sequencia da P.A de %d elementos: \n", takeint(k_elements->arr[0]));
    for (int i = 0; i < takeint(k_elements->arr[0]); i++) {
        
        item_a_next_numerator = item_a_numerator_ratio * (i + 1);
        item_a_next_denominator = item_a_denominator_ratio * (i + 1);
        printf("%d/%d  ", item_a_next_numerator, item_a_next_denominator);
    }
    printf("\n");

    for (int i = 1; i <= takeint(k_elements->arr[0]); i++) {
        
        item_b_numerator_next = item_b_ratio * (i * i);
        item_b_denominator_next = 2 * i * item_b_ratio;
        
        if (item_b_numerator_next % item_b_denominator_next == 0) {
            printf("%d  ", item_b_numerator_next / item_b_denominator_next);    
        } else {
            printf("%d/%d  ", item_b_numerator_next, item_b_denominator_next);
        }
    }
    printf("\n");    
    
    return 0;
}