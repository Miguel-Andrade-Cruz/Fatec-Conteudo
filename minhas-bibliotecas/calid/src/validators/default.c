#include <string.h>
#include <sys/ucontext.h>
#include "../calid.h"



int _greater_than(Any bound, Any input) {

    return *input.value.a_float > *bound.value.a_float;
}

Rule *greater_than(Any delimiter) {

    Any bound = {.value.a_int = delimiter.value.a_int, .type = INT};
    Rule *greater_than;

    greater_than->bound = bound;
    greater_than->validator = _greater_than;

    return greater_than;
}
//
// --------------------------------
//
int _less_than(Any bound, Any input) {

    return *input.value.a_float < *bound.value.a_float;
}

Rule *less_than(Any delimiter) {

    Any bound = {.value.a_int = delimiter.value.a_int, .type = INT};
    Rule *less_than;

    less_than->bound = bound;
    less_than->validator = _less_than;

    return less_than;
}
//
// --------------------------------
//
int _capitalized(Any bound, Any input) {

    char first_letter = *input.value.a_char;
    return
        first_letter >= 0x41 && first_letter < 0x5B;
}

Rule *capitalized(Any delimiter) {

    Rule *capitalized;
    capitalized->validator = _capitalized;

    return capitalized;
}
// 
// --------------------------------
// 
int _max_length(Any bound, Any input) {

    return strlen(input.value.a_char) > *bound.value.a_int;
}

Rule *max_length(Any delimiter) {

    Any bound = {.value.a_int = delimiter.value.a_int, .type = INT};
    Rule *max_length;

    max_length->bound = bound;
    max_length->validator = _max_length;

    return max_length;
}
// 
// -------------------------------
// 
int _numeric_only(Any bound, Any input) {

    for (int c = 0; c < strlen(input.value.a_char); c++) {
        if ( c < 0x30 || c > 0x39 ) {
            return 0;
        }
    }
    return 1;
}

Rule *numeric_only(Any delii) {

    Rule *numeric_only;
    numeric_only->validator = _numeric_only;

    return numeric_only;
}


