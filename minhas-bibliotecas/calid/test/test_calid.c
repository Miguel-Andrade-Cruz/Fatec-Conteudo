#include <stdio.h>
#include "../src/calid.h"
#include "../src/validators/custom.c"

int main() {

    char name[25], email[45], cpf[14];

    RuleSet name_rules = {
        capitalized(),
        max_length(25)
    };

    RuleSet email_rules = {
            alphaNum_only(),
            max_length(45)
    };

    RuleSet cpf_rules = {
            numeric_only(),
            max_length(11)
            // valid_cpf(),
    };

    FormField fields[3] = {
        {
            .pointer = {.value.a_char = name, .type = CHAR},
            .requests = &name_rules
        },
        {
            .pointer = {.value.a_char = email, .type = CHAR},
            .requests = &email_rules
        },
        {
            .pointer = {.value.a_char = cpf, .type = CHAR},
            .requests = &cpf_rules
        }
    };

    Form sign_up_form = {.form_fields = fields, .fields_qtd = 3};

    fill_form(&sign_up_form);

    printf("Your name is %c", *name);
    printf("Your email is %c", *email);
    printf("Your cpf is %c", *cpf);

    return 0;
}