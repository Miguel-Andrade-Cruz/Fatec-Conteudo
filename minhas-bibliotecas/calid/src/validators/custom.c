#include "default.c"

int alphaNum_only(Any bound, AnyPointer input) {

    char *value = input.value.a_char;

    int str_size = strlen(input.value.a_char);
    for (int i = 0; i < str_size; i++) {

        if ( 
            value[i] < 0x30 || value[i] > 0x39 ||
            value[i] < 0x40 || value[i] > 0x5A
        ) {
            return 0;
        }
    } 
    return 1;
}

int valid_cpf(Any bound, AnyPointer input) {
    // TODO: Desenvolver validador de cpf
    return 0; //
}
