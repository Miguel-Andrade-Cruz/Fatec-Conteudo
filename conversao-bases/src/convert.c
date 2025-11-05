#include <math.h>
#include "translators.c"


void splitter(ConversionPackage *package, int preserve_base) {
    
    int alg_limit = package->size;
    
    int base;
    if (preserve_base == 1) base = package->current_base;
    base = package->target_base;
    
    int value = package->base_10_number;
    
    int i = alg_limit -1;
    while (value != 0) {
        package->target_number[i] = value % base;
        value /= package->target_base;

        i--;
    }
    
    return;
}

void x_to_decimal(ConversionPackage *package) {
    
    int int_vec[LIMIT_MAX];
    chars_to_ints(package, int_vec);
    
    int alg_limit = package->size;
    int converted = 0;
    for (int i = 0, *alg_pos = &i; i < alg_limit; i++) {
        converted += pow(package->target_base, *alg_pos) * package->current_number[*alg_pos];
    }
    
    package->base_10_number = converted;
    splitter(package, 1);
    
    return;
}


void decimal_to_x(ConversionPackage *package) {
    char placeholder[LIMIT_MAX];
    
    splitter(package, 0);
    
    return;
}


void chunk_conversion(ConversionPackage *package, int chunk_size) {
    
    ConversionPackage chunk_package = {
        .current_base = 2,
        .target_base = package->target_base,
        .size = get_alg_limit(2)
    };
    
    int portion_index;
    for (int chunk_index = 0, index = 0; index < LIMIT_BASE_2; chunk_index++) {
        
        portion_index = 0;
        char next_value;
        while (portion_index % chunk_size != 0 || portion_index == 0) {
            
            if (index > LIMIT_BASE_2 - 1) {
                next_value = '0';
            } else {
                next_value = package->current_number[index];
            }
            
            chunk_package.current_number[portion_index] = next_value;
            portion_index++;
            index++;
        }
        x_to_decimal(&chunk_package);
        package->target_number[index] = int_to_char(chunk_package.base_10_number);
    }
    
    return;
}




void convert(ConversionPackage *package) {
    
    if (package->current_base == 10) {
        
        x_to_decimal(package);
    }
    return;
}
