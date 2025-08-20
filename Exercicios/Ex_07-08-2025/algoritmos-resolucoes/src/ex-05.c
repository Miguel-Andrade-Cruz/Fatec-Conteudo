#include <stdio.h>

// Feito por: Miguel Andrade e Luan Ferraz

typedef enum {
    INT,
    FLOAT,
    CHAR
} InputType;

typedef union {
    int output_int;
    float output_float;
    char output_char;
} Output;



void get_input(Output *output, InputType input_type, char *msg) {
    
    printf("%s\n", msg);
    switch (input_type) {
        case INT:
            scanf("%d", &output->output_int);
            break;
        case CHAR:
            scanf("%c", &output->output_char);
            break;
        case FLOAT:
            scanf("%f", &output->output_float);
            break;
    }
    return;
}


float calculate_inss(float brute_salary) {
    float aliquote_percentuals[4] = {
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

    float sum_of_ranges = 0.0;
    float salary_range;
    
    int lenght = sizeof(contribution_ranges) / sizeof(contribution_ranges[0]);
    for (int i = 0; i < lenght; i++) {
        if ( brute_salary >= contribution_ranges[i]) {
            if (i == 0) {
                salary_range = contribution_ranges[i];
            } else {
                salary_range = contribution_ranges[i] - contribution_ranges[i - 1];
            }
            sum_of_ranges += salary_range * aliquote_percentuals[i];
        } else if (brute_salary >= contribution_ranges[i-1] && brute_salary < contribution_ranges[i]) {
            salary_range = brute_salary - contribution_ranges[i - 1];
            sum_of_ranges += salary_range * aliquote_percentuals[i];
        }
    }

    return sum_of_ranges;
}

int main() {

    // Cálculo de um salário líquido de um professor.
    // Serão fornecidos via teclado o valor da hora aula,
    // o número de aulas dadas e o desconto do INSS

    float liquid_salary;
    float inss_discount;
    
    
    char cost_per_hour_msg[] = "Qual é o valor de sua hora/aula? \n";
    InputType cost_per_hour_type = FLOAT;
    Output cost_per_hour_output;
    get_input(&cost_per_hour_output, cost_per_hour_type, cost_per_hour_msg);

    char classes_msg[] = "Quantas aulas foram dadas? \n";
    InputType classes_type = INT;
    Output classes_output;
    get_input(&classes_output, classes_type, classes_msg);

    float brute_salary = cost_per_hour_output.output_float * classes_output.output_int;

    inss_discount = calculate_inss(brute_salary);
    liquid_salary = brute_salary - inss_discount;
    printf("Valor do desconto: %f Salário líquido de %f \n", inss_discount, liquid_salary);

    return 0;
}
