#include <stdio.h>


int main() {
    float current_salary;
    float adjusted_salary;
    
    float adjust_first_range = 0.15;
    float adjust_second_range = 0.10;
    float adjust_third_range = 0.05;
    
    float first_range = 800.00;
    float second_range = 1000.00;
    
    printf("Insira o valor do salário: \n");
    scanf("%f", &current_salary);
    
    if (current_salary <= first_range) {
        adjusted_salary = current_salary * (1 - adjust_first_range);
    } else if (current_salary > first_range && current_salary <= second_range) {
        adjusted_salary = current_salary * (1 - adjust_second_range);
    } else {
        adjusted_salary = current_salary * (1 - adjust_third_range);
    }
   
    printf("Salário anterior: %f salário ajustado para %.2f", current_salary, adjusted_salary); 
    return 0;
}