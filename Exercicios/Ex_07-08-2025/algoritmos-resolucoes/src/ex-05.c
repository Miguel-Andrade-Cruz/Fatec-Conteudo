#include <stdio.h>


int main() {

    float class_per_hour_value;
    int classes;
    float inss_discount;
    float liquid_salary;
    
    printf("Quantas aulas são ministradas?");
    scanf("%d", &classes);
    
    printf("Qual é o valor hora/aula?");
    scanf("%f", &class_per_hour_value);
    
    printf("Quanto é o valor de desconto do INSS?");
    scanf("%f", &inss_discount);
    
    liquid_salary = (classes * class_per_hour_value) * (1 - inss_discount);
    
    
    printf("O valor do salário líquido é de %f", liquid_salary);
    
    return 0;
}