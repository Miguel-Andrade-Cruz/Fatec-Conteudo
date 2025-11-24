#include <math.h>
#include <string.h>
#include "gui.c"


void splitter(ConversionPackage *package, int preserve_base, int returned) {
    
    
    return;
}


void x_to_decimal(ConversionPackage *package) {
    
    int alg_limit = package->size;
    int converted = 0;
    for (int i = alg_limit - 1, exponent = 0; i >= 0; i--, exponent++) {
        converted += pow(package->target_base, exponent) * package->current_number[i];
    }
    package->base_10_number = converted;
    
    return;
}


void decimal_to_x(ConversionPackage *package) {

    int alg_limit = package->size;
    int value = package->base_10_number;
    
    int i = alg_limit - 1;
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
    }
    
    return;
}




void convert(ConversionPackage *package) {
    
    if (package->target_base == 10) {
        
        ConversionPackage temp_package = {
            .target_base = 10,
            .size = package->size
        };
        x_to_decimal(package);
        decimal_to_x(&temp_package);
        memcpy(package->target_number, temp_package.target_number, sizeof(temp_package.target_number));
    
        return;
    }

    
    if (package->current_base == 8 || package->current_base == 16) {
        x_to_decimal(package);
        
        ConversionPackage temp_package = {
            .base_10_number = package->base_10_number,
            .size = package->size,
            .target_base = 2,
        };
        decimal_to_x(&temp_package);
        
        memcpy(package->target_number, temp_package.target_number, sizeof(temp_package.target_number));
        if (package->target_base == 8) {
            bin_to_dec_partition(package, 3);
        }
        if (package->target_base == 16) {
            bin_to_dec_partition(package, 4);
        }
    }
    
    
    if (package->current_base == 2) {
        if (package->target_base == 8) {
            bin_to_dec_partition(package, 3);
        }
        if (package->target_base == 16) {
            bin_to_dec_partition(package, 4);
        }
    }
    
    
    if (package->current_base == 10) {
        ConversionPackage temp_package = {
            .current_number = *package->current_number,
            .current_base = 10,
            .size = package->size
        };
        
        x_to_decimal(&temp_package);
        package->base_10_number = temp_package.base_10_number;
        decimal_to_x(package);
    }

    return;
}
