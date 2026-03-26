#include "middleware.h"


void clear_buffer() {
    
    while (getchar() != '\n');
    return;
}


void ask_for_strings(
    char *str_1,
    char *str_2,
    char *str_3,
    char *str_4,
    char *str_5
) {
    
    char *str_vec[5] = {str_1, str_2, str_3, str_4, str_5};
    for (int i = 0; i < 5; i++) {
        
        printf("[ %d ] ->> ", i + 1);
        scanf("%s", str_vec[i]);
        clear_buffer();
    }
    return;
}


void show_formatting(
    char *str_1,
    char *str_2,
    char *str_3,
    char *str_4,
    char *str_5,
    int ten,
    int twenty,
    int thirty,
    int forty,
    int fifty,
    int one_through_zero
) {
    
    printf("%14d%8d%8d%8d%8d\n", ten, twenty, thirty, forty, fifty);
    printf("%12d%d%d%d%d\n",
        one_through_zero,
        one_through_zero,
        one_through_zero,
        one_through_zero,
        one_through_zero
    );
    
    printf("%6s%34s\n", str_1, str_5);
    printf("%16s%15s\n", str_2, str_4);
    printf("%22s\n", str_3);
    return;
}