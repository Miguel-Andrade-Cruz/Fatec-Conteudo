#include "middleware.h"
#include <stdio.h>


void clear_buffer() {
    
    while (getchar() != '\n');
    return;
}

float ask_kilometers_traveled() {
    
    float kilometers_traveled;
    
    printf("Digite a distância perocrrida em quilômetros:  ");
    scanf("%f", &kilometers_traveled);
    return kilometers_traveled;
}

float ask_gasoline_consumed() {
    
    float gasoline_consumed;
    
    printf("Digite a  consumo de gasolina em litros:  ");
    scanf("%f", &gasoline_consumed);
    return gasoline_consumed;
}

float calculate_consumption(float kilometers_traveled, float gasoline_consumed) {
    
    float km_per_liter = kilometers_traveled / gasoline_consumed;
    return km_per_liter;
}

void show_consumption(float consumption) {
    
    // TODO: Desenvolver função
    return
}