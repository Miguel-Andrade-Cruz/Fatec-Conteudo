// #include <stdio.h>
#include "validators/custom.c"

const int MAX_RULES = 5;

int do_checklist(FormField field) {

    for (int check_i = 0; check_i < field.rules_qtd; check_i++) {

        Rule rule = field.requests[check_i];
        int is_valid = rule.validator(rule.bound, field.pointer);
        if (is_valid == 0) {
            return 0;
        }
    }

    return 1; //
}



void fill_field(FormField field) {

    char format_specifier[3];

    switch (field.pointer.type) {
        case INT:
            strcpy(format_specifier, "%d");
        case FLOAT:
            strcpy(format_specifier, "%f");
        case CHAR:
            strcpy(format_specifier, "%c");
    }

    do {
        printf("%s", field.question);
        if (scanf(format_specifier, &field.pointer.value) == 0) {
            while (getchar() != '\n');
            continue;
        }
    } while (do_checklist(field) == 0);

    return;
}



void fill_form(Form *form) {

    for (int i = 0; form->fields_qtd; i++) {
        
        fill_field(form->form_fields[i]);
    }

    return;
}