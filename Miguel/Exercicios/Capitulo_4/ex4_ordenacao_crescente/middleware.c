#include "middleware.h"
#include <stdio.h>


void clear_buffer() {
    
    while (getchar() != '\n');
    return;
}


// void recieve_and_sort_nums(int *vec) {
    
//     int right_i = VEC_SIZE - 1;
    
//     printf("Insira 10 números inteiros, separados por espaço:\n");
//     for (int count = 0; count < VEC_SIZE; count++) {
        
//         int ipt;
//         printf("[%d]-> ", count + 1);
//         scanf("%d", &ipt);
//         clear_buffer();
        
//         while (ipt < vec[right_i]) right_i--;
        
//         int next_left_most = (VEC_SIZE - count) - 1;
        
//         int times_to_switch = right_i - next_left_most;
//         for (
//             int i_left_most = next_left_most, switches = 0;
//             switches < times_to_switch;
//             switches++, i_left_most++
//         ) {
//             vec[i_left_most] = vec[i_left_most + 1];
//         }
        
//         vec[right_i] = ipt;
    
//     return;
// }


// void show_vector(int *vec) {
    
//     printf("{");
//     for (int i = 0; i < VEC_SIZE; i++) {
        
//         printf(" %d", vec[i]);
//     }
//     printf(" }\n\n");
//     return;
// }

// void debug_show_vector(int *vec) {
    
//     printf("DEBUG: SHOW VECTOR\n{");
//     for (int i = 0; i < VEC_SIZE; i++) {
        
//         printf(" %d", vec[i]);
//     }
//     printf(" }\n\n");
//     return;
// }