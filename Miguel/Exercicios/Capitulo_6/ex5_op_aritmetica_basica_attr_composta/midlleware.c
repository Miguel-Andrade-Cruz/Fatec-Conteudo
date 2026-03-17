#include "middleware.h"


void clear_buffer() {
    
    while (getchar() != '\n');
    return;
}

void ask_for_two_numbers(float *acc_num, float *num) {
    
    printf("Digite o primeiro número:  ");
    scanf("%f", acc_num);
    
    printf("Digite o segundo número:  ");
    scanf("%f", acc_num);
    return;
}

void add_acc(float acc_num, float num) {
    
    // 'prev' means 'previous'
    float prev_acc_num = acc_num;
    acc_num += num;
    printf("A adição entre %.2f e %.2f = %.2f", prev_acc_num, num, acc_num);
    return;
}

void sub_acc(float acc_num, float num) {
    
    // 'prev' means 'previous'
    float prev_acc_num = acc_num;
    acc_num -= num;
    printf("A subtração entre %.2f e %.2f = %.2f", prev_acc_num, num, acc_num);
    return;
}

void mult_acc(float acc_num, float num) {
    
    // 'prev' means 'previous'
    float prev_acc_num = acc_num;
    acc_num *= num;
    printf("A multiplicação entre %.2f e %.2f = %.2f", prev_acc_num, num, acc_num);
    return;
}


void div_acc(float acc_num, float num) {
    
    // 'prev' means 'previous'
    float prev_acc_num = acc_num;
    acc_num /= num;
    printf("A divisão entre %.2f e %.2f = %.2f", prev_acc_num, num, acc_num);
    return;
}
