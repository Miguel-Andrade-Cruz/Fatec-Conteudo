
const int TO_INT_OFFSET = 10;
const int TO_CHAR_OFFSET = 9;

const int TO_INT_BITMASK = 0x0F;

const int TO_CHAR_DIGIT_BITMASK = 0x30;
const int TO_CHAR_ALPHA_BITMASK = 0x40;


typedef enum {
    LIMIT_BASE_2 = 16,
    LIMIT_BASE_8 = 5,
    LIMIT_BASE_10 = 5,
    LIMIT_BASE_16 = 4,
    LIMIT_MAX = 16
} ALG_LIMIT;

ALG_LIMIT get_alg_limit(int base) {
    ALG_LIMIT alg_limit;
    if (base == 2) {alg_limit = LIMIT_BASE_2;}
    if (base == 8) {alg_limit = LIMIT_BASE_8;}
    if (base == 10) {alg_limit = LIMIT_BASE_10;}
    if (base == 16) {alg_limit = LIMIT_BASE_16;}
    
    return alg_limit;
}


