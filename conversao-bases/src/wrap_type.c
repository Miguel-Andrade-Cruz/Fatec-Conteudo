#include "alg_limits.c"


typedef struct {
    
    int current_base;
    int target_base;

    int current_number[LIMIT_MAX];
    int target_number[LIMIT_MAX];
    
    int base_10_number;
    
    ALG_LIMIT size;

} ConversionPackage;