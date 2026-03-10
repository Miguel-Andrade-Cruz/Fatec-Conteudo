#include "../src/fill_form.c"

int main() {


    char name[25], email[45], cpf[14];

    Rule name_rules[2] = {
        {
            .validator = max_length,
            .bound.value.a_int = 25,
            .bound.type = INT
        },
        {
            .validator = capitalized,
        }
    };

    Rule email_rules[2] = {
            {
                .validator = alphaNum_only,
            },
            {
                .validator = max_length,
                .bound.value.a_int = 45,
                .bound.type = INT
            }
    };


    Rule cpf_rules[2] = {
        {
            .validator = numeric_only,
        },
        {
            .validator = max_length,
            .bound.value.a_int = 14,
            .bound.type = INT
        }
    };

    FormField fields[3] = {
        {
            .question = "What is your name?",
            .requests = name_rules,
            .pointer = {.value.a_char = name, .type = CHAR},
            .rules_qtd = 2
        },
        {
            .question = "Enter your email:",
            .pointer = {.value.a_char = email, .type = CHAR},
            .requests = email_rules,
            .rules_qtd = 2
        },
        {
            .question = "Enter your CPF:",
            .pointer = {.value.a_char = cpf, .type = CHAR},
            .requests = cpf_rules,
            .rules_qtd = 2
        }
    };

    Form sign_up_form = {.form_fields = fields, .fields_qtd = 3};

    fill_form(&sign_up_form);

    printf("Your name is %c", *name);
    printf("Your email is %c", *email);
    printf("Your cpf is %c", *cpf);

    return 0;
}