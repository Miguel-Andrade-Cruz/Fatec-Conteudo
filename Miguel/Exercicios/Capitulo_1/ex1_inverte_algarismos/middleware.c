#include "middleware.h"

void clear_buffer() {
    
    while ( getchar() != '\n' );
    return;
}


int valid_input() {
    int input;
    
    do {
        printf("Insira um número: \n");
        scanf("%d", &input);
        
    } while (input <= 99 || input > 999);
    clear_buffer();
    
    return input;
}


int reflect_number(int input) {
    
    int hundreds, tens, units;
    int mirror_input = 0;
    
    // get the hundreds
    hundreds = input / (BASE_TEN * BASE_TEN);
    mirror_input += hundreds * (BASE_TEN / BASE_TEN);
    
    input -= hundreds * (BASE_TEN * BASE_TEN);
    
    // get the tens
    tens = input / BASE_TEN;
    mirror_input += tens * BASE_TEN;
    
    input -= tens * BASE_TEN;
    
    // get the units
    units = input / (BASE_TEN / BASE_TEN);
    mirror_input += units * (BASE_TEN * BASE_TEN);
    
    return mirror_input;
}
