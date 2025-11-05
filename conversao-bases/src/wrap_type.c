#include "alg_limits.c"


typedef struct {
    
    int current_base;
    int target_base;

    char current_number[LIMIT_MAX];
    char target_number[LIMIT_MAX];
    
    int base_10_number;
    
    ALG_LIMIT size;

} ConversionPackage;