#include "middleware.h"


void clear_buffer() {
    
    while (getchar() != '\n');
    return;
}


// void ask_for_10_numbers(int *input_vec) {
    
//     printf("Insira 10 números:  ");
//     for (int i_num = 0; i_num < VEC_SIZE; i_num++) {
        
//         printf("%d -> ", i_num + 1);
//         scanf("%d", &input_vec[i_num]);
//     }
//     return;
// }


// void extract_even_nums(int *input, int *returned) {
    
//     for (int i_num = 0, i_even = 0; i_num < VEC_SIZE; i_num++) {
        
//         if (input[i_num] % 2 == 0) {
            
//             returned[i_even] = input[i_num];
//             i_even++;
//         }
//     }
//     return;
// }


// void extract_odd_nums(int *input, int *returned) {
    
//     for (int i_num = 0, i_odd = 0; i_num < VEC_SIZE; i_num++) {
        
//         if (input[i_num] % 2 != 0) {
            
//             returned[i_odd] = input[i_num];
//             i_odd++;
//         }
//     }
//     return;
// }


// void show_vecs(int *even_vec, int *odd_vec) {
    
//     printf("Números pares passados:\n");
//     printf("{  ");
//     for (int i_num = 0; i_num < VEC_SIZE / 2; i_num++) {
        
//         printf("%d  ", even_vec[i_num]);
//     }
//     printf("{\n\n");
    
    
//     printf("Números ímpares passados:\n");
//     printf("{  ");
//     for (int i_num = 0; i_num < VEC_SIZE / 2; i_num++) {
        
//         printf("%d  ", odd_vec[i_num]);
//     }
//     printf("{\n\n");
//     return;
// }