#ifndef DATA_TYPES_H
#define DATA_TYPES_H

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


#endif