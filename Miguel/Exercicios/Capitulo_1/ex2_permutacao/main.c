#include "middleware.h"


int main() {

    char var_type = select_var_type();
    
    if (var_type == 'c') {
        char_switcher();
    }
    else if (var_type == 'i') {
        int_switcher();
    }

    return 0;
}
