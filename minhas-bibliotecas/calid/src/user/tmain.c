#include "../scan.c"


int main() {
    
    Generic *age;
    Field age_field;
    field("Boas novas, quanto anos tienes: ", &age, INT, &age_field);
    
    Filter age_filters[] = {
        filter( *greater_than, (Generic){.v_int = 18}, INT),
        filter( *less_than, (Generic){.v_int = 100}, INT)
    };
    
    Generic *currency;
    Field currency_field;
    field("Tipo do fato [ 'D' para débito, 'C' para crédito ]: ",
        &currency, CHAR, &currency_field
    );
    
    
    Filter currency_filters[] = {
        filter( *limits_to_char, (Generic){.v_str = "CD"}, STR),
        filter( *limits_to_char, (Generic){.v_str = "CDBA"}, STR)
    };
    
    
    apply(&age_field, age_filters);
    apply(&currency_field, currency_filters);
    
    Field form[2] = {
        age_field,
        currency_field
    };
    
    scan(form);
    
    printf("A sua idade então é %d\n", *age);
    
    return 0;
}
