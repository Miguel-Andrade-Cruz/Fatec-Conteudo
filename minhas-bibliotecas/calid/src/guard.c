#include "inspec.c"



void run_guard_array(Guard *guard) {
    
    printf("rodou o run guard array ein... (7 gauard.c)\n");
    
    for (int i = 0; i < guard->value_size; i++) {
        
        while (inspec(guard) == 1);
    }
}


void run_guard_unique(Guard *guard) {

    while (inspec(guard) == 1);
    return;
}


void run_guard(Guard *guard) {
    
    Any value;
    if (guard->value_size > 1) {    
        run_guard_array(guard);    
        
    } else if (guard->value_size == 1) {
        run_guard_unique(guard);
    }
    
    return;
}

