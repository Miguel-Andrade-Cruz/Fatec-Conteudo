// 4 - Receba via teclado a distancia em km e a quantidade de litros de gasolina
//    consumidos por um carro em um percurso.
//    Calcule o consumo em km/l e escreva uma mensagem de acordo com a tabela
//    abaixo:
//    CONSUMO (km/l) MENSAGEM
//    menor que 8    Venda o carro!
//    entre 8 e 14   Economico!
//    maior que 14   Super economico

#define INNER_MODE
// #define OUTER_MODE


#ifdef OUTER_MODE
#include "middleware.h"

int main() {
    
    char again = 'n';
    do {
        
        float kilometers_traveled = ask_kilometers_traveled();
        float gasoline_liters = ask_gasoline_consumed();
        
        float average_consumption = calculate_consumption(kilometers_traveled, gasoline_liters);
        show_consumption(average_consumption);
        
        // +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
        printf("Deseja executar novamente? ( s / n )");
        scanf("%c", &again);
        clear_buffer();
    } while (again == 's');
    
    return 0;
}
#endif // OUTER_MODE


#ifdef INNER_MODE
#include <stdio.h>

void clear_buffer() {
    
    while (getchar() != '\n');
    return;
}


float ask_kilometers_traveled() {
    
    float kilometers_traveled;
    
    printf("Digite a distância percorrida em quilômetros:  ");
    scanf("%f", &kilometers_traveled);
    clear_buffer();
    return kilometers_traveled;
}


float ask_gasoline_consumed() {
    
    float gasoline_consumed;
    
    printf("Digite a  consumo de gasolina em litros:  ");
    scanf("%f", &gasoline_consumed);
    clear_buffer();
    return gasoline_consumed;
}


float calculate_consumption(float kilometers_traveled, float gasoline_consumed) {
    
    float km_per_liter = kilometers_traveled / gasoline_consumed;
    return km_per_liter;
}


void show_consumption(float consumption) {
    
    const int LOW_EFFICIENCY = 8;
    const int HIGH_EFFICIENCY = 14;
    
    printf("Consumo médio: %.1fKm/L  ", consumption);
    if (consumption < LOW_EFFICIENCY) {
        printf("Venda o carro!\n");
        
    } else if (consumption > HIGH_EFFICIENCY) {
        printf("Super econômico\n");
        
    } else {
        printf("Econômico!\n");
    }
    return;
}

int main() {
    
    char again = 'n';
    do {
        
        float kilometers_traveled = ask_kilometers_traveled();
        float gasoline_liters = ask_gasoline_consumed();
        
        float average_consumption = calculate_consumption(kilometers_traveled, gasoline_liters);
        show_consumption(average_consumption);
        
        // +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
        printf("Deseja executar novamente? ( s / n )");
        scanf("%c", &again);
        clear_buffer();
    } while (again == 's');
    
    return 0;
}
#endif // INNER_MODE
