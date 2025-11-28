#include <math.h>
#include "utils.c"


void x_to_decimal(ConversionPackage *package) {

    int converted = 0;
    for (int i = LIMIT_MAX - 1, exponent = 0; i >= 0; i--, exponent++) {
        converted += (int) (pow(package->current_base, exponent) * package->current_number[i]);
    }
    package->base_10_number = converted;

    return;
}


void decimal_to_x(ConversionPackage *package) {

    int value = package->base_10_number;

    int i = LIMIT_MAX - 1;
    while (i >= 0) {
        if (value == 0) {
            package->target_number[i] = 0;
        } else {
            package->target_number[i] = value % package->target_base;
            value /= package->target_base;
        }

        i--;
    }

    return;
}


void bin_to_dec_partition(ConversionPackage *package, int chunk_size) {
        
    for (int i = 0; i < LIMIT_MAX; i++) package->target_number[i] = 0;
    
    ConversionPackage transition_package = {.current_base = 2};

    int offset;
    if (chunk_size == 3) {
        offset = 6;
    } else {
        offset = 4;
    }

    int chunk[chunk_size];
    int portion_index;
    int next_value;
    for (int index = LIMIT_MAX - 1, chunk_index = LIMIT_MAX - 1; index >= 0; chunk_index--) {

        portion_index = LIMIT_MAX - 1;
        for (int i = 0; i < chunk_size; i++) {

            if (index < 0) {
                next_value = 0;
            } else {
                next_value = package->current_number[index];
            }
            
            transition_package.current_number[portion_index] = next_value;
            portion_index--;
            index--;
            
        }
        x_to_decimal(&transition_package);
        package->target_number[chunk_index] = transition_package.base_10_number;
        
    }

    return;
}


void convert(ConversionPackage *package) {



    if (package->target_base == 10) {

        x_to_decimal(package);

        ConversionPackage temp_package = {
          .target_base = 10,
          .base_10_number = package->base_10_number
        };
        decimal_to_x(&temp_package);

        memcpy(package->target_number, temp_package.target_number, LIMIT_MAX * sizeof(int));
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
        
        if (package->target_base == 2) {
            memcpy(package->target_number, temp_package.target_number, LIMIT_MAX * sizeof(int));
        }
        
        memcpy(temp_package.current_number, temp_package.target_number, LIMIT_MAX * sizeof(int));
        if (package->target_base == 8) {
            bin_to_dec_partition(&temp_package, 3);
        }
        if (package->target_base == 16) {
            bin_to_dec_partition(&temp_package, 4);
        }
        
        memcpy(package->target_number, temp_package.target_number, LIMIT_MAX * sizeof(int));
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
        ConversionPackage temp_package = { .current_base = 10 };
        memcpy(temp_package.current_number, package->current_number, LIMIT_MAX * sizeof(int));

        x_to_decimal(&temp_package);

        package->base_10_number = temp_package.base_10_number;
        decimal_to_x(package);
    }

    return;
}

