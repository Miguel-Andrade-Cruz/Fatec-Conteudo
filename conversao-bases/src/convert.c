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


void binary_partition(int *binary_sequence, int chunk_size, int conjunt[1][4]) {
    
    int chunk[chunk_size];
    
    int portion_index;
    int next_value;
    for (int index = 0; index < LIMIT_BASE_2;) {
        
        portion_index = 0;
        while (portion_index % chunk_size != 0 || portion_index == 0) {
            
            if (index > LIMIT_BASE_2 - 1) {
                next_value = 0;
            } else {
                next_value = binary_sequence[index];
            }
            
            chunk[portion_index] = next_value;
            portion_index++;
            index++;
        }
        
        
    }
    
    return;
}




void convert(ConversionPackage *package) {
    
    
    if (package->current_base == 10) {
        
        x_to_decimal(package);
    }
    return;
}
