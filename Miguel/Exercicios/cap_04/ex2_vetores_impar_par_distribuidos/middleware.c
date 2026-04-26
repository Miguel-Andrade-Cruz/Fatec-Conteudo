#include "middleware.h"


void clear_buffer() {
    
    while (getchar() != '\n');
    return;
}


void ask_for_10_numbers(int *input_vec) {
    
    printf("Insira 10 números:  ");
    for (int i_num = 0; i_num < VEC_SIZE; i_num++) {
        
        printf("%d -> ", i_num + 1);
        scanf("%d", &input_vec[i_num]);
    }
    return;
}


void split_even_odd_evenly(int *input_vec, int *vec_1, int *vec_2) {
    
    // To split the vectors into evens and odds, evenly
    char turn = 'o';
    for (int i_ipt = 0, i_vec_1 = 0, i_vec_2 = 0; i_ipt < VEC_SIZE; i_ipt++) {
        
        int current_num = input_vec[i_ipt];
        
        if (turn == 'o' && current_num % 2 != 0) {
            vec_1[i_vec_1] = current_num;
            i_vec_1++;
            turn = 'e';
            
        } else if (turn == 'e' && current_num % 2 == 0) {
            vec_1[i_vec_1] = current_num;
            i_vec_1++;
            turn = 'o';
            
        } else {
            vec_2[i_vec_2] = current_num;
            i_vec_2++;
        }
    }
}


void show_vecs(int *even_vec, int *odd_vec) {
    
    printf("Números pares passados:\n");
    printf("{ ");
    for (int i_num = 0; i_num < VEC_SIZE / 2; i_num++) {
        
        printf(" %d ", even_vec[i_num]);
    }
    printf(" }\n\n");
    
    
    printf("Números ímpares passados:\n");
    printf("{ ");
    for (int i_num = 0; i_num < VEC_SIZE / 2; i_num++) {
        
        printf(" %d ", odd_vec[i_num]);
    }
    printf(" }\n\n");
    return;
}
