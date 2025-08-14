#include <stdio.h>

// Feito por: Miguel Andrade e Luan Ferraz

float calculate_inss(float brute_salary) {
    float aliquote_ranges[4] = {
        0.075,
        0.09,
        0.12,
        0.14
    };

    float contribution_ranges[4] = {
        1518.00,
        2793.88,
        4190.83,
        8157.41
    };

    float sum_of_pieces = 0.0;
    float salary_range;
    for (int i = 0; i < 4; i++) {
        if ( brute_salary >= contribution_ranges[i]) {
            if (i == 0) {
                salary_range = contribution_ranges[i];
            } else {
                salary_range = contribution_ranges[i] - contribution_ranges[i - 1];
            }
            sum_of_pieces += salary_range * aliquote_ranges[i];
        } else if (brute_salary >= contribution_ranges[i-1] && brute_salary < contribution_ranges[i]) {
            salary_range = brute_salary - contribution_ranges[i - 1];
            sum_of_pieces += salary_range * aliquote_ranges[i];
        }
    }

    return sum_of_pieces;
}

int main() {

    // Cálculo de um salário líquido de um professor.
    // Serão fornecidos via teclado o valor da hora aula,
    // o número de aulas dadas e o desconto do INSS


    // float class_per_hour_value;
    // int classes;
    // float inss_discount;
    // float liquid_salary;

    float brute_salary;

    scanf("%f", &brute_salary);

    float inss_discount = calculate_inss(brute_salary);
    printf("Valor do desconto: %f", inss_discount);

    return 0;
}
