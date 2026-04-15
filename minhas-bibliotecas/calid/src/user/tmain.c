#include "../scan.c"


int main() {
    
    Generic *age;
    Field age_field;
    field("Boas novas, quanto anos tienes: ", &age, INT, &age_field);
    
    Filter age_filters[2] = {
        filter( *greater_than, 18 ),
        filter( *less_than, 100 )
    };
    apply(&age_field, age_filters);
    
    scan(&age_field);
    
    
    printf("A sua idade então é %d", *age);
    
    return 0;
}
