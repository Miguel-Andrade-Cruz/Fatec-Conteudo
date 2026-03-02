#include <stdio.h>

int main() {

    char name[25], email[45], cpf[14];

    Rule name_rules[2] = {
        capitalized(),
        max_length(25)
    };

    Rule email_rules[2] = {
        prohibited_chars(),
        max_length(45)
    };
    
    Rule cpf_rules[3] = {
        numeric_only(),
        valid_cpf(),
        max_length(11)
    };

    Form sign_up_form[3] = {
        {
            .PChar = *name,
            .rule = *name_rules
        },
        {
            .PChar = *email,
            .rule = *email_rules
        },
        {
            .PChar = *cpf,
            .rule = *cpf_rules
        }
    }


    fill_form(*sign_up_form);

    printf("Your name is %c", *name);
    printf("Your email is %c", *email);
    printf("Your cpf is %c", *cpf);
    
    return 0;
}