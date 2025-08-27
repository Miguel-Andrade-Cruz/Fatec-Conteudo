#include <stdio.h>
#include <string.h>

#include "./inputer.h"
#include "../d_type/d_type.h"
#include "../validator/validator.h"


int checklist(Inputer *ipt_sketch, Validator *checker[], int lenght) {
    int passed_check;
    
    Validator *current_checker;
    int i;
    for (i = 0; i < lenght; i++) {
        current_checker = checker[i];
        passed_check = current_checker->action(ipt_sketch->value, current_checker->state);
        if (passed_check == 0) {
            return 0;
        }
    }
    
    return 1;
}

void pull(Inputer *ipt_sketch, Validator *checker[], int lenght) {
    
    do {
        
        printf("%s", ipt_sketch->msg);
        
        char format_specifier[3];
        switch (ipt_sketch->type) {
            case T_FLOAT:
                strcpy(format_specifier, "%f");
                break;
            case T_CHAR:
                strcpy(format_specifier, "%c");
                break;
            case T_INT:
                strcpy(format_specifier, "%d");
                break;
        }
        
        scanf(format_specifier, &(ipt_sketch->value));
    } while (checklist(ipt_sketch, checker, lenght) == 0);

    return;
}
