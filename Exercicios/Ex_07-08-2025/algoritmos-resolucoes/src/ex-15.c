#include <stdio.h>

void int_positive_inpt(int *holder) {
    
    // Recieves a varaible and assigns a user input
    // when the user inputs a non-zero positive value.
    
    int input;
    do {
        printf("Insira o valor: \n");
        scanf("%d", &input);
    } while (input <= 0);
    
    *holder = input;
    
    return;
}





void form_hours_fill(int *hour_classes, int classes_qtd) {
    
    int hours_ministred;
    for (int i = 0; i < classes_qtd; i++){
        printf("Horas na aula %d: ", i + 1);
        int_positive_inpt(&hours_ministred);
        
        hour_classes[i] = hours_ministred;
    }
    
    return;
}

float form_teacher_level() {
    
    const float teacher_level_one = 55.00;
    const float teacher_level_two = 67.00;
    const float teacher_level_three = 78.00;
    
    char teacher_level;
    float selected_teacher_level;
    
    do {
        printf("Insira seu nível de professor: \n");
        scanf("%c", &teacher_level);
        
        if (teacher_level == '1') {
            selected_teacher_level = teacher_level_one;
            break;
        } else if (teacher_level == '2') {
            selected_teacher_level = teacher_level_two;
            break;
        } else if (teacher_level == '3') {
            selected_teacher_level= teacher_level_three;
            break;
        }
    } while (1);
    
    return selected_teacher_level;
}


int main() {
    
    // A FATEC RUBENS LARA faz o pagamento de seus professores
    // por hora/aula. Faça um algoritmo que calcule e exiba o
    // salário de um professor. Sabe-se que o valor da hora/aula
    // segue a tabela abaixo:
    // Professor Nível 1 R$55,00 por hora/aula
    // Professor Nível 2 R$67,00 por hora/aula
    // Professor Nível 3 R$78,00 por hora/aula
    
    
    int classes_qtd;
    float value_hour_per_class = form_teacher_level();
    
    
    printf("Quantas aulas você teve?: ");
    scanf("%d", &classes_qtd);
    
    int classes_list[classes_qtd];
    
    form_hours_fill(classes_list, classes_qtd);
    
    int total_hours = 0;
    for (int i = 0; i < classes_qtd; i++) {
        total_hours += classes_list[i];
    }
    
    float amount = total_hours * value_hour_per_class;
    
    printf("Seu total de horas/aula é de R$ %f \n", amount);
    
    return 0;
}