#include <stdio.h>

float calcuate_median(float grades[4]) {
   float sum = 0;
   float median;
   
   int i;
   for (i = 0; i < 4; i++) {
       sum += grades[i];
   }
   
   median = sum / 4;
   return median;
}

float get_validated_grade() {
    float input;
    do {
        printf("insira um valor de nota \n");
        scanf("%f", &input);
    } while (input < 0 || input > 10);
    
    return input;
}

int main() {
    int is_approved;
    
    float grades[4];
    
    int next_grade;
    for (next_grade = 0; next_grade < 4; next_grade++) {
        printf("nota da prova %d", next_grade);
        grades[next_grade] = get_validated_grade();
    }
    
    is_approved = next_grade < 6;
    if (is_approved == 0) {
        printf("reprovado");
    } else {
        printf("aprovado");
    }
    
    return 0;
}