

typedef union {
    
    int *V_INT;
    float *V_FLOAT;
    char *V_CHAR;
} Any;


typedef enum {
    T_INT,
    T_FLOAT,
    T_CHAR
} TYPE;


typedef struct {
    Any value;
    TYPE type;
} TypedValue;


typedef int (*Checkup)(TypedValue, TypedValue);


typedef struct {
    
    TypedValue bound;
    Checkup action;
} Rule;


typedef struct {
    
    TypedValue value;
    int value_size;
    
    Rule *requires;
    int requires_size;
} Guard;