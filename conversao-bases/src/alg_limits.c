
// Algarism limits for correspondent bases

typedef enum {
    LIMIT_BASE_2 = 15,
    LIMIT_BASE_8 = 5,
    LIMIT_BASE_10 = 5,
    LIMIT_BASE_16 = 4,
    LIMIT_MAX = 15
} ALG_LIMIT;

ALG_LIMIT get_alg_limit(int base) {
    ALG_LIMIT alg_limit;
    if (base == 2) {alg_limit = LIMIT_BASE_2;}
    if (base == 8) {alg_limit = LIMIT_BASE_8;}
    if (base == 10) {alg_limit = LIMIT_BASE_10;}
    if (base == 16) {alg_limit = LIMIT_BASE_16;}
    
    return alg_limit;
}

