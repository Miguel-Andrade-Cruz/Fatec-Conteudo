#include <stdio.h>


int main() {
    
    const float MINIMAL_SALARY_2025 = 1518.00;
    const float value_per_hour = MINIMAL_SALARY_2025 / 12;
    const float fee = 0.03;
    
    int labour_hours;
    
    scanf("%d", &labour_hours);
    
    float brute_salary = value_per_hour * labour_hours;
    float liquid_salary = brute_salary * (1 - fee);
    
    printf("Seu salário líquido é um total de R$ %f", liquid_salary);
    
    return 0;
}