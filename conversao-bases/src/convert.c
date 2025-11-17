#include <math.h>
#include "wrap_function.c"


void splitter(ConversionPackage *package, int preserve_base, int returned) {
    
    
    return;
}


void x_to_decimal(ConversionPackage *package) {
    
    int alg_limit = package->size;
    int converted = 0;
    for (int i = 0, *alg_pos = &i; i < alg_limit; i++) {
        converted += pow(package->target_base, *alg_pos) * package->current_number[i];
    }
    package->base_10_number = converted;
    
    return;
}


void decimal_to_x(ConversionPackage *package) {

    int alg_limit = package->size;
    int value = package->base_10_number;
    
    int i = alg_limit -1;
    while (value != 0) {
        package->target_number[i] = value % package->target_base;
        value /= package->target_base;

        i--;
    }
    
    return;
}


void bin_to_dec_partition(ConversionPackage *package, int chunk_size) {
    
    ConversionPackage transition_package = {.target_base = 2, .size = LIMIT_BASE_2};
    
    int chunk[chunk_size];
    int portion_index;
    int next_value;
    for (int index = 0, chunk_index = 0; index < LIMIT_BASE_2; chunk_index++) {
        
        portion_index = 0;
        while (portion_index % chunk_size != 0 || portion_index == 0) {
            
            if (index > LIMIT_BASE_2 - 1) {
                next_value = 0;
            } else {
                next_value = package->current_number[index];
            }
            
            transition_package.current_number[portion_index] = next_value;
            portion_index++;
            index++;
        }
        
        x_to_decimal(&transition_package);
        package->current_number[chunk_index] = transition_package.base_10_number;
        
    }
    
    return;
}




void convert(ConversionPackage *package) {
    
    
    if (package->current_base == 10) {
        
        x_to_decimal(package);
    }
    return;
}
