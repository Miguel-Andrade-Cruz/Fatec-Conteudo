#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float gt;
    float lt;
    int (*monad)(float, float, float);
} in_between_monad;


int in_between(float target, float gt, float lt) { 
    /*
     * return true if the target is equal or greater than gt
     * and equal or less than lt, otherwise returns false
     */
     
     if (target >= gt && target <= lt) {
         return 1;
     } else {
         return 0;
     }
}

int exec_in_between_monad(in_between_monad *monad, float target) {
    return monad->monad(target, monad->gt, monad->lt);
}


in_between_monad* create_in_between_monad(float gt, float lt){
    
    in_between_monad *monad = malloc(sizeof(in_between_monad));
    monad->gt = gt;
    monad->lt = lt;
    monad->monad = in_between;
    
    return monad;
}



typedef int (*validator)(float);



void get_float_inputs(float *inputs, int size, char *msgs[], in_between_monad *validator) {
    
    int i;
    for (i = 0; i < size; i++) {
        do {
            printf("%s", msgs[i]);
            scanf("%f", &inputs[i]);
            
        } while (exec_in_between_monad(validator, inputs[i]) == 0);
    }
    
    return;
}






int main() {
    char
        msg1[] = "Nota 1: \n",
        msg2[] = "Nota 2: \n",
        msg3[] = "Nota 3: \n",
        msg4[] = "Nota 4: \n"
    ;
    char *msgs[] = {msg1, msg2, msg3, msg4};
    
    int size = 4;
    float grades[size];
    
    in_between_monad* between_0_10 = create_in_between_monad(0.0, 10.0);
    
    
    get_float_inputs(grades, size, msgs, between_0_10);
    
    float sum = 0.0;
    int i;
    for (i = 0; i < size; i++) {
        sum += grades[i];
    }
    float mean = sum / size;
    
    printf("Sua média final é %f\n", mean);
    if ( mean >= 6.0) {
        printf("Você foi aprovado\n");
    } else {
        printf("Você foi reporvado\n");
    }
    
    
    return 0;
}