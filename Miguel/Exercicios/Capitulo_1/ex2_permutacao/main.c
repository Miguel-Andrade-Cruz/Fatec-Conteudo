#include <stdio.h>
#include "middleware.h"


int main() {
    
    char again = 'n';
    do {
        char var_type = select_var_type();
        
        if (var_type == 'c') {
            char_switcher();
        }
        else if (var_type == 'i') {
            int_switcher();
        }
        
        printf("Deseja executar novamente? ");
        scanf("%c", &again);
    } while (again == 's');
    return 0;
}
