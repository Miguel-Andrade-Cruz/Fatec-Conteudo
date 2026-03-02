#include <string.h>
#include "../calid.h"

int _alphaNum_only(Any bound, Any input) {

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

Rule *alphaNum_only() {

    Rule *alphaNum_only;
    alphaNum_only->validator = _alphaNum_only;

    return alphaNum_only;
}
// 
// -----------------------------------
// 
int _valid_cpf(Any bound, Any input) {
    // TODO: Desenvolver validador de cpf
    return 0; //
}

Rule *valid_cpf() {

    Rule *valid_cpf;
    valid_cpf->validator = _valid_cpf;

    return 0;
}