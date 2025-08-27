#include <stdio.h>


int main() {
    char id;
    float n1, n2, n3, exercises_mean;
    
    printf("Nota 1:\n");
    scanf("%f", &n1);
    
    printf("Nota 2:\n");
    scanf("%f", &n2);
    
    printf("Nota 3:\n");
    scanf("%f", &n3);
    
    printf("Média de ex:\n");
    scanf("%f", &exercises_mean);
    
    float ma = (n1 + n2 * 2 + n3 * 3 + exercises_mean) / 7;
    
    
    char concept;
    if (ma < 4.0) {
      concept = 'E';  
    } else if (ma >= 4.0 && ma < 6.0) {
        concept = 'D';
    } else if ( ma >= 6.0 && ma < 7.5) {
        concept = 'C';
    } else if (ma >= 7.5 && ma < 9.0) {
        concept = 'B';
    } else {
        concept = 'A';
    }
    

    printf("id de aluno: %c\n", id);
    printf("Nota 1: %f\n", n1);
    printf("Nota 1: %f\n", n2);
    printf("Nota 1: %f\n", n3);
    printf("Média de exercícios: %f\n", exercises_mean);
    
    printf("Conceito: %c", concept);
    if (concept == 'A' || concept || 'B' || concept == 'C') {
        printf("APROVADO");
    } else {
        printf("REPROVADO");
    }
    
    return 0;
}