#include "middleware.h"
#include <stdio.h>


void clear_buffer() {
    
    while (getchar() != '\n');
    return;
}


int ask_for_number() {
    
    int num;
    
    printf("Insira um número positivo:  ");
    scanf("%d", &num);
    clear_buffer();
    return num;
}


int sum_number_algarisms(int num) {
    
    const int BASE_TEN = 10;
    // 'alg' means 'algarism'
    int alg_sum = 0;
    
    // starts with maximum value for power of ten
    for (int power_of_ten = 9; power_of_ten >= 0; power_of_ten--) {
        
        int div_ans = num / pow(BASE_TEN, power_of_ten);
        alg_sum += div_ans;
        num -= div_ans * pow(BASE_TEN, power_of_ten);
        
        #ifdef DEBUG
        printf("TOTAL UNTIL NOW: %d\n", alg_sum);
        #endif
    }
    
    return alg_sum;
}


void show_sum_of_algarisms(int num, int sum_of_alg) {
    
    printf("A soma dos algarismos de %d é igual a %d\n", num, sum_of_alg);
    return;
}
