

typedef enum {
    T_CHAR,
    T_INT,
    T_FLOAT,
} ipt_type;

typedef union {
    
    int v_int;
    float v_float;
    char v_char;
} Outputer;

typedef int (*Checker)(Outputer, Outputer);
typedef struct {
    
    Outputer state;
    Checker action;

} Validator;



typedef struct {
    int qtd;
    Validator *arr[];
} Needs;


