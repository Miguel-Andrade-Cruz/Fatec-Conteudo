#include "../lib/calid/calid.c"
int main() {
    
    Inputer inputs[] = {{.msg = "Números da sequência para exibir: \n", .type = T_INT}};
    InputerSet *k_elements = group_inputs(inputs, 1);
    
    Validator *checking[] = {greater_than(0)};
    Needs *checkers = group_needs(checking, 1);
    
    pull(k_elements, checkers);
    
    int item_a_ratio = 3;
    int item_b_ratio = 4;
    int item_a_next_element;
    int item_b_next_element;
    
    printf("Sequencia da P.A de %d elementos: \n", takeint(k_elements->arr[0]));
    for (int i = 0; i < takeint(k_elements->arr[0]); i++) {
        
        item_a_next_element = item_a_ratio * (i + 1);
        printf("%d  ", item_a_next_element);
    }
    printf("\n");
    
    for (int i = 0; i < takeint(k_elements->arr[0]); i++) {
        
        item_b_next_element = item_b_ratio * (i + 1);
        printf("1/%d  ", item_b_next_element);
    }
    printf("\n");
    
    
    
    return 0;
}